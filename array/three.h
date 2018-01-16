// three elements in an array whose sum is equal to a given number

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findtriplet(int arr[], int n, int sum)
{
	sort(arr, arr + n);

	int j, k;

	bool atleastone = false;

	for(int i = 0; i < (n-2); i++)
	{
		j = i + 1;
		k = n - 1;

		while(j < k)
		{
			int currsum = arr[i] + arr[j] + arr[k];

			if(currsum == sum)
			{
				cout<<"triplets are "<<arr[i]<<", "<<arr[j]<<", "<<arr[k]<<endl;
				atleastone = true;
			}

			(currsum < sum) ? j++ : k--;
		}
	}

	if(!atleastone)
	{
		cout<<"no triplets found"<<endl;
	}
}

int three()
{
	int arr[] = {1, 4, 45, 6, 10, 8};
	int sum = 50;

	int n = sizeof(arr) / sizeof(arr[0]);

	findtriplet(arr, n, sum);

	return 0;
}