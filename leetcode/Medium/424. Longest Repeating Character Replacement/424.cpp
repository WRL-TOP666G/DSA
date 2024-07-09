class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> dict;
        int res = 0;
        int mostFrequency = 0;
        for(int l=0, r=0; r<s.size(); r++){
            dict[s[r]]++;
            mostFrequency = max(mostFrequency, dict[s[r]]);

            if( (r - l + 1) - mostFrequency > k ){
                dict[s[l++]]--;
            } else {
                res = max(res, r-l+1);
            }
        }
        return res;
    }
};

// TC: O(n)
// SC: O(n)

