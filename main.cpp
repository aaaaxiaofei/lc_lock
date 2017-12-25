#include "CashRegister.cpp"
// #include "Money.cpp"
#include <iostream>
using namespace std;

int main () {

	CashRegister cr;
	cr.initialize();
	
	cr.MakeChange(1, 10);
	return 0;
}