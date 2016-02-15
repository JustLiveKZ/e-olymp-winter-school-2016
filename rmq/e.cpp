#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;

const int INF = (int) 1e9;
const double eps = 1e-9;

template<typename T>
class RMQ {
    vector<vector<T>> m;

public:
    void build(const vector<T> &v) {
        m.resize(v.size());
        ui j = (ui) llround(log2(v.size())) + 1;
        for (ui i = 0; i < m.size(); i++) {
            m[i].resize(j);
            m[i][0] = v[i];
        }
        for (j = 1; (1 << j) <= v.size(); j++) {
            for (ui i = 0; i + (1 << j) - 1 < v.size(); i++) {
                m[i][j] = min(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T get(ui l, ui r) {
        if (l > r) {
            swap(l, r);
        }
        ui j = (ui) log2(r - l + 1);
        return min(m[l][j], m[r - (1 << j) + 1][j]);
    }
};


int main() {
    ui n, m, a, b;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        RMQ<ui> rmq;
        vector<ui> v;
        ll ans = 0;
        cin >> m >> a >> b;
        for (ui i = 0; i < n + 2 * m; i++) {
            ui t = a * (i + 1) + b;
            if (i < n) {
                v.push_back(t);
                if (i == n - 1) {
                    rmq.build(v);
                }
            } else {
                ui l = (a * (i + 1) + b) % n;
                i++;
                ui r = (a * (i + 1) + b) % n;
                ans += rmq.get(l, r);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}