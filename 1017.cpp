#include<iostream>
using namespace std;


int merge(int array[], int const left, int const mid, int const right)
{
	int s1 = mid - left + 1;
	int s2 = right - mid;

	int *leftArray = new int[s1],
		*rightArray = new int[s2];

	for (int i = 0; i < s1; i++)
		leftArray[i] = array[left + i];
	for (int j = 0; j < s2; j++)
		rightArray[j] = array[mid + 1 + j];

	int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0; 
	int indexOfMergedArray = left; 
    int sum=0;
	while (indexOfSubArrayOne < s1 && indexOfSubArrayTwo < s2) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
            sum+=indexOfSubArrayTwo;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	while (indexOfSubArrayOne < s1) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
        sum+=indexOfSubArrayTwo;
	}
	while (indexOfSubArrayTwo < s2) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
    return sum;
}

int mergeSort(int array[], int begin, int end)
{
    if (begin >= end)
        return 0; 
    int sum=0;
    auto mid = (begin + end) / 2;
    sum+=mergeSort(array, begin, mid);
    sum+=mergeSort(array, mid + 1, end);
    sum+=merge(array, begin, mid, end);
    return sum;
}


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int size;
        cin>>size;
        int arr[size];
        for(int j=0;j<size;j++)
        {
            cin>>arr[j];
        }
        cout<<mergeSort(arr, 0, size-1)<<endl;
    }
    return 0;
}