/*
Returns Cycle in form of vector if exist or empty vector.
use 0 based adj and it returns 0 based path.
*/

vector<int> cycle_detection_dfs(vector<vector<int>> &adj) {
    int n = adj.size();
    int start = -1, end;
    vector<int> par(n);
    vector<int> vis(n);
    auto dfs = [&](auto && dfs, int node, int parent) -> void {
        vis[node] = 1;
        par[node] = parent;
        for (auto it : adj[node]) {
            if (it == parent)
                continue;
            if (vis[it]) {
                if (start == -1) {
                    start = node;
                    end = it;
                }
                return;
            } else {
                dfs(dfs, it, node);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            dfs(dfs, i, -1);
            if (start != -1)
                break;
        }
    }
    if (start == -1)
        return {};

    vector<int> ans;
    ans.emplace_back(start);
    while (ans.back() != end) {
        ans.emplace_back(par[ans.back()]);
    }
    ans.emplace_back(start);
    return ans;
}
