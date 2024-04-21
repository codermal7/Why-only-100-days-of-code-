class Solution {
    struct DSU {
        vector<int> par, rank;

        DSU(int n) {
            par.resize(n);
            iota(par.begin(), par.end(), 0);
            rank.assign(n, 1);
        }

        int find(int x) {
            if (par[x] != x) {
                par[x] = find(par[x]);
            }
            return par[x];
        }

        bool doUnion(int n1, int n2) {
            int p1 = find(n1);
            int p2 = find(n2);

            if (p1 == p2) {
                return false;
            }
            if (rank[p1] < rank[p2])
                swap(p1, p2);

            rank[p1] += rank[p2];
            par[p2] = p1;

            return true;
        }

        bool same(int n1, int n2) { return find(n1) == find(n2); }
    };

public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        DSU dsu(n);
        for (auto edge : edges) {
            dsu.doUnion(edge[0], edge[1]);
        }

        return dsu.same(source, destination);
    }
};