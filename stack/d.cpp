#include <bits/stdc++.h>

using namespace std;

int n;
stack<int> s;

int main() {
    cin >> n;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == 0) {
            if (s.empty()) {
                cout << "0\n";
            } else {
                s.pop();
                cout << s.top() << "\n";
            }
        } else {
            if (s.empty()) {
                s.push(t);
            } else {
                s.push(max(t, s.top()));
            }
        }
    }
}
