#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#define MAX 20

void quickSort(int arr[MAX], int low, int high);
int partition(int arr[MAX], int low, int high);

void merge(int arr[MAX], int l, int m, int r);
void mergeSort(int arr[MAX], int l, int r);

void printArray(int arr[], int size);

int main()
{

	int size;

	printf("\nThis is the main process: ");
	printf("\nProcess ID: %d", getpid());
	printf("\nParent Process ID: %d", getppid());

	printf("\n\n\nEnter array size: ");
	scanf("%d", &size);

	int arr[size];

	int i = 0;

	while (i != size)
	{
		printf("Enter the %d no: ", i + 1);
		scanf("%d", &arr[i]);
		++i;
	}

	int option;
	printf("\n\nSelect One Process :");
	printf("\n1. Zombie Process");
	printf("\n2. Orphan Process");
	printf("\n3. Exit");
	printf("\n\nEnter your choice: ");
	scanf("%d", &option);

	pid_t pid;
	pid = fork();

	switch (option)
	{
	case 1:
		if (pid == -1)
			printf("\nChild Process was not created");

		else if (pid == 0)
		{
			printf("\n Child process : ID : %d", getpid());
			printf("\n Parent process : ID : %d", getppid());

			printf("\n Array : ");
			printArray(arr, size);

			quickSort(arr, 0, size - 1);

			printf("\nSorted Array: ");
			printArray(arr, size);
			printf("\n\nChild Process enter into Zombie State\n\n");
		}
		else
		{
			sleep(5);
			printf("\nParent process : Process ID : %d", getpid());

			printf("\nArray : ");
			printArray(arr, size);

			mergeSort(arr, 0, size - 1);

			printf("\nSorted Array : ");
			printArray(arr, size);
			system("ps -l");
			exit(0);
		}
		break;

	case 2:
		if (pid == -1)
			printf("\nThe Child Process is not created");

		else if (pid == 0)
		{
			printf("\nChild process : ID : %d", getpid());
			printf("\nParent is : ID : %d", getppid());

			printf("\nArray : ");
			printArray(arr, size);

			quickSort(arr, 0, size - 1);

			printf("\nSorted Array : ");
			printArray(arr, size);

			printf("\n\nParent Process ID BEFORE sleep() : %d", getppid());

			sleep(10);

			printf("\nParent Process is terminated, the Child Process is in ORPHAN state\n\n");
			printf("\nParent Process ID AFTER sleep() : %d", getppid());
			system("ps -l");
			printf("\nThe Child Process is executed successfully\n\n");
		}
		else
		{
			printf("\nI'm in parent process : ID : %d", getpid());

			printf("\nOriginal Array : ");
			printArray(arr, size);

			mergeSort(arr, 0, size - 1);

			printf("\nSorted Array : ");
			printArray(arr, size);

			printf("\nThe Parent Process executed successfully.\n\n");

			system("ps -l");
			exit(0);
		}
		break;
	case 3:
		return 0;
	default:
		printf("\nInvalid choice, please try again\n");
	}

	system("ps -l");

	return 0;
}

int partition(int arr[MAX], int low, int high)
{
	int pivot = arr[high];

	int i = low - 1;

	int j;
	for (j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	int temp = arr[high];
	arr[high] = arr[i + 1];
	arr[i + 1] = temp;

	return (i + 1);
}

void quickSort(int arr[MAX], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
    are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
    are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void printArray(int arr[], int size)
{
	printf("\n");
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}
