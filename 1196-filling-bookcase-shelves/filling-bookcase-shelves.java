class Solution {

    // public int help(int[][] books , int i , int j , int shelfWidth){

    //     int n = books.length;
    //     if(j == n) return 0;
    //     if(i == n) return 1000000000;

    //     int temp = shelfWidth , max = Integer.MIN_VALUE;
    //     int one = Integer.MAX_VALUE;

    //     for(int k=j ; k<n ; k++){
    //         if(books[k][0] <= temp){
    //             max = Math.max(max , books[k][1]);
    //             temp -= books[k][0];
    //             one = Math.min(one , max + help(books , i+1 , k+1 , shelfWidth));
    //         }
    //         // two = help(books , i+1 , j)
    //     }
    //     return one;
    // }    
    int[] dp;

    public int help(int[][] books , int ind , int selfWidth){

        int n = books.length;
        if(ind == n) return 0;
        if(dp[ind] != -1) return dp[ind];

        int i = ind, availwidth = selfWidth, maxheight = Integer.MIN_VALUE, res = Integer.MAX_VALUE;
        for(i  = ind ; i < n && availwidth >= books[i][0] ; i++) {
            availwidth -= books[i][0];
            maxheight = Math.max(maxheight, books[i][1]);
            res = Math.min(res, maxheight + help(books, i + 1, selfWidth));
        }
        // maxheight += help(books, i, selfWidth);
        return dp[ind] = res;
    }

    public int minHeightShelves(int[][] books, int shelfWidth) {
        
        dp = new int[books.length];
        Arrays.fill(dp , -1);

        return help(books , 0 ,shelfWidth);
    }
}