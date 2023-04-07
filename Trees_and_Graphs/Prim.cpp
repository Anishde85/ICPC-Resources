const int inf = 1e9;

void prim() {
    int n;
    cin >> n;

    // edge format : {to, weight}.
    vector<vector<vector<int>>> adj(n);
    
    // number of edges.
    int m; cin >> m;

    for(int i = 0; i < m; ++i) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    int total_weight = 0;

    // {to, weight}
    vector<vector<int>> min_e(n, {-1, inf});

    min_e[0][1] = 0;

    struct compare {
        bool operator() (const vector<int> &x, const vector<int> &y) const {
            return x[1] < y[1];
        }
    };

    set<vector<int>, compare> q;
    
    q.insert({0, 0});

    vector<bool> selected(n, false);

    for (int i = 0; i < n; ++i) {
        if (q.empty()) {
            cout << "No MST!" << endl;
            return;
        }

        auto iter = *q.begin();
        q.erase(q.begin());

        int v = iter[0];
        
        selected[v] = true;

        total_weight += iter[1];

        if (min_e[v][0] != -1) {
            cout << v << " " << min_e[v][0] << endl;
        }

        for (auto e : adj[v]) {
            if (!selected[e[0]] && e[1] < min_e[e[0]][1]) {
                q.erase({e[0], min_e[e[0]][1]});
                min_e[e[0]] = {v, e[1]};
                q.insert({e[0], e[1]});
            }
        }
    }

    cout << total_weight << endl;
}