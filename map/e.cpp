#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

string a, b;

int cnta[26], cntb[26];

int main() {
    while (getline(cin, a)) {
        getline(cin, b);

        fill(cnta, cnta + 26, 0);
        fill(cntb, cntb + 26, 0);

        for (int i = 0; i < a.length(); i++) {
            cnta[a[i] - 'a']++;
        }
        for (int i = 0; i < b.length(); i++) {
            cntb[b[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            int c = min(cnta[i], cntb[i]);
            for (int j = 0; j < c; j++) {
                printf("%c", i + 'a');
            }
        }
        cout << endl;
    }

    return 0;
}