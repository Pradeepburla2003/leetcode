class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        s.push(asteroids[0]);
        int k,f=0;
        for(int i=1;i<asteroids.size();i++){
            k=asteroids[i];
            f=0;
            if(k>0 or (s.empty())) s.push(k);
            else{
                while(!s.empty()){
                    if(s.top()<0){
                        s.push(k);
                        break;
                    }
                    else{
                        if(abs(k)<s.top()) break;
                        else if(abs(k)==s.top()){
                            s.pop();
                            f=1;
                            break;
                        }
                        else{
                            s.pop();
                        }
                    }
                }
                if(f==0 && s.empty()) s.push(k);
            }
        }
        vector<int>ans(s.size(),0);
        for(int i=s.size()-1;i>=0;i--){
            ans[i]=s.top();
            s.pop();
        }
        return ans;
    }
};