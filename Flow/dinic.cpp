#include<bits/stdc++.h>

// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2")

using namespace std;

typedef long long ll;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const ll inf = 1e16;
const ll mod = 1e9 + 7;

//***************************************************

struct FlowEdge {
    ll v, u;
    ll cap, flow = 0;
    FlowEdge(ll v, ll u, ll cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const ll flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<ll>> adj;
    ll n, m = 0;
    ll s, t;
    vector<ll> level, ptr;
    queue<ll> q;

    Dinic(ll n, ll s, ll t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(ll v, ll u, ll cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            ll v = q.front();
            q.pop();
            for (ll id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    ll dfs(ll v, ll pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (ll& cid = ptr[v]; cid < (ll)adj[v].size(); cid++) {
            ll id = adj[v][cid];
            ll u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow() {
        ll f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

void solve_test() {

    ll n, m; cin >> n >> m;

    Dinic obj(n + 2, 1, n);

    for(ll i = 0; i < m; ++i) {
        ll x, y, z; cin >> x >> y >> z;
        obj.add_edge(x, y, z);
    }
    
    cout << obj.flow() << '\n';
}

int main() {
    IOS;

    ll t = 1;
    // cin >> t;
 
    while(t--) {
        solve_test();
    }
 
    return 0;
}
