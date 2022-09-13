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

public:

	TSLList() : Head(nullptr), Tail(nullptr), ListSize(0) {};

	//-------------------------------------------------------------------------------------

	Type& operator[] (const int Index)
	{
		FNode* Current = Head;
		for (int i = 0; i < Index; i++)
		{
			Current = Current->Next;
		}
		return Current->Element;
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
};