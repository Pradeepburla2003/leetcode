class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=1,size=tickets.size(),start=0,temp;
        queue<int>q;
        for(auto it:tickets){
            q.push(it);
        }
        while(true){
            if(start==k && q.front()==1) return ans;
            if(q.front()>0){
                ans+=1;
                temp=q.front()-1;
            }
            else{
                temp=0;
            }
            q.pop();
            q.push(temp);
            start++;
            if(start==size) start=0;
        }
    }
};