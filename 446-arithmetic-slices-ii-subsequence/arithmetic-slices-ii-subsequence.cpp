class Solution {
public:
    typedef long long ll;
    int numberOfArithmeticSlices(vector<int>& nums) {
        ll ans=0,dif;
        vector<unordered_map<ll,ll>>sub;
        unordered_map<ll,ll>maps;
        sub.push_back(maps);
        for(ll i=1;i<nums.size();i++){
            unordered_map<ll,ll>temp;
            for(ll j=0;j<i;j++){
                dif=ll(ll(nums[i])-ll(nums[j]));
                if(sub[j].find(dif)!=sub[j].end()){
                    ll t=sub[j][dif]+1;
                    ans+=sub[j][dif];
                    temp[dif]+=t;
                }
                else{
                    temp[dif]++;
                }
            }
            // for(auto l:temp){
            //     cout<<l.first<<" "<<l.second<<" ";
            // }
            // cout<<endl;
            sub.push_back(temp);
        }
        return int(ans);
    }
};