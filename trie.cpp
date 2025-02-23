const int MAX_C = 26;
const int MAX_S = 1e6 + 1;

int Trie[MAX_S][MAX_C], cnt[MAX_S];
int num = 0;

void insert(string s) {
    int u = 0;
    for (char c : s) {
        if (!Trie[u][c - 'A'])
            Trie[u][c - 'A'] = ++num;
        u = Trie[u][c - 'A'];
    }
    cnt[u]++;
}

bool search(string s) {
    int u = 0;
    for (char c : s) {
        if (!Trie[u][c - 'A'])
            return false;
        u = Trie[u][c - 'A'];
    }
    return cnt[u] > 0;
}

// Reset between test cases
void reset() {
    memset(Trie, 0, sizeof(Trie));
    memset(cnt, 0, sizeof(cnt));
    num = 0;
}
