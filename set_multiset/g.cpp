#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

int n, m;
vector<int> v;
set<int> s;
int t;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        v.push_back(t);
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> t;
        s.insert(t);
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (s.find(v[i]) == s.end()) {
            cnt++;
        }
    }

    cout << cnt << endl;

    for (int i = 0; i < n; i++) {
        if (s.find(v[i]) == s.end()) {
            cout << v[i] << " ";
        }
    }

    return 0;
}