// Initially, dis[i] = inf 
void bellmanFord(vector<ll> &dis, vector<vector<ll>> &edges, ll src, ll n) {

    dis[src] = 0;

    for(ll i = 0; i < n; ++i) {
        for(auto &edge : edges) {
            ll x = edge[0], y = edge[1], w = edge[2];

            // To avoid relaxation from vertices for which there is no path currently.
            if(dis[x] < inf) {
                dis[y] = min(dis[y], dis[x] + w);
            }
        }
    }
}