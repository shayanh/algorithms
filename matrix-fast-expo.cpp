typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;

T power(T x, int k) {
    T ret = 1;

    while (k) {
        if (k & 1)
            ret *= x;
        k >>= 1;
        x *= x;
    }
    return ret;
}

VVT multiply(VVT &A, VVT &B) {
    int n = A.size(), m = A[0].size(), k = B[0].size();
    VVT C(n, VT(k, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            for (int l = 0; l < m; l++)
                C[i][j] += A[i][l] * B[l][j];

    return C;
}

VVT power(VVT &A, int k) {
    int n = A.size();
    VVT ret(n, VT(n)), B = A;
    for (int i = 0; i < n; i++)
        ret[i][i] = 1;

    while (k) {
        if (k & 1)
            ret = multiply(ret, B);
        k >>= 1;
        B = multiply(B, B);
    }
    return ret;
}
