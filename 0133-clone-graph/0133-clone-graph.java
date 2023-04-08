class Solution {
    Node []visited;
    public Node cloneGraph(Node node) {
        if(node==null) return null;
        visited = new Node[101];
        return dfs(node);
    }
    public Node dfs(Node node){
        if(visited[node.val] != null) return visited[node.val];
        visited[node.val] = new Node(node.val);
        for(Node n: node.neighbors) visited[node.val].neighbors.add(dfs(n));
        return visited[node.val];
    }
}