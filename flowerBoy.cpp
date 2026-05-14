#include <bits/stdc++.h>
using namespace std;

bool canCollect(vector<int> &a, vector<int> &b, int k) {
    int n = a.size(), m = b.size();
    for (int pos = 0; pos <= n; pos++) {
        vector<int> temp = a;
        temp.insert(temp.begin() + pos, k);  // Insert flower with beauty k at pos
        int i = 0, j = 0;
        while (i < temp.size() && j < m) {
            if (temp[i] >= b[j]) {
                j++;
            }
            i++;
        }
        if (j == m) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        int i = 0, j = 0;
        while (i < n && j < m) {
            if (a[i] >= b[j]) {
                j++;
            }
            i++;
        }
        if (j == m) {
            cout << 0 << endl;
            continue;
        }

        int low = 1, high = 1e9, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canCollect(a, b, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
