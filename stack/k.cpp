#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    int cnt = 0;
    int ans = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            cnt++;
        } else {
            if (cnt > 0) {
                cnt--;
            } else {
                ans++;
            }
        }
    }
    ans += cnt;

    cout << ans;

    return 0;
}