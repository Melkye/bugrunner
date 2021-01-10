#pragma once

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int** MartixGenerator(int order);
void MatrixPrinter(int** matrix, int rows, int columns);
void MatrixTransponer(int** matrix, int order);
void ColumnEraser(int** matrix, int* rows, int* columns, int column_number);
string* StringArray(int** matrix, int rows, int columns);
void SArrayPrinter(string* array, int length);
void StringManip(string* array, int length);
void StringSort(string* array, int length);