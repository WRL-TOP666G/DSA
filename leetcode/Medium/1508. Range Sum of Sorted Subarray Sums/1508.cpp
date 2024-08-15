class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int res = 0;
        vector<int> sum_arr;
        int idx = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                sum_arr.push_back(sum);
            }
        }
        sort(sum_arr.begin(), sum_arr.end());
        int MOD = 1000000007;
        for(int i=left-1; i<=right-1; i++){
            res = (res + sum_arr[i]) % MOD;
        }
        return res;
    }
};

// TC: O(n ^ 2)
// SC: O(n)
