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

vi Dijikstra(vvpii &adj, int src, int dest) {
    vi relaxed(adj.size());
    vi dis(adj.size(), pinf);
    vi par(adj.size(), -1);
    dis[src] = 0;
    minh<pii> pq;
    pq.push(mp(0, src));
    while (!pq.empty()) {
        int node = pq.top().S;
        int distance = pq.top().F;
        pq.pop();
        if (relaxed[node])
            continue;
        relaxed[node] = 1;
        for (auto it : adj[node]) {
            pii p = it;
            int curNode = it.F;
            int lengthEdge = it.S;
            int updated_length = distance + lengthEdge;
            if (updated_length < dis[curNode]) {
                dis[curNode] = updated_length;
                pq.push(mp(updated_length, curNode));
                par[curNode] = node;
            }
        }
    }
    //return dis;
    if (dis[dest] == pinf)
        return {};
    vi ans;
    ans.eb(dest);
    while (ans.back() != src) {
        ans.eb(par[ans.back()]);
    }
    reverse(ftl(ans));
    return ans;
}
