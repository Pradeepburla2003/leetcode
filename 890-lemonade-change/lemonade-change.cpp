class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0,tens = 0, tewnty = 0;
        for(int i=0;i<bills.size();i++){
            if(bills[i] == 5) fives+=1;
            else if(bills[i] == 10){
                if(fives > 0){
                    fives--;
                    tens+=1;
                }
                else return false;
            }
            else{
                if(fives > 0 && tens > 0){
                    tens--;
                    fives--;
                }
                else if(fives >=3){
                    fives-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};