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

void insert_sort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int x = a[i];
		int pos = i - 1;
		while ((pos >= 0) && (a[pos] > x))
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}



void Quick_Sort(int a[], int l, int r)
{
	int x = a[(l + r) / 2];
	int i = l, j = r;
	do {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			Swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j)
		Quick_Sort(a, l, j);
	if (i < r)
		Quick_Sort(a, i, r);
}














int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	Nhap(a, n);
	insert_sort(a, n);
	Xuat(a, n);
	return 0;
}