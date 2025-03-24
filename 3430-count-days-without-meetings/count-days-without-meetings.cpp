class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int ans=0,flag=0;
        int maxi=meetings[0][1];
        ans+=meetings[0][0]-1;
        for(int i=1;i<meetings.size();i++){
            if(meetings[i][0]>maxi){
                ans+=meetings[i][0]-maxi-1;
            }
            maxi=max(maxi,meetings[i][1]);
        }
        if(maxi<days) ans+=days-maxi;
        return ans;
    }
};