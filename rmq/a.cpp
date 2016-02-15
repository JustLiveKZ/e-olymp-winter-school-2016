#include <bits/stdc++.h>

using namespace std;

int n, m, a1, u1, v1;

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
    cin >> n >> m >> a1 >> u1 >> v1;

    a.push_back(a1);
    for (int i = 0; i < n - 1; i++) {
        a1 = (23 * a1 + 21563) % 16714589;
        a.push_back(a1);
    }

    build();

    int ans = get(u1 - 1, v1 - 1);
    for (int i = 0; i < m - 1; i++) {
        u1 = ((17 * u1 + 751 + ans + 2 * (i + 1)) % n) + 1;
        v1 = ((13 * v1 + 593 + ans + 5 * (i + 1)) % n) + 1;
        ans = get(u1 - 1, v1 - 1);
    }

    cout << u1 << " " << v1 << " " << ans;

    return 0;
}