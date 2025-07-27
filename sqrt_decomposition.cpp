struct SqrtLazy {
    vector<long long> arr, blocks, lazy;
    vector<bool> isLazy; // Tracks if block has pending updates
    int n, block_size;

    SqrtLazy(vector<long long>& a) {
        arr = a;
        n = a.size();
        block_size = sqrt(n) + 1;
        int num_blocks = (n + block_size - 1) / block_size;

        blocks.resize(num_blocks, 0);
        lazy.resize(num_blocks, 0);
        isLazy.resize(num_blocks, false);

        // Precompute block sums
        for (int i = 0; i < n; i++) {
            blocks[i / block_size] += arr[i];
        }
    }

    // Resolve lazy values for a specific block
    void resolve(int block_idx) {
        if (!isLazy[block_idx]) return;

        long long add_val = lazy[block_idx];
        int start = block_idx * block_size;
        int end = min((block_idx + 1) * block_size, n);

        // Apply lazy update to all elements in the block
        for (int i = start; i < end; i++) {
            arr[i] += add_val;
        }

        // Update block sum
        blocks[block_idx] += add_val * (end - start);

        // Reset lazy
        lazy[block_idx] = 0;
        isLazy[block_idx] = false;
    }

    // Range update: add 'x' to all elements in [l, r]
    void update(int l, int r, long long x) {
        int start_block = l / block_size;
        int end_block = r / block_size;

        // 1. Left partial block
        if (start_block == end_block) {
            resolve(start_block);
            for (int i = l; i <= r; i++) {
                arr[i] += x;
                blocks[start_block] += x;
            }
            return;
        }

        // 2. Left partial block (resolve first!)
        resolve(start_block);
        for (int i = l; i < (start_block + 1) * block_size; i++) {
            arr[i] += x;
            blocks[start_block] += x;
        }

        // 3. Full blocks (lazy update)
        for (int b = start_block + 1; b < end_block; b++) {
            lazy[b] += x;
            isLazy[b] = true;
            blocks[b] += x * block_size; // Update block sum immediately
        }

        // 4. Right partial block (resolve first!)
        resolve(end_block);
        for (int i = end_block * block_size; i <= r; i++) {
            arr[i] += x;
            blocks[end_block] += x;
        }
    }

    // Range query: sum of elements in [l, r]
    long long query(int l, int r) {
        long long sum = 0;
        int start_block = l / block_size;
        int end_block = r / block_size;

        // 1. Left partial block
        if (start_block == end_block) {
            resolve(start_block);
            for (int i = l; i <= r; i++) sum += arr[i];
            return sum;
        }

        // 2. Left partial block
        resolve(start_block);
        for (int i = l; i < (start_block + 1) * block_size; i++) {
            sum += arr[i];
        }

        // 3. Full blocks (use precomputed sums)
        for (int b = start_block + 1; b < end_block; b++) {
            sum += blocks[b]; // Blocks already include lazy updates!
        }

        // 4. Right partial block
        resolve(end_block);
        for (int i = end_block * block_size; i <= r; i++) {
            sum += arr[i];
        }

        return sum;
    }
};
