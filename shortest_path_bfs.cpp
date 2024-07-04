/*
This is a template for shortest path through bfs (use when weight is
equal to 1).(0 based adj list pls!)
it returns shortest path between source and destination in form of vector(0 based).
if the src and des is not connected then it returns empty vector
if you only want shortest dist vector to all nodes from src the return the dis vector
I have ued 0 based indexing here
Prepare adj vector correctly for directed and undirected graphs
*/

vector<int> spbfs(vector<vector<int>> &adj, int src, int des) {
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
