#include <iostream>
#include <time.h>

using namespace std;

enum actions{MIN, MAX, AVG};//hello

//min
int min(int** arr, size_t rows, size_t cols) {
	int min = arr[0][0];
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (arr[i][j] < min)
				min = arr[i][j];
		}
	}
	return min;
}

//max
int max(int** arr, size_t rows, size_t cols) {
	int max = arr[0][0];
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (arr[i][j] > max)
				max = arr[i][j];
		}
	}
	return max;
}
//avg
int avg(int** arr, size_t rows, size_t cols) {
	int avg{};
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
				avg += arr[i][j];
		}
	}
	return avg/(rows*cols);
}

template <class T>
T** create_matr(size_t rows, size_t cols) {
	T** matr = new T * [rows];//создаём массив указателей на одномерные массивы
	for (size_t i = 0; i < rows; i++)
	{
		matr[i] = new T[cols];
	}
	return matr;
}

template <typename T>
void delete_matr(T** matr, size_t rows) {
	//сначала удаляем данные внутри строк
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matr[i];
	}
	delete[] matr;
}

template <typename T>
void init_matr(T** matr, size_t rows, size_t cols) {

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matr[i][j] = rand() % 50;
		}
	}
}

template <typename T>
void show_matr(T** matr, size_t rows, size_t cols) {

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << matr[i][j] << "\t";
		}
		cout << endl;
	}
}

int Action(int** matr, size_t rows, size_t cols, int (*act) (int**, size_t, size_t)) {
	return act(matr, rows, cols);//вызывыем одну из функций
}

int main() {
	size_t C, R;
	cout << "Enter rows , cols for new matrix:";
	cin >> R;
	cin >> C;
	int** mat;
	int choice{ 3 };

	int (*act[3]) (int**, size_t, size_t) = {min, max, avg}; //указатель на одну из функций (min, max или avg)

	srand(time(NULL));
	mat = create_matr<int>(R, C);
	init_matr(mat, R, C);
	show_matr(mat, R, C);

	do {
		cout << "Choose an action on matrix:\n "<<MIN<<" - min \n "<<MAX<<" - max\n "<<AVG<<" - avg\n";
		cin >> choice;
		if (choice>=0 && choice <3)
		//cout << endl<<Action(mat, R, C, act[choice]);
		switch (choice) {
		case MIN: cout << endl << Action(mat, R, C, min);
			break;
		case MAX: cout << endl << Action(mat, R, C, max);
			break;
		case AVG: cout << endl << Action(mat, R, C, avg);
			break;
		
		}
	} while (choice != 3);

	delete_matr(mat, R);


	return 0;
}