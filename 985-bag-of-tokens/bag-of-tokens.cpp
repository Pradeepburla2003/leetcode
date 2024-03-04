class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score=0,i=0,j=tokens.size()-1,maxi=0;
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i];
                score+=1;
                i+=1;
            }
            else{
                if(score>0){
                    power+=tokens[j];
                    score-=1;
                }
                j-=1;
            }
            maxi=max(maxi,score);
        }
        return maxi;
    }
};