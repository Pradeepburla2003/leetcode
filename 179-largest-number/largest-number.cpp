class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0) return "";
        vector<string>str;
        for(auto i:nums){
            str.push_back(to_string(i));
        }
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1;j<nums.size();j++){
                string temp1 = str[i] + str[j];
                string temp2 = str[j] + str[i];
                if(temp1 < temp2){
                    swap(str[i],str[j]);
                }
            }
        }
        string ans = "";
        for(auto i:str) ans += i;
        if(ans[0] == '0') return "0";
        return ans;
    }
};