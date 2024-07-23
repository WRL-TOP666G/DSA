class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(auto num:nums){
            mp[num]++;
        }

        sort(nums.begin(), nums.end(), [&](auto a, auto b){
            if(mp[a] == mp[b]){
                return a > b;
            } else {
                return mp[a] < mp[b];
            }
        });

        return nums;
    }
};
// TC: O(nlog(n))
// SC: O(n)