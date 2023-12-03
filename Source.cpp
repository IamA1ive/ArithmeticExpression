#include "TStack.h"
#include "TArithm.h"
#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	
	TArithm A1("(3+4*3)");
	cout << A1.Postfix().Get();
	cout << A1.Postfix().Get();
	cout << A1.Postfix().Get();
	cout << A1.Postfix().Get();
	cout << A1.Postfix().Get();



	return 0;
}