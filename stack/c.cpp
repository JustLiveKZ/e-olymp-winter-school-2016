#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) { break; }

        while (true) {
            cin >> t;
            if (t == 0) { cout << "\n"; break; }

            vector<int> v;
            stack<int> s;
            v.push_back(t);
            for (int i = 1; i < n; i++) {
                cin >> t;
                v.push_back(t);
            }

            bool yes = true;
            int head = 1;
            for (int i = 0; i < n; i++) {
                int top = s.empty() ? 0 : s.top();
                if (v[i] > top) {
                    for (int j = head; j < v[i]; j++) {
                        s.push(j);
                    }
                    head = v[i] + 1;
                } else {
                    if (v[i] == top) {
                        s.pop();
                    } else {
                        yes = false;
                        break;
                    }
                }
            }
            cout << (yes ? "Yes" : "No") << "\n";
        }

    }

    return 0;
}