#include "TStack.h"
#include "TArithm.h"
#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");




	TArithm A6("1+2*(3+4-(5-2)*3+2)");
	A6.Output();




	return 0;
}