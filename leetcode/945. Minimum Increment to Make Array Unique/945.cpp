class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int cnt = 0, res = 0;
        auto [min, max] = minmax_element(nums.begin(), nums.end());
        const int n = nums.size(), min_num = *min, max_num = *max;
        vector<int> freq(n + max_num - min_num + 1, 0);

        for(auto& n:nums){
            freq[n-min_num]++;
        }

        for(int i=0; cnt<n; i++){
            int f = freq[i];
            cnt += (f!=0);
            if(f>1){
                freq[i+1] += f-1;
                res += f-1;
            }
        }

        return res;
    }
};

// TC: O(n)
// SC: O(n)