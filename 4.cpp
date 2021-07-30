// Minimum Gifts
// Problem Description
// A Company has decided to give some gifts to all of its employees. For that, company has given some rank to each employee. Based on that rank, company has made certain rules to distribute the gifts.

// The rules for distributing the gifts are:

// Each employee must receive at least one gift.

// Employees having higher ranking get a greater number of gifts than their neighbours.

// What is the minimum number of gifts required by company?

// Constraints
// 1 < T < 10

// 1 < N < 100000

// 1 < Rank < 10^9

// Input
// First line contains integer T, denoting the number of testcases.

// For each testcases:

// First line contains integer N, denoting number of employees.

// Second line contains N space separated integers, denoting the rank of each employee.

// Output
// For each testcase print the number of minimum gifts required on new line.

// Time Limit
// 1

// Examples
// Example 1

// Input

// 2

// 5

// 1 2 1 5 2

// 2

// 1 2

// Output

// 7

// 3

// Explanation

// For testcase 1, adhering to rules mentioned above,

// Employee # 1 whose rank is 1 gets one gift

// Employee # 2 whose rank is 2 gets two gifts

// Employee # 3 whose rank is 1 gets one gift

// Employee # 4 whose rank is 5 gets two gifts

// Employee # 5 whose rank is 2 gets one gift

// Therefore, total gifts required is 1 + 2 + 1 + 2 + 1 = 7

// Similarly, for testcase 2, adhering to rules mentioned above,

// Employee # 1 whose rank is 1 gets one gift

// Employee # 2 whose rank is 2 gets two gifts

// Therefore, total gifts required is 1 + 2 = 3


#include<bits/stdc++.h>
using namespace std;
int mingifts (vector<int> &ratings) {
	int gifts = 0;
	int size = ratings.size();

	// if the vector is empty: return zero
	if (size == 0) return gifts;

	int giftState = 1;
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
		{
			gifts += giftState;
			continue;
		}

		if (ratings[i + 1] > ratings[i])
		{
			gifts += giftState;
			giftState++;
		}
		else if (ratings[i + 1] < ratings[i])
		{
			int startgiftState = giftState;
			int startIndex = i;

			while (i + 1 < size && ratings[i + 1] < ratings[i])
			{
				i++;
			}

			int startgiftStateFromRight = i - startIndex + 1;
			gifts += (startgiftStateFromRight + 1) * startgiftStateFromRight / 2;

			// Adjusting for the local maxima point.
			if (startgiftState > startgiftStateFromRight)
			{
				gifts += startgiftState - startgiftStateFromRight;
			}

			// Let's exclude this local minima point now as this will be accounted in the next iteration.
			gifts--;
			i--;
			giftState = 1;
		}
		else
		{
			gifts += giftState;
			giftState = 1;
		}
	}

	// return the miimum gifts required the the given ratings vector
	return gifts;
}

//driver code
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long n, l;
		cin >> n;
		vector<long > rating; // vector of ratings

		for (int i = 0; i < n; i++)
		{	cin >> l;
			rating.push_back(l);
		}

		//print the output, mingifts function return the minimum gifts required
		cout << mingifts(rating) << endl;
	}
	return 0;
}