#include <iostream>
using namespace std;

void dynamicArray(int ** arr, int data);
void change(int *t);
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int *pnt = arr;
	int **pkt = &pnt;
	//dynamicArray(pkt, 6);
	cout << "pnt" << pnt << endl;
	cout << "&pnt" << &pnt << endl;
	cout << "pkt" << pkt << endl;
	cout << "*pnt" << *pkt << endl;
	cout << "**pkt" << **pkt << endl;
	dynamicArray(pkt, 6);
	cout << "**pkt" << **pkt << endl;

}

void dynamicArray(int ** arr, int data)
{
	int b[4] = { 2, 4, 6, 8 };

	cout << "b" << b << endl;
	cout << "*arr" << *arr << endl;
	*arr = b;

	cout << "*arr" << *arr << endl;
}

void change(int *t)
{
	cout << *t << endl;
	*t = 20;
}