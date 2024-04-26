#pragma once
#ifndef VECTOR.h
#define VECTOR

template <typename T>
class Vector
{
public:
	Vector(T);
	Vector<T> push(T item);
	Vector<T> unshift(T item);
	T pop();
	T shift();
private:
	T array vector;
	int size;
};
#endif

