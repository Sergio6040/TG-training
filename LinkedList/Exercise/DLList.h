#pragma once

template<typename Type>
class TDLList
{
private:

	struct FNode
	{
		Type Data;
		FNode* Next = nullptr;
		FNode* Previous = nullptr;

		FNode() = default;
		FNode(const Type& NewData, FNode* NewPrevious, FNode* NewNext) : Data(NewData), Next(NewNext), Previous(NewPrevious) {};
	};

	FNode* Head;
	FNode* Tail;

	int Size;

	FNode* GetNode(const int Index)
	{
		FNode* Current;

		if (Index < (Size / 2))
		{
			Current = Head;
			for (int i = 0; i < Index; i++)
			{
				Current = Current->Next;
			}
		}
		else
		{
			Current = Tail;
			for (int i = Size - 1; i > Index; i--)
			{
				Current = Current->Previous;
			}
		}
		return Current;
	}


public:

	class FIterator
	{
	private:
		FNode* Current;

	public:

		FIterator(FNode* NewCurrent)
		{
			Current = NewCurrent;
		}

		FIterator& operator++()
		{
			Current = Current->Next;
			return *this;
		}

		Type& operator*()
		{
			return Current->Data;
		}

		const Type& operator*() const
		{
			return Current->Data;
		}

		bool operator!=(const FIterator& Other)
		{
			return Current != Other.Current;
		}
	};

	//-------------------------------------------------------------------------------------

	FIterator begin()
	{
		return FIterator(Head);
	}

	//-------------------------------------------------------------------------------------

	FIterator end()
	{
		return FIterator(nullptr);
	}

	//-------------------------------------------------------------------------------------

	TDLList() : Head(nullptr), Tail(nullptr), Size(0) {};

	//-------------------------------------------------------------------------------------

	~TDLList()
	{
		Clear();
	};

	//-------------------------------------------------------------------------------------

	TDLList(const TDLList& InList)
	{
		FNode* Current = InList.Head;
		for (int i = 0; i < InList.Size; i++)
		{
			AddTail(Current->Data);
			Current = Current->Next;
		}
	}

	//-------------------------------------------------------------------------------------

	Type& operator[](const int Index)
	{
		return GetNode(Index)->Data;
	}

	//-------------------------------------------------------------------------------------

	const Type& operator[](const int Index) const
	{
		return GetNode(Index)->Data;
	}

	//-------------------------------------------------------------------------------------

	void operator=(const TDLList& InList)
	{
		Clear();
		FNode* Current = InList.Head;
		for (int i = 0; i < InList.Size; i++)
		{
			AddTail(Current->Data);
			Current = Current->Next;
		}
	}

	//-------------------------------------------------------------------------------------

	Type& GetHead()
	{
		return Head->Data;
	}

	//-------------------------------------------------------------------------------------

	const Type& GetHead() const
	{
		return Head->Data;
	}

	//-------------------------------------------------------------------------------------

	Type& GetTail()
	{
		return Tail->Data;
	}

	//-------------------------------------------------------------------------------------

	const Type& GetTail() const
	{
		return Tail->Data;
	}

	//-------------------------------------------------------------------------------------

	bool IsEmpty() const
	{
		return Size == 0;
	}

	//-------------------------------------------------------------------------------------

	int GetSize() const
	{
		return Size;
	}

	//-------------------------------------------------------------------------------------

	void AddHead(const Type& InData)
	{
		FNode* NewHead = new FNode(InData, nullptr, Head);

		Head = NewHead;

		if (Size == 0)
		{
			Tail = Head;
		}
		Size++;
	}

	//-------------------------------------------------------------------------------------

	void AddTail(const Type& InData)
	{
		if (Size == 0)
		{
			AddHead(InData);
		}
		else
		{
			FNode* NewTail = new FNode(InData, Tail, nullptr);

			Tail->Next = NewTail;
			Tail = NewTail;
			Size++;
		}
	}

	//-------------------------------------------------------------------------------------

	void Insert(const Type& InData, const int Index)
	{
		if (Index == 0)
		{
			AddHead(InData);
		}
		else if (Index > 0 && Index < Size)
		{
			FNode* Current = GetNode(Index);

			FNode* NewNode = new FNode(InData, Current->Previous, Current);

			Current->Previous->Next = NewNode;
			Current->Previous = NewNode;

			/*Previous->Next->Previous = NewNode;
			Previous->Next = NewNode;*/
			Size++;
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
			Head->Previous = nullptr;
			Size--;
		}
		else if (Index > 0 && Index < Size)
		{
			FNode* Previous = GetNode(Index - 1);
			FNode* ToRemove = Previous->Next;

			Previous->Next = ToRemove->Next;
			ToRemove->Next->Previous = Previous;

			delete ToRemove;
			Size--;

			/*ToRemove = GetNode(Index);
			ToRemove->Previous->Next = ToRemove->Next;
			ToRemove->Next->Previous = ToRemove->Previous;*/
		}
	}

	//-------------------------------------------------------------------------------------

	void Clear()
	{
		FNode* NextUp;

		for (int i = 0; i < Size; i++)
		{
			NextUp = Head->Next;
			delete Head;
			Head = NextUp;
		}
		Size = 0;
	}

	//-------------------------------------------------------------------------------------

	template<typename Pred>
	void ForEach(const Pred& Predicate)
	{
		for (int i = 0; i < Size; i++)
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
			if (Predicate(Current->Data))
			{
				return &Current->Data;
			}

			Current = Current->Next;
		}

		//if doesn't find the Data
		return nullptr;
	}

	//-------------------------------------------------------------------------------------

	template<typename Pred>
	TSLList<Type> FilterByPredicate(const Pred& Predicate) const
	{
		TSLList<Type> NewList;

		FNode* Current = Head;
		for (int i = 0; i < Size; i++)
		{
			if (Predicate(Current->Data))
			{
				NewList.AddTail(Current->Data);
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
		for (int i = 0; i < Size; i++)
		{
			if (Predicate(Current->Data))
			{
				Remove(i);
				i--;
			}
			Current = Current->Next;
		}
	}
};
