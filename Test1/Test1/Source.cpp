#include "Stuff.h"

int main()
{
	int order;
	cout << "Enter the matrix order: ";
	cin >> order;
	int** M = MartixGenerator(order);
	MatrixPrinter(M, order, order);
	cout << endl;

	MatrixTransponer(M, order);
	MatrixPrinter(M, order, order);
	cout << endl;

	cout << "Enter the number of a column you want to delete (1 to " << order << "): ";
	int* rows = new int; *rows = order;
	int* columns = new int; *columns = order;
	int* column = new int; cin >> *column;
	ColumnEraser(M, rows, columns, *column);
	delete column;
	MatrixPrinter(M, *rows, *columns);
	cout << endl;

	string* S = StringArray(M, *rows, *columns);
	cout << "The string array is:" << endl;
	SArrayPrinter(S, order);
	cout << endl;

	StringManip(S, order);
	cout << "The array with negatives first is:" << endl;
	SArrayPrinter(S, order);
	cout << endl;

	StringSort(S, order);
	cout << "The sorted array is:" << endl;
	SArrayPrinter(S, order);
	cout << endl;
	system("pause");
}