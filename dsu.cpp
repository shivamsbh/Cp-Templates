struct DS {
	vector<int> par, sizz;
	int no_comp, max_csize = 1;
	DS(int n): par(n), sizz(n, 1) {
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
