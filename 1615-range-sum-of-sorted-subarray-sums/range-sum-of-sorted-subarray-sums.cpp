class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        map<int,int>mp;
        int ans=0,mod=1e9+7;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                mp[sum]++;
            }
        }
        int c=0,found=0;
        for(auto i:mp){
            cout<<i.first<<" "<<i.second<<endl;
        }
        for(auto i:mp){
            if(found){
                if(c+i.second>right){
                    ans=(ans%mod+((right-c)*(i.first))%mod)%mod;
                    break;
                }
                ans=(ans%mod+(i.second*i.first)%mod)%mod;
                c+=i.second;
                cout<<ans<<endl;
            }
            else{
                if(i.second+c>=left){
                    found=1;
                    c+=i.second;
                    if(right<=c){
                        ans=(ans%mod+((right-left+1)*i.first)%mod)%mod;
                        cout<<ans<<endl;
                        break;
                    }
                    ans=(ans%mod+((c-left+1)*i.first)%mod)%mod;
                    cout<<ans<<endl;
                }
                else{
                    c+=i.second;
                }
            }
        }
        return ans;
    }
};