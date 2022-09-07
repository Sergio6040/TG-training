#pragma once

#include<cstring>

template <typename T, int N> 
class TStaticArray
{
	int ArraySize = N;
	T* SpecialArray = new T[N];

public:

	const T& operator[] (const int Index) const
	{
		return SpecialArray[Index];
	}

	T& operator[] (const int Index)
	{
		return SpecialArray[Index];
	}

//--------------------------------------------------------------

	const T& Front() const
	{
		return SpecialArray[0];
	}

	T& Front()
	{
		return SpecialArray[0];
	}

//--------------------------------------------------------------

	const T& Back() const
	{
		return SpecialArray[ArraySize];
	}

	T& Back()
	{
		return SpecialArray[ArraySize];
	}

//--------------------------------------------------------------

	const T* GetData() const
	{
		return SpecialArray;
	}

	T* GetData()
	{
		return SpecialArray;
	}

//--------------------------------------------------------------
	
	bool IsEmpty() const
	{
		return N == 0;
	}

//--------------------------------------------------------------

	int GetSize() const
	{
		return N;
	}

//--------------------------------------------------------------

	void Fill(T Value)
	{
		for (int i = 0; i < ArraySize; i++)
		{
			SpecialArray[i] = Value;
		}
	}

//--------------------------------------------------------------

	bool Swap(T& OtherArray)
	{
		int OtherSize = sizeof(OtherArray) / sizeof(OtherArray[0]);

		if (OtherSize == N)
		{
			T* AuxiliarArray = new T[N];
			memcpy(AuxiliarArray, SpecialArray, N);
			memcpy(SpecialArray, OtherArray, N);
			memcpy(OtherArray, AuxiliarArray, N);

			delete[] OtherArray;
		}
	}

};