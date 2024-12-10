class Solution {
public:
    int maximumLength(string s) {
        int ans = -1;
        vector<vector<int>>vc(26);
        vector<int>temp;
        int prev = s[0] - 'a';
        int cnt = 1;
        for(int i=1;i<s.size();i++){
            int curr = s[i] - 'a';
            if(prev == curr) cnt++;
            else{
                vc[prev].push_back(cnt);
                cnt = 1;
            }
            prev = curr;
        }
        vc[prev].push_back(cnt);
        for(auto it:vc){
            temp = it;
            int size = temp.size();
            sort(temp.begin(),temp.end());
            if(size==1){
                if (temp[0] >= 3) ans = max(ans, temp[0] - 2);
            }
            else if(size>1){
                if(size>=3){
                    ans = max(ans,max(temp[size-1]-2,temp[size-3]));
                    if(temp[size-2]==temp[size-1]) ans = max(ans,temp[size-2]-1);
                    else ans = max(ans,temp[size-2]);
                }
                else if(size==2){
                    if(temp[size-1]>2){
                        ans = max(ans,temp[1]-2);
                        if(temp[0]==temp[1]) ans = max(ans,temp[0]-1);
                        else ans = max(ans,temp[0]);
                    }
                    else if(temp[size-1]==2) ans = max(ans,1);
                }
            }
        }
        return ans;
    }
};