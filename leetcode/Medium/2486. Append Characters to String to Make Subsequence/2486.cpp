class Solution {
public:
    int appendCharacters(string s, string t) {
        int tIdx = 0;
        for(auto& c:s){
            if(c == t[tIdx]) tIdx++;
            if(tIdx == t.length()) break;
        }
        return t.length() - tIdx;
    }
};

// TC: O(S)
// SC: O(1)
