class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int res = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), seats.end());

        for(int i=0; i<seats.size(); i++){
            res += abs(seats[i] - students[i]);
        }

        return res;
    }
};


// TC: O(nlog(n))
// SC: O(1)



class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = 100;
        vector<int> seatCnt(n+1, 0);
        vector<int> studentCnt(n+1, 0);
        int seatIdx = 0;
        int studentIdx = 0;
        int res = 0;

        for(auto &s:seats) seatCnt[s]++;
        for(auto &s:students) studentCnt[s]++;

        while(seatIdx <= n && studentIdx <= n){
            while(seatIdx <= n && seatCnt[seatIdx] == 0) seatIdx++;
            while(studentIdx <= n && studentCnt[studentIdx] == 0) studentIdx++;

            if(seatIdx <= n && studentIdx <= n){
                int diff = min(seatCnt[seatIdx], studentCnt[studentIdx]);
                res += diff * abs(seatIdx - studentIdx);
                seatCnt[seatIdx] -= diff;
                studentCnt[studentIdx] -= diff;
            }
        }

        return res;
    }
};


// TC: O(n + k)
// SC: O(k)
// k == 100