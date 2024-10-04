class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n = skill.size();
        long long sum = skill[0] + skill[n-1];
        long long ans = skill[0] * skill[n-1];
        for(int i=1; i<(n/2); i++){
            if(skill[i] + skill[n-i-1] != sum) return -1;
            ans += (skill[i] * skill[n-i-1]);
        }
        return ans;
    }
};