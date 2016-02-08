#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

queue<int> q;
deque<int> minq;

int main() {
    int n, k;
    cin >> n >> k;

    int t;
    for (int i = 0; i < k - 1; i++) {
        cin >> t;
        while (minq.size() > 0 && minq.back() > t) {
            minq.pop_back();
        }
        minq.push_back(t);
        q.push(t);
    }

    for (int i = 0; i < n - k + 1; i++) {
        cin >> t;
        while (minq.size() > 0 && minq.back() > t) {
            minq.pop_back();
        }
        minq.push_back(t);
        q.push(t);
        cout << minq.front() << " ";
        if (minq.front() == q.front()) {
            minq.pop_front();
        }
        q.pop();
    }

    return 0;
}