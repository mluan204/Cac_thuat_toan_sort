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

void Heapify(int a[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && a[left] < a[largest])
		largest = left;

	if (right<n && a[right] < a[largest]) {
		largest = right;
	}

	if (largest != i)
	{
		Swap(a[largest], a[i]);
		Heapify(a, n, largest);
	}
}

void HeapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		Heapify(a, n, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		Swap(a[0], a[i]);
		Heapify(a, i, 0);
	}
}







int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	Nhap(a, n);
	HeapSort(a, n);
	Xuat(a, n);
	return 0;
}