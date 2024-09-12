class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>vc1(26,0);
        for(int i=0; i<allowed.size(); i++){
            vc1[allowed[i]-'a']++;
        }
        int ans = 0;
        for(int i=0; i<words.size(); i++){
            int flag = 0;
            for(int j=0; j<words[i].size(); j++){
                if(vc1[words[i][j]-'a'] == 0){
                    // cout<<words[i][j]<<" "<<vc1[words[i][j]-'a']<<" ";
                    flag = 1;
                    break;
                }
            }
            // cout<<flag<<endl;
            if(flag == 0) ans++;
        }
        return ans;
    }

};