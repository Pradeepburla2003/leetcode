class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int,int>>in;
        for(auto i:intervals){
            in.push_back({i[0],1});
            in.push_back({i[1]+1,-1});
        }
        sort(in.begin(),in.end());
        int ans = 1,current = 0;
        for(auto it:in){
            current+=it.second;
            ans = max(ans,current);
        }
        return ans;
    }
};