#include<bits/stdc++.h>
using namespace std;

/* 
Author :- Rahul_Nautiyal
Digital Sign:- RAH_25-0612
*/

using ll = long long;

ll binExp(ll a, ll b)
{
	ll res = 1;
	while(b > 0)
	{
		if(b & 1)
		{
			res *= a;
		}
		a *= a;
		b >>= 1;
	}
	return res;
}

ll binExpMod(ll a, ll b, ll mod)
{
	ll res = 1;
	a %= mod;
	while(b > 0)
	{
		if(b & 1)
		{
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}

int main()
{
	ll a, b, mod;
	cin >> a >> b >> mod;
	cout << binExpMod(a, b, mod);
	return 0;
}
