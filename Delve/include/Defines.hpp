#pragma once
template<typename T>
class array_return
{
public:
	~array_return() { delete[] ptr; }
	T*	   ptr;
	size_t size;
};

class ends
{
public:
	int low;
	int high;
};

template<typename T>
class sum_ends
{
public:
	int low;
	int high;
	T	sum;
};

template<typename T>
class sub_array_ret
{
public:
	~sub_array_ret() { delete[] ptr; }
	T*	   ptr;
	size_t size;
	T	   sum;
};
