class Solution {
    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        List<List<Integer>> res = new ArrayList<>();
        Map<Integer, List<Integer>> map = new HashMap<>();

        for(int i=0; i<n; i++){
            map.put(i, new ArrayList<>());
            res.add(new ArrayList<>());
        }

        for(int[] e:edges){
            map.get(e[1]).add(e[0]);
        }

        for(int i=0; i<n; i++){
        	// dfs(i, i, map, res, new boolean[n]);
            bfs(i, map, res, new boolean[n]);
            Collections.sort(res.get(i));
        }
        return res;
    }

    private void bfs(int idx, Map<Integer, List<Integer>> map, List<List<Integer>> res, boolean[] visited){
        Queue<Integer> q = new LinkedList<>();
        visited[idx] = true;
        q.add(idx);
        while(!q.isEmpty()){
            int now = q.poll();
            for(int next:map.get(now)){
                if(visited[next]) continue;
                q.add(next);
                res.get(idx).add(next);
                visited[next] = true;
            }
        }
    }

    private void dfs(int idx, int now, Map<Integer, List<Integer>> map, List<List<Integer>> res, boolean[] visited){
        if(visited[now]) return;
        visited[now] = true;
        if(idx!=now) res.get(idx).add(now);
        for(int next:map.get(now)){
            dfs(idx, next, map, res, visited);
        }
        
    }
}

// TC: O(N^3) -> (E*V) = ((N-1)*N)*N
// SC: O(N^2) -> (E+V) = ((N-1)*N)+N
