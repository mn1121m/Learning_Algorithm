#include<iostream>
#include<string>
#include<vector>

using namespace std;

// String
string s1;
string s2;
string LCS[1001][1001];

// Main
int main()
{
	cin >> s1;
	cin >> s2;

	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{
			if (s1[i-1] == s2[j-1])
			{	
				LCS[i][j] = LCS[i-1][j-1] + s1[i-1];
			}
			else
			{	
				if(LCS[i-1][j].length() >= LCS[i][j-1].length())
					LCS[i][j] = LCS[i-1][j];
				else 
					LCS[i][j] = LCS[i][j-1];
			}
		}
	}
    // Outputs the length of the longest common subsequence on the first line.
    // The second line outputs the longest common sequence when applied according to the method used in the Python reference code above.
    // But, if there is no common subsequence, the second line will not be printed.
	cout << LCS[s1.length()][s2.length()].length() << '\n';
	cout << LCS[s1.length()][s2.length()] <<'\n';


}