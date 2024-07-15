class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = healths.size();
        vector<vector<int>> robots;
        vector<vector<int>> st;

        for(int i=0; i<n ;i++) robots.push_back({positions[i], healths[i], directions[i], i});
        sort(robots.begin(), robots.end());
        for(auto &r : robots){
            if(st.empty() || r[2] == 'R' || st.back()[2] == 'L'){
                st.push_back(r);
                continue;
            }

            if(r[2] == 'L'){
                bool add = true;
                while(!st.empty() && st.back()[2] == 'R' && add){
                    int last_heal = st.back()[1];
                    if(r[1] > last_heal){
                        st.pop_back();
                        r[1]--;
                    } else if (r[1] == last_heal){
                        st.pop_back();
                        add = false;
                    } else {
                        st.back()[1]--;
                        add = false;
                    }
                }
                if(add) st.push_back(r);
            }
        }

        vector<int> res;
        sort(st.begin(), st.end(), [](vector<int>& a, vector<int>& b){
            return a[3] < b[3];
        });
        for(auto &r:st){
            res.push_back(r[1]);
        }
        return res;
    }
};

// TC: O(nlog(n))
// SC: O(n)

