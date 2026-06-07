/*
Problem: Friends (UVA)
Link:    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1549
Topic:   Graph Theory / DFS
Time:    O(m * n)
Space:   O(m * n)
*/

/* اللهم انفعنا بما علمتنا، وعلمنا ما ينفعنا، وزدنا علما. */

/* اللهم انفعنا بما علمتنا، وعلمنا ما ينفعنا، وزدنا علما. */

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int ll
typedef long long ll;
#define sz(s) (ll)(s).size()
#define all(s) s.begin(), s.end()
ll inf = 2e5 + 5;
ll ninf = 2e9 + 5;

void Speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<vector<int> > adj;
void solve() {
    int n, e;
    cin >> n >> e;
    adj.resize(n);
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        cout << adj[i].size() << '\n';
    }
}

signed main() {
    Speed();
    //ll t; cin >> t; while (t--)
    solve();
    return 0;
}

/* El-Khayat */
/* El-Khayat */


