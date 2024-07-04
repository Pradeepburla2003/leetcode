class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0,j=0,n=haystack.size(),m=needle.size();
        if(m>n) return -1;
        while(i<=n-m){
            cout<<needle<<" ";
            if(haystack[i]==needle[0]){
                int k=i;
                j=0;
                while(j<m and k<n){
                    if(needle[j]!=haystack[k]){
                        break;
                    }
                    cout<<needle[j];
                    j++;
                    k++;
                }
                if(j==needle.size()) return i;
            }
            i++;
        }
        return -1;
    }
};