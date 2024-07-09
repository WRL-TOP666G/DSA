class Solution {
public:
    int helper(int now, int k, vector<int> v){
        if(v.size() == 1) return v[0];
        int idx = (now + k) % v.size();
        v.erase(v.begin() + idx);
        return helper(idx, k, v);
    }
    int findTheWinner(int n, int k) {
        vector<int> v;
        for(int i=1; i<=n; i++)
            v.push_back(i);

        return helper(0, k-1, v);
    }
};

// TC: O(n + k)
// SC: O(n)
