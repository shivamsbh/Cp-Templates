/*
use 0 based indexing please
*/
/*template<class T>         bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }*/

struct DSK {
	vector<int> par, sizz;
	int no_comp, max_csize = 1;
	DSK(int n): par(n), sizz(n, 1) {
		iota(par.begin(), par.end(), 0);
		no_comp = n;
	}
	int leader(int x) {
		if (par[x] == x)
			return x;
		return (par[x] = leader(par[x]));
	}
	bool is_connected(int x, int y) {
		return (leader(x) == leader(y));
	}
	int size(int x) {
		return sizz[leader(x)];
	}
	bool merge(int x, int y) {
		int xpar = leader(x);
		int ypar = leader(y);
		if (xpar == ypar)
			return false;
		no_comp--;
		if (size(xpar) < size(ypar))
			swap(xpar, ypar);
		sizz[xpar] += sizz[ypar];
		par[ypar] = xpar;
		ckmax(max_csize, size(xpar)); 
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
