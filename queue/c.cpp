#include <bits/stdc++.h>

using namespace std;

int n;
string s;
const int N = 150010;

int a[N];
int heads[N];
int tails[N];
int ne[N];
int pv[N];
int ptr = 0;


int main() {
    cin >> n;


    fill(heads, heads + N, -1);
    fill(tails, tails + N, -1);
    fill(ne, ne + N, -1);
    fill(pv, pv + N, -1);

    for (int i = 0; i < n; i++) {
        cin >> s;
        int q, t;
        if (s == "pushback" || s == "pushfront") {
            cin >> q >> t;
            a[ptr] = t;
            if (heads[q] == -1) {
                heads[q] = ptr;
                tails[q] = ptr;
            } else {
                if (s == "pushback") {
                    ne[tails[q]] = ptr;
                    pv[ptr] = tails[q];
                    tails[q] = ptr;
                } else {
                    pv[heads[q]] = ptr;
                    ne[ptr] = heads[q];
                    heads[q] = ptr;
                }
            }
            ptr++;
        } else {
            cin >> q;
            if (heads[q] == tails[q]) {
                t = a[heads[q]];
                heads[q] = tails[q] = -1;
            } else {
                if (s == "popback") {
                    t = a[tails[q]];
                    tails[q] = pv[tails[q]];
                    ne[tails[q]] = -1;
                } else {
                    t = a[heads[q]];
                    heads[q] = ne[heads[q]];
                    pv[heads[q]] = -1;
                }
            }
            cout << t << "\n";
        }
    }

    return 0;
}
