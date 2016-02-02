#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
string s;

int main() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            cnt++;
        } else {
            if (cnt == 0) {
                cout << "NO";
                return 0;
            }
            cnt--;
        }
    }
    if (cnt == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}