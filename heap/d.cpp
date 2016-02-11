#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

int n, h, b, e, t;

typedef pair<int, int> pii;

int main() {
    while (cin >> n) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> res(n, 0);
        cin >> h >> b >> e;
        for (int i = 0; i < n; i++) {
            cin >> t;
            pq.push(make_pair(t, -i));
            while (i - abs(pq.top().second) >= h) {
                pq.pop();
            }
            res[abs(pq.top().second)]++;
        }
        for (int i = b - 1; i < e; i++) {
            cout << res[i];
            cout << ((i == e - 1) ? "\n" : "\t");
        }
    }

    return 0;
}