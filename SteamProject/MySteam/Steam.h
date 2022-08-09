#pragma once
#include "CategoryHandler.h"
#include "Category.h"

class FSteam
{
	FCategoryHandler MainHandler = FCategoryHandler();
	FCategory Uncategorized = FCategory("Uncategorized");

public:

	FSteam();

	void RunApp();

};