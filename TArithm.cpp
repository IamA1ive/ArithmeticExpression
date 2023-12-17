#include "TArithm.h"
#include "TStack.h"
#include <iostream>
#include <string>
using namespace std;

TArithm::TArithm(string str) {
	mist_imbalance = 0;
	mist_braces = 0;
	mist_null = 0;
	infix = str;
	postfix = Postfix();
	res = Calc();
}
TArithm::~TArithm() = default;
string TArithm::Postfix() {
	string Postfix;
	TStack op;
	int right_brace = 0, left_brace = 0;
	int num_counter = 0, op_counter = 0;
	for (char i : infix) {
		if (IsNumber(i)) {
			Postfix += i;
			num_counter++;
		}
		else if (i == ')') {
			right_brace++;
			while (!op.Empty() && op.Top() != '(') {
				Postfix += op.Get();
			}
			op.Get();
		}
		else if (i == '(') {
			left_brace++;
			op.Put(i);
		}
		else {
			op_counter++;
			while (!op.Empty() && GetPriority(op.Top()) >= GetPriority(i)) {
				Postfix += op.Get();
			}
			op.Put(i);
		}
	}
	while (!op.Empty()) {
		Postfix += op.Get();
	}
	if (!(num_counter == op_counter + 1)) {
		mist_imbalance++;
	}
	if (left_brace != right_brace) {
		mist_braces++;
	}
	return Postfix;
}
bool TArithm::IsNumber(char i) {
	return ((i == '1') || (i == '2') || (i == '3') || (i == '4') || (i == '5') || (i == '6') || (i == '7') || (i == '8') || (i == '9') || (i == '0'));
}
int TArithm::GetPriority(double i) {
	if (i == '+' || i == '-')
		return 1;
	else if (i == '*' || i == '/')
		return 2;
	return 0;
}
double TArithm::Calc() {
	TStack Stack;
	for (char i : postfix) {
		if (IsNumber(i)) Stack.Put(i - '0');
		else {
			double second = Stack.Get();
			double first = Stack.Get();
			double res = 0;
			switch (i) {
			case '+':
				res = first + second;
				break;
			case '-':
				res = first - second;
				break;
			case '*':
				res = first * second;
				break;
			case '/':
				if (second == 0) {
					mist_null++;
					res = 0;
					break;
				}
				res = first / second;
				break;
			}
			Stack.Put(res);
		}
	}
	return (Stack.Get());
}
void TArithm::Input() {
	mist_null = 0;
	mist_imbalance = 0;
	mist_braces = 0;
	cin >> infix;
	postfix = Postfix();
	res = Calc();
}
void TArithm::Output() {
	if ((mist_braces + mist_imbalance + mist_null) == 0) {
		cout << "Выражение: " << infix << endl;
		cout << "Постфиксная форма: " << postfix << endl;
		cout << "Результат: " << res << endl;
	}
	else {
		if (mist_null > 0) {
			cout << "Ошибка: деление на ноль" << endl;
		}
		if (mist_imbalance > 0) {
			cout << "Ошибка: количество операций не соответствует количеству операндов" << endl;
		}
		if (mist_braces > 0) {
			cout << "Ошибка: количество левых скобок не соответствует количеству правых скобок" << endl;
		}
	}
}