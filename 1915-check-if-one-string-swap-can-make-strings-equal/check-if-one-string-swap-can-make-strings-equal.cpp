class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        int flag=0;
        vector<int>temp;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                flag++;
                temp.push_back(i);
            }
        }
        if(flag==0) return true;
        if(flag%2 or flag>2) return false;
        string t1=s1,t2=s2;
        t1[temp[0]]=s1[temp[1]];
        t1[temp[1]]=s1[temp[0]];
        if(t1==s2) return true;
        t2[temp[0]]=s2[temp[1]];
        t2[temp[1]]=s2[temp[0]];
        if(t2==s1) return true;
        return false;
    }
};