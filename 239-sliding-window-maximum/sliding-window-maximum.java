class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] ans = new int[nums.length-k+1];
        Deque<Integer> dq= new LinkedList<>();
        int start=0;
        for(int i=0;i<nums.length;i++){
            while(dq.size()>0 && nums[dq.peekLast()]<nums[i]){
                dq.pollLast();
            }
            dq.addLast(i);
            if(i>=k-1){
                ans[start++]=nums[dq.peekFirst()];
                if(dq.peekFirst()==i-k+1){
                    dq.pollFirst();
                }
            }
        }
        return ans;
    }
}