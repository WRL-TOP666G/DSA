class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> tasks;
        int N = difficulty.size(), res = 0, best = 0;

        for(int i=0; i<N; i++){
            tasks.push_back(make_pair(difficulty[i], profit[i]));
        }

        sort(tasks.begin(), tasks.end());
        sort(worker.begin(), worker.end());

        int i=0;
        for(int &w:worker){
            while(i<N && w>=tasks[i].first)
                best = max(best, tasks[i++].second);
            res += best;
        }
        return res;
    }
};

// TC: O(Dlog(D) + Wlog(W)) 
// SC: O(D)