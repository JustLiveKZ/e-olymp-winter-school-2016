#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

int n, q, t, l, r, ans;

template<typename T>
class RMQ {
    vector<vector<T>> m;

public:
    void build(vector<T> &v) {
        m.resize(v.size());
        int j = (int) llround(log2(v.size())) + 1;
        for (int i = 0; i < m.size(); i++) {
            m[i].resize(j);
            m[i][0] = v[i];
        }
        for (j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                m[i][j] = max(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T get(int l, int r) {
        if (l > r) {
            swap(l, r);
        }
        int j = (int) log2(r - l + 1);
        return max(m[l][j], m[r - (1 << j) + 1][j]);
    }
};

int main() {
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cin >> q;
        vector<int> a(n);
        vector<int> v;
        vector<int> nxt(n, -1);
        int p, cnt = 1, s = 0;
        for (int i = 0; i < n; i++) {
            cin >> t;
            a[i] = t;
            if (i == 0) {
                p = t;
            } else {
                if (t == p) {
                    cnt++;
                } else {
                    p = t;
                    cnt = 1;
                    for (int j = s; j < i; j++) {
                        nxt[j] = i;
                    }
                    s = i;
                }
            }
            v.push_back(cnt);
        }
        RMQ<int> rmq;
        rmq.build(v);
        for (int i = 0; i < q; i++) {
            cin >> l >> r;
            l--;
            r--;
            if (a[l] == a[r]) {
                ans = r - l + 1;
            } else {
                ans = max(nxt[l] - l, rmq.get(nxt[l], r));
            }
            cout << ans << "\n";
        }
    }

    return 0;
}