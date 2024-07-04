/*
This is the template for Dijikstra's Algorithm

It returns shortest path(vector<int>) from src to dest if exist or
empty vector if path don't exist

return the dis vector if you need the shortest distance
from the source node (as in parameters) to every other node.

dist is pinf if the respective node is unreachable from
the source node

important-->prepare adj list very carefully for undirected graph
i.e
adj[a].emplace_back(make_pair(b, w));
adj[b].emplace_back(make_pair(a, w));(don't miss it)
*/

vector<int> Dijkstra(vector<vector<pair<int, int>>> &adj, int src, int dest) {
    vector<int> relaxed(adj.size());
    vector<int> dis(adj.size(), pinf);
    vector<int> par(adj.size(), -1);
    dis[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if (relaxed[node])
            continue;

        relaxed[node] = 1;

        for (auto it : adj[node]) {
            pair<int, int> p = it;
            int curNode = it.first;
            int lengthEdge = it.second;
            int updated_length = distance + lengthEdge;

            if (updated_length < dis[curNode]) {
                dis[curNode] = updated_length;
                pq.push(make_pair(updated_length, curNode));
                par[curNode] = node;
            }
        }
    }

    if (dis[dest] == pinf)
        return {};

    vector<int> ans;
    ans.emplace_back(dest);

    while (ans.back() != src) {
        ans.emplace_back(par[ans.back()]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
