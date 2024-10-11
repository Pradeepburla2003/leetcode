class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long prefix = 1,suffix = 1,res = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            res = max(res,max(prefix,suffix));
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
        }
        return res;
    }
};