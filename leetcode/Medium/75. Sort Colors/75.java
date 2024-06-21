class Solution {
    public void sortColors(int[] nums) {
        int[] arr = new int[3];
        for(int n:nums){
            arr[n]++;
        }

        for(int i=0, j=0; i<nums.length; i++){
            while(arr[j]==0){
                j++;
            }
            nums[i] = j;
            arr[j]--;
        }
    }
}

// 2 pass
// TC: O(n)
// SC: O(1)

class Solution {
    public void sortColors(int[] nums) {
        int l = 0;
        int r = nums.length-1;
        int idx = 0;
        while(idx <= r){
            if(nums[idx] == 0){
                nums[idx] = nums[l];
                nums[l] = 0;
                l++;
            }
            else if(nums[idx] == 2){
                nums[idx] = nums[r];
                nums[r] = 2;
                r--;
                idx--;
            }

            idx++;
        }
        
    }
}


// 1 pass
// TC: O(n)
// SC: O(1)

