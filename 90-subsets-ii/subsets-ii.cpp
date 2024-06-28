class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>temp;
        sort(nums.begin(),nums.end());
        int n=nums.size(),k=pow(2,n);
        for(int i=0;i<k;i++){
            vector<int>sub;
            for(int j=0;j<32;j++){
                if((i>>j)&1) sub.push_back(nums[j%n]);
            }
            temp.insert(sub);
        }
        vector<vector<int>> ans;
        for(auto i:temp){
            ans.push_back(i);
        }
        // sort(ans.begin(),ans.end());
        return ans;
    }
};