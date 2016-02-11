#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

int k, n;
string s;

int main() {
    cin >> k;
    for (int q = 0; q < k; q++) {
        cin >> n;
        map<string, int> m1;
        map<int, int> m2;
        for (int i = 0; i < n; i++) {
            cin >> s;
            m1[s] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> s;
            m2[i] = m1[s];
        }
        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            cin >> s;
            ans[m2[i]] = s;
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}