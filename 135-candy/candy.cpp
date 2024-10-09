class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>left(n),right(n);
        for(int i=0; i<ratings.size(); i++){
            if(i==0 or ratings[i]<=ratings[i-1]) left[i] = 1;
            else left[i] = left[i-1] + 1;
            if(i==0 or ratings[n-i-1]<=ratings[n-i]) right[n-i-1] = 1;
            else right[n-i-1] = right[n-i] + 1;
            cout<<left[i]<<" "<<right[n-i-1]<<endl;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += max(left[i],right[i]);
        }
        return ans;
    }
};