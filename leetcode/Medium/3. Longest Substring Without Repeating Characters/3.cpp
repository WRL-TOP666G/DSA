class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int l = 0;
        int maxLen = 0;
        for(int r=0; r<s.length(); r++){
            mp[s[r]]++;
            while(mp[s[r]] > 1){
                mp[s[l]]--;    
                l++;
            }   
            maxLen = max(maxLen, r-l+1); 
        }
        return maxLen;
    }
};


// TC: O(n)
// SC: O(n)

