class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=customers[0][1],time=customers[0][0]+customers[0][1],n=customers.size();
        for(int i=1;i<n;i++){
            if(customers[i][0]>=time){
                ans+=(customers[i][1]);
                time=customers[i][0]+customers[i][1];
            }
            else{
                time+=(customers[i][1]);
                ans+=(time-customers[i][0]);
            }
            cout<<time<<" "<<ans<<endl;
        }
        return ans/n;
    }

};