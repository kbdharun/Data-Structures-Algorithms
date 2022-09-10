//Recursive
#include<iostream>
using namespace std;

bool sequentialSearch(int arr[], int target, int index, int last, int* locn)
{
	if (arr[index] == target)
		return true;
	else
		sequentialSearch(arr, target, index+1, last, locn);
}

bool binarySearch(int arr[], int begin, int end, int target, int *locn)
{
	if (begin > end)
	{
		*locn = -1;
		return false;
	}
	
	int mid = (begin + end)/2;
	if (target<arr[mid])
		return binarySearch(arr, begin, mid-1, target, locn);
	else if (target > arr[mid])
		return binarySearch(arr, mid+1, end, target, locn);
	else
	{
		*locn = mid;
		return true;
	}
}

int main()
{
	int n;
	cout << "Enter no of elements:";
	cin >> n;

	int a[n];
	cout << "Enter array elements:\n";
	for (int i=0; i<n; i++)
	{
		cin >> a[i];
	}

	int targetValue;
	cout << "Enter target value:";
	cin >> targetValue;
	int loc;
	if (sequentialSearch(a, targetValue, 0, n, &loc))
		cout << "FOUND" << endl;
	else
		cout << "NOT FOUND" << endl;

	if (binarySearch(a, 0, n-1, targetValue, &loc))
		cout << "FOUND" << endl;
	else
		cout << "NOT FOUND" << endl;
}
