class Solution:
    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        oldToNew = {}
        if node is None:
            return None
        def dfs(node):
            if node in oldToNew:
                return oldToNew[node]
            
            cloneNode = Node(node.val)
            oldToNew[node] = cloneNode
            for n in node.neighbors:
                cloneNode.neighbors.append(dfs(n))
            return cloneNode
        return dfs(node)