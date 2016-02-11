#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

string s;

class Median {
    priority_queue<int, vector<int>, greater<int >> pq_min;
    priority_queue<int> pq_max;

    void rebalance() {
        size_t total_cnt = pq_min.size() + pq_max.size();

        size_t size = total_cnt / 2;
        size_t diff = total_cnt % 2;

        while (pq_max.size() > size) {
            pq_min.push(pq_max.top());
            pq_max.pop();
        }

        while (pq_min.size() > size + diff) {
            pq_max.push(pq_min.top());
            pq_min.pop();
        }
    }

public:
    Median() {
        pq_min.push(INF);
        pq_max.push(-INF);
    }

    void insert(int t) {
        if (t > pq_max.top()) {
            pq_min.push(t);
        } else {
            pq_max.push(t);
        }
        rebalance();
    }

    int get_median() {
        return pq_min.top();
    }

    void delete_median() {
        pq_min.pop();
        rebalance();
    }
};


int main() {
    Median median;
    while (cin >> s) {
        if (s == "#") {
            cout << median.get_median() << "\n";
            median.delete_median();
        } else {
            int t = atoi(s.c_str());
            median.insert(t);
        }
    }

    return 0;
}