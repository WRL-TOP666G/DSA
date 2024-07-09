class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        for(auto &c:s1) v1[c-'a']++;

        for(int i=0; i<s2.length(); i++){
            v2[s2[i]-'a']++;

            if(i >= s1.length()){
                v2[s2[i - s1.length()] - 'a']--;
            }

            if(v1 == v2) return true;
        }
        return false;
    }
};

// TC: O(n1 + n2)
// SC: O(1)

