class Solution {
public:
    vector<int> par;
    vector<int> rnk;

    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unionbyrnk(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) {
            return;
        }

        if (rnk[pu] == rnk[pv]) {
            par[pv] = pu;
            rnk[pu]++;
        }
        else if (rnk[pu] > rnk[pv]) {
            par[pv] = pu;
        }
        else {
            par[pu] = pv;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        par.resize(n);
        rnk.assign(n, 0);

        for (int i = 0; i < n; i++) {
            par[i] = i;
        }

        int components = n;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {

                    int pi = find(i);
                    int pj = find(j);

                    if (pi != pj) {
                        unionbyrnk(i, j);
                        components--;
                    }
                }
            }
        }

        return n - components;
    }
};