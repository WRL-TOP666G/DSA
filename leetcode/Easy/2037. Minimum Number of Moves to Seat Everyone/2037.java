class Solution {
    public int minMovesToSeat(int[] seats, int[] students) {
        int res = 0;
        Arrays.sort(seats);
        Arrays.sort(students);

        for(int i=0; i<seats.length; i++){
            res += Math.abs(seats[i] - students[i]);
        }

        return res;
    }
}

// TC: O(nlog(n))
// SC: O(1)


class Solution {
    public int minMovesToSeat(int[] seats, int[] students) {
        int n = 100;
        int seatCnt[] = new int[n+1];
        int studentCnt[] = new int[n+1];
        int res = 0;
        int seatIdx = 0;
        int studentIdx = 0;

        for(int s:seats) seatCnt[s]++;
        for(int s:students) studentCnt[s]++;

        while(seatIdx <= n && studentIdx <= n){
            while(seatIdx <= n && seatCnt[seatIdx] == 0) seatIdx++;
            while(studentIdx <= n && studentCnt[studentIdx] == 0) studentIdx++;

            if(seatIdx <= n && studentIdx <= n){
                int diff = Math.min(seatCnt[seatIdx], studentCnt[studentIdx]);
                res += diff * Math.abs(seatIdx - studentIdx);
                seatCnt[seatIdx] -= diff;
                studentCnt[studentIdx] -= diff;
            }
        }

        return res;
    }
}


// TC: O(n+k)
// SC: O(k)
// k == 100