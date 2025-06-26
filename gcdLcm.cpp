#include<bits/stdc++.h>
using namespace std;

/* 
Author :- Rahul_Nautiyal
Digital Sign:- RAH_25-0612
*/

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << "GCD: " << gcd(a, b) << "\n";
	cout << "LCM: " << lcm(a, b) << "\n";
	return 0;
}
