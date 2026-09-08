class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        int m = hats[0].size();

        int mod = 1e9 + 7;

        vector<vector<int>> peoples(41);

        for (int i = 0; i < n; i++) {
            for (auto& hat : hats[i]) {
                peoples[hat].push_back(i);
            }
        }

        int dp[41][1 << 10];
        function<int(int, int)> solve = [&](int idx, int mask) -> int {
            if (idx == 41)
                return (__builtin_popcount(mask) == n);
            if (dp[idx][mask] != -1)
                return dp[idx][mask];

            long long count = solve(idx + 1, mask);

            for (int p : peoples[idx]) {

                if (mask & (1 << p))
                    continue;

                count = (count + solve(idx + 1, mask | (1 << p))) % mod;
            }

            return dp[idx][mask] = count;
        };

        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};