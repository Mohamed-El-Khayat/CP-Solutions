/*
Problem: Counting Roads (AtCoder)
Link:    https://atcoder.jp/contests/abc061/tasks/abc061_b
Topic:   Graph Theory
Time:    O(N + M)
Space:   O(N + M)
*/

/* اللهم انفعنا بما علمتنا، وعلمنا ما ينفعنا، وزدنا علما. */

#include <bits/stdc++.h>
using namespace std;

void Speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<vector<int>> adj;

void solve() {
    int n, m;
    cin >> n >> m;

    adj.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        a--, b--; // Convert to 0-based indexing

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Output the number of edges of each node
    for (int i = 0; i < n; i++) {
        cout << adj[i].size() << '\n';
    }
}

int main() {
    Speed();
    solve();
    return 0;
}

/* El-Khayat */
