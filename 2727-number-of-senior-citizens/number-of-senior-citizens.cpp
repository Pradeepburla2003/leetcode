class Solution {
public:
    int countSeniors(vector<string>& details) {
       int ans=0;
       for(int i=0;i<details.size();i++){
            int s=stoi(details[i].substr(11,2));
            // int temp=stoi(s);
            if(s>60) ans++;
       } 
       return ans;
    }
};