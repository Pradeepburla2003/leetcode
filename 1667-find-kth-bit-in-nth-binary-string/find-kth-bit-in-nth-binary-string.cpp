class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        while(s.size()<k){
            string temp = s;
            s += '1';
            for(int i=temp.size()-1;i >=0; i--){
                if(temp[i] == '0') s += '1';
                else s += '0';
            }
        }
        return s[k-1];
    }
};