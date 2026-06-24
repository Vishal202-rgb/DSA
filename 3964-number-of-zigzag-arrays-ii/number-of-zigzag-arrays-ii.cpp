class Solution {
public:
    static const int MOD = 1000000007;
    using ll = long long;

    struct Matrix {
        vector<vector<ll>> a;
        Matrix(int n) {
            a.assign(n, vector<ll>(n, 0));
        }
    };
    Matrix multiply(const Matrix &A, const Matrix &B) {
        int sz = A.a.size();
        Matrix C(sz);

        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (A.a[i][k] == 0) continue;
                for (int j = 0; j < sz; j++) {
                    if (B.a[k][j] == 0) continue;
                    C.a[i][j] =
                        (C.a[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
                }
            }
        }
        return C;
    }
    Matrix power(Matrix base, long long exp) {
        int sz = base.a.size();
        Matrix res(sz);
        for (int i = 0; i < sz; i++)
            res.a[i][i] = 1;

        while (exp > 0) {
            if (exp & 1)
                res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int S = 2 * m;

        Matrix T(S);

        for (int last = 0; last < m; last++) {
            for (int nxt = last + 1; nxt < m; nxt++) {
                T.a[m + nxt][last] = 1;
            }
            for (int nxt = 0; nxt < last; nxt++) {
                T.a[nxt][m + last] = 1;
            }
        }

        vector<ll> init(S, 0);
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < m; b++) {
                if (a == b) continue;
                if (b > a)
                    init[m + b]++;
                else
                    init[b]++;
            }
        }
        Matrix P = power(T, n - 2);

        vector<ll> ansVec(S, 0);
        for (int i = 0; i < S; i++) {
            if (init[i] == 0) continue;
            for (int j = 0; j < S; j++) {
                ansVec[j] =
                    (ansVec[j] + init[i] * P.a[j][i]) % MOD;
            }
        }
        ll ans = 0;
        for (ll x : ansVec)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};