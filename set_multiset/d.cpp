#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

multiset<pair<int, int>> s;

int main() {
    int tests, n, f, t;
    cin >> tests;
    for (int test = 0; test < tests; test++) {
        s.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> f >> t;
            if (s.find(make_pair(t, f)) != s.end()) {
                s.erase(s.find(make_pair(t, f)));
            } else {
                s.insert(make_pair(f, t));
            }
        }
        if (s.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}