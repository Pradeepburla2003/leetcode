class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>temp(nums.size(),0);
        vector<bool>ans;
        for(int i=1;i<nums.size();i++){
            if(abs(nums[i]-nums[i-1])%2) temp[i]=1;
            temp[i]+=temp[i-1];
        }
        for(int i=0;i<queries.size();i++){
            if(temp[queries[i][1]]-temp[queries[i][0]]==queries[i][1]-queries[i][0]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};