#include "CashRegister.cpp"
// #include "Money.cpp"
#include <iostream>
using namespace std;

int main () {

	cout << "Hello ansys" << endl;

	CashRegister cr;
	cr.initialize();
	
	cr.MakeChange(1,-3);
	return 0;
}