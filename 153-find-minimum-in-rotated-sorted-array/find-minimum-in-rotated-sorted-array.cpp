class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0,end = nums.size() - 1,ans = INT_MAX;
        while(start <= end){
            int mid = (start + end)/2;
            if(nums[start] <= nums[mid]){
                ans = min(ans,nums[start]);
                start = mid + 1;
            }
            else{
                ans = min(ans,nums[mid]);
                end = mid - 1;
            }
        }
        return ans;
    }
};