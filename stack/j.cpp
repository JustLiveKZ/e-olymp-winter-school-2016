#include <bits/stdc++.h>

using namespace std;

stack<int> st;
string s;

int main() {
    cin >> s;
    int ans = 0;
    int max_cnt = 1;

/*
( ) ( ( ) ) ( )
1 2 3 4 5 6 7 8 9 10 11 12 13 14
 */
    st.push(0);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i + 1);
        } else {
            if (!st.empty()) {
                st.pop();
                if (st.empty()) {
                    st.push(i + 1);
                } else {
                    int top = st.top();
                    int temp_max = i - top + 1;
                    if (ans == temp_max) {
                        max_cnt++;
                    } else if (temp_max > ans) {
                        ans = temp_max;
                        max_cnt = 1;
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}