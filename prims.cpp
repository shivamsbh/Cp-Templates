
/*0 based input */

int Prims(vector<vector<pair<int, int>>> &adj) {
    int n = adj.size();
    vector<int> vis(n);
    minh<pii> min_heap;
    int ans = 0;
    min_heap.push(make_pair(0, 0));
    int vs_added = 0;
    while (!min_heap.empty()) {
        pair<int, int> p = min_heap.top();
        min_heap.pop();
        if (vis[p.second] == 1)
            continue;
        vis[p.second] = 1;
        vs_added++;
        ans += p.first;
        for (auto it : adj[p.second]) {
            if (!vis[it.first])
                min_heap.push(make_pair(it.second, it.first));
        }
    }
    if (vs_added != n)
        return -1;
    else
        return ans;
}
