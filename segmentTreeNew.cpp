// Mode explanation:
// 0 -> Min Tree
// 1 -> Max Tree
// 2 -> Sum Tree

class SegmentTree {
private:
    int n;
    int mode;
    vector<long long> tree;
    vector<long long> data;

    long long identity() {
        if (mode == 0) return LLONG_MAX;
        if (mode == 1) return LLONG_MIN;
        if (mode == 2) return 0;
        return 0;
    }

    long long combine(long long left, long long right) {
        if (mode == 0) return min(left, right);
        if (mode == 1) return max(left, right);
        if (mode == 2) return left + right;
        return 0;
    }

    void build(int node, int start, int end) {
        assert(node < (int)tree.size() && "Node index out of range in build");
        if (start > end) return;
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = start + (end - start) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void update(int idx, long long value, int node, int start, int end) {
        assert(node < (int)tree.size() && "Node index out of range in update");
        if (idx < start || idx > end) return;
        if (start == end) {
            data[idx] = value;
            tree[node] = value;
        } else {
            int mid = start + (end - start) / 2;
            if (idx <= mid)
                update(idx, value, 2 * node + 1, start, mid);
            else
                update(idx, value, 2 * node + 2, mid + 1, end);
            tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    long long query(int l, int r, int node, int start, int end) {
        assert(node < (int)tree.size() && "Node index out of range in query");
        if (r < start || l > end) return identity();
        if (l <= start && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        long long leftQuery = query(l, r, 2 * node + 1, start, mid);
        long long rightQuery = query(l, r, 2 * node + 2, mid + 1, end);
        return combine(leftQuery, rightQuery);
    }

public:
    SegmentTree(vector<long long>& arr, int mode) : mode(mode) {
        assert(mode >= 0 && mode <= 2 && "Invalid mode. Use 0 for min, 1 for max, 2 for sum.");
        if (arr.empty()) {
            n = 0;
            return;
        }
        n = arr.size();
        data = arr;
        tree.resize(4 * n, identity());
        build(0, 0, n - 1);
    }

    void update(int idx, long long value) {
        assert(n > 0 && "SegmentTree is empty");
        assert(idx >= 0 && idx < n && "Index out of range");
        update(idx, value, 0, 0, n - 1);
    }

    long long query(int l, int r) {
        assert(n > 0 && "SegmentTree is empty");
        l = max(l, 0LL);
        r = min(r, n - 1LL);
        assert(l <= r && "Query indices are invalid after trimming");
        return query(l, r, 0, 0, n - 1);
    }
};
