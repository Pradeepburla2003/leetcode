class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int ans = INT_MAX,temp = 0;
        vector<int>time;
        for(auto i:timePoints){
            int hour = stoi(i.substr(0,2));
            int minutes = stoi(i.substr(3,2));
            int total_minutes = hour * 60 + minutes;
            time.push_back(total_minutes);
        }
        int n = time.size();
        for(int i=0; i<n-1; i++){
            ans = min(time[i+1] - time[i],ans);
        }
        int last = 24 * 60 - time[n-1] + time[0];
        ans = min(last,ans);
        return ans;
    }
};