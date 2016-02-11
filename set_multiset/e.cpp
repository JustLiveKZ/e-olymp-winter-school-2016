#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

set<string> words;

char s[300];

int main() {
    scanf("%[^a-zA-Z]", s);
    while (scanf("%[a-zA-Z]", s) == 1) {
        int l = strlen(s);
        for (int i = 0; i < l; i++) {
            s[i] = tolower(s[i]);
        }
        words.insert(s);
        scanf("%[^a-zA-Z]", s);
    }

    for (auto it = words.begin(); it != words.end(); it++) {
        cout << *it << "\n";
    }

    return 0;
}