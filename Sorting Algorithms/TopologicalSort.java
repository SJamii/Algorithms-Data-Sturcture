// Leetcode : 207. Course Schedule

class Solution {
        int courses = 4;
        int[][] preReq = {
                {1,0},{2,0},{3,1},{3,2}
        };
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i=0;i<courses;i++) {
            adj.add(new ArrayList<>());
        }
        for(int i=0;i<preReq.length;i++) {
            adj.get(preReq[i][0]).add(preReq[i][1]);
        }
        int indegree[] = new int[courses];
        for(int i=0;i<courses;i++) {
            for(int it : adj.get(i)) {
                indegree[it]++;
            }
        }
        Queue<Integer> q = new LinkedList<Integer>();
        for(int i=0;i<courses;i++) {
            if(indegree[i] == 0) {
                q.add(i);
            }
        }

        List<Integer> topo = new ArrayList<Integer>();
        while (!q.isEmpty()) {
            int node = q.peek();
            q.remove();
            topo.add(node);
            for(int it : adj.get(node)) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.add(it);
                }
            }
        }

        if(topo.size() == courses) {
            System.out.println("POSSIBLE");
        } else {
            System.out.println("NOT POSSIBLE");
        }
}
