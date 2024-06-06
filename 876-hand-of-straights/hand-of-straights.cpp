class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;
        if(hand.size()%groupSize!=0) return false;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        if(mp.size()<groupSize) return false;
        int c=0;
        vector<vector<int>>storing;
        while(1){
            vector<int>temp;
            for(auto i:mp){
                if(i.second>0){
                    temp.push_back(i.first);
                    mp[i.first]--;
                    c+=1;
                }
                if(temp.size()==groupSize or c==hand.size()) break;
            }
            if(temp.size()<groupSize && temp.size()>0) return false;
            if(temp.size()==groupSize) storing.push_back(temp);
            if(c==hand.size()) break;
        }
        for(int i=0;i<storing.size();i++){
            for(int j=1;j<groupSize;j++){
                if(storing[i][j]!=storing[i][j-1]+1)    return false;
            }
        }
        return true;
    }
};