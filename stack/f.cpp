#include <bits/stdc++.h>

using namespace std;

int n;
stack<int> s;
int q;

int main() {
    cin >> n;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> q;
        if (q == 1) {
            cin >> t;
        }
        if (q == 1) {
            if (s.empty()) {
                s.push(t);
            } else {
                s.push(min(s.top(), t));
            }
        } else if (q == 2) {
            s.pop();
        } else {
            cout << s.top() << "\n";
        }
    }
}
