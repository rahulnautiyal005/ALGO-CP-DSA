#include<bits/stdc++.h>
using namespace std;

/* 
Author :- Rahul_Nautiyal
Digital Sign:- RAH_25-0612
*/

using v = vector<bool>;

v sieve(int n)
{
	v isPrime(n+1, true);
	isPrime[0] = isPrime[1] = false;

	for(int i = 2; i*i <= n; i++)
	{
		if(isPrime[i])
		{
			for(int j = i*i; j <= n; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	return isPrime;
}

int main()
{
	int n;
	cin >> n;
	v primes = sieve(n);
	for(int i = 0; i <= n; i++)
	{
		if(primes[i]) cout << i << " ";
	}
	return 0;
}
