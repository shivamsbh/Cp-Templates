    vector<int> nG(n, n), nS(n, n), pG(n, -1), pSm(n, -1);

    // Compute next greater elements
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && v[st.top()] < v[i]) {
            nG[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    // Compute next smaller elements
    stack<int> st2;
    for (int i = 0; i < n; ++i) {
        while (!st2.empty() && v[st2.top()] > v[i]) {
            nS[st2.top()] = i;
            st2.pop();
        }
        st2.push(i);
    }

    // Compute previous greater elements
    stack<int> st3;
    for (int i = n - 1; i >= 0; --i) {
        while (!st3.empty() && v[st3.top()] < v[i]) {
            pG[st3.top()] = i;
            st3.pop();
        }
        st3.push(i);
    }

    // Compute previous smaller elements
    stack<int> st4;
    for (int i = n - 1; i >= 0; --i) {
        while (!st4.empty() && v[st4.top()] > v[i]) {
            pSm[st4.top()] = i;
            st4.pop();
        }
        st4.push(i);
    }
