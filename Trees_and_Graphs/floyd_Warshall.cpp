// dis[i][j] = edge weight initially.
// dis[i][j] = 'inf' if there is no path from 'i' to 'j'.
// vertices from 1 to 'n'.
void floydWarshall(vector<vector<ll>> &dis, ll n) {
    for(ll k = 1; k <= n; ++k) {
        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}