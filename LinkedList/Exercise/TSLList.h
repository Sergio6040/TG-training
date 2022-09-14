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

	TSLList(TSLList& InList)
	{
		FNode* Current = InList.Head;
		AddHead(Current->Element);
		for (int i = 1; i < InList.ListSize; i++)
		{
			AddTail(Current->Element);
			Current = Current->Next;
		}
	}

	//-------------------------------------------------------------------------------------

	Type& operator[] (const int Index)
	{
		return GetNode(Index)->Element;
	}

	//-------------------------------------------------------------------------------------

	const Type& operator[] (const int Index) const
	{
		return GetNode(Index)->Element;
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
		FNode* NewHead = new FNode();
		NewHead->Element = InElement;
		NewHead->Next = Head;

		Head = NewHead;

		ListSize++;
	}

	//-------------------------------------------------------------------------------------

	void AddTail(const Type& InElement)
	{
		FNode* NewTail = new FNode();
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
		}
		else if (Index > 0 && Index < ListSize)
		{
			FNode* NewNode = new FNode();
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
			GetNode(Index - 1)->Next = GetNode(Index + 1);
			delete GetNode(Index);
			ListSize--;
		}
	}

	//-------------------------------------------------------------------------------------

	void Clear()
	{
		FNode* NextUp;

		for (int i = 0; i < ListSize; i++)
		{
			NextUp = Head->Next;
			delete Head;
			Head = NextUp;
		}
		ListSize = 0;
	}
};