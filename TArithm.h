#pragma once
#include "TStack.h"
#include <string>
using namespace std;


class TArithm {
	string infix;
	string postfix;
	double res;
	int mist_null;
	int mist_imbalance;
	int mist_braces;
public:
	TArithm(string str);
	~TArithm();
	string Postfix();
	bool IsNumber(char i);
	int GetPriority(double i);
	double Calc();
	void Braces();
	void Input();
	void Output();
};
