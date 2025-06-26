
#include<bits/stdc++.h>
using namespace std;

/* 
Author :- Rahul_Nautiyal
Digital Sign:- RAH_25-0612
*/

using v = vector<int>;

v computeLPS(string pattern)
{
	int m = pattern.size();
	v lps(m, 0);
	int len = 0;

	for(int i = 1; i < m; )
	{
		if(pattern[i] == pattern[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len != 0)
			{
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}

v KMPSearch(string text, string pattern)
{
	v positions;
	int n = text.size(), m = pattern.size();

	v lps = computeLPS(pattern);

	int i = 0, j = 0;

	while(i < n)
	{
		if(pattern[j] == text[i])
		{
			i++, j++;
		}

		if(j == m)
		{
			positions.push_back(i - j);  // match found at i - j
			j = lps[j - 1];
		}
		else if(i < n && pattern[j] != text[i])
		{
			if(j != 0)
				j = lps[j - 1];
			else
				i++;
		}
	}
	return positions;
}

int main()
{
	string text, pattern;
	cin >> text >> pattern;

	v match_positions = KMPSearch(text, pattern);

	for(int pos : match_positions)
		cout << "Pattern found at index: " << pos << "\n";

	return 0;
}
