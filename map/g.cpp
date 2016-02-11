#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

map<string, int> m;

string s;

string ans;
int cnt;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        m[s]++;
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second >= cnt) {
            cnt = it->second;
            ans = it->first;
        }
    }

    cout << ans << " " << cnt;

    return 0;
}