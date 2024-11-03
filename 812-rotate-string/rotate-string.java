class Solution {
    public boolean rotateString(String s, String goal) {
        int n = s.length();
        if(s.length() != goal.length()) return false;
        for(int i=0;i<n;i++){
            if (s.charAt(i) == goal.charAt(0)) { 
                if (s.substring(i).equals(goal.substring(0, n - i)) && 
                    s.substring(0, i).equals(goal.substring(n - i))) {
                    return true;
                }
            }
        }
        return false;
    }
}