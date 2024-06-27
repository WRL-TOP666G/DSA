class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> mp;
        for(auto &e:edges){
            mp[e[0]]++;
            mp[e[1]]++;
        }
        int n = mp.size();
        for(const auto &[key, val]:mp){
            if(val == n-1)
                return key;
        }
        return -1;
    }
};

// TC: O(e + n)
// SC: O(n)
// e: edges.size(), n: number of nodes


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] 
            ? edges[0][0]: edges[0][1];
    }
};

// TC: O(1)
// SC: O(1)