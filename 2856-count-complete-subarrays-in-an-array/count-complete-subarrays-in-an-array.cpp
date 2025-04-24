class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int totalDistinct =st.size();
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            for (int j = i; j < n; j++) {
                freq[nums[j]]++;
                if (freq.size() == totalDistinct) {
                    count++;
                }
            }
        }

        return count;
    }
};
