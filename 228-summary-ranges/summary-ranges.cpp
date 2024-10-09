class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        if(nums.size() == 0) return ans;
        int start = nums[0],n = nums.size();
        string s = "";
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]+1){
                if(start != nums[i-1]) s = to_string(start) + "->" + to_string(nums[i-1]);
                else s = to_string(start);
                ans.push_back(s);
                start = nums[i];
            }
        }
        if(start != nums[n-1]) s = to_string(start) + "->" + to_string(nums[n-1]);
        else s = to_string(start);
        ans.push_back(s);
        return ans;
    }
};