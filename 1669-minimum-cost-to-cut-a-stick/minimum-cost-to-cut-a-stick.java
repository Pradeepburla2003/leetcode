class Solution {
    public int help(ArrayList<Integer>cuts,int i,int j,int[][] dp){
        if(i>j) return 0;
        int mini=Integer.MAX_VALUE;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<=j;k++){
            int cost=cuts.get(j+1)-cuts.get(i-1)+help(cuts,i,k-1,dp)+help(cuts,k+1,j,dp);
            mini=Math.min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    public int minCost(int n, int[] cuts) {
        // Arrays.sort(cuts);
        ArrayList<Integer>arr=new ArrayList<>();
        for (int cut : cuts) {
            arr.add(cut);
        }
        arr.add(0);
        arr.add(n);
        Collections.sort(arr);
        int size=arr.size();
        int [][] dp= new int[size][size];
        for(int i=0;i<size;i++){
            Arrays.fill(dp[i],-1);
        }
        return help(arr,1,arr.size()-2,dp);
    }
}