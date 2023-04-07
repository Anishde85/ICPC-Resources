#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
vector<pair<int, int>> g[N];
vector<int> BridgeTree[N];
bool isBridge[N];
bool vis[N];
int disc[N], low[N], tim = 0;
int comp[N], component_number = 0;
int DP[N], MaxLen[N];

void dfs(int node, int par) {
    // dfs for finding bridges in O(N + M)
    vis[node] = true;
    disc[node] = ++tim;
    low[node] = tim;
    for (int i = 0; i < g[node].size(); i++) {
        if (g[node][i].first == par) // it the next node is the parent
            continue;
        if (!vis[g[node][i].first]) { // if the next node has not been visited
            dfs(g[node][i].first, node);
            if (low[g[node][i].first] > disc[node]) {
                isBridge[g[node][i].second] = true; // mark the current edge as a bridge
            }
            low[node] = min(low[node], low[g[node][i].first]);
        } else { // if the next node has been visited
            low[node] = min(low[node], disc[g[node][i].first]);
        }
    }
}

void dfs1(int node, int par) {
    vis[node] = true;
    comp[node] = component_number;
    for (int i = 0; i < g[node].size(); i++) {
        if (vis[g[node][i].first] || isBridge[g[node][i].second]) 
        // next node has already been visited or current edge is a bridge
            continue;
        dfs1(g[node][i].first, node);
    }
}

void dfs2(int node, int par) {
    for (int i = 0; i < BridgeTree[node].size(); i++) {
        if (BridgeTree[node][i] == par)
            continue;
        dfs2(BridgeTree[node][i], node);
    }
    if (BridgeTree[node].size() == 1 && node != 1) {
        DP[node] = 1;
        MaxLen[node] = 1;
        return;
    }
    for (int i = 0; i < BridgeTree[node].size(); i++) {
        if (BridgeTree[node][i] == par)
            continue;
        DP[node] = max(DP[node], MaxLen[node] + MaxLen[BridgeTree[node][i]]);
        MaxLen[node] = max(MaxLen[node], MaxLen[BridgeTree[node][i]] + 1);
        DP[node] = max(DP[node], MaxLen[node]);
    }
}

void Solve() {
    // taking input
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(-1, -1)); // so that indexing starts from 1
    for (int i = 1; i <= m; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(make_pair(u, i));
        g[u].push_back(make_pair(v, i));
        edges.push_back(make_pair(u, v));
    }

    // dfs for finding bridges in O(N + M)
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
    }

    // dfs to group all the maximal components together, so that we can shrink it to one node
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            component_number++;
            dfs1(i, -1);
        }
    }

    // shrinking all the maximal components to one node
    for (int i = 1; i <= m; i++) {
        if (isBridge[i]) {
            BridgeTree[comp[edges[i].first]].push_back(comp[edges[i].second]);
            BridgeTree[comp[edges[i].second]].push_back(comp[edges[i].first]);
        }
    }

    // Finding the diameter of the tree in terms of number nodes
    dfs2(1, -1);

    int ans = 0;
    for (int i = 1; i <= component_number; i++) {
        ans = max(ans, DP[i] - 1); // subtracting 1 because we need the number of edges
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}