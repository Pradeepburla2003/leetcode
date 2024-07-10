class Solution {
public:
    int minOperations(vector<string>& logs) {
        string temp="";
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="./") continue;
            else if(logs[i]=="../") {if(temp.size()>0) temp.pop_back();}
            else temp.push_back('1');
            // cout<<temp.size()<<" ";
        }
        return temp.size();
    }
};