#include "f.h"

void swap(double* a, double* b)
{
	double tmp = *a;
	*a = *b;
	*b = tmp;
}
double* arrayAllocat(int size)
{
	double* array = (double*)malloc(size * sizeof(double));
	if (array == NULL) exit(1);

	return array;
}
void arrayFillRand(double* array, int size)
{
	for (int i = 0; i < size; i++)
		array[i] = rand() % 100;
}
void arrayFillRandomInRange(double* array, int size)
{
	int l, h;
	printf("l = \n");
	scanf("%d", &l);
	printf("h = \n");
	scanf("%d", &h);
	for (int i = 0; i < size; i++)
		array[i] = rand() %(h - l + 1) + l;
}
void arrayFillUser(double* array, int size)
{
	for (int i = 0; i < size; i++)
		scanf("%lf", &array[i]);
}
void arrayPrint(double* array, int size)
{
	for (int i = 0; i < size; i++)
		printf("%0.0lf ", array[i]);
	printf("\n");
}
int linearSearch(double* arr, int n, int key) 
{
	for (int i = 0; i < n; i++) {
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}
int binarySearch(double* arr, int l, int r, int x)
{
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (arr[mid] == x)
			return mid;

		if (arr[mid] < x)
			l = mid + 1;

		else
			r = mid - 1;
	}
	return -1;
}
//sort
void bubbleSort(double* array, int size)
{
	bool sw = false;
	for (int j = 0; j < size-1; j++)
	{
		for (int i = 0; i < size - 1 - j; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				sw = true;
			}

		}
		if (sw == false) break;
	}
}

void modbubbleSort(double* array, int size)
{
	bool sw = true;
	int l = 0, r = size - 1;
	while (sw)
	{
		sw = false;
		for (int i = l; i < r; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
			}
			sw = true;
		}
		r--;
		for (int i = r; i > l; i--)
		{
			if (array[i] < array[i - 1])
			{
				swap(array + i, array + i - 1);
				sw = true;
			}
		}
		l++;
	}
}

void merge(double* array, int l, int mid, int r)
{
	int s1 = mid - l + 1;
	int s2 = r - mid;

	double* l_arr = (double*)malloc(s1 * sizeof(double));
	if (l_arr == NULL) exit(2);
	double* r_arr = (double*)malloc(s2 * sizeof(double));
	if (r_arr == NULL) exit(3);

	for (int i = 0; i < s1; i++)
	{
		l_arr[i] = array[l + i];
	}
	for (int i = 0; i < s2; i++)
	{
		r_arr[i] = array[mid + i + 1];
	}
	int i = 0, j = 0, k = l;
	while (i < s1 && j < s2)
	{
		if (l_arr[i] < r_arr[j])
		{
			array[k] = l_arr[i];
			i++;
		}
		else
		{
			array[k] = r_arr[j];
			j++;
		}
		k++;
	}
	while (i < s1)
	{
		array[k] = l_arr[i];
		i++;
		k++;
	}
	while (j < s2)
	{
		array[k] = r_arr[j];
		j++;
		k++;
	}

	free(l_arr);
	free(r_arr);

}
void mergeSort(double* array, int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;

		mergeSort(array, l, mid);
		mergeSort(array, mid + 1, r);

		merge(array, l, mid, r);
	}
}

//void countingSort(double* arr, int n, int k) {
//	int* c = (int*)malloc((k + 1) * sizeof(*array));
//	memset(c, 0, sizeof(*array) * (k + 1));
//
//	for (int i = 0; i < n; ++i) {
//		++c[array[i]];
//	}
//
//	int b = 0;
//	for (int i = 0; i < k + 1; ++i) {
//		for (int j = 0; j < c[i]; ++j) {
//			array[b++] = i;
//		}
//	}
//
//	free(c);
//}

void selectionSort(double* array, int size) {
	for (int step = 0; step < size - 1; step++) {
		int min_idx = step;
		for (int i = step + 1; i < size; i++) {
			if (array[i] < array[min_idx])
				min_idx = i;
		}
		swap(&array[min_idx], &array[step]);
	}
}

void insertSort(double* array, int size)
{
	double key;

	for (int i = 1; i < size; i++)
	{
		key = array[i];
		int k = i;
		while (k >= 0)
		{
			if (array[k] > key)
			{
				double tmp = key;
				key = array[k];
				array[k] = tmp;
				k--;
			}
		}
	}
}

void quickSort(double* array, int l, int r) 
{
	if (l >= r)
		return;
	int mid = (l + r) / 2;
	double based = array[mid];
	int i = l, j = r;
	while (i <= j)
	{
		while (array[i] < based)
			i++;
		while (array[j] > based)
			j--;
		if (i <= j)
		{
			swap(array + i, array + j);
			i++;
			j--;
		}
	}
	quickSort(array, l, j);
	quickSort(array, i, r);
}
