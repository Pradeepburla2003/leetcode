class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        if(mp.size()<groupSize or hand.size()%groupSize!=0) return false;
        int c=0;
        vector<vector<int>>storing;
        while(1){
            vector<int>temp;
            for(auto i:mp){
                // cout<<i.first<<" "<<i.second<<endl;
                if(i.second>0){
                    temp.push_back(i.first);
                    mp[i.first]--;
                    // cout<<i.first<<" "<<i.second<<endl;
                    c+=1;
                }
                if(temp.size()==groupSize or c==hand.size()) break;
            }
            if(temp.size()<groupSize && temp.size()>0) return false;
            if(temp.size()==groupSize) storing.push_back(temp);
            // for(int j=0;j<temp.size();j++) cout<<temp[j]<<" ";
            // cout<<endl;
            if(c==hand.size()) break;
            
        }
        for(int i=0;i<storing.size();i++){
            for(int j=1;j<groupSize;j++){
                if(storing[i][j]!=storing[i][j-1]+1){
                    // cout<<storing[i][j]<<" "<<storing[i][j-1];
                    return false;
                }
            }
        }
        return true;
    }
};