class Solution {
    public int findLHS(int[] nums) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        for(int num :nums){
            mp.put(num,mp.getOrDefault(num,0)+1);
        }
        int len,maxLen=0;
        for(int num:nums){
            if(mp.containsKey(num+1)){
                len=mp.get(num)+mp.get(num+1);
                maxLen=Math.max(len,maxLen);
            }
        }
        return maxLen;
    }
}