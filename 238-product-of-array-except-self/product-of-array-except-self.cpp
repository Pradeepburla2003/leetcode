class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum=1,c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) sum=sum*nums[i];
            else c+=1;
        }
        // vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(c>1) nums[i]=(0);
            else if(nums[i]==0) nums[i]=sum;
            else if(c>0) nums[i]=0;
            else nums[i]=sum/nums[i];
        }
        return nums;
    }
};