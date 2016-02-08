#include <bits/stdc++.h>

using namespace std;

deque<int> q;
string s;

int main() {
    while (true) {

        getline(cin, s);
        if (s.substr(0, 10) == "push_front") {
            int t = atoi(s.substr(11).c_str());
            q.push_front(t);
            cout << "ok\n";
        } else if (s.substr(0, 9) == "push_back") {
            int t = atoi(s.substr(10).c_str());
            q.push_back(t);
            cout << "ok\n";
        } else if (s.substr(0, 9) == "pop_front") {
            cout << q.front() << "\n";
            q.pop_front();
        } else if (s.substr(0, 8) == "pop_back") {
            cout << q.back() << "\n";
            q.pop_back();
        } else if (s.substr(0, 5) == "front") {
            cout << q.front() << "\n";
        } else if (s.substr(0, 4) == "back") {
            cout << q.back() << "\n";
        } else if (s.substr(0, 4) == "size") {
            cout << q.size() << "\n";
        } else if (s.substr(0, 5) == "clear") {
            q.clear();
            cout << "ok\n";
        } else if (s.substr(0, 4) == "exit") {
            cout << "bye\n";
            break;
        }
    }

    return 0;
}