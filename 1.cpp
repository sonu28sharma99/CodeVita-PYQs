// Problem Description
// Three characters { #, *, . } represents a constellation of stars and galaxies in space. Each galaxy is demarcated by # characters.
// There can be one or many stars in a given galaxy. Stars can only be in shape of vowels { A, E, I, O, U } . A collection of * in the shape of the vowels is a star.
// A star is contained in a 3x3 block. Stars cannot be overlapping. The dot(.) character denotes empty space.

// Given 3xN matrix comprising of { #, *, . } character, find the galaxy and stars within them.

// Note: Please pay attention to how vowel A is denoted in a 3x3 block in the examples section below.

// Constraints
// 3 <= N <= 10^5

// Input
// Input consists of single integer N denoting number of columns.

// Output
// Output contains vowels (stars) in order of their occurrence within the given galaxy. Galaxy itself is represented by # character.

// Time Limit
// 1

// Examples
// Example 1

// Input

// 18

// * . * # * * * # * * * # * * * . * .

// * . * # * . * # . * . # * * * * * *

// * * * # * * * # * * * # * * * * . *

// Output

// U#O#I#EA

// Explanation

// As it can be seen that the stars make the image of the alphabets U, O, I, E and A respectively.

// Example 2

// Input

// 12

// * . * # . * * * # . * .

// * . * # . . * . # * * *

// * * * # . * * * # * . *

// Output

// U#I#A

// Explanation

// As it can be seen that the stars make the image of the alphabet U, I and A.


// SOLUTION:-

#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main()
{
	FIO;
	int n, i = 0; cin >> n;
	char a[3][n];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	while (i < n)
	{
		if (a[0][i] == '#' && a[1][i] == '#' && a[2][i] == '#')
		{
			cout << "#", i++;
			continue;
		}
		else if (a[0][i] == '.' && a[1][i] == '.' && a[2][i] == '.')
		{
			i++;
			continue;
		}
		else if (a[0][i] == '.' && a[0][i + 1] == '*' && a[0][i + 2] == '.' && a[1][i] == '*' && a[1][i + 1] == '*' && a[1][i + 2] == '*' && a[2][i] == '*' && a[2][i + 1] == '.' && a[2][i + 2] == '*')
		{
			cout << "A", i += 3;
			continue;
		}
		else if (a[0][i] == '*' && a[0][i + 1] == '*' && a[0][i + 2] == '*' && a[1][i] == '*' && a[1][i + 1] == '*' && a[1][i + 2] == '*' && a[2][i] == '*' && a[2][i + 1] == '*' && a[2][i + 2] == '*')
		{
			cout << "E", i += 3;
			continue;
		}
		else if (a[0][i] == '*' && a[0][i + 1] == '*' && a[0][i + 2] == '*' && a[1][i] == '.' && a[1][i + 1] == '*' && a[1][i + 2] == '.' && a[2][i] == '*' && a[2][i + 1] == '*' && a[2][i + 2] == '*')
		{
			cout << "I", i += 3;
			continue;
		}
		else if (a[0][i] == '*' && a[0][i + 1] == '*' && a[0][i + 2] == '*' && a[1][i] == '*' && a[1][i + 1] == '.' && a[1][i + 2] == '*' && a[2][i] == '*' && a[2][i + 1] == '*' && a[2][i + 2] == '*')
		{
			cout << "O", i += 3;
			continue;
		}
		else if (a[0][i] == '*' && a[0][i + 1] == '.' && a[0][i + 2] == '*' && a[1][i] == '*' && a[1][i + 1] == '.' && a[1][i + 2] == '*' && a[2][i] == '*' && a[2][i + 1] == '*' && a[2][i + 2] == '*')
		{
			cout << "U", i += 3;
			continue;
		}
		else
			i++;
	}
	return 0;
}