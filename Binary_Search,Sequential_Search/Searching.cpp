//Iterative
#include<iostream>
using namespace std;

bool sequentialSearch(int arr[],int last, int target, int* locn)
{
	int looker=0;
	while(looker < last && target!=arr[looker])
		looker++;
	*locn = looker;
	return (target==arr[looker]);
}

bool binarySearch(int list[], int last, int target, int* locn)
{
	int begin;
	int mid;
	int end;

	begin=0;
	end = last;
	while(begin <=end)
	{
		mid = (begin+end)/2;
		cout << mid;
		if (target > list[mid])
			begin = mid+1;
		else if (target < list[mid])
			end = mid-1;
		else
			begin = end+1;
	}

	*locn = mid;
	return (target == list[mid]);

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
	if (sequentialSearch(a, n, targetValue,&loc))
		cout << "Target is found using sequentialSearch" << endl;
	else
		cout << "Target is NOT found using sequentialSearch" << endl;

	
	if (binarySearch(a,n, targetValue, &loc))
		cout << "Target found using binarySearch" << endl;
	else
		cout << "Target NOT found using binarySearch" << endl;
	return 0;
}
