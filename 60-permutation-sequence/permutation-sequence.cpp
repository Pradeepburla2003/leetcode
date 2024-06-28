class Solution {
public:
    void fun(string s,vector<int>&v,int n,vector<string>&temp){
        // cout<<s<<endl;
        if(s.size()==n){
            temp.push_back(s);
            return ;
        }
        for(int i=1;i<=n;i++){
            if(v[i]==0){
                v[i]=1;
                s.push_back(i+'0');
                fun(s,v,n,temp);
                v[i]=0;
                s.pop_back();
            }
        }
    }
    string getPermutation(int n, int k) {
        string s="";
        vector<int>v(n+1,0);
        vector<string>temp;
        fun(s,v,n,temp);
        return temp[k-1];
    }
};