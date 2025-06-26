#include<bits/stdc++.h>
using namespace std;

/* 
Author :- Rahul_Nautiyal
Digital Sign:- RAH_25-0612
*/

using v = vector<int>;

class FenwickTree
{
	private:
	v bit;
	int n;

	public:
	FenwickTree(int size)
	{
		n = size;
		bit.resize(n + 1, 0);
	}

	void update(int i, int delta)
	{
		i++;
		while(i <= n)
		{
			bit[i] += delta;
			i += i & -i;
		}
	}

	int query(int i)
	{
		i++;
		int sum = 0;
		while(i > 0)
		{
			sum += bit[i];
			i -= i & -i;
		}
		return sum;
	}

	int rangeQuery(int l, int r)
	{
		return query(r) - query(l - 1);
	}
};

int main()
{
	int n;
	cin >> n;
	v a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	FenwickTree ft(n);
	for(int i = 0; i < n; i++) ft.update(i, a[i]);

	int q;
	cin >> q;
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int l, r;
			cin >> l >> r;
			cout << ft.rangeQuery(l, r) << "\n";
		}
		else
		{
			int pos, val;
			cin >> pos >> val;
			ft.update(pos, val - a[pos]);
			a[pos] = val;
		}
	}
	return 0;
}
