#include <stdlib.h>
#include <stdio.h>

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void swapfl(float &a, float &b)
{
	float t = a;
	a = b;
	b = t;
}

void Bubblesort(int *&a, int n)
{
	for (int i = 0; i < n - 1; i++)
	for (int j = i + 1; j < n; j++)
	if (a[i] < a[j]) swap(a[i], a[j]);
}

void SortEven(int *&a, int n)
{
	for (int i = 0; i < n - 1; i++)
	if (a[i] % 2 == 0)
	for (int j = i + 1; j < n; j++)
	if (a[j] % 2 == 0)
	if (a[i] < a[j]) swap(a[i], a[j]);
}

void printList(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void printFlList(float *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%.2f ", a[i]);
	printf("\n");
}

void CopyArray(int *&b, int *a, int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

void SortMinus(float *&a, int n)
{
	for (int i = 0; i < n - 1; i++)
	if (a[i] >= 0)
	for (int j = i + 1; j < n; j++)
	if (a[j] >= 0)
	if (a[i] < a[j]) swapfl(a[i], a[j]);
	for (int i = 0; i < n - 1; i++)
	if (a[i] < 0)
	for (int j = i + 1; j < n; j++)
	if (a[j] < 0)
	if (a[i] > a[j]) swapfl(a[i], a[j]);
}

bool ktnt(int x)
{
	if ((x == 2) || (x == 3) || (x == 5)) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i < x / 2; i += 2)
	if (x%i == 0) return false;
	return true;
}

void SortPrime(int *&a, int n)
{
	for (int i = 0; i < n - 1; i++)
	if (ktnt(a[i]))
	for (int j = i + 1; j < n; j++)
	if (ktnt(a[j]))
	if (a[i] > a[j]) swap(a[i], a[j]);
}

int EvenFirst(int *&a, int n)
{
	int i = 0, j = n - 1;
	while (i <= j)
	{
		while ((a[i] % 2 == 0) && (i < n)) i++;
		while ((a[j] % 2 != 0) && (j >= 0)) j--;
		if (i <= j) swap(a[i], a[j]);
	}
	for (i = 0; i < n; i++)
	if (a[i] % 2 != 0) return i;
}

void SortOddEven(int *&a, int n)
{
	int m = EvenFirst(a, n);
	for (int i = 0; i < m - 1; i++)
	for (int j = i + 1; j < m; j++)
	if (a[i] > a[j]) swap(a[i], a[j]);
	for (int i = m; i < n - 1; i++)
	for (int j = i + 1; j < n; j++)
	if (a[i] < a[j]) swap(a[i], a[j]);
}

void CopyFlArray(float *&b, float *a, int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

void BigOnRight(float *&a, int n)
{
	for (int i = 0; i < n - 1; i++)
	for (int j = i + 1; j < n; j++)
	if (a[i]>a[j]) swapfl(a[i], a[j]);
}

void main()
{
	int *A = (int*)calloc(sizeof(int), 100);
	int *B = (int*)calloc(sizeof(int), 100);
	float *F = (float*)calloc(sizeof(float), 100);
	float *T = (float*)calloc(sizeof(float), 100);
	int n, m;
	
	printf("Nhap vao so phan tu mang so nguyen: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("A[%d]= ", i);
		scanf("%d", &A[i]);
	}
	
	printf("Mang ban dau:\n");
	printList(A, n);

	CopyArray(B, A, n);
	Bubblesort(B, n);
	printf("Mang giam dan:\n");
	printList(B, n);

	CopyArray(B, A, n);
	SortEven(B, n);
	printf("Mang so chan giam dan:\n");
	printList(B, n);

	CopyArray(B, A, n);
	SortPrime(B, n);
	printf("Mang so nguyen to tang dan:\n");
	printList(B, n);

	CopyArray(B, A, n);
	SortOddEven(B, n);
	printf("Mang so chan ben trai tang dan, so le ben phai giam dan:\n");
	printList(B, n);

	printf("Nhap vao so phan tu mang so thuc: ");
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		printf("F[%d]= ", i);
		scanf("%f", &F[i]);
	}
	
	printf("Mang ban dau:\n");
	printFlList(F, m);

	CopyFlArray(T, F, m);
	SortMinus(T, m);
	printf("Mang so am tang dan, so duong giam dan:\n");
	printFlList(T, m);

	CopyFlArray(T, F, n);
	BigOnRight(T, m);
	printf("Mang phan tu lon hon phan tu been trai:\n");
	printFlList(T, m);

	system("pause");
}