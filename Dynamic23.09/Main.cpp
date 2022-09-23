#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Заполняем массив случайными числами из диапазона от Begin до End
template <typename T>
void fill_arr(T arr[], int lenght, int begin, int end) {
	srand(time(0));
	for (int i = 0; i < lenght; i++)
		arr[i] = rand() % (end - begin) + begin;
}

// Вывод массива на экран
template <typename T>
void show_arr(T arr, int lenght) {
	cout << "[";
	for (int i = 0; i < lenght; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

// Задача 1
template <typename T>
void arr_add(T *&arr, int lenght, int num) {
	if (num <= 0)
		return;
	// Создаем новый массив
	T* tmp = new T[lenght + num]{};
	// копируем элементы из arr в tmp
	for (int i = 0; i < lenght; i++)
		tmp[i] = arr[i];
	// очищаем изначальный массив
	delete[] arr;
	// Перенаправляем на массив новой длины
	arr = tmp;
}

// Задача 2
template <typename T>
void arr_del(T*& arr, int lenght, int num) {
	if (num <= 0)
		return;
	if (num >= lenght) {
		delete[]arr;
		arr = new T[0];
		return;
	}
	// Создаем новый массив
	T* tmp = new T[lenght - num];
	// копируем элементы из arr в tmp
	for (int i = 0; i < lenght - num; i++)
		tmp[i] = arr[i];
	// очищаем изначальный массив
	delete[] arr;
	// Перенаправляем на массив новой длины
	arr = tmp;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	// Выделение участка динамической памяти для хранения значения типа int
	/*int* p1 = new int;
	cout << "p1 = " << p1 << endl;
	*p1 = 15;
	cout << "Разыменование p1 = " << *p1 << endl; // 15

	// Очищаем область памяти, на которую направлен указатель. Необходимо во избежание утечки данных
	 delete p1;

	// Перенаправление указателя на новый участок динамической памяти
	p1 = new int;
	cout << "p1 = " << p1 << endl;
	cout << "Разыменование p1 = " << *p1 << endl; // мусор
	*p1 = 20;
	cout << "Разыменование p1 = " << *p1 << endl; // 20
	delete p1;
	p1 = nullptr;
	
	if (p1 == nullptr)
		cout << "Указатель не направлен\n";
	else
		cout << "*p1 = " << *p1 << endl;*/

	// Выделение участка динамической памяти под динамический массив
	/*cout << "Введите длину массива: ";
	cin >> n;	
	int* dArr = new int[n];
	
	for (int i = 0; i < n; i++) {
		dArr[i] = (i + 1) * 10;
		cout << dArr[i] << ' ';
	}
	cout << endl;

	// Очистка памяти, выделенной под динамический массив
	delete[] dArr;
	dArr = nullptr;*/

	// Задача 1. Увеличение длины массива
	/*cout << "Задача 1\nВведите длину массива: ";
	int size1;
	cin >> size1;
	int* arr1 = new int [size1];	
	fill_arr(arr1, size1, 1, 100);
	cout << "Изначальный массив:\n";
	show_arr(arr1, size1);
	cout << "Введите количество новых элементов: ";
	cin >> n;
	arr_add(arr1, size1, n);
	if (n > 0)
		size1 += n;
	cout << "Итоговый массив:\n";
	show_arr(arr1, size1);

	delete[] arr1;
	arr1 = nullptr;*/
		
	// Задача 2. Уменьшение длины массива
	/*cout << "Задача 2\nВведите длину массива: ";
	int size2;
	cin >> size2;
	int* arr2 = new int[size2];
	fill_arr(arr2, size2, 1, 100);
	cout << "Изначальный массив:\n";
	show_arr(arr2, size2);
	cout << "Сколько элементов удалить? -> ";
	cin >> n;
	arr_del(arr2, size2, n);
	if (n >= size2)
		size2 = 0;
	else
		if (n > 0)
			size2 -= n;
	cout << "Итоговый массив:\n";
	show_arr(arr2, size2);

	delete[] arr2;
	arr2 = nullptr;*/

	// Двумерный динамический массив
	//int* mx = new int[5][4]; // НЕПРАВИЛЬНО
	int rows = 5, cols = 3;
	int** mx = new int* [rows];
	for (int i = 0; i < rows; i++)
		mx[i] = new int[cols];
	// Очистка двумерного массива
	//delete[][]mx; // НЕПРАВИЛЬНО
	for (int i = 0; i < rows; i++)
		delete[] mx[i];
	delete []mx;

	return 0;
}