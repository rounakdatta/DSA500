// find the longest common subsequence using dynamic programming

#include <iostream>
#include <string.h>
#define MAX(a, b) ((a > b)? a : b)

using namespace std;

int lcs(string a, string b, int m, int n)
{
	if(m == 0 || n == 0)
	{
		return 0;
	}
	if(a[m - 1] == b[n - 1])
	{
		return 1 + lcs(a, b, m - 1, n - 1);
	}
	else
	{
		return (MAX(lcs(a, b, m - 1, n), lcs(a, b, m, n - 1)));
	}
}

int main()
{
	string word1, word2;
	word1 = "happybirthdaytoyou";
	word2 = "whatsyourbirthdate";
	cout << "LCS : " << lcs(word1, word2, word1.length(), word2.length());

	return 0;
}