#pragma once
template<typename T>
class array_return
{
public:
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
	T*	   ptr;
	size_t size;
	T	   sum;
};
