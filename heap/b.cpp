#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

vector<int> a;
int n, t;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
    }

    bool ok = true;

    int i = 0;
    while (i * 2 + 1 < n) {
        if (a[i] > a[i * 2 + 1]) {
            ok = false;
            break;
        }
        if (i * 2 + 2 < n) {
            if (a[i] > a[i * 2 + 2]) {
                ok = false;
                break;
            }
        }
        i++;
    }

    cout << (ok ? "YES" : "NO");

    return 0;
}