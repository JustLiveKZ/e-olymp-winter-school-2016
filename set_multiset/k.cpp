#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

vector<set<pair<int, int> > > v(1);

int k, n, m;
char a[100][100];
vector<int> on[100][100];

set<vector<int>> s;

int main() {
    cin >> k >> n >> m;

    for (int q = 0; q < k; q++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] == '*') {
                    on[i][j].push_back(q);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s.insert(on[i][j]);
        }
    }

    cout << s.size();
    return 0;
}