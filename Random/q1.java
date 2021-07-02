class Solution {
    public int[] twoSum(int[] nums, int target) {
        if (nums.length <= 1) {
            return null;
        }
        return twoSumRec(nums, target, 0);
        
    }
    
    private int[] twoSumRec(int[] nums, int target, int p) {
        if (p >= nums.length -1){
            return null;
        }
        for (int i = p + 1; i< nums.length; i++) {
            if (nums[i] + nums[p] == target) {
                int[] arr = {p,i};
                return arr;
            }
        }
        return twoSumRec(nums, target, p+1);
    }
}