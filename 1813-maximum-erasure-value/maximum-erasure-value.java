class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int ans = Integer.MIN_VALUE;
        HashMap<Integer,Integer> mp = new HashMap<>();
        int i=0,j=0,n=nums.length,sum=0;
        while(i<n){
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
            if(mp.get(nums[i])==2){
                ans = Math.max(ans,sum);
                System.out.println(i+" "+j);
                while(mp.get(nums[j])==1){
                    sum-=nums[j];
                    mp.remove(nums[j]);
                    j++;
                }
                sum-=nums[j];
                mp.put(nums[i],1);
                j++;
            }
            sum+=nums[i];
            i++;
        }
        ans = Math.max(ans,sum);
        return ans;
    }
}