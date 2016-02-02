#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    string n;
    getline(cin, n);
    int q = atoi( n.c_str() );
    for (int j = 0; j < q; j++) {
        string str;
        getline(cin, str);

        stack<char> s;
        bool ok = true;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '[') {
                s.push(str[i]);
            } else {
                if (s.empty()) {
                    ok = false;
                } else {
                    if ((str[i] == ')' && s.top() == '(') || (str[i] == ']' && s.top() == '[')) {
                        s.pop();
                    } else {
                        ok = false;
                    }
                }
            }
        }

        if (!s.empty()) {
            ok = false;
        }

        cout << (ok ? "Yes" : "No") << endl;
    }

    return 0;
}