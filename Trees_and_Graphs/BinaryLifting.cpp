int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int node, int parent)
{
    tin[node] = ++timer;
    up[node][0] = parent;
    for (int i = 1; i <= l; ++i)
        up[node][i] = up[up[node][i-1]][i-1];

    for (int child : adj[node]) {
        if (child != parent)
            dfs(child,node);
    }

    tout[node] = ++timer;
}

bool is_ancestor(int u, int v)
{   
    // checks whether u is an ancestor of v
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
int kth_ancestor(int node,int k){
    int i=0,j=1;
    while(j<=k){
        if(j&k){
            node=up[node][i];
        }
        j*=2;i++;
    }
    return node;
}
void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    l = ceil(log2(n+1));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}