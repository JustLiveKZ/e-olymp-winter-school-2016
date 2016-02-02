#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > v;

int main() {
    v.push_back(make_pair(0, 0));
    int t, m;
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> t >> m;
        if (m == 0) {
            v.push_back(v[v[t].first]);
        } else {
            v.push_back(make_pair(t, v[t].second + m));
        }
        ans += v.back().second;
    }
    cout << ans;
    return 0;
}