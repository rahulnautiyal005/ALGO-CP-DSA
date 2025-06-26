#include<bits/stdc++.h>
using namespace std;

/* 
Author :- Rahul_Nautiyal
Digital Sign:- RAH_25-0612
*/

using v = vector<int>;

class DSU
{
	private :
	v parent;
	v rank;

	public :

	DSU(int n)
	{
		rank.resize(n ,0);
		parent.resize(n);
		for(int i=0;i<n;i++)
		{
			parent[i] = i;
		}
	}

	int findUlParent(int a)
	{
		if(parent[a] == a) return a;

		return a = findUlParent(parent[a]);

	}

	void dsuSet(int a , int b)
	{
		int ulp_a = findUlParent(a);
		int ulp_b = findUlParent(b);

		if(ulp_a == ulp_b) return ;

		if(rank[ulp_a] > rank[ulp_b])
		{
			parent[ulp_b] = ulp_a;
		}
		else if(rank[ulp_a] < rank[ulp_b])
		{
			parent[ulp_a] = ulp_b;
		}
		else
		{
			parent[ulp_b] = ulp_a;
			rank[ulp_a] ++;
		}
	}

};



int main() {

	int n ; 
	cin>> n;
	DSU dt(n);
	return 0;
}
