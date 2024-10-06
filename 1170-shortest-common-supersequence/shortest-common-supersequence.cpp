class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,0));
        int m = str1.size(),n=str2.size();
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(str1[i] == str2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        int i=0,j=0,k=0;
        string s;
        while(i<m && j<n){
            if(str1[i] == str2[j]){
                s += str1[i];
                i++;
                j++;
            }
            else{
                if(dp[i+1][j] > dp[i][j+1]){
                    s+=str1[i];
                    i++;
                }
                else{
                    s+=str2[j];
                    j++;
                }
            }
        }
        while(i<m) s+=str1[i++];
        while(j<n) s+=str2[j++];
        return s;
    }
};