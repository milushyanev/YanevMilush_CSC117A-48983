#include<iostream>
#include "my_NumberT.h"

using namespace std;

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

int NN()
{
	
	my_NumberT<int> numm(10);
	numm.setValue(10);

	return numm.getValue();
}