#pragma once
#include "SLList.h"

template<typename Type>
class TStack
{
private:
	TSLList<Type> List;

public:
	
	void Push(const Type& InData)
	{
		List.AddHead(InData);
	}

	void Pop()
	{
		List.Remove(0);
	}

	Type& Peek() const
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
