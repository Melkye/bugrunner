#include "Pop.h"

int main()
{
	cout << "Enter the number of strings you'd like to write: ";
	int n_strings;
	cin >> n_strings;

	string* a_Binaries = new string[n_strings];
	Text(a_Binaries, n_strings);

	int** a_Numbers = new int* [n_strings];
	BinToDec(a_Numbers, a_Binaries, n_strings);
	MatrixPrinter(a_Numbers, n_strings, n_strings);
	system("pause");
}