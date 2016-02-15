#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> a;
vector<vector<int> > min_a;

void build() {
    min_a.resize(a.size());
    int l = (int) llround(log2(n)) + 1;

    for (int i = 0; i < min_a.size(); i++) {
        min_a[i].resize(l);
        min_a[i][0] = a[i];
    }

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            min_a[i][j] = min(min_a[i][j - 1], min_a[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int get(int l, int r) {
    if (l > r) {
        swap(l, r);
    }
    int j = (int) log2(r - l + 1);
    return min(min_a[l][j], min_a[r - (1 << j) + 1][j]);
}

int main() {
    int t;
    cin >> n >> m;
    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> t;
        a[t - 1] = i + 1;
    }

    build();

    int l, r;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        cout << get(l - 1, r - 1) << "\n";
    }

    return 0;
}