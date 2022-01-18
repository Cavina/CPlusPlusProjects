#include <iostream>

int inversionCount(int arr[], int begin, int size)
{
	int count = 0;
	for(int i = begin; i < size; ++i)
	{
		for(int j = i+1; j < size; ++j)
		{
			if(arr[i] > arr[j])
			{
				count++;
			}			
		}
	}
	return count;
}

int mergeCount(int arr[], int temp[], int begin, int end)
{
	int i = begin;
	int n = end-begin+1;
	int j = n/2+1;
	int k = 0;
	int count = 0;

	while(i <= n/2 && j <= n)
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
			count += (n/2 - i);
		}
	}

	while(i <= n/2)
	{	
		temp[k] = arr[i];
		i++;
		k++;
	}
	while(j <= n)
	{
		temp[k] = arr[j];
		j++;
		k++;
	}
	
	return count;

}

int countInversions(int arr[], int temp[], int begin, int end)
{
	int CL = 0, CM = 0, CR = 0;
	int count = 0;
	int size = (end-begin)+1;
	if(size <= 2)
	{
		count += inversionCount(arr, begin, end+1);
		std::sort(arr, arr+end+1);
		return count;
	}
	else
	{
		 CL = countInversions(arr, temp, begin, begin+(end-begin)/2);
		 CR = countInversions(arr, temp, begin+2+(end-begin)/2, end);
		 CM = mergeCount(arr, temp, begin, end);
	}
	return CL+CR+CM;
}

int main(){

/*
	int a[] = {5,3,6,2,1};
	std::cout << inversionCount(a, 5) << std::endl;

	int b[] = {4,7,6,3,5,9};
	int temp[5];
	std::cout << mergeCount(b, temp, 0, 4) << std::endl;

	for(int i = 0; i < 5; i++)
	{
		std::cout << temp[i] << std::endl;
	}
	int c[] = {6,3};
	std::cout << "Count Inversion" << countInversions(c, 0, 2) << std::endl;

	for(int i = 0; i < 2; i++)
	{
		std::cout << c[i] << std::endl;
	}
*/

	int temp[6];

	int a[] = {5,3,6,2,0,4};
	std::cout << countInversions(a, temp, 0, 5) << std::endl;
/*
	int b[] = {4,5,2,1,3};
	std::cout << countInversions(b, temp, 0, 4) << std::endl;
*/
	int c[] = {32,1,3,2,0,4};
	std::cout << countInversions(c, temp, 0, 5) << std::endl;

	return 0;
}
