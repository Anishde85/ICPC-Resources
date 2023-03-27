// dis[i] for all vertex 'i' assumes to be initialized with infinity.
void dijkstra(vector<vector<pair<ll, ll>>> &graph, vector<ll> &dis, ll src) {

    auto compare = [&](const pair<ll, ll> &x, const pair<ll, ll> &y) {
        return x.first > y.first;
    };

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(compare)> pq(compare);

    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty()) {
        pair<ll, ll> cur = pq.top();
        pq.pop();

        ll x = cur.first;

        if(cur.second != dis[x]) {
            continue;
        }

        for (auto &edge : graph[x]) {
            ll y = edge.first, w = edge.second;
            if (dis[y] > dis[x] + w) {
                dis[y] = dis[x] + w;
                pq.push({y, dis[y]});
            }
        }
    }
}