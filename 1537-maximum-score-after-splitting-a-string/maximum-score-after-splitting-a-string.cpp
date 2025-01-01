class Solution {
public:
    int maxScore(string s) {
        int ans = 0,z = 0, o = 0,n=s.size()-1;
        vector<int>zeros(s.size()),ones(s.size());
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') z+=1;
            if(s[n-i]=='1') o+=1;
            zeros[i]=z;
            ones[n-i]=o;
        }
        for(int i=0;i<s.size()-1;i++){
            ans=max(ans,zeros[i]+ones[i+1]);
        }
        return ans;
    }
};