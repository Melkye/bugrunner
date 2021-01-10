#include "Pop.h"

int main()
{
	cout << "Enter the number of strings you'd like to write: ";
	int n_strings;
	cin >> n_strings; cin.ignore(1, '\n');
	
	string* a_Binaries = new string[n_strings];
	Text(a_Binaries, n_strings);
	cout << "Your string array is: \n";
	StringArrayPrinter(a_Binaries, n_strings);
	cout << "\n";

	int** a_Numbers = new int* [n_strings];
	BinToDec(a_Numbers, a_Binaries, n_strings);
	cout << "Decimal matrix: \n";
	MatrixPrinter(a_Numbers, n_strings, n_strings);
	cout << "\n";

	MatrixSort(a_Numbers, n_strings, n_strings);
	cout << "Decimal matrix: sorted my min abs in row: \n";
	MatrixPrinter(a_Numbers, n_strings, n_strings);
	cout << "\n";
	system("pause");
}