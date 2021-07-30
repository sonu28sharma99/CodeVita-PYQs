// Count Pairs
// Problem Description
// Given an array of integers A, and an integer K find number of happy elements.

// Element X is happy if there exists at least 1 element whose difference is less than K i.e. an element X is happy,
//  if there is another element in the range [X-K, X+K] other than X itself.

// Constraints
// 1 <= N <= 10^5

// 0 <= K <= 10^5

// 0 <= A[i] <= 10^9

// Input
// First line contains two integers N and K where N is size of the array and K is a number as described above

// Second line contains N integers separated by space.

// Output
// Print a single integer denoting the total number of happy elements.

// Time Limit
// 1

// Examples
// Example 1

// Input

// 6 3

// 5 5 7 9 15 2

// Output

// 5

// Explanation

// Other than number 15, everyone has at least 1 element in the range [X-3, X+3].
//  Hence they are all happy elements. Since these five are in number, the output is 5.

// Example 2

// Input

// 3 2

// 1 3 5

// Output

// 3

// Explanation

// All numbers have at least 1 element in the range [X-2, X+2]. Hence they are all happy elements.
// Since these three are in number, the output is 3.

// SOLUTION:-

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void test()
{
    ll n, k, l;
    scanf("%lld", &n);

    set<ll> s; // to remove duplicate elements from array (we distinct elements only)
    map<ll, int> m; // to keep track of frequency of each element in given array

    for (int i = 0; i < n; i++)
    {   scanf("%lld", &l);
        s.insert(l); //insertion in to set
        m[l]++;      // counting frequency for element l
    }

    //copying the set to array a(to acess previous, current and next element at a time)
    // set by default sort the input , we dont need to sort the array
    n = s.size();
    ll a[n], i = 0, count = 0;

    for (ll x : s) {
        a[i] = x;
        i++;
    }


    // loop to check  (adjacent diff <=k )
    //since we dont have previous element for a[0] , we keep a separatle check for this (jst to avoid runtime error)
    if (a[1] - a[0] <= k) count += m[a[0]];
    for (int i = 1; i < n - 1; i++)
    {
        // when this condition satisfies we increment the count by that element frequency.
        if ( a[i + 1] - a[i] <= k || abs(a[i] - a[i - 1]) <= k) count += m[a[i]];
    }
    //since we dont have next element for a[n-1] , we keep a separatle check for this (jst to avoid runtime error)
    if (a[n - 1] - a[n - 2] <= k) count += m[a[n - 1]];

    // printing output
    cout << count;

}

//driver code
int main()
{   test();
}