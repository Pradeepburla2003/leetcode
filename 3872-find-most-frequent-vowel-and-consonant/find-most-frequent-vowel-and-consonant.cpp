class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>ch(26);
        for(auto i:s){
            ch[i-'a']++;
        }
        int maxi=0,maxi2=0;
        for(int i=0;i<26;i++){
            if(i==0 or i==4 or i==8 or i==14 or i==20) maxi=max(ch[i],maxi);
            else maxi2=max(ch[i],maxi2);
        }
        return maxi+maxi2;
    }
};