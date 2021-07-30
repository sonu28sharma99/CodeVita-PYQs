// Problem Description
// Given an array of integers, perform atmost K operations so that the sum of elements of final array is minimum. An operation is defined as follows -

// Consider any 1 element from the array, arr[i].

// Replace arr[i] by floor(arr[i]/2).

// Perform next operations on updated array.

// The task is to minimize the sum after atmost K operations.

// Constraints
// 1 <= N, K <= 10^5.

// Input
// First line contains two integers N and K representing size of array and maximum numbers of operations that can be performed on the array respectively.

// Second line contains N space separated integers denoting the elements of the array, arr.

// Output
// Print a single integer denoting the minimum sum of the final array.

// Time Limit
// 1

// Examples
// Example 1

// Input

// 4 3

// 20 7 5 4

// Output

// 17

// Explanation

// Operation 1 -> Select 20. Replace it by 10.

// New array = [10, 7, 5, 4]

// Operation 2 -> Select 10. Replace it by 5.

// New array = [5, 7, 5, 4].

// Operation 3 -> Select 7. Replace it by 3.

// New array = [5,3,5,4].

// Sum = 17.

#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ull unsigned long long
int main()
{
	FIO;
	ull n, k, x, y, s = 0; cin >> n >> k;
	priority_queue<int> p;
	for (ull i = 0; i < n; i++)
	{
		cin >> x;
		p.push(x);
	}
	while (k--)
	{
		x = p.top();
		p.pop();
		x = floor(x / 2);
		p.push(x);
	}
	while (!p.empty())
	{
		s += p.top();
		p.pop();
	}
	cout << s;
	return 0;
}