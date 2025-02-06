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
    vector<int> tree;
    vector<int> lazy;
    
    // Helper function to propagate lazy values
    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            // Apply the pending update
            tree[node] += (end - start + 1) * lazy[node];
            
            // Propagate to children if not leaf
            if (start != end) {
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    
    // Recursive function to build the tree
    void build(const std::vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, node*2, start, mid);
        build(arr, node*2+1, mid+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    
public:
    LazySegmentTree(const std::vector<int>& arr) {
        n = arr.size();
        int height = (int)ceil(log2(n)) + 1;
        int size = 1 << height;
        tree.resize(size);
        lazy.resize(size, 0);
        build(arr, 1, 0, n-1);
    }
    
    // Range update: add 'val' to all elements in [l, r]
    void updateRange(int l, int r, int val) {
        _updateRange(1, 0, n-1, l, r, val);
    }
    
    void _updateRange(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);
        
        if (start > r || end < l) return;
        
        if (l <= start && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        
        int mid = (start + end) / 2;
        _updateRange(node*2, start, mid, l, r, val);
        _updateRange(node*2+1, mid+1, end, l, r, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    
    // Range query: sum of elements in [l, r]
    int queryRange(int l, int r) {
        return _queryRange(1, 0, n-1, l, r);
    }
    
    int _queryRange(int node, int start, int end, int l, int r) {
        push(node, start, end);
        
        if (start > r || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        
        int mid = (start + end) / 2;
        return _queryRange(node*2, start, mid, l, r) + 
               _queryRange(node*2+1, mid+1, end, l, r);
    }
};
