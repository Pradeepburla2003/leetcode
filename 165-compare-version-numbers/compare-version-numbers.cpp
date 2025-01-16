class Solution {
public:
    void help(string version1,vector<int>&v){
        int temp=0;
        for(int i=0;i<version1.size();i++){
            if(version1[i]=='.'){
                v.push_back(temp);
                temp=0;
            }
            else{
                if(temp==0 && version1[i]=='0') continue;
                temp=temp*10+(version1[i]-'0');
            }
        }
        v.push_back(temp);
    }
    int compareVersion(string version1, string version2) {
        vector<int>v1,v2;
        help(version1,v1);
        help(version2,v2);
        int size=min(v1.size(),v2.size());
        int i;
        for(i=0;i<size;i++){
            if(v1[i]>v2[i]) return 1;
            if(v1[i]<v2[i]) return -1;
        }
        for(int j=i;j<v1.size();j++){
            if(v1[j]!=0) return 1;
        }
        for(int j=i;j<v2.size();j++){
            if(v2[j]!=0) return -1;
        }
        return 0;
    }
};