class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long res = 0, cnt = 1;
        vector<long long> freq(n, 0);
        
        for(auto& r:roads){
            freq[r[0]]++;
            freq[r[1]]++;
        }

        sort(freq.begin(), freq.end());
        for(auto& f:freq){
            res += cnt * f;
            cnt++;
        }

        return res;
    }
};

// TC: O(nlog(n))
// SC: O(n)
