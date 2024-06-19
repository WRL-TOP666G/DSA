class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->(a[0]-b[0]));
        int N = profit.length, best = 0;
        Arrays.sort(worker);
        int res = 0;
        for(int i=0; i<N; i++){
            pq.add(new int[]{difficulty[i], profit[i]});
        }

        for(int w:worker){
            while(!pq.isEmpty() && w >= pq.peek()[0]){
                best = Math.max(best, pq.peek()[1]);
                pq.poll();
            }
            res += best;
        }


        return res;
    }
}


// TC: O(Dlog(D) + Wlog(W))
// SC: O(D)