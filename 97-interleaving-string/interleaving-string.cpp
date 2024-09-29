class Solution {
public:
    bool help(string s1, string s2, string s3, int i, int j, int k, vector<vector<vector<int>>>& dp) {
        if (k == s3.size()) return true;
        if (dp[i][j][k] != -1) return dp[i][j][k];
        bool comp1 = false, comp2 = false;
        if (i < s1.size() && s1[i] == s3[k]) {
            comp1 = help(s1, s2, s3, i + 1, j, k + 1, dp);
        }
        if (j < s2.size() && s2[j] == s3[k]) {
            comp2 = help(s1, s2, s3, i, j + 1, k + 1, dp);
        }
        return dp[i][j][k] = comp1 || comp2;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, -1)));
        return help(s1, s2, s3, 0, 0, 0, dp);
    }
};
