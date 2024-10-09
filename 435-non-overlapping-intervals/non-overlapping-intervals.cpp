class Solution {
public:
    static bool comp(vector<int>&val1,vector<int>&val2){
        if(val1[1]<val2[1]) return 1;
        return 0;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(),intervals.end(),comp);
        int lastend = INT_MIN;
        for(auto it : intervals){
            if(it[0] >= lastend){
                lastend = it[1];
            }
            else count++;
        }
        return count;
    }
};