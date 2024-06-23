class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0, res = 0;
        multiset<int> ms;

        for(int i=0; i<nums.size(); i++){
            ms.insert(nums[i]);

            if(*ms.rbegin() - *ms.begin() <= limit)
                res = max(res, i-l+1);

            while(l < i && *ms.rbegin() - *ms.begin() > limit){
                ms.erase(ms.find(nums[l++]));
            }
            
        }

        return res;
    }
};


// TC: O(nlog(n))
// SC: O(n)


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxd, mind;
        int l=0, i=0;
        for(;i<nums.size(); i++){
            while(!maxd.empty() && nums[i] > maxd.back()) maxd.pop_back();
            while(!mind.empty() && nums[i] < mind.back()) mind.pop_back();
            maxd.push_back(nums[i]);
            mind.push_back(nums[i]);

            if(maxd.front() - mind.front() > limit){
                if(maxd.front() == nums[l]) maxd.pop_front();
                if(mind.front() == nums[l]) mind.pop_front();
                l++;
            }
        }


        return i-l;
    }
};

// TC: O(n)
// SC: O(n)
