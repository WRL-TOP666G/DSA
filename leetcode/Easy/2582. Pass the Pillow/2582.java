class Solution {
    public int passThePillow(int n, int time) {
        int div = time / (n - 1);
        int mod = time % (n - 1);

        if(div%2==1) return (n - mod);
        else return (1 + mod);
    }
}

// TC: O(1)
// SC: O(1)