// If you find any mistake or have a better solution, feel free to let me know.

/*
Problem: Is it a tree (spoj)
Link:    https://www.spoj.com/problems/PT07Y/
Topic:   Graph Theory / DFS
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
vector<int> start;
vector<int> finish;
int timer = 0;
bool tree_flag = false;
bool cycle_flag = false;
bool forward_flag = false;
bool cross_flag = false;

void dfsC(int node) {
    start[node] = timer++;
    for (auto ch: adj[node]) {
        if (start[ch] == -1) {
            tree_flag = true;
            dfsC(ch);
        } else if (finish[ch] == -1) cycle_flag = true;
        else if (start[node] < start[ch]) forward_flag = true;
        else cross_flag = true;
    }
    finish[node] = timer++;
}

void solve() {
    int n, e;
    cin >> n >> e;
    start.resize(n, -1);
    finish.resize(n, -1);
    adj.resize(n);
    int root = 0;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }
    for (int i = 0; i < n; i++) {
        if (start[i] == -1) {
            root++;
            dfsC(i);
        }
    }
    (root == 1 and !cycle_flag and !forward_flag and !cross_flag) ? cout << "YES" : cout << "NO";
}

signed main() {
    Speed();
    solve();
    return 0;
}

/* El-Khayat */
