#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ��������� ������ ���������� ������� �� ��������� �� Begin �� End
template <typename T>
void fill_arr(T arr[], int lenght, int begin, int end) {
	srand(time(0));
	for (int i = 0; i < lenght; i++)
		arr[i] = rand() % (end - begin) + begin;
}

// ����� ������� �� �����
template <typename T>
void show_arr(T arr, int lenght) {
	cout << "[";
	for (int i = 0; i < lenght; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

// ������ 1
template <typename T>
void arr_add(T *&arr, int lenght, int num) {
	if (num <= 0)
		return;
	// ������� ����� ������
	T* tmp = new T[lenght + num]{};
	// �������� �������� �� arr � tmp
	for (int i = 0; i < lenght; i++)
		tmp[i] = arr[i];
	// ������� ����������� ������
	delete[] arr;
	// �������������� �� ������ ����� �����
	arr = tmp;
}

// ������ 2
template <typename T>
void arr_del(T*& arr, int lenght, int num) {
	if (num <= 0)
		return;
	if (num >= lenght) {
		delete[]arr;
		arr = new T[0];
		return;
	}
	// ������� ����� ������
	T* tmp = new T[lenght - num];
	// �������� �������� �� arr � tmp
	for (int i = 0; i < lenght - num; i++)
		tmp[i] = arr[i];
	// ������� ����������� ������
	delete[] arr;
	// �������������� �� ������ ����� �����
	arr = tmp;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	// ��������� ������� ������������ ������ ��� �������� �������� ���� int
	/*int* p1 = new int;
	cout << "p1 = " << p1 << endl;
	*p1 = 15;
	cout << "������������� p1 = " << *p1 << endl; // 15

	// ������� ������� ������, �� ������� ��������� ���������. ���������� �� ��������� ������ ������
	 delete p1;

	// ��������������� ��������� �� ����� ������� ������������ ������
	p1 = new int;
	cout << "p1 = " << p1 << endl;
	cout << "������������� p1 = " << *p1 << endl; // �����
	*p1 = 20;
	cout << "������������� p1 = " << *p1 << endl; // 20
	delete p1;
	p1 = nullptr;
	
	if (p1 == nullptr)
		cout << "��������� �� ���������\n";
	else
		cout << "*p1 = " << *p1 << endl;*/

	// ��������� ������� ������������ ������ ��� ������������ ������
	/*cout << "������� ����� �������: ";
	cin >> n;	
	int* dArr = new int[n];
	
	for (int i = 0; i < n; i++) {
		dArr[i] = (i + 1) * 10;
		cout << dArr[i] << ' ';
	}
	cout << endl;

	// ������� ������, ���������� ��� ������������ ������
	delete[] dArr;
	dArr = nullptr;*/

	// ������ 1. ���������� ����� �������
	/*cout << "������ 1\n������� ����� �������: ";
	int size1;
	cin >> size1;
	int* arr1 = new int [size1];	
	fill_arr(arr1, size1, 1, 100);
	cout << "����������� ������:\n";
	show_arr(arr1, size1);
	cout << "������� ���������� ����� ���������: ";
	cin >> n;
	arr_add(arr1, size1, n);
	if (n > 0)
		size1 += n;
	cout << "�������� ������:\n";
	show_arr(arr1, size1);

	delete[] arr1;
	arr1 = nullptr;*/
		
	// ������ 2. ���������� ����� �������
	/*cout << "������ 2\n������� ����� �������: ";
	int size2;
	cin >> size2;
	int* arr2 = new int[size2];
	fill_arr(arr2, size2, 1, 100);
	cout << "����������� ������:\n";
	show_arr(arr2, size2);
	cout << "������� ��������� �������? -> ";
	cin >> n;
	arr_del(arr2, size2, n);
	if (n >= size2)
		size2 = 0;
	else
		if (n > 0)
			size2 -= n;
	cout << "�������� ������:\n";
	show_arr(arr2, size2);

	delete[] arr2;
	arr2 = nullptr;*/

	// ��������� ������������ ������
	//int* mx = new int[5][4]; // �����������
	int rows = 5, cols = 3;
	int** mx = new int* [rows];
	for (int i = 0; i < rows; i++)
		mx[i] = new int[cols];
	// ������� ���������� �������
	//delete[][]mx; // �����������
	for (int i = 0; i < rows; i++)
		delete[] mx[i];
	delete []mx;

	return 0;
}