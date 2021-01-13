// IT IS A DIVIDE & CONQUER SORTING ALGORITHM.

#include<bits/stdc++.h>
using namespace std;

void merge_procedure(int arr[], int start, int end, int n) {
	// temporary array to store the sorted result 
	int tmp [n];
	int mid = start + (end - start)/2;
	
	// i = iterator for the first half
	// j = iterator for the second half
	// k = iterator fot the tmp[] array
	int i = start, j = mid + 1, k = start;
	
	while(i <= mid && j <= end) {
		if(arr[i] < arr[j]) tmp[k++] = arr[i++];
		else tmp[k++] = arr[j++];
	}
	
	// fill the array if some of the elements are still left
	while(i <= mid) tmp[k++] = arr[i++];
	while(j <= end)	tmp[k++] = arr[j++];
	
	// copying back the sorted elements of the 2 parts
	// in the original array
	for(int x = start; x <= end; x++) arr[x] = tmp[x];
}

void merge_sort(int arr[], int start, int end, int n) {
	// Base case(s)
	if(start >= end) return;
	
	// Step 1: divide the array
	int mid = start + (end - start)/2;
	
	// Step 2: sort the array (recursively)
	merge_sort(arr, start, mid, n);
	merge_sort(arr, mid + 1, end, n);
	
	// Step 3: merge the sorted array back
	merge_procedure(arr, start, end, n);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	
	int arr[] = {-5, 7, 0, 6, -8, 1, 12, 20, 5, 5, -5, 100};
	int n = sizeof(arr)/sizeof(int);
	
	merge_sort(arr, 0, n - 1, n);
	cout << "Sorted array: \n";
	for(auto x: arr) cout << x << " ";    

    return 0;
}