class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans = 0,i=0,j=0;
        while(i<g.size() && j<s.size()){
            if(g[i]<=s[j]){
                ans+=1;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};