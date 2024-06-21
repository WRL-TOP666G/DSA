class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> arr(3, 0);
        for(auto &n:nums){
            arr[n]++;
        }

        for(int i=0, j=0; i<nums.size(); i++){
            while(arr[j]==0) j++;
            nums[i] = j;
            arr[j]--;
        }
    }
};

// TC: O(n)
// SC: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int idx = 0, l = 0;
        int r = nums.size()-1;
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
};

// 1 pass
// TC: O(n)
// SC: O(1)

