#include <bits/stdc++.h>

using namespace std;

stack<int> st;

int main() {
    while (true) {
        string s;
        getline(cin, s);

        if (s.substr(0, 4) == "push") {
            int n = atoi(s.substr(5).c_str());
            st.push(n);
            cout << "ok\n";
        } else if (s.substr(0, 4) == "back") {
            cout << st.top() << "\n";
        } else if (s.substr(0, 4) == "size") {
            cout << st.size() << "\n";
        } else if (s.substr(0, 5) == "clear") {
            while (!st.empty()) {
                st.pop();
            }
            cout << "ok\n";
        } else if (s.substr(0, 3) == "pop") {
            cout << st.top() << "\n";
            st.pop();
        } else if (s.substr(0, 4) == "exit") {
            cout << "bye\n";
            break;
        }

    }

    return 0;
}