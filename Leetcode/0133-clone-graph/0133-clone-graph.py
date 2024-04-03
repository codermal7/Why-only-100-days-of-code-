class Solution:
    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        oldtonew = {}
        return self.dfs(node, oldtonew)

    def dfs(self, node, oldtonew):
        if not node:
            return None
        if node in oldtonew:
            return oldtonew[node]
        copy = Node(node.val)
        oldtonew[node] = copy
        for n in node.neighbors:
            copy.neighbors.append(self.dfs(n, oldtonew))
        return copy