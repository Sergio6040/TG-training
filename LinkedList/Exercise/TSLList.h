#pragma once

template<typename Type>
class TSLList
{
private:

	struct FNode
	{
		Type Element;
		FNode* Next = nullptr;
	};

	FNode* Head;
	FNode* Tail;

	int ListSize;

	FNode&* GetNode(const int Index)
	{
		FNode* Current = Head;
		for (int i = 0; i < Index; i++)
		{
			Current = Current->Next;
		}
		return Current;
	}

public:

	TSLList() : Head(nullptr), Tail(nullptr), ListSize(0) {};

	//-------------------------------------------------------------------------------------

	Type& operator[] (const int Index)
	{
		return GetNode(Index)->Element;
	}

	//-------------------------------------------------------------------------------------

	const Type& operator[] (const int Index) const
	{
		FNode* Current = Head;
		for (int i = 0; i < Index; i++)
		{
			Current = Current->Next;
		}
		return Current->Element;
	}

	//-------------------------------------------------------------------------------------

	Type& Head()
	{
		return Head->Element;
	}

	const Type& Head() const
	{
		return Head->Element;
	}

	//-------------------------------------------------------------------------------------

	void Tail()
	{
		return Tail->Element;
	}

	//-------------------------------------------------------------------------------------

	const void Tail() const
	{
		return Tail->Element;
	}

	//-------------------------------------------------------------------------------------

	bool IsEmpty() const
	{
		return ListSize == 0;
	}

	//-------------------------------------------------------------------------------------

	int GetSize() const
	{
		return ListSize;
	}

	//-------------------------------------------------------------------------------------

	void AddHead(const Type& InElement)
	{
		FNode* NewHead;
		NewHead->Element = InElement;
		NewHead->Next = Head;

		Head = NewHead;

		ListSize++;
	}

	//-------------------------------------------------------------------------------------

	void AddTail(const Type& InElement)
	{
		FNode* NewTail;
		NewTail->Element = InElement;

		Tail->Next = NewTail;

		ListSize++;

	}

	//-------------------------------------------------------------------------------------

	void Insert(const Type& InElement, const int Index)
	{
		if (Index == 0)
		{
			AddHead(InElement);
			ListSize++;
		}
		else if (Index > 0 && Index < ListSize)
		{
			FNode* NewNode;
			NewNode->Element = InElement;

			GetNode(Index - 1)->Next = NewNode;
			NewNode->Next = GetNode(Index);
			ListSize++;
		}
	}

	//-------------------------------------------------------------------------------------

	void Remove(const int Index)
	{
		if (Index >= 0 && Index < ListSize)
		{
			GetNode(Index)->Next = nullptr;
			GetNode(Index - 1)->Next = GetNode(Index + 1);
			ListSize--;
		}
	}

	//-------------------------------------------------------------------------------------

	void Clear()
	{
		
	}
};