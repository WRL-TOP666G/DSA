class Solution {
    public int findCenter(int[][] edges) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int[] e:edges){
            map.put(e[0], map.getOrDefault(e[0], 0)+1);
            map.put(e[1], map.getOrDefault(e[1], 0)+1);
        }
        int n = map.size();
        for(int key:map.keySet()){
            if(map.get(key) == n-1)
                return key;
        }

        return -1;
    }
}

// TC: O(e + n)
// SC: O(n)
// e: edges.length, n: number of nodes


class Solution {
    public int findCenter(int[][] edges) {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] 
        ? edges[0][0]: edges[0][1];
    }
}

// TC: O(1)
// SC: O(1)