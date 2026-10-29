class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0), tin(n), tout(n), sz(n, 1);
        vector<int> mask(n, 0), order;
        order.reserve(n);
        vector<pair<int, int>> st = {{0, 0}};
        while (!st.empty()) {
            auto [u, p] = st.back();
            st.pop_back();

            tin[u] = order.size();
            order.push_back(u);
            up[0][u] = p;
            mask[u] = (u == 0 ? 0 : mask[p]) ^ (1 << (s[u] - 'a'));

            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                st.push_back({v, u});
            }
        }
        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            sz[up[0][u]] += sz[u];
        }

        for (int u = 0; u < n; u++)
            tout[u] = tin[u] + sz[u] - 1;

        for (int j = 1; j < LOG; j++) {
            for (int u = 0; u < n; u++)
                up[j][u] = up[j - 1][up[j - 1][u]];
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];
            for (int j = 0; j < LOG; j++)
                if (diff & (1 << j))
                    u = up[j][u];

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }
            return up[0][u];
        };

        vector<int> bit(n + 1, 0);

        auto add = [&](int idx, int val) {
            for (int i = idx + 1; i <= n; i += i & -i)
                bit[i] ^= val;
        };

        auto rangeUpdate = [&](int l, int r, int val) {
            add(l, val);
            if (r + 1 < n) add(r + 1, val);
        };

        auto get = [&](int idx) {
            int res = 0;
            for (int i = idx + 1; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        };

        vector<bool> ans;

        for (string& q : queries) {
            string op;
            int u, v;
            char c;

            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                ss >> c;

                int delta = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));

                rangeUpdate(tin[u], tout[u], delta);
                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);
                int mu = mask[u] ^ get(tin[u]);
                int mv = mask[v] ^ get(tin[v]);

                int pathMask = mu ^ mv ^ (1 << (s[w] - 'a'));

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }
        return ans;
    }
};