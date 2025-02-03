class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int count=1,i=1;
        while(i<nums.size()){
            if(nums[i]>nums[i-1]){
                while(i<nums.size() && nums[i]>nums[i-1]){
                    i+=1;
                    count+=1;
                }
                ans=max(count,ans);
                count=1;
            }
            else if(nums[i]<nums[i-1]){
                while(i<nums.size() && nums[i]<nums[i-1]){
                    i+=1;
                    count+=1;
                }
                ans=max(ans,count);
                count=1;
            }
            else{
                i+=1;
            }
        }
        return ans;
    }
};