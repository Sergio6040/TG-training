#pragma once

template<typename T>
class TDynamicArray
{
	T* DynamicArray;
	int Size;
	int Capacity;

public:

	TDynamicArray()
	{
		DynamicArray = new T[3];
		Size = 0;
		Capacity = 3;
	}

	TDynamicArray(int InCapacity)
	{
		DynamicArray = new T[InCapacity];
		Size = 0;
		Capacity = InCapacity;
	}

	TDynamicArray(const TDynamicArray& Object) : Size{Object.Size}, Capacity{Object.Capacity}
	{
		/*DynamicArray = new T[Object.Capacity];
		for (int i = 0; i < size; i++)
		{
			DynamicArray[i] = Object.DynamicArray[i];
		}*/

		Append(Object);
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

	T& operator= (const T& OtherArray)
	{
		Clear();
		Append(OtherArray);
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
		return DynamicArray[Size];
	}

	T& Back()
	{
		return DynamicArray[Size];
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
		return Size == 0;

	}

	//------------------------------------------------------------------------------------------

	int GetSize() const
	{
		return Size;
	}

	//------------------------------------------------------------------------------------------

	int GetCapacity() const
	{
		return Capacity;
	}

	//------------------------------------------------------------------------------------------

	void Reserve() const
	{
		Resize(Capacity * 2);
	}

	//------------------------------------------------------------------------------------------

	void ShrinkToFit()
	{
		Capacity = Size;
		Resize(Capacity);
	}

	//------------------------------------------------------------------------------------------

	void Clear()
	{
		for (int i = 0; i < Size; i++)
		{
			delete DynamicArray[i];
		}
		Size = 0;
	}

	//------------------------------------------------------------------------------------------

	void PushBack(const T& NewItem)
	{
		CheckBounds();

		Size++;
		DynamicArray[Size] = NewItem;
	}

	//------------------------------------------------------------------------------------------

	void PopBack()
	{
		delete DynamicArray[Size];
		Size--;
	}

	//------------------------------------------------------------------------------------------

	void Insert(const T& NewItem, int Position)
	{
		CheckBounds();

		Size++;

		//Auxiliar variables
		T AuxiliarA{ DynamicArray[Position] };
		T AuxiliarB{ DynamicArray[Position] };

		for (int i = Position; i < Size - 1; i++)
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

		for (int i = Position; i < Size - 1; i++)
		{
			DynamicArray[i] = DynamicArray[i + 1];
		}

		delete DynamicArray[Size];
		Size--;
	}

	//------------------------------------------------------------------------------------------

	void Fill(const T& Value)
	{
		for (int i = 0; i < Size; i++)
		{
			DynamicArray[i] = Value;
		}
	}

	//------------------------------------------------------------------------------------------

	bool Swap(T& OtherArray)
	{
		int OtherSize = sizeof(OtherArray) / sizeof(OtherArray[0]);

		if (OtherSize == Size)
		{
			T* AuxiliarArray = new T[Size];
			memcpy(AuxiliarArray, DynamicArray, Size);
			memcpy(DynamicArray, OtherArray, Size);
			memcpy(OtherArray, AuxiliarArray, Size);

			delete[] OtherArray;
			return true;
		}
		return false;
	}

	//------------------------------------------------------------------------------------------

	void Append(const T& OtherArray)
	{
		int OtherArraySize = sizeof(OtherArray) / sizeof(T);
		int NewSize = Size + OtherArraySize;
		Resize(NewSize);

		int OtherIndex = 0;

		for (int i = Size; i < NewSize; i++)
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

		for (int i = 0; i < Size; i++)
		{
			NewDynamicArray[i] = DynamicArray[i];
		}

		delete[] DynamicArray;
		DynamicArray = NewDynamicArray;

		delete[] NewDynamicArray;

	}

	void CheckBounds()
	{
		if (Size >= Capacity)
		{
			Reserve();
		}
	}

};