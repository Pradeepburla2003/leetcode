class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int mod = 1e9 + 7;
        for(i=0;i<s.size();i++){
            if(s[i] != ' ') break;
        }
        int sym = 1;
        if(!isdigit(s[i])){
            if(s[i] == '-') sym = -1;
            else if(s[i] != '+') return 0;
            i+=1;
        }
        while(i<s.size() && s[i] == '0') i++;
        int num = 0;
        while(i<s.size() && isdigit(s[i])){
            int digit = s[i] - '0';
            if(num > (INT_MAX - digit) / 10){
                return (sym == 1) ? INT_MAX : INT_MIN;
            }
            num = num * 10 + digit;
            i++;
        }
        num *= sym;
        return num;
    }
};