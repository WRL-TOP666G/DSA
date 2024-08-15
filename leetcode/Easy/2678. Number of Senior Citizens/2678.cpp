class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;

        for(auto s:details){
            int age = 0;
            age += (s[11] - '0') * 10 + (s[12] - '0');
            if(age > 60) res++;
        }


        return res;
    }
};

// TC: O(n)
// SC: O(1)