#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
stack<int> s;
vector<int> a;
int t;
ll ans = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
    }

    int i = 0;
    while (i < n) {
        if (s.empty() || a[s.top()] <= a[i]) {
            s.push(i);
            i++;
        } else {
            int top = s.top();
            s.pop();

            ll area = (1ll * a[top]) * (s.empty() ? i : i - 1 - s.top());
            ans = max(ans, area);
        }
    }

    while (!s.empty()) {
        int top = s.top();
        s.pop();

        ll area = (1ll * a[top]) * (s.empty() ? i : i - 1 - s.top());
        ans = max(ans, area);
    }

    cout << ans;
    return 0;
}