#include <bits/stdc++.h>

using namespace std;

set<int> s;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b) {
        swap(a, b);
    }
    if (c > d) {
        swap(c, d);
    }

    for (int i = a; i <= b; i++) {
        for (int j = c; j <= d; j++) {
            s.insert(i * j);
        }
    }

    cout << s.size();


    return 0;
}