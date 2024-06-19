class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, r = static_cast<long long>(sqrt(c));
        while(l <= r) {
            if(l * l + r * r == c) return true;
            else if(l * l + r * r > c) r--;
            else l++;
        }

        return false;
    }
};

// TC: O(sqrt(c))
// SC: O(1)