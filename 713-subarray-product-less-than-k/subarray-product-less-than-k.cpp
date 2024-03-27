class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int pro=1,ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            pro=1;
            for(int j=i;j<n;j++){
                pro=pro*nums[j];
                if(pro<k) ans+=1;
                else break;
            }
        }
        return ans;
    }
};