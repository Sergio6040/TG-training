#pragma once

template<typename T>
class TDynamicArray
{
	T* DynamicArray;
	int ArraySize;
	int ArrayCapacity;

public:

	//TDynamicArray() = default;

	TDynamicArray(int InCapacity)
	{
		DynamicArray = new T[InCapacity];
		ArraySize = 0;
		ArrayCapacity = InCapacity;
	}

	//------------------------------------------------------------------------------------------

	~TDynamicArray()
	{
		delete[] DynamicArray;
	}

	//------------------------------------------------------------------------------------------


	const T& operator[] (const int Index) const
	{
		CheckBounds();
		return DynamicArray[Index];
	}

	//------------------------------------------------------------------------------------------


	T& operator[] (const int Index)
	{
		CheckBounds();
		return DynamicArray[Index];
	}

	//------------------------------------------------------------------------------------------

	const T& Front() const
	{
		return DynamicArray[0];
	}

	T& Front()
	{
		return DynamicArray[0];
	}

	//------------------------------------------------------------------------------------------

	const T& Back() const
	{
		return DynamicArray[ArraySize];
	}

	T& Back()
	{
		return DynamicArray[ArraySize];
	}

	//------------------------------------------------------------------------------------------

	const T* GetData() const
	{
		return DynamicArray;
	}

	T* GetData()
	{
		return DynamicArray;
	}

	//------------------------------------------------------------------------------------------

	bool IsEmpty() const
	{
		return ArraySize == 0;
		
	}

	//------------------------------------------------------------------------------------------

	int GetSize() const
	{
		return ArraySize;
	}

	//------------------------------------------------------------------------------------------

	int GetCapacity() const
	{
		return ArrayCapacity;
	}

	//------------------------------------------------------------------------------------------

	void Reserve() const
	{
		Resize(ArrayCapacity * 2);
	}

	//------------------------------------------------------------------------------------------

	void ShrinkToFit()
	{
		ArrayCapacity = ArraySize;
		Resize(ArrayCapacity);
	}

	//------------------------------------------------------------------------------------------

	void Clear()
	{
		for (int i = 0; i < ArraySize; i++)
		{
			delete DynamicArray[i];
		}
		ArraySize = 0;
	}

	//------------------------------------------------------------------------------------------

	void PushBack(const T& NewItem)
	{
		CheckBounds();

		ArraySize++;
		DynamicArray[ArraySize] = NewItem;
	}

	//------------------------------------------------------------------------------------------

	void PopBack()
	{
		delete DynamicArray[ArraySize];
		ArraySize--;
	}

	//------------------------------------------------------------------------------------------

	void Insert(const T& NewItem, int Position)
	{
		CheckBounds();

		ArraySize++;

		//Auxiliar variables
		T AuxiliarA{DynamicArray[Position]};
		T AuxiliarB{DynamicArray[Position]};

		for (int i = Position; i < ArraySize - 1; i++)
		{
			//moves the values +1 position
			AuxiliarA = DynamicArray[i + 1];
			DynamicArray[i + 1] = AuxiliarB;
			AuxiliarB = AuxiliarA;
		}
		DynamicArray[Position] = NewItem;
	}

	//------------------------------------------------------------------------------------------

	void Erase(int Position)
	{
		CheckBounds();

		for (int i = Position; i < ArraySize - 1; i++)
		{
			DynamicArray[i] = DynamicArray[i + 1];
		}

		delete DynamicArray[ArraySize];
		ArraySize--;
	}

	//------------------------------------------------------------------------------------------
	
	void ShrinkToFit(int Value)
	{
		ArrayCapacity = ArraySize;
		Resize(ArrayCapacity);
	}

	//------------------------------------------------------------------------------------------

	void Fill(const T& Value)
	{
		for (int i = 0; i < ArraySize; i++)
		{
			DynamicArray[i] = Value;
		}
	}

	//------------------------------------------------------------------------------------------

	bool Swap(T& OtherArray)
	{
		int OtherSize = sizeof(OtherArray) / sizeof(OtherArray[0]);

		if (OtherSize == ArraySize)
		{
			T* AuxiliarArray = new T[ArraySize];
			memcpy(AuxiliarArray, DynamicArray, ArraySize);
			memcpy(DynamicArray, OtherArray, ArraySize);
			memcpy(OtherArray, AuxiliarArray, ArraySize);

			delete[] OtherArray;
			return true;
		}
		return false;
	}

	//------------------------------------------------------------------------------------------

	void Append(const T& OtherArray)
	{
		int OtherArraySize = sizeof(OtherArray) / sizeof(T);
		int NewSize = ArraySize + OtherArraySize
		Resize(NewSize);

		int OtherIndex = 0;

		for (int i = ArraySize; i < NewSize; i++)
		{
			DynamicArray[i] = OtherArray[OtherIndex];
			OtherIndex++;
		}

		CheckBounds();
	}

	//------------------------------------------------------------------------------------------
	 
	void Resize(int NewCapacity)
	{
		T* NewDynamicArray = new T[NewCapacity];

		for (int i = 0; i < ArraySize; i++)
		{
			NewDynamicArray[i] = DynamicArray[i];
		}

		delete[] DynamicArray;
		DynamicArray = NewDynamicArray;

		delegate[] NewDynamicArray;

	}

	void CheckBounds()
	{
		if (ArraySize >= ArrayCapacity)
		{
			Reserve();
		}
	}

};