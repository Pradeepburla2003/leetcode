class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> unique(nums.begin(), nums.end());
        int k = unique.size(); // total distinct elements

        unordered_map<int, int> freq;
        int count = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            freq[nums[right]]++;

            // shrink window from left while it contains all k unique elements
            while (freq.size() == k) {
                // all subarrays from left to end (right) are valid
                count += (n - right);
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }
        }

        return count;
    }
};
