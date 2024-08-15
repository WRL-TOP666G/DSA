class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto i:target){
            mp[i]++;
        }
        for(auto i:arr){
            mp[i]--;
        }

        for(auto [k, v]: mp){
            if(v>0) return false;
        }
        return true;
    }
};

// TC: O(n)
// SC: O(n)