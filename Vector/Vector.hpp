#ifndef VECTOR_HPP_
#define VECTOR_HPP_

template <typename DataT>
MyVector <DataT>::MyVector() :
	size 	(0),
	data	(nullptr)
{}

template <typename DataT>
MyVector <DataT>::~MyVector()
{
	if(data != nullptr)
		delete [] data;
}

template <typename DataT>
MyVector <DataT>::MyVector(int init_size) :
	size	(init_size),
	data	(new DataT[init_size])
{}

template <typename DataT>
MyVector <DataT>::MyVector(const MyVector<DataT>& vector) :
	size 	(vector.size),
	data	(new DataT[vector.size])
{
	for(int i = 0; i < vector.size; i++)
		data[i] = vector.data[i];
}

template <typename DataT>
MyVector <DataT>::MyVector(MyVector<DataT> && vector)
{
	VSwap(vector);
}

template <typename DataT>
void MyVector<DataT>::VSwap(MyVector<DataT> & V)
{
	std::swap(size, V.size);
	std::swap(data, V.data);
}

template <typename Class>
std::istream& operator>>(std::istream & stream, MyVector<Class> & V)
{
	for(int i = 0; i < V.size; i++)
		std::cin >> V.data[i];

	return stream;
}

template <typename DataT>
std::ostream& operator<<(std::ostream & stream, MyVector<DataT> & V)
{
	stream << "(";
	for(int i = 0; i < V.size - 1; i++)
		stream << V.data[i] << ", ";
	stream << V.data[V.size - 1] << ") ";

	return stream;
}

template <typename Data>
MyVector<Data>	operator*(Data number, const MyVector<Data>& rhs)
{
	MyVector<Data> v1(rhs.size);

	for(int i(0); i < v1.size; i++)
		v1.data[i] = rhs.data[i] * number;

	return v1;
}

template <typename DataT>
MyVector<DataT>& MyVector<DataT>::operator=(const MyVector<DataT> & V)
{
	MyVector<DataT> copy(V);
	VSwap(copy);

	return(*this);
}

template <typename DataT>
MyVector<DataT> & MyVector<DataT>::operator=(MyVector<DataT> && rhs)
{
	VSwap(rhs);
}

template <typename DataT>
const DataT & MyVector<DataT>::operator[](int index) const
{
	return data[index];
}

template <typename DataT>
DataT & MyVector<DataT>::operator[](int index)
{
	return data[index];
}

template <typename DataT>
MyVector<DataT> MyVector<DataT>::operator+(const MyVector<DataT> & rhs)
{
	assert(this->size == rhs.size);

	MyVector<DataT> v1(rhs);
	for(int i(0); i < rhs.size; i++)
		v1.data[i] += rhs.data[i];

	return v1;
}

template <typename DataT>
MyVector<DataT> MyVector<DataT>::operator-(const MyVector<DataT> & rhs)
{
	assert(this->size == rhs.size);

	MyVector<DataT> v1(rhs.size);
	for(int i(0); i < rhs.size; i++)
		v1.data[i] = this->data[i] - rhs.data[i];
	return v1;
}

template <typename DataT>
MyVector<DataT> MyVector<DataT>::operator*(DataT number)
{
	MyVector<DataT> v1(this->size);

	for(int i(0); i < v1.size; i++)
		v1.data[i] = this->data[i] * number;
	return v1;
}

template <typename DataT>
MyVector<DataT> MyVector<DataT>::operator/(DataT number)
{
	MyVector<DataT> v1(this->size);

	for(int i(0); i < v1.size; i++)
		v1.data[i] = this->data[i] / number;

	return v1;
}

template <typename DataT>
void MyVector<DataT>::Show(const MyVector<DataT> & V)
{
	if(size)
	{
		std::cout << "(";
		for(int i = 0; i < size - 1; i++)
			std::cout << data[i] << ", ";
		std::cout << data[size -1] << ") " << std::endl;
	}
}

#endif
