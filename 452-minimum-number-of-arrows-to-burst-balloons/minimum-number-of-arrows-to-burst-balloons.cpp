class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans = 1;
        vector<int>temp = points[0];
        for(int i=1; i<points.size(); i++){
            if(temp[1] < points[i][0]){
                ans += 1;
                temp = points[i];
            }
            else{
                temp[1] = min(temp[1],points[i][1]);
            }
        }
        return ans;
    }
};