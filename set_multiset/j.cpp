#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

set<int> s;

string str, cmd;

int main() {
    while (getline(cin, str)) {
        cmd = str.substr(0, 6);
        int n = atoi(str.substr(7).c_str());
        if (cmd == "insert") {
            s.insert(n);
        } else if (cmd == "delete") {
            if (s.find(n) != s.end()) {
                s.erase(s.find(n));
            }
        } else {
            cout << (s.find(n) != s.end() ? "true" : "false") << "\n";
        }
    }

    return 0;
}