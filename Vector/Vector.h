#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <fstream>
#include <cstring>

template <typename DataT>
class MyVector
{
	private:
		int 			size;
		DataT*			data;
		std::fstream 	file;

	public:
		MyVector		();
		MyVector		(int init_size);
		MyVector        (const MyVector& vector);
		MyVector		(MyVector && vector);
		~MyVector		();

		template <typename Data>
		friend std::istream& 	operator>>(std::istream& stream, MyVector<Data>& V);

		template <typename Data>
		friend std::ostream& 	operator<<(std::ostream& stream, MyVector<Data>& V);

		template <typename Data>
		friend MyVector<Data>	operator*(Data number, const MyVector<Data>& rhs);

		MyVector<DataT> &		operator=	(const MyVector<DataT> & rhs);
		MyVector<DataT> &		operator=	(MyVector && rhs);
		const DataT &			operator[]	(int index) const;
		DataT &					operator[]	(int index);
		MyVector<DataT>			operator+	(const MyVector & rhs);
		MyVector<DataT>			operator-	(const MyVector & rhs);
		MyVector<DataT>			operator*	(DataT number);
		MyVector<DataT>			operator/	(DataT number);
		
		void 					Show 		(const MyVector<DataT> & V);	
		void 					VSwap		(MyVector & V);
};

#include "Vector.hpp"
#endif
