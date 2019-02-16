// find pair with given sum array

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void findPair(int arr[], int lengthofarray, int sum)
{
	sort(arr, arr + lengthofarray);

	int beg = 0, end = lengthofarray - 1;

	while(beg < end)
	{
		if(arr[beg] + arr[end] == sum)
		{
			printf("\npair found for %d[%d] and %d[%d]\n", arr[beg], beg, arr[end], end);
		}

		(arr[beg] + arr[end] < sum)? beg++:end--;
	}
}

int main()
{
	int arr[] = {8, 7, 2, 5, 3, 1};
	int sum = 10;

	int lengthofarray = sizeof(arr)/sizeof(arr[0]); // sizeof(int)

	findPair(arr, lengthofarray, sum);

	return 0;
}