#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

int n, m;
set<int> s;
int t;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        s.insert(t);
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> t;
        s.insert(t);
    }

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}