/* $Id$ */
# ifndef CPPAD_VECTOR_INCLUDED
# define CPPAD_VECTOR_INCLUDED

/* --------------------------------------------------------------------------
CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-12 Bradley M. Bell

CppAD is distributed under multiple licenses. This distribution is under
the terms of the 
                    Eclipse Public License Version 1.0.

A copy of this license is included in the COPYING file of this distribution.
Please visit http://www.coin-or.org/CppAD/ for information on other licenses.
-------------------------------------------------------------------------- */

/*
$begin CppAD_vector$$
$spell
	thread_alloc
	cppad.hpp
	Bool
	resize
	cout
	endl
	std
	Cpp
	const
	vec
	ostream
	elem
$$

$index vector, CppAD template class$$
$index class, template CppAD vector$$
$index template, CppAD vector class$$

$section The CppAD::vector Template Class$$

$head Syntax$$
$code # include <cppad/vector.hpp>$$

$head Description$$
The include file $code cppad/vector.hpp$$ defines the
vector template class $code CppAD::vector$$.
This is a $cref SimpleVector$$ template class and in addition
it has the features listed below:

$head Include$$
The file $code cppad/vector.hpp$$ is included by $code cppad/cppad.hpp$$
but it can also be included separately with out the rest of the 
CppAD include files.

$head capacity$$
If $icode x$$ is a $codei%CppAD::vector<%Scalar%>%$$,
and $icode cap$$ is a $code size_t$$ object,
$codei%
	%cap% = %x%.capacity()
%$$
set $icode cap$$ to the number of $icode Scalar$$ objects that
could fit in the memory currently allocated for $icode x$$.
Note that
$codei%
	%x%.size() <= %x%.capacity()
%$$

$head Assignment$$
$index assignment, CppAD vector$$
If $icode x$$ and $icode y$$ are 
$codei%CppAD::vector<%Scalar%>%$$ objects,
$codei%
	%y% = %x%
%$$
has all the properties listed for a
$cref/simple vector assignment/SimpleVector/Assignment/$$
plus the following:

$subhead Check Size$$
The $code CppAD::vector$$ template class will check that
the size of $icode x$$ is either zero or the size of $icode y$$
before doing the assignment.
If this is not the case, $code CppAD::vector$$ will use
$cref ErrorHandler$$
to generate an appropriate error report.
Allowing for assignment to a vector with size zero makes the following
code work:
$codei%
	CppAD::vector<%Scalar%> %y%;
	%y% = %x%;
%$$

$subhead Return Reference$$
A reference to the vector $icode y$$ is returned.
An example use of this reference is in multiple assignments of the form
$codei%
	%z% = %y% = %x%
%$$

$head Element Access$$
$index [], CppAD vector$$
$index vector, [] CppAD$$
If $icode x$$ is a $codei%CppAD::vector<%Scalar%>%$$ object
and $code i$$ has type $code size_t$$,
$codei%
	%x%[%i%]
%$$
has all the properties listed for a
$cref/simple vector element access/SimpleVector/Element Access/$$
plus the following:
$pre

$$
The object $icode%x%[%i%]%$$ has type $icode Scalar$$
(is not possibly a different type that can be converted to $icode Scalar$$).
$pre

$$
If $icode i$$ is not less than the size of the $icode x$$,
$code CppAD::vector$$ will use
$cref ErrorHandler$$
to generate an appropriate error report.

$head push_back$$
$index push_back, CppAD vector$$
$index vector, CppAD push_back$$
If $icode x$$ is a $codei%CppAD::vector<%Scalar%>%$$ object
with size equal to $icode n$$ and
$icode s$$ has type $icode Scalar$$,
$codei%
	%x%.push_back(%s%)
%$$
extends the vector $icode x$$ so that its new size is $icode n$$ plus one
and $icode%x%[%n%]%$$ is equal to $icode s$$
(equal in the sense of the $icode Scalar$$ assignment operator).


$head push_vector$$
$index push_vector, CppAD$$
$index vector, CppAD push$$
If $icode x$$ is a $codei%CppAD::vector<%Scalar%>%$$ object
with size equal to $icode n$$ and
$icode v$$ is a $cref/simple vector/SimpleVector/$$
with elements of type $icode Scalar$$ and size $icode m$$,
$codei%
	%x%.push_vector(%v%)
%$$
extends the vector $icode x$$ so that its new size is $icode%n%+%m%$$
and $icode%x%[%n% + %i%]%$$ is equal to $icode%v%[%i%]%$$
for $icode%i = 1 , ... , m-1%$$
(equal in the sense of the $icode Scalar$$ assignment operator).

$head Output$$
If $icode x$$ is a $codei%CppAD::vector<%Scalar%>%$$ object
and $icode os$$ is an $code std::ostream$$,
and the operation
$codei%
	%os% << %x%
%$$
will output the vector $icode x$$ to the standard
output stream $icode os$$.
The elements of $icode x$$ are enclosed at the beginning by a
$code {$$ character,
they are separated by $code ,$$ characters,
and they are enclosed at the end by $code }$$ character.
It is assumed by this operation that if $icode e$$
is an object with type $icode Scalar$$,
$codei%
	%os% << %e%
%$$
will output the value $icode e$$ to the standard
output stream $icode os$$.

$head resize$$
The call $icode%x%.resize(%n%)%$$ set the size of $icode x$$ equal to 
$icode n$$. 
If $icode%n% <= %x%.capacity()%$$, 
no memory is freed or allocated and the capacity of $icode x$$ does not change.

$head clear$$
All memory allocated for the vector is freed
and both its size and capacity are set to zero.
The can be useful when using very large vectors
and when checking for memory leaks (and there are global vectors)
see the $cref/memory/CppAD_vector/Memory and Parallel Mode/$$ discussion.

$head vectorBool$$
$index vectorBool$$
The file $code <cppad/vector.hpp>$$ also defines the class
$code CppAD::vectorBool$$.
This has the same specifications as $code CppAD::vector<bool>$$ 
with the following exceptions

$list number$$
The class $code vectorBool$$ conserves on memory
(on the other hand, $code CppAD::vector<bool>$$ is expected to be faster
than $code vectorBool$$).

$lnext
The $code CppAD::vectorBool$$ output operator
prints each boolean value as 
a $code 0$$ for false,
a $code 1$$ for true, 
and does not print any other output; i.e.,
the vector is written a long sequence of zeros and ones with no
surrounding $code {$$, $code }$$ and with no separating commas or spaces. 

$lnext
If $icode x$$ has type $code vectorBool$$
and $icode i$$ has type $code size_t$$,
the element access value $icode%x%[%i%]%$$ has an unspecified type
(referred to here as $icode elementType$$)
that can be implicitly converted to $code bool$$.
The return value of the assignment operator
$codei%
	%x%[%i%] = %y%
%$$
also has type $icode elementType$$. Thus, if $icode z$$
has type $code bool$$, the syntax
$codei%
	%z% = %x%[%i%] = %y%
%$$
is valid.
$lend

$head Memory and Parallel Mode$$
$index thread_alloc, vector$$
$index vector, thread_alloc$$
These vectors use the multi-threaded fast memory allocator 
$cref thread_alloc$$:

$list number$$
The routine $cref/parallel_setup/ta_parallel_setup/$$ must
be called before these vectors can be used 
$cref/in parallel/ta_in_parallel/$$.
$lnext
Using these vectors affects the amount of memory 
$cref/in_use/ta_inuse/$$ and $cref/available/ta_available/$$.
$lnext
Calling $cref/resize/CppAD_vector/resize/$$ with a zero argument,
makes the corresponding memory available (though $code thread_alloc$$)
to the current thread.
$lnext
Available memory
can then be completely freed using $cref/free_available/ta_free_available/$$.
$lend

$head Example$$
$children%
	example/cppad_vector.cpp%
	example/vector_bool.cpp
%$$
The files
$cref cppad_vector.cpp$$ and
$cref vector_bool.cpp$$ each
contain an example and test of this template class.
They return true if they succeed and false otherwise.

$head Exercise$$
$index exercise, CppAD::vector$$
Create and run a program that contains the following code:
$codep
	CppAD::vector<double> x(3);
	size_t i;
	for(i = 0; i < 3; i++)
		x[i] = 4. - i;
	std::cout << "x = " << x << std::endl;
$$

$end


$end

------------------------------------------------------------------------ 
*/

# include <cstddef>
# include <iostream>
# include <limits>
# include <cppad/local/cppad_assert.hpp>
# include <cppad/check_simple_vector.hpp>
# include <cppad/thread_alloc.hpp>

CPPAD_BEGIN_NAMESPACE
/*!
\defgroup vector_hpp vector.hpp
\{
\file vector.hpp
File used to define CppAD::vector and CppAD::vectorBool
*/

// ---------------------------------------------------------------------------
/*!
The CppAD Simple Vector template class.
*/
template <class Type>
class vector {
private:
	/// maximum number of Type elements current allocation can hold
	size_t capacity_;
	/// number of Type elements currently in this vector
	size_t length_;
	/// pointer to the first type elements 
	/// (not defined and should not be used when capacity_ = 0)
	Type   * data_;
public:
	/// type of the elements in the vector
	typedef Type value_type;

	/// default constructor sets capacity_ = length_ = data_ = 0
	inline vector(void) 
	: capacity_(0), length_(0), data_(0)
	{ }
	/// sizing constructor
	inline vector(
		/// number of elements in this vector
		size_t n
	) : capacity_(0), length_(n), data_(0)
	{	if( length_ > 0 )
		{	// set capacity and data
			data_ = thread_alloc::create_array<Type>(length_, capacity_); 
		}
	}
	/// copy constructor
	inline vector(
		/// the *this vector will be a copy of \c x
		const vector& x
	) : capacity_(0), length_(x.length_), data_(0)
	{	if( length_ > 0 )
		{	// set capacity and data	
			data_ = thread_alloc::create_array<Type>(length_, capacity_); 

			// copy values using assignment operator
			size_t i;
			for(i = 0; i < length_; i++)
				data_[i] = x.data_[i];
		}
	}
	/// destructor
	~vector(void)
	{	if( capacity_ > 0 )
			thread_alloc::delete_array(data_); 
	}

	/// maximum number of elements current allocation can store
	inline size_t capacity(void) const
	{	return capacity_; }

	/// number of elements currently in this vector.
	inline size_t size(void) const
	{	return length_; }

	/// change the number of elements in this vector.
	inline void resize(
		/// new number of elements for this vector
		size_t n
	)
	{	length_ = n;
		// check if we can use current memory
		if( capacity_ >= length_ )
			return;
		// check if there is old memory to be freed
		if( capacity_ > 0 )
			thread_alloc::delete_array(data_);
		// get new memory and set capacity
		data_ = thread_alloc::create_array<Type>(length_, capacity_);
	}

	/// free memory and set number of elements to zero 
	inline void clear(void)
	{	length_ = 0;
		// check if there is old memory to be freed
		if( capacity_ > 0 )
			thread_alloc::delete_array(data_);
		capacity_ = 0;
	}

	/// vector assignment operator
	inline vector& operator=(
		/// right hand size of the assingment operation
		const vector& x
	)
	{	size_t i;
		// If original lenght is zero, then resize
		// otherwise a length mismatch is an error.
		if( length_ == 0 )
			resize( x.length_ );
		CPPAD_ASSERT_KNOWN(
			length_ == x.length_ ,
			"vector: size miss match in assignment operation"
		);
		for(i = 0; i < length_; i++)
			data_[i] = x.data_[i];
		return *this;
	}
	/// non-constant element access; i.e., we can change this element value
	Type& operator[](
		/// element index, must be less than length
		size_t i
	)
	{	CPPAD_ASSERT_KNOWN(
			i < length_,
			"vector: index greater than or equal vector size"
		);
		return data_[i]; 
	}
	/// constant element access; i.e., we cannot change this element value
	const Type& operator[](
		/// element index, must be less than length
		size_t i
	) const
	{	CPPAD_ASSERT_KNOWN(
			i < length_,
			"vector: index greater than or equal vector size"
		);
		return data_[i]; 
	}
	/// add an element to the back of this vector
	void push_back(
		/// value of the element
		const Type& s
	)
	{	CPPAD_ASSERT_UNKNOWN( length_ <= capacity_ );
		if( length_ + 1 > capacity_ )
		{	// store old capacity and data values
			size_t old_capacity = capacity_;
			Type*  old_data     = data_;
			// set new capacity and data values
			data_ = thread_alloc::create_array<Type>(length_ + 1, capacity_);
			// copy old data values
			size_t i;
			for(i = 0; i < length_; i++)
				data_[i] = old_data[i];
			// free old data
			if( old_capacity > 0 )
				thread_alloc::delete_array(old_data);
		}
		data_[length_++] = s;
		CPPAD_ASSERT_UNKNOWN( length_ <= capacity_ );
	}

	/*! add vector to the back of this vector
	(we could not use push_back becasue MS V++ 7.1 did not resolve
	to non-template member function when scalar is used.)
	*/
	template <class Vector>
	void push_vector(
		/// value of the vector that we are adding
		const Vector& v
	)
	{	CheckSimpleVector<Type, Vector>();
		CPPAD_ASSERT_UNKNOWN( length_ <= capacity_ );
		size_t m = v.size();
		size_t i;
		if( length_ + m > capacity_ )
		{	// store old capacity and data values
			size_t old_capacity = capacity_;
			Type*  old_data     = data_;
			// set new capacity and data values
			data_ = thread_alloc::create_array<Type>(length_ + m, capacity_);
			// copy old data values
			for(i = 0; i < length_; i++)
				data_[i] = old_data[i];
			// free old data
			if( old_capacity > 0 )
				thread_alloc::delete_array(old_data);
		}
		for(i = 0; i < m; i++)
			data_[length_++] = v[i];
		CPPAD_ASSERT_UNKNOWN( length_ <= capacity_ );
	}
};

/// output a vector
template <class Type>
inline std::ostream& operator << (
	/// stream to write the vector to
	std::ostream&              os  , 
	/// vector that is output
	const CppAD::vector<Type>& vec )
{	size_t i = 0;
	size_t n = vec.size();

	os << "{ ";
	while(i < n)
	{	os << vec[i++]; 
		if( i < n )
			os << ", ";
	}
	os << " }";
	return os;
}

// ---------------------------------------------------------------------------
/*!
Class that is used to hold a non-constant element of a vector.
*/
class vectorBoolElement {
	/// the boolean data is packed with sizeof(UnitType) bits per value
	typedef size_t UnitType;
private:
	/// pointer to the UnitType value holding this eleemnt
	UnitType* unit_;
	/// mask for the bit corresponding to this element
	/// (all zero except for bit that corresponds to this element)
	UnitType mask_;
public:
	/// constructor from member values
	vectorBoolElement(
		/// unit for this element
		UnitType* unit , 
		/// mask for this element
		UnitType mask  )
	: unit_(unit) , mask_(mask)
	{ }
	/// constuctor from another element
	vectorBoolElement(
		/// other element
		const vectorBoolElement& e )
	: unit_(e.unit_) , mask_(e.mask_)
	{ }
	/// conversion to a boolean value
	operator bool() const
	{	return (*unit_ & mask_) != 0; }
	/// assignment of this element to a bool
	vectorBoolElement& operator=(
		/// right hand side for assignment
		bool bit
	)
	{	if(bit)
			*unit_ |= mask_;
		else	*unit_ &= ~mask_;
		return *this;
	} 
	/// assignment of this element to another element
	vectorBoolElement& operator=(const vectorBoolElement& e)
	{	if( *(e.unit_) & e.mask_ )
			*unit_ |= mask_;
		else	*unit_ &= ~mask_;
		return *this;
	} 
};

class vectorBool {
	/// the boolean data is packed with sizeof(UnitType) bits per value
	typedef size_t UnitType;
private:
	/// number of bits packed into each UnitType value in data_
	static const size_t bit_per_unit_ 
		= std::numeric_limits<UnitType>::digits;
	/// number of UnitType values in data_
	size_t    n_unit_;
	/// number of bits currently stored in this vector
	size_t    length_;
	/// pointer to where the bits are stored
	UnitType *data_;

	/// minimum number of UnitType values that can store length_ bits
	/// (note that this is really a function of length_)
	size_t unit_min(void)
	{	if( length_ == 0 )
			return 0;
		return (length_ - 1) / bit_per_unit_ + 1;
	}
public:
	/// type corresponding to the elements of this vector
	/// (note that non-const elements actually use vectorBoolElement)
	typedef bool value_type;

	/// default constructor (sets all member data to zero)
	inline vectorBool(void) : n_unit_(0), length_(0), data_(0)
	{ }
	/// sizing constructor
	inline vectorBool(
		/// number of bits in this vector
		size_t n
	) : n_unit_(0), length_(n), data_(0)
	{	if( length_ > 0 )
		{	// set n_unit and data
			size_t min_unit = unit_min();
			data_ = thread_alloc::create_array<UnitType>(min_unit, n_unit_);
		}
	}
	/// copy constructor
	inline vectorBool(
		/// the *this vector will be a copy of \c v
		const vectorBool& v
	) : n_unit_(0), length_(v.length_), data_(0)
	{	if( length_ > 0 )
		{	// set n_unit and data
			size_t min_unit = unit_min();
			data_ = thread_alloc::create_array<UnitType>(min_unit, n_unit_);

			// copy values using UnitType assignment operator
			CPPAD_ASSERT_UNKNOWN( min_unit <= v.n_unit_ ); 
			size_t i;
			for(i = 0; i < min_unit; i++)
				data_[i] = v.data_[i];
		}
	}
	/// destructor
	~vectorBool(void)
	{	if( n_unit_ > 0 )
			thread_alloc::delete_array(data_);
	}

	/// number of elements in this vector
	inline size_t size(void) const
	{	return length_; }

	/// maximum number of elements current allocation can store
	inline size_t capacity(void) const
	{	return n_unit_ * bit_per_unit_; }

	/// change number of elements in this vector
	inline void resize(
		/// new number of elements for this vector
		size_t n
	)
	{	length_ = n;
		// check if we can use the current memory
		size_t min_unit = unit_min();
		if( n_unit_ >= min_unit )
			return;
		// check if there is old memory to be freed
		if( n_unit_ > 0 )
			thread_alloc::delete_array(data_);
		// get new memory and set n_unit
		data_ = thread_alloc::create_array<UnitType>(min_unit, n_unit_);
	}

	/// free memory and set number of elements to zero
	inline void clear(void)
	{	length_ = 0;
		// check if there is old memory to be freed
		if( n_unit_ > 0 )
			thread_alloc::delete_array(data_);
		n_unit_ = 0;
	}

	/// vector assignment operator
	inline vectorBool& operator=(
		/// right hand size of the assingment operation
		const vectorBool& v
	)
	{	size_t i;
		CPPAD_ASSERT_KNOWN(
			length_ == v.length_ ,
			"vectorBool: size miss match in assignment operation"
		);
		size_t min_unit = unit_min();
		CPPAD_ASSERT_UNKNOWN( min_unit <= n_unit_ );
		CPPAD_ASSERT_UNKNOWN( min_unit <= v.n_unit_ );
		for(i = 0; i < min_unit; i++)
			data_[i] = v.data_[i];
		return *this;
	}
	/// non-constant element access; i.e., we can change this element value
	vectorBoolElement operator[](
		/// element index, must be less than length
		size_t k
	)
	{	size_t i, j;
		CPPAD_ASSERT_KNOWN(
			k < length_,
			"vectorBool: index greater than or equal vector size"
		);
		i    = k / bit_per_unit_;
		j    = k - i * bit_per_unit_;
		return vectorBoolElement(data_ + i , UnitType(1) << j );
	}
	/// constant element access; i.e., we cannot change this element value
	bool operator[](size_t k) const
	{	size_t i, j;
		UnitType unit, mask;
		CPPAD_ASSERT_KNOWN(
			k < length_,
			"vectorBool: index greater than or equal vector size"
		);
		i    = k / bit_per_unit_;
		j    = k - i * bit_per_unit_;
		unit = data_[i];
		mask = UnitType(1) << j;
		return (unit & mask) != 0;
	}
	/// add an element to the back of this vector
	void push_back(
		/// value of the element
		bool bit
	)
	{	CPPAD_ASSERT_UNKNOWN( unit_min() <= n_unit_ );
		size_t i, j;
		UnitType mask;
		if( length_ + 1 > n_unit_ * bit_per_unit_ )
		{	CPPAD_ASSERT_UNKNOWN( unit_min() == n_unit_ );
			// store old n_unit and data values
			size_t    old_n_unit = n_unit_;
			UnitType* old_data   = data_;
			// set new n_unit and data values
			data_ = thread_alloc::create_array<UnitType>(n_unit_+1, n_unit_);
			// copy old data values
			for(i = 0; i < old_n_unit; i++)
				data_[i] = old_data[i]; 
			// free old data
			if( old_n_unit > 0 )
				thread_alloc::delete_array(old_data);
		}
		i    = length_ / bit_per_unit_;
		j    = length_ - i * bit_per_unit_;
		mask = UnitType(1) << j;
		if( bit )
			data_[i] |= mask;
		else	data_[i] &= ~mask;
		length_++;
	}
	/// add vector to the back of this vector
	template <class Vector>
	void push_vector(
		/// value of the vector that we are adding
		const Vector& v
	)
	{	 CheckSimpleVector<bool, Vector>();
		size_t min_unit = unit_min();
		CPPAD_ASSERT_UNKNOWN( length_ <= n_unit_ * bit_per_unit_ );
		// some temporaries
		size_t i, j, k, ell;
		UnitType mask;
		bool bit;
		// store old length
		size_t old_length = length_;
		// new length and minium number of units;
		length_    = length_ + v.size();
		min_unit   = unit_min();
		if( length_ >= n_unit_ * bit_per_unit_ )
		{	// store old n_unit and data value
			size_t  old_n_unit = n_unit_;
			UnitType* old_data = data_;
			// set new n_unit and data values
			data_ = thread_alloc::create_array<UnitType>(min_unit, n_unit_);
			// copy old data values
			for(i = 0; i < old_n_unit; i++)
				data_[i] = old_data[i]; 
			// free old data
			if( old_n_unit > 0 )
				thread_alloc::delete_array(old_data);
		}
		ell = old_length;
		for(k = 0; k < v.size(); k++)
		{
			i    = ell / bit_per_unit_;
			j    = ell - i * bit_per_unit_;
			bit  = v[k];
			mask = UnitType(1) << j;
			if( bit )
				data_[i] |= mask;
			else	data_[i] &= ~mask;
			ell++;
		}
		CPPAD_ASSERT_UNKNOWN( length_ == ell );
		CPPAD_ASSERT_UNKNOWN( length_ <= n_unit_ * bit_per_unit_ );
	}
};

/// output a vector
inline std::ostream& operator << (
	/// steam to write the vector to
	std::ostream&      os  , 
	/// vector that is output
	const vectorBool&  v   )
{	size_t i = 0;
	size_t n = v.size();

	while(i < n)
		os << v[i++]; 
	return os;
}

/*! \} */
CPPAD_END_NAMESPACE
# endif
