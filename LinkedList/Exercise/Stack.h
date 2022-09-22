#pragma once
#include "SLList.h"

template<typename Type>
class TStack
{
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

	Type& Peek() 
	{
		return List.GetHead();
	}
};
