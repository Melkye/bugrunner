#include "Pop.h"

void Text(string* a_Strings, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << "Enter the line number " << i + 1 << ":";
	//	cout << "Конченная ты Visual Studio! Исчадие ада, порождённое компанией Microsoft" << endl;
		//int h;
		//cin >> h;
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
		a_Decimals[i] = new int[number_of_rows];
		for (int j = 0; j < number_of_rows; j++)
		{
			numbers_in_row = 0;
			a_Decimals[i][j] = 0;
			// выделить слово(число) + перевести в 10-ное
			for (int k = 0; k < this_string.size(); k++)
			{
				if (this_string[k] != ' ')
				{
					this_word += this_string[k];
				}
				if ((this_string[k] == ' ' || k == this_string.size() - 1)
					&& !this_word.empty())
				{
					for (int p = this_word.size() -1; p > 0; p--) // переведення числа у 10-у систему та запис у масив
					{
						a_Decimals[i][j] = +pow(this_word[p], (this_word.size() - 1) - p);
					}
					numbers_in_row++;
					this_word = "";
				}
			}
			if (numbers_in_row < numbers_in_row)
			{
				for (int t = numbers_in_row - 1; t < number_of_rows - 1; t++)
				{
					a_Decimals[i][t] = random_l_limit + rand() % (random_r_limit + 1 - random_l_limit);
				}
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