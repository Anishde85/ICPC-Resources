#include<bits/stdc++.h>

// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2")

using namespace std;

vector<vector<int>> adj;

vector<bool> visited;
vector<int> tin, low;
vector<vector<int>> bridges;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                bridges.push_back({v, to});
            }
        }
    }
}

void solve_test() {
    int n, m; cin >> n >> m;

    adj.assign(n, vector<int>(0));
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    bridges.clear();

    for(int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;

        // 0-indexed vertices.
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for(auto &b : bridges) {
        cout << b[0] << ' ' << b[1] << '\n';
    }
}

int main() {
    solve_test();
    return 0;
}