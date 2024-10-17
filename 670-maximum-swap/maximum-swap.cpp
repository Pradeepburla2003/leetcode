class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int ind = 0;
        for(int i=0;i<s.size();i++){
            char maxi = '0';
            int found = 0;
            for(int j=i+1;j<s.size();j++){
                if(s[i]<s[j] && s[j] >= maxi){
                    maxi = max(maxi,s[j]);
                    ind = j;
                    found = 1;
                }
            }
            if(found){
                swap(s[i],s[ind]);
                break;
            }
        }
        num = stoi(s);
        return num;
    }
};