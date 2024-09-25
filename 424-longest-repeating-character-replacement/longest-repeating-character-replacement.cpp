class Solution {
public:
    int characterReplacement(string s, int k) {
       int n = s.size(), res = 0,left = 0,right = 0,maxfreq = 0;
       vector<int>freq(26,0);
       while(right < n){
            freq[s[right] - 'A']++;
            maxfreq = max(maxfreq,freq[s[right] - 'A']);
            if((right - left + 1 - maxfreq) > k){
                freq[s[left] - 'A']--;
                left++;
            }
            if((right - left + 1 - maxfreq) <= k){
                res = max(res,right - left + 1);
            }
            right++;
       }
       return res;
    }
};