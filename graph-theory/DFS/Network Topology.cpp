// If you find any mistake or have a better solution, feel free to let me know.

/*
Problem: Network Topology
Link:    https://codeforces.com/contest/292/problem/B
Topic:   Grapgh Theory / DFS
Time:    O(N+E)
Space:   O(N+E)
*/

/* اللهم انفعنا بما علمتنا، وعلمنا ما ينفعنا، وزدنا علما. */

#include <bits/stdc++.h>
using namespace std;

void Speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<vector<int> > adj;
vector<bool> vis;

void DFS(int node) {
    vis[node] = true;
    for (auto child: adj[node]) {
        if (!vis[child]) DFS(child);
    }
}

void solve() {
    int n, e;
    cin >> n >> e;
    adj.resize(n);
    vis.resize(n);
    for (int i = 0; i < e; i++) {
        int from, to;
        cin >> from >> to;
        from--, to--;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    int c1 = 0;
    int c2 = 0;
    int cn = 0;
    int root = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            DFS(i);
            root++;
        }
        if (adj[i].size() == 1) c1++;
        else if (adj[i].size() == 2) c2++;
        else if (adj[i].size() == n - 1) cn++;
        else {
            cout << "unknown topology";
            return;
        }
    }
    if (c1 == 2 and c2 == n - 2 and cn == 0 and root == 1) cout << "bus topology";
    else if (c1 == 0 and c2 == n and cn == 0 and root == 1) cout << "ring topology";
    else if (c1 == n - 1 and c2 == 0 and cn == 1 and root == 1) cout << "star topology";
    else cout << "unknown topology";
}

signed main() {
    Speed();
    //ll t; cin >> t; while (t--)
    solve();
    return 0;
}

/* El-Khayat */
