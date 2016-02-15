#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

template<typename T>
class RMQ {
    vector<vector<T>> m;

public:
    void build(const vector<T> &v) {
        m.resize(v.size());
        int j = (int) llround(log2(v.size())) + 1;
        for (int i = 0; i < m.size(); i++) {
            m[i].resize(j);
            m[i][0] = v[i];
        }
        for (j = 1; (1 << j) <= v.size(); j++) {
            for (int i = 0; i + (1 << j) - 1 < v.size(); i++) {
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
    RMQ<int> rmq;
    vector<int> v;
    int n, q, l, r, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        v.push_back(t);
    }
    rmq.build(v);
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << rmq.get(l - 1, r - 1) << "\n";
    }

    return 0;
}