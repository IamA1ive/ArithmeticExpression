#pragma once
const int MAX = 100;
class TStack {
	double* arr = new double[MAX];
	int top;
public:
	TStack();
	~TStack();
	void Put(double num);
	double Get();
	bool Empty();
	bool Full();
	double Top();
};

