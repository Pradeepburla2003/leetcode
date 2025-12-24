class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int m = apple.size(),n=capacity.size();
        int sum=0;
        for(int i=0;i<m;i++){
            sum+=apple[i];
        }
        int cnt=0,sum2=0;
        for(int i=0;i<capacity.size();i++){
            sum2+=capacity[i];
            cnt++;
            if(sum2>=sum) return cnt;
        }
        return cnt;
    }
};