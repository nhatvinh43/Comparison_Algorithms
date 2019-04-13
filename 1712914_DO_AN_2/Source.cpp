#include<iostream>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable:4996);
using namespace std;

typedef struct SortInfo
{
	unsigned long long SoPhepSoSanh;
	unsigned long long SoPhepGan;
	double ThoiGianSort;
};
void CreateData(int* &a, int n)
{
	a = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand();
	}
}
void PrintFile(SortInfo a[8], int n)
{
	FILE* fp1 = fopen("Insertion.txt", "at");
	fprintf(fp1, "Truong hop sap xep %d phan tu:\n", n);
	fprintf(fp1, "Thoi gian: %lf; So phep gan: %llu; So phep so sanh: %llu\n", a[0].ThoiGianSort, a[0].SoPhepGan, a[0].SoPhepSoSanh);
	fclose(fp1);
	FILE* fp2 = fopen("Bubble.txt", "at");
	fprintf(fp2, "Truong hop sap xep %d phan tu:\n", n);
	fprintf(fp2, "Thoi gian: %lf; So phep gan: %llu; So phep so sanh: %llu\n", a[1].ThoiGianSort, a[1].SoPhepGan, a[1].SoPhepSoSanh);
	fclose(fp2);
	FILE* fp3 = fopen("Shaker.txt", "at");
	fprintf(fp3, "Truong hop sap xep %d phan tu:\n", n);
	fprintf(fp3, "Thoi gian: %lf; So phep gan: %llu; So phep so sanh: %llu\n", a[2].ThoiGianSort, a[2].SoPhepGan, a[2].SoPhepSoSanh);
	fclose(fp3);
	FILE* fp4 = fopen("Shell.txt", "at");
	fprintf(fp4, "Truong hop sap xep %d phan tu:\n", n);
	fprintf(fp4, "Thoi gian: %lf; So phep gan: %llu; So phep so sanh: %llu\n", a[3].ThoiGianSort, a[3].SoPhepGan, a[3].SoPhepSoSanh);
	fclose(fp4);
	FILE* fp5 = fopen("Quick.txt", "at");
	fprintf(fp5, "Truong hop sap xep %d phan tu:\n", n);
	fprintf(fp5, "Thoi gian: %lf; So phep gan: %llu; So phep so sanh: %llu\n", a[4].ThoiGianSort, a[4].SoPhepGan, a[4].SoPhepSoSanh);
	fclose(fp5);
	FILE* fp6 = fopen("Merge.txt", "at");
	fprintf(fp6, "Truong hop sap xep %d phan tu:\n", n);
	fprintf(fp6, "Thoi gian: %lf; So phep gan: %llu; So phep so sanh: %llu\n", a[5].ThoiGianSort, a[5].SoPhepGan, a[5].SoPhepSoSanh);
	fclose(fp6);
	FILE* fp7 = fopen("Heap.txt", "at");
	fprintf(fp7, "Truong hop sap xep %d phan tu:\n", n);
	fprintf(fp7, "Thoi gian: %lf; So phep gan: %llu; So phep so sanh: %llu\n", a[6].ThoiGianSort, a[6].SoPhepGan, a[6].SoPhepSoSanh);
	fclose(fp7);
	FILE* fp8 = fopen("Radix.txt", "at");
	fprintf(fp8, "Truong hop sap xep %d phan tu:\n", n);
	fprintf(fp8, "Thoi gian: %lf; So phep gan: %llu; So phep so sanh: %llu\n", a[7].ThoiGianSort, a[7].SoPhepGan, a[7].SoPhepSoSanh);
	fclose(fp8);
}
void ArrToFile(int* a,int n, char* filename)
{
	FILE* fp = fopen(filename, "at");
	fprintf(fp, "\n");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%d ", a[i]);
	}
	fclose(fp);

}
void PrintScreen(SortInfo a)
{
	cout << "Thoi gian chay: " << a.ThoiGianSort << endl;
	cout << "So phep gan: " << a.SoPhepGan << endl;
	cout << "So phep so sanh: " << a.SoPhepSoSanh << endl;
}
void Output(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "		  ";
	}
	cout << endl;
}
int* Copy(int*a, int n)
{
	int* b = new int[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
	return b;
}
SortInfo Insertion(int *a,int n)
{
	SortInfo b;
	unsigned long long gan = 0;
	unsigned long long sosanh = 0;
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		sosanh++;
		while (j >= 0 && a[j] > key)
		{
			if (a[j] > key)
			{
				sosanh++;
			}
			a[j + 1] = a[j];
			j = j - 1;
			gan ++;
		}
		a[j + 1] = key;
	}
	b.SoPhepGan = gan;
	b.SoPhepSoSanh = sosanh;
	return b;
}
SortInfo Bubble(int *a, int n)
{
	SortInfo b;
	unsigned long long sosanh, gan;
	sosanh = gan = 0;
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			sosanh++;
			if (a[j] > a[j + 1])
			{
				gan++;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	b.SoPhepGan = gan;
	b.SoPhepSoSanh = sosanh;
	return b;
}
SortInfo Shaker(int *a, int n)
{
	SortInfo b;
	unsigned long long sosanh = 0;
	unsigned long long gan = 0;
	int Left = 0;
	int Right = n - 1;
	int temp;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			sosanh++;
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				k = i;
				gan++;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			sosanh++;
			if (a[i] < a[i - 1])
			{
				temp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = temp;
				k = i;
				gan++;
			}
		}
		Left = k;
	}
	b.SoPhepGan = gan;
	b.SoPhepSoSanh = sosanh;
	return b;
}
SortInfo Shell(int *a, int n)
{
	SortInfo b;
	unsigned long long sosanh = 0;
	unsigned long long gan = 0;
	int i, j, k, temp;
	for (i = n / 2; i > 0; i = i / 2)
	{
		for (j = i; j < n; j++)
		{
			for (k = j - i; k >= 0; k = k - i)
			{
				sosanh++;
				if (a[k + i] >= a[k])
				{
					break;
				}
				else
				{
					temp = a[k];
					a[k] = a[k + i];
					a[k + i] = temp;
					gan++;
				}
			}
		}
	}
	b.SoPhepGan = gan;
	b.SoPhepSoSanh = sosanh;
	return b;
}
int partition(int *a, int l, int u, SortInfo& b)
{
	unsigned long long sosanh = 0;
	unsigned long long gan = 0;
	int x = a[l];
	int temp;
	int j = l;
	for (int i = l + 1; i <= u; i++)
	{
		sosanh++;
		if (a[i] < x)
		{
			j++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			gan++;
		}
	}
	int p = j;
	temp = a[l];
	a[l] = a[p];
	a[p] = temp;
	gan++;
	b.SoPhepGan += gan;
	b.SoPhepSoSanh += sosanh;
	return p;
}
SortInfo Quick(int* a, int low, int hi, SortInfo& b)
{
	if (low < hi)
	{
		int p = partition(a, low, hi,b);
		Quick(a, low, p - 1,b);
		Quick(a, p + 1, hi,b);
	}
	return b;
}
void Merge(int *a, int left, int mid, int right, SortInfo& b)
{
	unsigned long long sosanh = 0;
	unsigned long long gan = 0;
	int* temp1=new int[mid-left+1];
	int* temp2=new int[right - mid];
	int index_a = left;
	for (int i = 0; i < mid - left + 1; i++)
	{
		temp1[i] = a[index_a++];
	}
	for (int i = 0; i < right - mid; i++)
	{
		temp2[i] = a[index_a++];
	}

	int index_temp1 = 0, index_temp2 = 0;
	index_a = left;

	while (index_temp1 <= mid - left && index_temp2 < right - mid)	
	{
		sosanh++;
		if (temp1[index_temp1] < temp2[index_temp2]) 	
		{
			a[index_a] = temp1[index_temp1];
			gan++;
			index_temp1++;
		}
		else	
		{
			a[index_a] = temp2[index_temp2];
			gan++;
			index_temp2++;
		}
		index_a++;
	}

	while (index_temp1 <= mid - left)	
	{

		a[index_a] = temp1[index_temp1];
		index_a++;
		index_temp1++;
		gan++;
	}

	while (index_temp2 < right - mid)	
	{

		a[index_a] = temp2[index_temp2];
		index_a++;
		index_temp2++;
		gan++;
	}
	b.SoPhepGan += gan;
	b.SoPhepSoSanh += sosanh;
}
SortInfo MergeSort(int *a, int left, int right, SortInfo& b)	
{

	int mid = (right + left) / 2;
	if (left < right) 	
	{

		MergeSort(a, left, mid,b);
		MergeSort(a, mid + 1, right,b);
		Merge(a, left, mid, right,b);
	}
	return b;
}
void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void Heapify(int *a, int n, int i, SortInfo& b) 
{
	unsigned long long sosanh=0;
	unsigned long long gan=0;
	int Left = 2 * (i + 1) - 1;
	int temp;
	int Right = 2 * (i + 1);
	int Largest;
	if (Left<n && a[Left]>a[i])
	{
		Largest = Left;
		sosanh++;
	}
	else
	{
		Largest = i;
	}
	if (Right<n && a[Right]>a[Largest])
	{
		sosanh++;
		Largest = Right;
	}
	if (i != Largest)
	{
		temp = a[i];
		a[i] = a[Largest];
		a[Largest] = temp;
		gan++;
		Heapify(a, n, Largest,b);
	}
	b.SoPhepGan += gan;
	b.SoPhepSoSanh += sosanh;
}
void BuildHeap(int *a, int n, SortInfo& b) 
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		Heapify(a, n, i, b);
	}
}
SortInfo Heap(int *a, int n, SortInfo& b)
{
	BuildHeap(a, n, b);
	int temp;
	for (int i = n - 1; i > 0; i--)
	{
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		b.SoPhepGan++;
		Heapify(a, i, 0, b);
	}
	return b;
}
SortInfo Radix(int *a, int n)
{
	SortInfo b;
	unsigned long long gan = 0;
	int i;
	long long maxExp = 1;
	for (i = 0; i != n; i++)
	{
		while (a[i] / maxExp != 0)
		{
			maxExp *= 10;
		}
	}
	long long exp = 1;
	int *tmpBuffer = new int[n];
	while (maxExp / exp != 0)
	{
		int decimalBucket[10] = { 0 };
		for (i = 0; i != n; i++)
		{
			decimalBucket[a[i] / exp % 10]++;
		}
		for (i = 1; i != 10; i++)
		{
			decimalBucket[i] += decimalBucket[i - 1];
		}
		for (i = n - 1; i != -1; i--)
		{
			tmpBuffer[--decimalBucket[a[i] / exp % 10]] = a[i];
		}
		for (i = 0; i != n; i++)
		{
			a[i] = tmpBuffer[i];
			gan++;
		}
		exp *= 10;
	}
	b.SoPhepSoSanh = 0;
	b.SoPhepGan = gan;
	return b;
}
void Sorting(int *a, int n, int i, SortInfo b[8])
{
	int** temp = NULL;
	temp = new int*[8];
	for (int i = 0; i < 8; i++)
	{
		temp[i] = new int[n];
	};
	for (int i = 0; i < 8; i++)
	{
		temp[i] = Copy(a, n);
	}
	double t1 = clock();
	b[0] = Insertion(temp[0], n);
	b[0].ThoiGianSort = (double)(clock() - t1) / (double)CLOCKS_PER_SEC;
	cout << "Insertion Sort: \n";
	PrintScreen(b[0]);
	FILE* fp = fopen("Insertion_Data.txt", "at");
	fprintf(fp, "\nMang %d phan tu sau khi sap xep bang Insertion Sort, lan chay thu %d \n\n", n, i);
	ArrToFile(temp[0],n, "Insertion_Data.txt");
	fclose(fp);
	t1 = clock();
	b[1] = Bubble(temp[1], n);
	b[1].ThoiGianSort = (double)(clock() - t1) / (double)CLOCKS_PER_SEC;
	cout << "Bubble Sort:\n";
	PrintScreen(b[1]);
	fp = fopen("Bubble_Data.txt", "at");
	fprintf(fp, "\nMang %d phan tu sau khi sap xep bang Bubble Sort, lan chay thu %d \n\n", n, i);
	ArrToFile(temp[1], n, "Bubble_Data.txt");
	fclose(fp);
	t1 = clock();
	b[2] = Shaker(temp[2], n);
	b[2].ThoiGianSort = (double)(clock() - t1) / (double)CLOCKS_PER_SEC;
	cout << "Shaker Sort:\n";
	PrintScreen(b[2]);
	fp = fopen("Shaker_Data.txt", "at");
	fprintf(fp, "\nMang %d phan tu sau khi sap xep bang Shaker Sort, lan chay thu %d \n\n", n, i);
	ArrToFile(temp[2], n, "Shaker_Data.txt");
	fclose(fp);
	t1 = clock();
	b[3] = Shell(temp[3], n);
	b[3].ThoiGianSort = (double)(clock() - t1) / (double)CLOCKS_PER_SEC;
	cout << "Shell Sort: \n";
	PrintScreen(b[3]);
	fp = fopen("Shell_Data.txt", "at");
	fprintf(fp, "\nMang %d phan tu sau khi sap xep bang Shell Sort, lan chay thu %d \n\n", n, i);
	ArrToFile(temp[3], n, "Shell_Data.txt");
	fclose(fp);
	b[4].SoPhepGan = b[4].SoPhepSoSanh = 0;
	t1 = clock();
	b[4] = Quick(temp[4], 0, n - 1, b[4]);
	b[4].ThoiGianSort = (double)((clock() - t1) / (double)CLOCKS_PER_SEC);
	cout << "Quick Sort: \n";
	PrintScreen(b[4]);
	fp = fopen("Quick_Data.txt", "at");
	fprintf(fp, "\nMang %d phan tu sau khi sap xep bang Quick Sort, lan chay thu %d \n\n", n, i);
	ArrToFile(temp[4], n, "Quick_Data.txt");
	fclose(fp);
	b[5].SoPhepGan = b[5].SoPhepSoSanh = 0;
	t1 = clock();
	b[5] = MergeSort(temp[5], 0, n - 1, b[5]);
	b[5].ThoiGianSort = (double)((clock() - t1) / (double)CLOCKS_PER_SEC);
	cout << "Merge Sort: \n";
	PrintScreen(b[5]);
	fp = fopen("Merge_Data.txt", "at");
	fprintf(fp, "\nMang %d phan tu sau khi sap xep bang Merge Sort, lan chay thu %d \n\n", n, i);
	ArrToFile(temp[5], n, "Merge_Data.txt");
	fclose(fp);
	b[6].SoPhepGan = b[6].SoPhepSoSanh = 0;
	t1 = clock();
	b[6] = Heap(temp[6], n, b[6]);
	b[6].ThoiGianSort = (double)((clock() - t1) / (double)CLOCKS_PER_SEC);
	cout << "Heap Sort: \n";
	PrintScreen(b[6]);
	fp = fopen("Heap_Data.txt", "at");
	fprintf(fp, "\nMang %d phan tu sau khi sap xep bang Heap Sort, lan chay thu %d \n\n", n, i);
	ArrToFile(temp[6], n, "Heap_Data.txt");
	fclose(fp);
	t1 = clock();
	b[7] = Radix(temp[7], n);
	b[7].ThoiGianSort = (double)(clock() - t1) / (double)CLOCKS_PER_SEC;
	cout << "Radix Sort: \n";
	PrintScreen(b[7]);
	fp = fopen("Radix_Data.txt", "at");
	fprintf(fp, "\nMang %d phan tu sau khi sap xep bang Radix Sort, lan chay thu %d \n\n", n, i);
	ArrToFile(temp[7], n, "Radix_Data.txt");
	fclose(fp);
	PrintFile(b,n);
}
int main()
{
	SortInfo info[8];
	int* a = NULL;
	int i;
	int n;
	cout << "Nhap so phan tu cua mang (100,1000,10000,100000,1000000) hoac so tuy y: ";
	cin >> n;
	cout << "Nhap so lan chay moi thuat toan: ";
	cin >> i;
	for (int k = 1; k<= i; k++)
	{
		CreateData(a, n);
		Sorting(a, n,k+1, info);
	}
	delete[]a;
	return 0;
}

