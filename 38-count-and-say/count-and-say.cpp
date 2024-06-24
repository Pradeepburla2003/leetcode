class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string prev="1",ans;
        int i=1;
        while(i<n){
            int count=1,size=prev.size();
            ans="";
            for(int j=1;j<size;j++){
                if(prev[j]!=prev[j-1]){
                    ans+=to_string(count);
                    ans+=prev[j-1];
                    count=1;
                }
                else count++;
            }
            // cout<<ans<<endl;
            ans+=to_string(count);
            ans+=prev[size-1];
            // cout<<ans<<endl;
            prev=ans;
            i++;
        }
        return prev;
    }
};