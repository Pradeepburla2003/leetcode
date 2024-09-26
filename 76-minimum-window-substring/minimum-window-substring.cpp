class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>hash(256,0);
        for(auto i:t){
            hash[i - ' ']++;
        }
        int index = -1,mini = INT_MAX,left = 0,right = 0,cnt = 0,n = s.size();
        while(right < n){
            if(hash[s[right] - ' '] > 0) cnt++;
            hash[s[right] - ' ']--;
            while(cnt == t.size()){
                if(right - left + 1 < mini){
                    mini = right - left + 1;
                    index = left;
                }
                hash[s[left] - ' ']++;
                if(hash[s[left] - ' '] > 0) cnt--;
                left++;
            }
            right++;
        }
        if(index == -1) return "";
        return s.substr(index,mini);
    }
};