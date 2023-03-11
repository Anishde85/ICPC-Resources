class DSU {
public:
    vector<int> parent, size;
    int connected_components;
    DSU(int n) : connected_components(n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find_parent(int v) {
        if (parent[v] == v)
            return v;
        return parent[v] = find_parent(parent[v]);
    }
    bool Union(int a, int b) {
        a = find_parent(a);
        b = find_parent(b);
        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
            connected_components--;
            return true;
        }
        return false;
    }
    bool is_connected(int a, int b) {
        return find_parent(a) == find_parent(b);
    }
};