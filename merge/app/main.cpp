#include <iostream>

int merge(int arr[], int temp[], int begin, int end, int mid);

int mergeSort(int arr[], int temp[], int begin, int end)
{
	int mid = 0; 
	int count = 0;
	
	if(end > begin)
	{
		mid = (end+begin)/2;
		
		count += mergeSort(arr, temp, begin, mid);
		count += mergeSort(arr, temp, mid+1, end);
		
		count += merge(arr, temp, begin, end, mid+1);
	}
	return count;

}
int merge(int arr[], int temp[], int begin, int end, int mid)
{
	int i = begin;
	int j = mid;
	int k = begin;
	int count = 0;
	while(i <= mid-1 && j <= end)
	{
		if(arr[i] <= 2*arr[j])
		{
			temp[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
			k++;
			count += (mid-i);
		}
	}

	i = begin;
	j = mid;
	k = begin;
	while(i <= mid-1 && j <= end)
	{
		if(arr[i] <= arr[j])
		{
			temp[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
			k++;
		}
	}
	while(i <= mid-1)
	{
		temp[k] = arr[i];
		i++;
	}

	while(j <= end)
	{
		temp[k] = arr[j];
		j++;
	}

	for(int i= begin; i < end+1; i++)
	{
		arr[i] = temp[i];
	}
	
	return count;
}

int main()
{ 	
	 int a[] = {8,3,5,2}; 
	 int temp[4];
	 
	std::cout << mergeSort(a, temp, 0, 3) << std::endl; 
	for(int i = 0; i < 4; ++i)
	{
		std::cout << a[i] << std::endl;
	}	
     return 0;
}
