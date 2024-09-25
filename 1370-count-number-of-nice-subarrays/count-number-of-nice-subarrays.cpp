class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        freq[0] = 1;
        int total = 0;
        int sum = 0;
        for(auto num:nums){
            if(num % 2 == 1) sum += 1;
            if(freq.find(sum - k) != freq.end()){
                total += freq[sum - k];
            }
            freq[sum]++;
        }
        return total;
    }
};