class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, zeros = 0,start = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 0) zeros++;
            if(zeros > k){
                ans = max(ans,i - start);
                while(nums[start] != 0){
                   start++;
                }
                start++;
                zeros--;
            }
        }
        ans = max(ans,n - start);
        return ans;
    }
};