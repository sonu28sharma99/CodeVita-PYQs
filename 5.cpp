// Problem Description
// Here on earth, our 24-hour day is composed of two parts, each of 12 hours. Each hour in each part has a corresponding hour in the other part separated by 12 hours: the hour essentially measures the duration since the start of the day part. For example, 1 hour in the first part of the day is equivalent to 13, which is 1 hour into the second part of the day.

// Now, consider the equivalent hours that are both prime numbers. We have 3 such instances for a 24-hour 2-part day:

// 5~17

// 7~19

// 11~23

// Accept two natural numbers D, P >1 corresponding respectively to number of hours per day and number of parts in a day separated by a space. D should be divisible by P, meaning that the number of hours per part (D/P) should be a natural number. Calculate the number of instances of equivalent prime hours. Output zero if there is no such instance. Note that we require each equivalent hour in each part in a day to be a prime number.

// Example:

// Input: 24 2

// Output: 3 (We have 3 instances of equivalent prime hours: 5~17, 7~19 and 11~23.)

// Constraints
// 10 <= D < 500

// 2 <= P < 50

// Input
// Single line consists of two space separated integers, D and P corresponding to number of hours per day and number of parts in a day respectively

// Output
// Output must be a single number, corresponding to the number of instances of equivalent prime number, as described above

// Time Limit
// 1

// Examples
// Example 1

// Input

// 36 3

// Output

// 2

// Explanation

// In the given test case D = 36 and P = 3

// Duration of each day part = 12

// 2~14~X

// 3~15~X

// 5~17~29 - instance of equivalent prime hours

// 7~19~31 - instance of equivalent prime hours

// 11~23~X

// Hence the answers is 2.

// Example 2

// Input

// 49 7

// Output

// 0

// Explanation

// Duration of each day part = 7

// 2~9~X~23~X~37~X

// 3~X~17~X~31~X~X

// 5~X~19~X~X~X~47

// 7~X~X~X~X~X~X

// Hence there are no equivalent prime hours.


// APPROACH-1

// #include<bits/stdc++.h>
// using namespace std;
// #define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define ull unsigned long long
// int isp(ull n)
// {
// 	int f = 1;
// 	for (ull i = 2; i <= n / 2; i++)
// 		if (n % i == 0)
// 		{
// 			f = 0;
// 			break;
// 		}
// 	return f;
// }
// int main()
// {
// 	FIO;
// 	ull h, s, p, f = 0, c = 0, d;	cin >> h >> p;
// 	d = h / p;
// 	for (ull i = 2; i <= d; i++)
// 	{
// 		f = 0;
// 		s = i;
// 		if (isp(i))
// 		{
// 			for (ull j = 0; j < p - 1; j++)
// 			{
// 				s = s + d;
// 				if (!isp(s))
// 					f = 1;
// 			}
// 			if (f == 0)
// 				c++;
// 		}
// 	}
// 	cout << c;
// 	return 0;
// }


// APPROACH-2

#include <bits/stdc++.h>
using namespace std;
int seive[600];
void SieveOfEratosthenes()
{
	int n = 600;
	memset(seive, -1, sizeof(seive));
	seive[1] = 0;

	for (int p = 2; p * p <= n; p++)
	{
		if (seive[p] == -1)
		{
			for (int i = p * p; i <= n; i += p)
				seive[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long int n, k;
	cin >> n >> k;
	SieveOfEratosthenes();
	long int i = 0, j, l, m, o, p = n / k;

	int a[100];
	long int n1 = n, k1 = k, ans = 0, flag = 0;
	n1 = 1;
	while (n1 < n)
	{
		a[i] = n1;
		n1 += (p);

		i++;
//cout<<a[i-1]<<n1<<"\n";
	}
	m = i;

	for (i = 0; i < p; i++)
	{
		flag = 0;
		for (j = 0; j < m; j++)
		{
			//cout<<a[j]<<" "<<seive[a[j]]<<"\n";
			if (seive[a[j]] != -1)
			{

				flag = 1;

			}
			a[j]++;

		}
		if (flag == 0)
			ans++;
	}
	cout << ans;
}