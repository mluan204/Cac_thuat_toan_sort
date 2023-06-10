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

void counting_sort(int input[], int n)
	{
		int* output = new int[n]; // The output will have sorted input array
		int max = input[0];
		int min = input[0];

		int i;
		for (i = 1; i < n; i++)
		{
			if (input[i] > max)
				max = input[i]; // Maximum value in array
			else if (input[i] < min)
				min = input[i]; // Minimum value in array
		}

		int k = max - min + 1; // Size of count array

		int* count_array = new int[k]; // Create a count_array to store count of each individual input value
		for (i = 0; i < k; i++)
			count_array[i] = 0;

		for (i = 0; i < n; i++)
			count_array[input[i] - min]++; // Store count of each individual input value

		/* Change count_array so that count_array now contains actual
		 position of input values in output array */
		for (i = 1; i < k; i++)
			count_array[i] += count_array[i - 1];

		// Populate output array using count_array and input array
		for (i = 0; i < n; i++)
		{
			output[count_array[input[i] - min] - 1] = input[i];
			count_array[input[i] - min]--;
		}

		for (i = 0; i < n; i++)
			input[i] = output[i]; // Copy the output array to input, so that input now contains sorted values
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
	selection_sort(a, n);
	Xuat(a, n);
	return 0;
}