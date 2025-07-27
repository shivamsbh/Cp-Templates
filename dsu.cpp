struct DS {
    vector<int> par, sizz;
    int no_comp, max_csize = 1;
    DS(int n) : par(n), sizz(n, 1) {
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
