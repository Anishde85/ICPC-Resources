// strongly connected components
vector<vector<int>> adj(N), adj_rev(N);
vector<bool> used(N);
vector<int> order, component;
void dfs1(int node) {
    used[node] = true;
    for (auto u : adj[node]){
        if (!used[u]){
            dfs1(u);
        }
    }    
    order.push_back(node);
}

void dfs2(int node) {
    used[node] = true;
    component.push_back(node);
    for (auto u : adj_rev[node]){
        if (!used[u]){
            dfs2(u);
        }
    }
}

void kosaraju(int n) {

    used.assign(n+10, false);
    order.clear();
    
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n+10, false);
    reverse(order.begin(), order.end());

    for (auto v : order){
        if (!used[v]) {
            component.clear();
            dfs2(v);
            // use current component
        }
    }
}