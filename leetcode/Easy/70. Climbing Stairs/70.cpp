// Memoization
class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> mp;
        return helper(n, mp);
    }

    int helper(int n, unordered_map<int, int>& mp){
        if(n==0 || n==1) return 1;
        if(n==2) return 2;
        if(mp.count(n) > 0) return mp[n];
        mp[n] = helper(n-1, mp) + helper(n-2, mp);
        return mp[n];
    }
};

// Tabulation
class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            if(i==1) dp[i] = 1;
            else dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// TC: O(n)
// SC: O(n)


class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        int prev = 1, cur = 1;
        for(int i=2; i<=n; i++){
            int tmp = cur;
            cur = cur + prev;
            prev = tmp;
        }
        return cur;
    }
};

// TC: O(n)
// SC: O(1)


