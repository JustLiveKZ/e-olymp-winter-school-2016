#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

set<pair<int, int>> s;

int main() {
    int c;

    while (cin >> c) {
        if (c == 0) {
            break;
        }
        if (c == 1) {
            int p, k;
            cin >> k >> p;
            s.insert(make_pair(p, k));
        } else {
            if (s.empty()) {
                cout << "0\n";
            } else {
                if (c == 3) {
                    cout << s.begin()->second << "\n";
                    s.erase(s.begin());
                } else {
                    cout << s.rbegin()->second << "\n";
                    auto q = --s.end();
                    s.erase(q);
                }
            }
        }
    }

    return 0;
}