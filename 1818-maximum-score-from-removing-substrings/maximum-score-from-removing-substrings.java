class Solution {
    public int maximumGain(String s, int x, int y) {
        if (x > y) {
            return removePairs(s, 'a', 'b', x, y);
        } else {
            return removePairs(s, 'b', 'a', y, x);
        }
    }

    int removePairs(String s, char first, char second, int val1, int val2) {
        Stack<Character> stack = new Stack<>();
        int score = 0;
        StringBuilder remaining = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (!stack.isEmpty() && stack.peek() == first && c == second) {
                stack.pop();
                score += val1;
            } else {
                stack.push(c);
            }
        }
        while (!stack.isEmpty()) {
            remaining.insert(0, stack.pop());
        }
        for (char c : remaining.toString().toCharArray()) {
            if (!stack.isEmpty() && stack.peek() == second && c == first) {
                stack.pop();
                score += val2;
            } else {
                stack.push(c);
            }
        }

        return score;
    }
}
