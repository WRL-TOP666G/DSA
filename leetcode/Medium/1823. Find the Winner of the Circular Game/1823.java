class Solution {
    
    public int findTheWinner(int n, int k) {
        List<Integer> list = new ArrayList<>();
        for(int i=1; i<=n; i++){
            list.add(i);
        }
        return helper(0, k-1, list);
    }

    private int helper(int loc, int k, List<Integer> list){
        if(list.size() == 1) return list.get(0);
        int idx = (loc + k) % list.size();
        list.remove(idx);
        return helper(idx, k, list);
    }
}

// TC: O(n + k)
// SC: O(n)
