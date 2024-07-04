/*
it returns a negative cycle if there or else a empty vector
if you want dist then return the dis vector
use 0 based input and expect 0 based output
*/

vector<int> BellmanFord(vector<vector<pair<int, int>>> &adj) {
	int n = adj.size();
	vector<int> dis(n);
	vector<int> par(n);
	dis[0] = 0;
	vector<int> changed;
	for (int i = 0; i < n; i++) {
		changed.clear();
		for (int node = 0; node < n; node++) {
			for (auto it : adj[node]) {
				int intialdistance = dis[node];
				int to_be_distance = intialdistance + it.second;
				if (to_be_distance < dis[it.first]) {
					par[it.first] = node;
					dis[it.first] = to_be_distance;
					changed.emplace_back(it.first);
				}
			}
		}
	}
	if (changed.size() == 0)
		return {};
	int suspectedNode = changed[0];
	for (int i = 0; i < n; i++)
		suspectedNode = par[suspectedNode];
	vector<int> ans;
	ans.emplace_back(suspectedNode);
	while (true) {
		ans.emplace_back(par[ans.back()]);
		if (ans.size() != 1 && ans.back() == suspectedNode)
			break;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
