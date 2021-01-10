#include "Pop.h"

void Text(string* a_Strings, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << "Enter the line number " << i + 1 << ": ";
		//int h;
		//cin >> h;
		//cin.get();
		getline(cin, a_Strings[i]);
	}
}

void BinToDec(int** a_Decimals, string* array_of_strings, int number_of_rows)
{
	string this_word = "", this_string;
	int numbers_in_row;
	srand(time(NULL));
	int random_r_limit, random_l_limit;
	cout << "Enter the limits of the range we'll use to fill in random numbers.\n"
		<< "Left limit: "; cin >> random_l_limit;
	cout << "Right limit: "; cin >> random_r_limit;
	for (int i = 0; i < number_of_rows; i++)
	{
		this_string = array_of_strings[i];
		numbers_in_row = 0;
		a_Decimals[i] = new int[number_of_rows];
		// выделить слово(число) + перевести в 10-ное
		for (int k = 0; k < this_string.size(); k++)
		{
			a_Decimals[i][numbers_in_row] = 0;
			if (this_string[k] != ' ')
			{
				this_word.push_back(this_string[k]);
			}
			if ((this_string[k] == ' ' || k == this_string.size() - 1) && !this_word.empty())
			{
				for (int p = this_word.size() - 1, st = 0; p + 1 > 0; p--, st++) // переведення числа у 10-у систему та запис у масив
				{
					a_Decimals[i][numbers_in_row] += this_word[p] == '1' ? pow(2, st) : 0;
				}
				numbers_in_row++;
				this_word = "";
			}
		}
		if (numbers_in_row < number_of_rows)
		{
			for (int t = numbers_in_row; t < number_of_rows; t++)
			{
				a_Decimals[i][t] = random_l_limit + rand() % (random_r_limit + 1 - random_l_limit);
			}
		}
	}
}

void MatrixPrinter(int** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << setw(4) << matrix[i][j];
		}
		cout << "\n";
	}
}

void StringArrayPrinter(string* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << endl;
	}
}

void MatrixSort(int** matrix, int rows, int columns)
{
	int* a_Mins = new int[rows];
	for (int i = 0; i < rows; i++)
	{
		a_Mins[i] = abs(matrix[i][0]);
		for (int j = 0; j < columns; j++)
		{
			if (abs(matrix[i][j]) < a_Mins[i]) a_Mins[i] = abs(matrix[i][j]);
		}
	}

	cout << "Additional array:\n";
	for (int i = 0; i < rows; i++)
	{
		cout << setw(4) << a_Mins[i];
	}
	cout << "\n";

	for (int k = 0; k < rows - 1; k++)
	{
		for (int i = 0; i < rows - 1; i++)
		{
			if (a_Mins[i] < a_Mins[i + 1])
			{
				a_Mins[i] += a_Mins[i + 1];
				a_Mins[i + 1] = a_Mins[i] - a_Mins[i + 1];
				a_Mins[i] -= a_Mins[i + 1];
				for (int j = 0; j < columns; j++)
				{
					matrix[i][j] += matrix[i + 1][j];
					matrix[i + 1][j] = matrix[i][j] - matrix[i + 1][j];
					matrix[i][j] -= matrix[i + 1][j];
				}
			}
		}
	}

	cout << "Additional array sorted:\n";
	for (int i = 0; i < rows; i++)
	{
		cout << setw(4) << a_Mins[i];
	}
	cout << "\n";
}