#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

set<int> s;

int n, k, t;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> t;
            s.insert(t);
        }
    }
    cout << s.size();

    return 0;
}