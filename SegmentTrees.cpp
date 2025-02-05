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
    std::vector<int> tree;
    std::vector<int> lazy;
    int n;

    void build(int node, int start, int end, const std::vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start - 1]; // Convert to 0-based array access
            return;
        }

        int mid = (start + end) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void apply(int node, int start, int end, int delta) {
        tree[node] += delta * (end - start + 1);
        if (start != end) {
            lazy[2 * node] += delta;
            lazy[2 * node + 1] += delta;
        }
        lazy[node] = 0;
    }

    int query(int node, int start, int end, int l, int r) {
        if (lazy[node] != 0) {
            int delta = lazy[node];
            apply(node, start, end, delta);
        }

        if (end < l || start > r) return 0;
        if (l <= start && end <= r) return tree[node];

        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) +
               query(2 * node + 1, mid + 1, end, l, r);
    }

    void update(int node, int start, int end, int l, int r, int delta) {
        if (lazy[node] != 0) {
            apply(node, start, end, lazy[node]);
        }

        if (start > r || end < l) return;

        if (l <= start && end <= r) {
            apply(node, start, end, delta);
            return;
        }

        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, delta);
        update(2 * node + 1, mid + 1, end, l, r, delta);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

public:
    LazySegmentTree(const std::vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(1, 1, n, arr);
    }

    int rangeQuery(int l, int r) {
        return query(1, 1, n, l, r);
    }

    void rangeUpdate(int l, int r, int delta) {
        update(1, 1, n, l, r, delta);
    }
};
