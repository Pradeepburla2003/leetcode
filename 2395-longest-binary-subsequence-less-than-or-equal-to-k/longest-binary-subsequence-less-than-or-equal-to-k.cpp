class Solution {
public:
    int help(string &s, int k, int i, int sum, int cnt, vector<vector<int>> &dp) {
        if (sum > k || i < 0) return 0;
        if (dp[i][cnt] != -1) return dp[i][cnt];

        long long temp = 0;
        if (s[i] == '1') {
            if (cnt >= 31) temp = (1LL << 31); // fixed large value
            else temp = 1LL << cnt;
        }

        int pick = INT_MIN;
        if (sum + temp <= k)
            pick = 1 + help(s, k, i - 1, sum + temp, cnt + 1, dp);
        int nonpick = help(s, k, i - 1, sum, cnt, dp);

        return dp[i][cnt] = max(pick, nonpick);
    }

    int longestSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return help(s, k, n - 1, 0, 0, dp);
    }
};
