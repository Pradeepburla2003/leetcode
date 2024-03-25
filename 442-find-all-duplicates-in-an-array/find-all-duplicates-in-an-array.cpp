class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>vec(n+1,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            vec[nums[i]]++;
            if(vec[nums[i]]>1) ans.push_back(nums[i]);
        }
        return ans;
    }
};