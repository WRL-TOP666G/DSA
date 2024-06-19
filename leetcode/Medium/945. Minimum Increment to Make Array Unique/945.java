class Solution {
    public int minIncrementForUnique(int[] nums) {
        Arrays.sort(nums);

        int res = 0, need = 0;

        for(int n:nums){
            res += Math.max(0, need - n);
            need = Math.max(n, need) + 1;
        }

        return res;
    }
}


// TC: O(nlog(n))
// SC: O(1)