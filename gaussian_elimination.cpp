set<int> getBasisNumbers(const vector<int>& arr) {
    vector<int> basis(31, 0);  // 31 bits for numbers up to 10^9
    
    // Build the basis using Gaussian elimination
    for (int num : arr) {
        for (int i = 30; i >= 0; i--) {
            if ((num >> i) & 1) {
                if (basis[i] == 0) {
                    basis[i] = num;  // Add new basis element
                    break;
                } else {
                    num ^= basis[i];  // Reduce using existing basis
                }
            }
        }
    }
    
    // Collect all non-zero basis elements into a set
    set<int> result;
    for (int i = 0; i < 31; i++) {
        if (basis[i] != 0) {
            result.insert(basis[i]);
        }
    }
    
    return result;
}
