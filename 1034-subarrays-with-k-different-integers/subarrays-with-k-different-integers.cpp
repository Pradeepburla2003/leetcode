class Solution {
public:
    int fun(vector<int>& nums, int k){
        int left = 0,right = 0,n = nums.size(),count = 0;
        unordered_map<int,int>freq;
        while(right < n){
            freq[nums[right]]++;
            while(freq.size() > k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            count += (right - left + 1);
            right++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k) - fun(nums,k-1);
    }
};