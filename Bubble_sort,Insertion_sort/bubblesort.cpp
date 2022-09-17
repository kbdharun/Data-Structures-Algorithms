#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
	int ct, walker;
	for (ct = 0; ct < n - 1; ct++)
		for (walker = 0; walker < n - ct - 1; walker++)
			if (arr[walker] > arr[walker + 1])
				swap(arr[walker], arr[walker + 1]);
}

void effBubbleSort(int arr[], int n)
{
	int ct, walker;
	bool sorted=false;
	for (ct = 0; ct < n - 1 ; ct++)
	{
		sorted = true;
		for (walker = 0; walker < n - ct - 1; walker++){
			
			if (arr[walker] > arr[walker + 1]){
				swap(arr[walker], arr[walker + 1]);
				sorted=false;
			}
		}
	}
}

void insertionSort(int arr[], int n)
{
	for (int ct=1; ct<n; ct++)
	{
		int hold=arr[ct];
		int walker = ct-1;
		while (walker>=0 && hold < arr[walker])
		{
			arr[walker+1] = arr[walker];
			walker--;
		}
		arr[walker+1] = hold;
	} 
}


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = {5, 1, 4, 2, 8};
	int N = sizeof(arr) / sizeof(arr[0]);
	
	bubbleSort(arr,N);
	cout << "\nSorted array using bubbleSort:\n";
	printArray(arr,N);

	effBubbleSort(arr,N);
	cout << "\nSorted array using efficient bubbleSort:\n";
	printArray(arr,N);
	
	insertionSort(arr,N);
	cout << "\nSorted array using insertion sort:\n";
	printArray(arr,N);
	return 0;
}

