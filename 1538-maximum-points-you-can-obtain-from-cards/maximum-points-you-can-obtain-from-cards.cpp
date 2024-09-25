class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0,res = 0;
        for(int i=0; i<k;i++){
            sum+=cardPoints[i];
        }
        res = sum;
        int j = cardPoints.size()-1;
        while(k>0){
            sum-=cardPoints[k-1];
            k--;
            sum+=cardPoints[j--];
            res = max(res,sum);
        }
        return res;
    }
};