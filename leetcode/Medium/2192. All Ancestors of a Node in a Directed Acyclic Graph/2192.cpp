class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n);
        unordered_map<int, vector<int>> mp;

        for(auto &e:edges){
            mp[e[1]].push_back(e[0]);
        }

        for(int i=0; i<n; i++){
            vector<bool> visited(n, false);
            bfs(i, mp, res, visited);
            // dfs(i, i, mp, res, visited);
            sort(res[i].begin(), res[i].end());
        }

        return res;
    }

    void bfs(int idx, unordered_map<int, vector<int>>& mp, vector<vector<int>>& res, vector<bool> visited){
        queue<int> q;
        visited[idx] = false;
        q.push(idx);
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(auto &next:mp[now]){
                if(visited[next]) continue;
                q.push(next);
                res[idx].push_back(next);
                visited[next] = true;
            }
        }
    }

    void dfs(int idx, int now, unordered_map<int, vector<int>>& mp, vector<vector<int>>& res, vector<bool>& visited){
        if(visited[now]) return;
        visited[now] = true;
        if(idx != now) res[idx].push_back(now);
        for(int next: mp[now]){
            dfs(idx, next, mp, res, visited);
        }
    }
};


// TC: O(N^3) -> (EV) = ((N-1)*N) * N
// SC: O(N^2) -> (E+V) = (N-1)*N +N
