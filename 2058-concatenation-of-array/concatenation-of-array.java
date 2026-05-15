class Solution {
    public int[] getConcatenation(int[] nums) {
        int n = nums.length;
        int[] ans = new int[2 * nums.length];
        int indx = 0;
        for(int i=0;i<2*nums.length;i++){
          ans[indx++] = nums[i%n];
        }

        return ans;
    }
}