vector<int> BellmanFord(int n, vector<int> &dist, vector<vector<pair<int, int>>> &adj) {
    dist[0] = 0;
    vector<int> par(n);
    par[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int a = 0; a < n; a++) {
            for (auto it : adj[a]) {
                int b = it.first;
                int w = it.second;
                if (dist[b] > dist[a] + w) {
                    dist[b] = dist[a] + w;
                    par[b] = a;
                }
            }
        }
    }
    bool chk_ = false;
    int node;
    for (int a = 0; a < n; a++) {
        for (auto it : adj[a]) {
            int b = it.first;
            int w = it.second;
            if (dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
                par[b] = a;
                node = b;
                chk_ = true;
                break;
            }
        }
        if (chk_)
            break;
    }
    if (!chk_)
        return {};
    vector<int> ans;
    for (int i = 0; i < n + 5; i++)
        node = par[node];
    ans.emplace_back(node);
    int x_x = par[node];
    while (true) {
        if (x_x != node)
            ans.emplace_back(x_x);
        else
            break;
        x_x = par[x_x];
    }
    ans.emplace_back(node);
    reverse(ans.begin(), ans.end());
    return ans;
}
