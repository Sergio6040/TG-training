#pragma once

template <typename T, int N> 
class TStaticArray
{
	N ArraySize;
	T* SpecialArray = new T[N];
};