#include "TStack.h"
#include <iostream>
using namespace std;

TStack::TStack() {
	top = -1;
}
TStack::~TStack() {
	delete[] arr;
}
void TStack::Put(double num) {
	if (!Full()) {
		arr[++top] = num;
	}
	else cout << "Ошибка: стек заполнен!" << endl;
}
double TStack::Get() {
	double res = 0;
	if (!Empty()) {
		res = arr[top--];
	}
	//else cout << "Ошибка: стек пуст!" << endl;
	return res;
}
double TStack::Top() {
	double res = 0;
	if (!Empty()) {
		res = arr[top];
	}
	//else cout << "Ошибка: стек пуст!" << endl;
	return res;
}
bool TStack::Empty() {
	return (top == -1);
}
bool TStack::Full() {
	return (top == MAX - 1);
}
