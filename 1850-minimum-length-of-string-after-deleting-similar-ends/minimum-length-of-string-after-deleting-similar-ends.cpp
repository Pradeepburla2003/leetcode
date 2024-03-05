class Solution {
public:
    int minimumLength(string s) {
        int start=0,end=s.size()-1,ans=s.size(),count1,count2;
        char s1,s2;
        while(start<end){
           s1=s[start];
            s2=s[end];
            if(s1!=s2) return ans;
            start+=1;
            end-=1;
            count1=1,count2=1;
            while(start<=end && s[start]==s1){
                start++;
                count1++;
            }
            // if(start==end) return 0;
            while(end>start && s[end]==s2){
                end--;
                count2+=1;
            }
    
            cout<<start<<" "<<end<<"----"<<count1<<" "<<count2<<endl;
            ans-=(count1+count2);
            cout<<ans<<endl;
        }
        return ans;
    }
};