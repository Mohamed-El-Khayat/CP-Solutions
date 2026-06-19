// If you find any mistake or have a better solution, feel free to let me know.

/*
Problem: Uniqueness (Codeforces)
Link:    https://codeforces.com/problemset/problem/1208/B
Topic:   Binary Search / Binary Search on Answer
Time:    (n^2)*log(n)
Space:   O(n)
*/

/* اللهم انفعنا بما علمتنا، وعلمنا ما ينفعنا، وزدنا علما. */

#include <bits/stdc++.h>
using namespace std;

void Speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    auto ok = [&](int m) {
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[a[i]]++;
        }

        for (int i = 0; i < m - 1 && !mp.empty(); i++) {
            mp[a[i]]--;
            if (mp[a[i]] == 0) mp.erase(a[i]);
        }

        int c = 0;

        for (int l = 0, r = m - 1; r < n; r++, l++) {
            mp[a[r]]--;
            if (mp[a[r]] == 0) mp.erase(a[r]);

            for (auto &j : mp) {
                if (j.second > 1) {
                    c++;
                    break;
                }
            }

            mp[a[l]]++;
        }

        return c != n - m + 1;
    };

    int l = 0, r = n, m, ans = 0;

    while (l <= r) {
        m = (l + r) / 2;

        if (ok(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans;
}

signed main() {
    Speed();
    solve();
    return 0;
}

/* El-Khayat */
