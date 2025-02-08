class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] ans = new int[temperatures.length];
        int size = temperatures.length;
        Stack<Integer> st = new Stack<>();
        st.push(size-1);
        for(int i=size-2;i>=0;i--){
            while(!st.isEmpty() && temperatures[st.peek()] <= temperatures[i]){
                st.pop();
            }
            if(!st.isEmpty()){
                ans[i]=st.peek()-i;
            }
            else{
                ans[i]=0;
            }
            st.push(i);
        }
        return ans;
    }
}