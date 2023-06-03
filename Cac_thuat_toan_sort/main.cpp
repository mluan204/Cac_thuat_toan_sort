#include <iostream>
using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Nhap(int a[],int &n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

void Xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void selection_sort(int a[], int n)
{
	int min, i, j;
	for (int i = 0; i < n-1; i++)
	{
		min = i;
		for (int j = i+1 ; j < n; j++)
		{
			if (a[j] < a[min]) {
				min = j;
			}
			Swap(a[min], a[j]);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	Nhap(a, n);
	selection_sort(a, n);
	Xuat(a, n);
	return 0;
}