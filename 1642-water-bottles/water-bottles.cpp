class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles,empty=numBottles;
        while(numBottles>=numExchange){
            numBottles-=numExchange;
            ans+=1;
            numBottles+=1;
        }
        return ans;
    }
};