//возможно не надо конвертировать char в double
#include "TArithm.h"
#include "TStack.h"
#include <iostream>
#include <string>
using namespace std;

TArithm::TArithm(string str) {
	expr = str;
	mist = 0;
}
TArithm::~TArithm() = default;
double TArithm::CharToDouble(char i) {
	double res = 0;
	if (IsNumber(i)) {
		switch (i) {
		case '1': res = 1;
			break;
		case '2': res = 2;
			break;
		case '3': res = 3;
			break;
		case '4': res = 4;
			break;
		case '5': res = 5;
			break;
		case '6': res = 6;
			break;
		case '7': res = 7;
			break;
		case '8': res = 8;
			break;
		case '9': res = 9;
			break;
		case '0': break;
		}
	}
	else cout << "Ошибка. Символ не является цифрой. Возвращён ноль." << endl;
	return res;
}
TStack TArithm::Postfix() {
	TStack Postfix;
	TStack op;
	for (char i : expr) {
		if (IsNumber(i)) {
			Postfix.Put(CharToDouble(i));
		}
		else if (i == ')') {
			char res = op.Get();
			while (res != '(') {
				Postfix.Put(i);
				res = op.Get();
			}
		}
		else {
			char res = op.Get();
			op.Put(res);
			if (i == '*' || i == '/') {
				while ((res == '*') || (res == '/')) {
					Postfix.Put(res);
					res = op.Get();
				}
			}
			if (i == '+' || i == '-') {
				while ((res == '*') || (res == '/') || (res == '+') || (res == '-')) {
				Postfix.Put(res);
				res = op.Get();
				}
			}
			op.Put(i);
		}
	}
	return Postfix;
}
bool TArithm::IsNumber(char i) {
	return ((i == '1') || (i == '2') || (i == '3') || (i == '4') || (i == '5') || (i == '6') || (i == '7') || (i == '8') || (i == '9') || (i == '0'));
}