#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

int main() {
    int tests;
    cin >> tests;
    int test_num, n, t;

    for (int test = 0; test < tests; test++) {
        cin >> test_num >> n;
        cout << test_num << " " << (n + 1) / 2 << "\n";
        priority_queue<int, vector<int>, greater<int>> pq_min;
        priority_queue<int> pq_max;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> t;
            if (pq_min.empty()) {
                pq_min.push(t);
            } else if (pq_min.top() > t) {
                pq_max.push(t);
            } else {
                pq_min.push(t);
            }

            if (pq_max.size() > pq_min.size()) {
                int top = pq_max.top();
                pq_max.pop();
                pq_min.push(top);
            }
            if (pq_min.size() - pq_max.size() > 1) {
                int top = pq_min.top();
                pq_min.pop();
                pq_max.push(top);
            }

            if (i % 2 == 0) {
                cnt++;
                cout << pq_min.top() << " ";
                if (cnt % 10 == 0) {
                    cout << "\n";
                }
            }
        }
        if (cnt % 10 != 0) {
            cout << "\n";
        }
    }

    return 0;
}