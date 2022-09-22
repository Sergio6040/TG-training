#pragma once
#include "SLList.h"

template<typename Type>
class TQueue
{
private:
	TSLList<Type> List;

public:

	void Enqueue(const Type& InData)
	{
		List.AddTail(InData);
	}

	void Dequeue()
	{
		List.Remove(0);
	}

	Type& Front()
	{
		return List.GetHead();
	}

	bool IsEmpty() const
	{
		return List.IsEmpty();
	}

	int GetSize() const
	{
		List.GetSize();
	}

};
