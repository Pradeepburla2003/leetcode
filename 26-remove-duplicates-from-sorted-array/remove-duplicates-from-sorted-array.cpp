class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans;
        int k=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==1) ans.push_back(nums[i]);
        }
        nums=ans;
        return ans.size();
    }
};