#include<bits/stdc++.h>
using namespace std;

/* 
Author :- Rahul_Nautiyal
Digital Sign:- RAH_25-0612
*/

using v = vector<int>;

class SegmentTree
{
	private:
	v seg;
	int size;

	public:
	SegmentTree(int n)
	{
		size = n;
		seg.resize(4 * n, 0);
	}

	void build(v &a, int idx, int low, int high)
	{
		if(low == high)
		{
			seg[idx] = a[low];
			return;
		}
		int mid = (low + high) / 2;
		build(a, 2 * idx + 1, low, mid);
		build(a, 2 * idx + 2, mid + 1, high);
		seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
	}

	int query(int idx, int low, int high, int l, int r)
	{
		// no overlap
		if(high < l || r < low) return 0;

		// complete overlap
		if(low >= l && high <= r) return seg[idx];

		// partial overlap
		int mid = (low + high) / 2;
		int left = query(2 * idx + 1, low, mid, l, r);
		int right = query(2 * idx + 2, mid + 1, high, l, r);
		return left + right;
	}

	void update(int idx, int low, int high, int pos, int val)
	{
		if(low == high)
		{
			seg[idx] = val;
			return;
		}
		int mid = (low + high) / 2;
		if(pos <= mid) update(2 * idx + 1, low, mid, pos, val);
		else update(2 * idx + 2, mid + 1, high, pos, val);

		seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
	}
};


int main()
{
	int n;
	cin >> n;
	v a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	SegmentTree st(n);
	st.build(a, 0, 0, n - 1);

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
			cout << st.query(0, 0, n - 1, l, r) << "\n";
		}
		else
		{
			int pos, val;
			cin >> pos >> val;
			st.update(0, 0, n - 1, pos, val);
		}
	}
	return 0;
}
