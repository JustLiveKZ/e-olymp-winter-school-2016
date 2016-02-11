#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

int n;
vector<string> v;
string s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}