#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
bool SearchMinEven(int** a, const int n, int& minEven);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	Print(a, n);
	int minEven;
	if (SearchMinEven(a, n, minEven))
		cout << "min even = " << minEven << endl;
	else
		cout << "there are no even elements" << endl;
		for (int i = 0; i < n; i++)
			delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
bool SearchMinEven(int** a, const int n, int& minEven)
{
	int j, k = -1;
	for (int i = 0; i < n; i++)
	{
		j = n - 1 - i;
			k = i;
			minEven = a[i][j];
			break;
	}

	if (k == -1)
		return false;
	for (int i = k + 1; i < n; i++)
	{
		j = n - 1 - i;
		if (a[i][j] < minEven)
		{
			minEven = a[i][j];
		}
	}
	return true;
}