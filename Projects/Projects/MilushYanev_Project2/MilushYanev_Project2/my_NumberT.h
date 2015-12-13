#ifndef my_NumberT_H
#define my_NumberT_H

//template
template<class T>

//class name
//declate functions using template
class my_NumberT
{
private:

	T value;

public:
	my_NumberT();
	my_NumberT(T);
	T getValue();
	void setValue(T);
};

#include<iostream>

using namespace std;

//declate template's variables
template <class T>
void my_NumberT<T>::setValue(T _value) {
	value = _value;
}
template <class T>
T my_NumberT<T>::getValue() {
	return value;
}
template <class T>
my_NumberT<T>::my_NumberT(T _value){
	value = _value;
}
template <class T>
my_NumberT<T>::my_NumberT(){
	value = 0;
}

#endif