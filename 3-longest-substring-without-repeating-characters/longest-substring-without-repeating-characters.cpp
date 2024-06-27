class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[200]={0};
        int i=0,j=0,n=s.size(),ans=0;
        while(j<n){
            if(arr[s[j]-' ']){
                int k=j-i;
                cout<<arr[s[j]-' ']<<" "<<s[j]<<endl;
                ans=max(ans,k);
                while(i<j && s[i]!=s[j]){
                    arr[s[i]-' ']=0;
                    i++;
                }
                // arr[]=0;
                i++;
            }
            arr[s[j]-' ']=1;
            j++;
        }
        ans=max(ans,j-i);
        return ans;
    }
};