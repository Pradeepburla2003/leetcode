class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans=0,i=0,j=people.size()-1;
        sort(people.begin(),people.end());
        while(i<=j){
            if(people[j]==limit){
                ans+=1;
                j-=1;
            }
            else{
                if(people[i]+people[j]<=limit){
                    ans+=1;
                    i++;
                    j--;
                }
                else{
                    ans+=1;
                    j--;
                }
            }
        }
        return ans;
    }
};