/**
 * @brief General template for segment tree range update range query
 *
 * @tparam T data type of segtree
 * @tparam U data type of lazytree
 * @tparam V data type of that value that will be passed in update function
 */
template <class T, class U, class V>
class SegmentTree {
    int n;
    vector<T> tree;
    vector<U> lazy;
    T IDENTITY_ELEMENT;
    T query(int node, int start, int end, int left, int right) {
        propagate(node, start, end);
        if (end < left || right < start)
            return IDENTITY_ELEMENT;
        if (left <= start && right >= end)
            return tree[node];
        int mid = start + (end - start) / 2;
        return combine(query(2 * node, start, mid, left, right), query(2 * node + 1, mid + 1, end, left, right));
    }

    void update(int node, int start, int end, int left, int right, V val) {
        propagate(node, start, end);
        if (end < left || right < start)
            return;
        if (start >= left && end <= right) {
            updateNode(node, start, end, left, right, val);
            propagate(node, start, end);
            return;
        }
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, left, right, val);
        update(2 * node + 1, mid + 1, end, left, right, val);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
    void build(int node, int start, int end, vector<T> &data) {
        if (start == end) {
            tree[node] = data[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, data);
        build(2 * node + 1, mid + 1, end, data);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
    /**
     * @brief function to update a particular node which is completely inside the range
     */
    void updateNode(int node, int start, int end, int left, int right, V val) {
        // write you code here
    }
    /**
     * @brief function to combine two segtree nodes
     */
    T combine(T leftNode, T rightNode) {
        // write you code here
    }
    /**
     * @brief funtion to propagate lazy node values
     */
    void propagate(int node, int start, int end) {
        //  write you code here
    }

public:
    SegmentTree(int size, T _IDENTITY_ELEMENT) : n(size), IDENTITY_ELEMENT(_IDENTITY_ELEMENT) {
        lazy.resize(4 * n);
        tree.resize(4 * n);
    }
    SegmentTree(vector<T> &initial_value, T _IDENTITY_ELEMENT) : SegmentTree((int)initial_value.size(), _IDENTITY_ELEMENT) {
        build(1, 0, n - 1, initial_value);
    }
    T query(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
    void update(int left, int right, V val) {
        update(1, 0, n - 1, left, right, val);
    }
    int size() {
        return n;
    }
};