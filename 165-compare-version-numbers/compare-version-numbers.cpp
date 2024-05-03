class Solution {
public:
    int compareVersion(string version1, string version2) {
        string s1="",s2="";
        int i=0,c=0;
        vector<int>v1,v2;
        while(i<version1.size()){
            if(version1[i]=='.' or (c==0 && version1[i]=='0')){
                if(version1[i]=='.'){
                    if(s1=="") v1.push_back(0);
                    else v1.push_back(stoi(s1));
                    s1="";
                }
                c=0;
            }
            else{
                s1+=version1[i];
                c=1;
            }
            i+=1;
        }
        i=0,c=0;
        while(i<version2.size()){
            if(version2[i]=='.' or (c==0 && version2[i]=='0')){
                if(version2[i]=='.'){
                    if(s2=="") v2.push_back(0);
                    else v2.push_back(stoi(s2));
                     s2="";
                }
                c=0;
            }
            else{
                s2+=version2[i];
                c=1;
            }
            i+=1;
        }
        if(s1!="") v1.push_back(stoi(s1));
        else v1.push_back(0);
        if(s2!="") v2.push_back(stoi(s2));
        else v2.push_back(0);
        for(i=0;i<v1.size() && i<v2.size();i++){
            if(v1[i]<v2[i]) return -1;
            if(v1[i]>v2[i]) return 1;
        }
        // cout<<"hi"<<v1.size()<<" "<<v2.size()<<endl;
        if(v1.size()>v2.size()){
            while(i<v1.size() && v1[i]==0) i+=1;
            if(i<v1.size()) return 1;
        }
        else if(v1.size()<v2.size()){
            while(i<v2.size() && v2[i]==0) i+=1;
            // cout<<i<<endl;
            if(i<v2.size()) return -1;
        }
        return 0;
    }
};