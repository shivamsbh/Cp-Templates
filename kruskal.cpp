/*
use 0 based indexing please
*/
struct DSK {
	vector<int> par, sizz;
	int no_comp, max_csize = 1;
	DSK(int n) : par(n), sizz(n, 1) {
		iota(par.begin(), par.end(), 0);
		no_comp = n;
	}
	int leader(int x) {
		if (par[x] == x)
			return x;
		else
			return (par[x] = leader(par[x]));
	}
	bool is_connected(int x, int y) {
		return (leader(x) == leader(y));
	}
	int size(int x) {
		return sizz[leader(x)];
	}
	bool merge(int x, int y) {
		int x_ = leader(x);
		int y_ = leader(y);
		if (x_ == y_)
			return false;
		no_comp--;
		if (size(x_) < size(y_))
			swap(x_, y_);
		sizz[x_] += sizz[y_];
		max_csize = max(max_csize, sizz[x_]);
		par[y_] = leader(x_);
		return true;
	}
};

int Kruskal(int n, vector<vector<pair<int, int>>> &adj) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> min_heap;
	for (int i = 0; i < n; i++) {
		for (auto it : adj[i]) {
			min_heap.push(make_pair(it.second, make_pair(i, it.first)));
		}
	}
	DSK ds(n);
	int ans = 0;
	while (!min_heap.empty()) {
		pair < int, pair<int, int>> p = min_heap.top();
		min_heap.pop();
		if (ds.merge(p.second.first, p.second.second))
			ans += p.first;
		if (ds.no_comp == 1)
			break;
	}
	if (ds.no_comp != 1)
		return -1;
	else
		return ans;
}
