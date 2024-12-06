class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int,int>mp;
        for(int i=0;i<banned.size();i++){
            mp[banned[i]]++;
        }
        int i = 1,c = 0,sum = 0;
        while(i<=n){
            if(sum+i> maxSum) break;
            if(mp.find(i)==mp.end()){
                c += 1;
                sum += i;
                // cout<<i<<endl;
            }
            cout<<sum<<endl;
            i+=1;
        }
        return c;
    }
};