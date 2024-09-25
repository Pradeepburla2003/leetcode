class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0,start = 0,n=s.size();
        vector<int>chr = {-1,-1,-1};
        for(int i=0; i<n; i++){
            chr[s[i] - 'a'] = i;
            if(chr[0] != -1 && chr[1] != -1 && chr[2] != -1){
                ans += 1 + min(chr[0],min(chr[1],chr[2]));
            }
        }
        return ans;
    }
};