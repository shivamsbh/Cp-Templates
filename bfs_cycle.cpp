/*
returns cycle in vector if exist or empty vector.pls use 0 based input and
expect 0 based output
*/
 
/*void remove_edge(vector<vector<int>> &adj, int u, int v) {
    adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
    adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
}*/
 
vector<int> spbfs_(vector<vector<int>> &adj, int src, int des) {
    int n = adj.size();
    vector<int> vis(n), par(n), dis(n, INT_MAX);
    dis[0] = 0;
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    int distance = -1;
    while (!q.empty()) {
        distance++;
        int loop = q.size();
        for (int i = 0; i < loop; i++) {
            int node = q.front();
            q.pop();
            dis[node] = min(dis[node], distance);
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    q.push(it);
                    par[it] = node;
                    vis[it] = 1;
                }
            }
        }
    }
    if (dis[des] == INT_MAX)
        return {};
    vector<int> ans;
    ans.emplace_back(des);
    while (ans.back() != src) {
        ans.emplace_back(par[ans.back()]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
 
vector<int> cycle_bfs(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> vis(n), par(n);
    int start = -1, end;
    auto bfs = [&](int node) {
        queue<int> q;
        q.push(node);
        par[node] = -1;
        while (!q.empty()) {
            int curNode = q.front();
            q.pop();
            vis[curNode] = 1;
            for (auto it : adj[curNode]) {
                if (it == par[curNode])
                    continue;
                else if (vis[it]) {
                    start = curNode;
                    end = it;
                    remove_edge(adj, end, start);  // Note: You need to define the remove_edge function.
                    return;
                } else {
                    q.push(it);
                    par[it] = curNode;
                }
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            bfs(i);
        }
        if (start != -1)
            break;
    }
    if (start == -1)
        return {};
    vector<int> ans = spbfs_(adj, start, end);
    return ans;
}
