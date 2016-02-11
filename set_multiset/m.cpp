#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

set<int> s;

int main() {
    int n;
    int t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        s.insert(t);
    }

    cout << s.size();

    return 0;
}