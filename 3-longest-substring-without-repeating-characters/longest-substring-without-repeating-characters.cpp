class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if(s == "   ") return 1;
        int ans = 0, start = 0, n = s.size();
        vector<int>freq(200,0);
        for(int i=0;i<s.size();i++){
            int index = s[i] - ' ';
            freq[index] += 1;
            if(freq[index]==2){
                ans = max(ans,i - start);
                while(start < i && freq[s[start] - ' '] != 2){
                    freq[s[start] - ' '] = 0;
                    start++;
                }
                freq[s[start] - ' '] = 1;
                start++;
            }
        }
        ans = max(ans,n-start);
        return ans;
    }
};