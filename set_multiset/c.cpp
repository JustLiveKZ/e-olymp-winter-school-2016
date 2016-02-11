#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

vector<int> a;
int m, n, t, k;

int head = 0;

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> t;
        a.push_back(t);
    }

    for (int i = 0; i < n; i++) {
        k++;
        cin >> t;
        for (int j = head; j < t; j++) {
            int p = j;
            while (p >= 1 && a[p - 1] > a[p]) {
                swap(a[p - 1], a[p]);
                p--;
            }
        }
        head = t;
        cout << a[k - 1] << "\n";
    }

    return 0;
}