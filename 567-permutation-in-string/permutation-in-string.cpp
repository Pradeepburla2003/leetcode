class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<long>temp(26);
        if(s1.size()>s2.size()) return false;
        for(int i=0;i<s1.size();i++){
            temp[s1[i]-'a']++;
        }
        int i=0,j=0,n=s2.size();
        long count=0;
        while(j<n){
            cout<<count<<endl;
            if(count==s1.size()) return true;
            if(temp[s2[j]-'a']==0){
                while(i<j && s2[i]!=s2[j]){
                    temp[s2[i]-'a']++;
                    count--;
                    i++;
                }
                if(i==j) i=j+1;
                else i+=1;
            }
            else{
                temp[s2[j]-'a']--;
                count++;
            }
            j++;
        }
        return (count==s1.size());
    }
};