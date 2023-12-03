#pragma once
#include "TStack.h"
#include <string>
using namespace std;


class TArithm {
	string expr;
	int mist;
public:
	TArithm(string str);
	~TArithm();
	TStack Postfix();
	bool IsNumber(char i);
	double CharToDouble(char i);
};