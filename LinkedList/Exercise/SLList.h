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

	FNode* GetNode(const int Index)
	{
		FNode* Current = Head;
		for (int i = 0; i < Index; i++)
		{
			Current = Current->Next;
		}
		return Current;
	}

public:

	class FIterator
	{
	private:
		FNode* Current;

	public:

		/*FIterator()
		{
			Current = Head;
		}*/

		FIterator(FNode* NewCurrent)
		{
			Current = NewCurrent;
		}

		FIterator& operator++ ()
		{
			Current = Current->Next;
			return *this;
		}

		Type& operator* ()
		{
			return Current->Element;
		}

		bool operator!= (const FIterator& Other)
		{
			return Current != Other.Current;
		}


	};

	FIterator begin()
	{
		if (Head)
		{
			return FIterator(Head);
		}
		return FIterator(nullptr);
	}

	FIterator end()
	{
		return FIterator(nullptr);
	}


	//Constructor
	//-------------------------------------------------------------------------------------

	TSLList() : Head(nullptr), Tail(nullptr), ListSize(0) {};

	//-------------------------------------------------------------------------------------

	~TSLList()
	{
		Clear();
	};

	//-------------------------------------------------------------------------------------

	TSLList(TSLList& InList)
	{
		FNode* Current = InList.Head;
		for (int i = 0; i < InList.ListSize; i++)
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

	void operator= (TSLList& InList)
	{
		Clear();
		FNode* Current = InList.Head;
		for (int i = 0; i < InList.ListSize; i++)
		{
			AddTail(Current->Element);
			Current = Current->Next;
		}
	}

	//-------------------------------------------------------------------------------------

	const Type& operator= (const int Index) const
	{
		return GetNode(Index)->Element;
	}

	//-------------------------------------------------------------------------------------

	Type& GetHead()
	{
		return Head->Element;
	}

	const Type& GetHead() const
	{
		return Head->Element;
	}

	//-------------------------------------------------------------------------------------

	Type& GetTail()
	{
		return Tail->Element;
	}

	//-------------------------------------------------------------------------------------

	const Type& GetTail() const
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

		if (ListSize == 0)
		{
			Tail = Head;
		}

		ListSize++;
	}

	//-------------------------------------------------------------------------------------

	void AddTail(const Type& InElement)
	{
		if (ListSize == 0)
		{
			AddHead(InElement);
		}
		else
		{
			FNode* NewTail = new FNode();
			NewTail->Element = InElement;

			Tail->Next = NewTail;
			Tail = NewTail;

			ListSize++;
		}

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
			FNode* Current = GetNode(Index);

			FNode* NewNode = new FNode();
			NewNode->Element = InElement;

			GetNode(Index - 1)->Next = NewNode;
			NewNode->Next = Current;
			ListSize++;
		}
	}

	//-------------------------------------------------------------------------------------

	void Remove(const int Index)
	{
		if (Index == 0)
		{
			FNode* NextUp = Head->Next;
			delete Head;
			Head = NextUp;
		}
		else if (Index > 0 && Index < ListSize)
		{
			FNode* Previous = GetNode(Index - 1);
			FNode* Pending = Previous->Next;
			Previous->Next = Pending->Next;
			delete Pending;
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

	//-------------------------------------------------------------------------------------

	template<typename Pred>
	void ForEach(const Pred& Predicate)
	{
		for (int i = 0; i < ListSize; i++)
		{
			Predicate(GetNode(i));
		}
	}

	//-------------------------------------------------------------------------------------

	template<typename Pred>
	Type* FindByPredicate(const Pred& Predicate) const
	{
		FNode* Current = Head;
		while (Current)
		{
			if (Predicate(Current->Element))
			{
				return &Current->Element;
			}

			Current = Current->Next;
		}

		//if doesn't find the element
		return nullptr;
	}

	//-------------------------------------------------------------------------------------

	template<typename Pred>
	TSLList<Type> FilterByPredicate(const Pred& Predicate) const
	{
		TSLList<Type> NewList;

		FNode* Current = Head;
		for (int i = 0; i < ListSize; i++)
		{
			if (Predicate(Current->Element))
			{
				NewList.AddTail(Current->Element);
			}
			Current = Current->Next;
		}
		return NewList;
	}

	//-------------------------------------------------------------------------------------

	template<typename Pred>
	void RemoveAllByPredicate(const Pred& Predicate) const
	{
		FNode* Current = Head;
		for (int i = 0; i < ListSize; i++)
		{
			if (Predicate(Current->Element))
			{
				Remove(i);
			}
			Current = Current->Next;
		}
	}
};