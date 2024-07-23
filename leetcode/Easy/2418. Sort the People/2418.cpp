class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> res;
        vector<pair<int, string>> A;
        int n = names.size();
        for(int i=0; i<n; i++){
            A.push_back({heights[i], names[i]});
        }

        sort(A.rbegin(), A.rend());
        for(int i=0; i<n; i++){
            res.push_back(A[i].second);
        }
        return res;
    }
};

// TC: O(n)
// SC: O(n)