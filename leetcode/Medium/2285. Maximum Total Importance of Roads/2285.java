class Solution {
    public long maximumImportance(int n, int[][] roads) {
        long res = 0L;
        long[] freq = new long[n];
        for(int[] r:roads){
            freq[r[0]]++;
            freq[r[1]]++;
        }
        Arrays.sort(freq);
        long i = 1;
        for(long f:freq){
            res += i*f;
            i++;
        }

        return res;
    }
}

// TC: O(nlog(n))
// SC: O(n)
