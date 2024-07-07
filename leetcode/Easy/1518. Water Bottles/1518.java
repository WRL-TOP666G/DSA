class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        int rest = 0;
        while(numBottles > 0){
            res += numBottles;
            int tmp = numBottles + rest;
            numBottles = tmp / numExchange;
            rest = tmp % numExchange;
        }
        return res;
    }
}

// TC: O(log(numBottles)/log(numExchange))
// SC: O(1)