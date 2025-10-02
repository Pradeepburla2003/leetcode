class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=numBottles,empty=numBottles;
        numBottles=0;
        while(empty!=0){
            if(empty>=numExchange){
                numBottles+=1;
                empty-=numExchange;
                numExchange+=1;
            }
            else{
                if(numBottles+empty<numExchange){
                    empty=0;
                }
                else{
                    ans+=numBottles;
                    empty+=numBottles;
                    numBottles=0;
                }
            }
        }
        return ans+=numBottles;
    }
};