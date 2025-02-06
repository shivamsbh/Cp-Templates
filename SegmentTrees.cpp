class SegmentTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int start, int end, int l, int r) {
        if (start > r || end < l)
            return 0;

        if (l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;
        int left = query(2 * node, start, mid, l, r);
        int right = query(2 * node + 1, mid + 1, end, l, r);
        return left + right;
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            arr[idx] = val;
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

public:
    SegmentTree(vector<int>& a) {
        arr = a;
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    int getSum(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    void updateValue(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
};

class LazySegmentTree {
private:
    int n;
    vector<int> tree, lazy;

    void build(int node, int tl, int tr, const vector<int>& arr) {
        if (tl == tr) {
            tree[node] = arr[tl - 1]; // Convert to 0-based array access
            return;
        }
        int tm = (tl + tr) >> 1;
        build(node<<1, tl, tm, arr);
        build(node<<1|1, tm+1, tr, arr);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }

    void push(int node, int tl, int tr) {
        if (lazy[node]) {
            int mid = (tl + tr) >> 1;
            int ln = mid - tl + 1;
            int rn = tr - mid;
            
            // Update current node
            tree[node] += lazy[node] * (tr - tl + 1);
            
            // Propagate to children if not leaf
            if (tl != tr) {
                lazy[node<<1] += lazy[node];
                lazy[node<<1|1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void range_update(int node, int tl, int tr, int l, int r, int val) {
        push(node, tl, tr);
        if (r < tl || tr < l) return;
        
        if (l <= tl && tr <= r) {
            lazy[node] += val;
            push(node, tl, tr);
            return;
        }
        
        int tm = (tl + tr) >> 1;
        range_update(node<<1, tl, tm, l, r, val);
        range_update(node<<1|1, tm+1, tr, l, r, val);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }

    int range_query(int node, int tl, int tr, int l, int r) {
        push(node, tl, tr);
        if (r < tl || tr < l) return 0;
        
        if (l <= tl && tr <= r) return tree[node];
        
        int tm = (tl + tr) >> 1;
        return range_query(node<<1, tl, tm, l, r) + 
               range_query(node<<1|1, tm+1, tr, l, r);
    }

public:
    LazySegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n + 1);
        lazy.resize(4*n + 1, 0);
        build(1, 1, n, arr);
    }

    // Update interval [l, r] (1-based) with +val
    void update(int l, int r, int val) {
        range_update(1, 1, n, l, r, val);
    }

    // Query sum of interval [l, r] (1-based)
    int query(int l, int r) {
        return range_query(1, 1, n, l, r);
    }
};
