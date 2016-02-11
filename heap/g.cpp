#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

int main() {
    int t;
    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> pq_min;
    priority_queue<int> pq_max;
    while (cin >> t) {
        cnt++;
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

        if (cnt % 2 == 1) {
            cout << pq_min.top() << "\n";
        } else {
            cout << (pq_min.top() + pq_max.top()) / 2 << "\n";
        }
    }

    return 0;
}