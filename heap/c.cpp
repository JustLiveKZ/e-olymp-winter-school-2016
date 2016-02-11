#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

priority_queue<int> pq;

bool process(priority_queue<int> &pq) {
    while (!pq.empty()) {
        vector<int> v;
        int d = pq.top();
        pq.pop();

        while (d--) {
            if (pq.empty()) {
                return false;
            }
            int t = pq.top();
            pq.pop();
            if (t > 1) {
                v.push_back(t - 1);
            }
        }
        for (int i = 0; i < v.size(); i++) {
            pq.push(v[i]);
        }
        v.clear();
    }
    return true;
}

int main() {
    int n;
    char c;
    while (scanf("%d%c", &n, &c) == 2) {
        pq.push(n);
        if (c == '\n') {
            printf(process(pq) ? "ok\n\n" : "fail\n\n");

            while (!pq.empty()) pq.pop();
        }
    }

    return 0;
}