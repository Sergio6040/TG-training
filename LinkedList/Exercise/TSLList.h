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

	TSLList()
	{

	}
	
};