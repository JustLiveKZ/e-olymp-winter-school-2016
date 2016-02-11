#include <bits/stdc++.h>

using namespace std;

int n, t;

vector<pair<int, int> > a;

int dist = (int) 2e9;

int p;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push_back(make_pair(t, i + 1));
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n - 1; i++) {
        if (dist > a[i + 1].first - a[i].first) {
            dist = a[i + 1].first - a[i].first;
            p = i;
        }
    }

    cout << dist << "\n" << a[p].second << " " << a[p + 1].second;

    return 0;
}