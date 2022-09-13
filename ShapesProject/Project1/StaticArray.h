#pragma once
#include<cstring>

template <typename T, int N> 
class TStaticArray
{
private:
	T* StaticArray = new T[N];

public:

	~TStaticArray()
	{
		delete[] StaticArray;
	}

	const T& operator[] (const int Index) const
	{
		return StaticArray[Index];
	}

	T& operator[] (const int Index)
	{
		return StaticArray[Index];
	}

//------------------------------------------------------------------------------------------

	const T& Front() const
	{
		return StaticArray[0];
	}

	T& Front()
	{
		return StaticArray[0];
	}

//------------------------------------------------------------------------------------------

	const T& Back() const
	{
		return StaticArray[N - 1];
	}

	T& Back()
	{
		return StaticArray[N - 1];
	}

//------------------------------------------------------------------------------------------

	const T* GetData() const
	{
		return StaticArray;
	}

	T* GetData()
	{
		return StaticArray;
	}

//------------------------------------------------------------------------------------------
	
	bool IsEmpty() const
	{
		return N == 0;
	}

//------------------------------------------------------------------------------------------

	int GetSize() const
	{
		return N;
	}

//------------------------------------------------------------------------------------------

	void Fill(const T& Value)
	{
		for (int i = 0; i < N; i++)
		{
			StaticArray[i] = Value;
		}
	}

//------------------------------------------------------------------------------------------

	void Swap(TStaticArray<T, N>& OtherArray)
	{
		T* AuxiliarArray = new T[N];

		for (int i = 0; i < N; i++)
		{
			AuxiliarArray[i] = StaticArray[i];
			StaticArray[i] = OtherArray[i];
			OtherArray[i] = AuxiliarArray[i];
		}

		delete[] AuxiliarArray;
	}

};