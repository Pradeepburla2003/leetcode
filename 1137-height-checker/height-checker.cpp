class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans=0,n=heights.size();
        vector<int>temp(heights.begin(),heights.end());
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;i++){
            if(temp[i]!=heights[i]) ans++;
        }
        return ans;
    }
};