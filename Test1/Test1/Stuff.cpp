#include "Stuff.h"

int** MartixGenerator(int order)
{
	int** matrix = new int* [order];
	for (int i = 0; i < order; i++)
	{
		matrix[i] = new int[order];
		for (int j = 0; j < order; j++)
		{
			matrix[i][j] = rand() % 19 - 9;
		}
	}
	return matrix;
}
 
void MatrixPrinter(int** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << setw(3) << matrix[i][j];
		}
		cout << endl;
	}
}

void MatrixTransponer(int** matrix, int order)
{
	for (int i = 0; i < order; i++)
	{
		for (int j = i+1; j < order; j++)
		{
			matrix[i][j] += matrix[j][i];
			matrix[j][i] = matrix[i][j] - matrix[j][i];
			matrix[i][j] -= matrix[j][i];
		}
	}
}

void ColumnEraser(int** matrix, int *rows, int* columns, int column_number)
{
	for (int i = 0; i < *rows-1; i++)
	{
		for (int j = column_number-1; j < *columns-1; j++)
		{
			matrix[i][j] = matrix[i][j + 1];
		}
		//delete matrix[i][*columns-1];
	}
	*columns -= 1;
}

string* StringArray(int** matrix, int rows, int columns)
{
	string* Strings = new string[rows];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns-1; j++)
		{
			Strings[i] += to_string(matrix[i][j] - matrix[i][j + 1]) + ' ';
		}
	}
	return Strings;
}

void SArrayPrinter(string* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << endl;
	}
}

void StringManip(string* array, int length)
{
	string* this_number = new string;
	string* temp = new string;
	for (int i = 0; i < length; i++)
	{
		*this_number = "";
		*temp = "";
		for (int j = 0; j < array[i].size(); j++)
		{
			if (array[i][j] != ' ') (*this_number).push_back(array[i][j]); 
			else if (array[i][j] == ' ' || j == (*array).size() - 1)
			{
				if (stod(*this_number) < 0) *temp += *this_number + ' ';
				*this_number = "";
			}
		}

		*this_number = "";
		for (int j = 0; j < array[i].size(); j++)
		{
			if (array[i][j] != ' ') (*this_number).push_back(array[i][j]);
			else if (array[i][j] == ' ' || j == (*array).size() - 1)
			{
				if (stod(*this_number) >= 0) *temp += *this_number + ' ';
				*this_number = "";
			}
		}
		array[i] = *temp;
	}
	delete this_number;
	delete temp;
}

void StringSort(string* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (array[j + 1].size() > array[j].size())
			{
				string* temp = new string;
				*temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = *temp;
				delete temp;
			}
		}
	}
}