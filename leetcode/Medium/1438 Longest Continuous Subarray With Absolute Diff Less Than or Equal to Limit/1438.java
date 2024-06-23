class Solution {
    public int longestSubarray(int[] nums, int limit) {
        int l = 0, length = 0;
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for(int i=0; i<nums.length; i++){
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);

            if(map.lastKey() - map.firstKey() <= limit){
                length = Math.max(length, i-l+1);
            }
            while(l < i && map.lastKey() - map.firstKey() > limit){
                map.put(nums[l], map.get(nums[l])-1);
                if(map.get(nums[l]) == 0){
                    map.remove(nums[l]);
                }
                l++;
            }
            
        }


        return length;
    }
}

// TC: O(nlog(n))
// SC: O(n)

class Solution {
    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> maxd = new ArrayDeque<>();
        Deque<Integer> mind = new ArrayDeque<>();
        int l=0, i=0;
        for(;i<nums.length; i++){
            while(!maxd.isEmpty() && nums[i] > maxd.peekLast()) maxd.pollLast();
            while(!mind.isEmpty() && nums[i] < mind.peekLast()) mind.pollLast();
            maxd.add(nums[i]);
            mind.add(nums[i]);
            if(maxd.peek() - mind.peek() > limit){
                if(maxd.peek() == nums[l]) maxd.poll();
                if(mind.peek() == nums[l]) mind.poll();
                l++;
            }
        }
        return i-l;
    }
}

// TC: O(n)
// SC: O(n)
