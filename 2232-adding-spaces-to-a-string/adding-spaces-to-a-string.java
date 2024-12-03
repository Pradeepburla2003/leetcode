class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder ans = new StringBuilder();
        int i = 0;
        for (int j = 0; j < s.length(); j++) {
            if (i < spaces.length && spaces[i] == j) {
                ans.append(" ");
                i++;
            }
            ans.append(s.charAt(j));
        }
        return ans.toString();
    }
}