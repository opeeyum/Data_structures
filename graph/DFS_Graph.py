class Solution:    
    
    def dfs_Of_Graph(self, V, adj):
        "Function to return a list containing the DFS traversal of the graph."
        visited = [0 for i in range(V)]
        res = []
        stack = []
        stack.append(0)
        while stack:
            top = stack.pop()
            if visited[top] != 0:
                continue
            visited[top] = 1
            for i in range(len(adj[top])-1, -1, -1):
                stack.append(adj[top][i])
            res.append(top)
        return res

if __name__ == "__main__":
    V, E = map(int, input().split())
    adj = [[] for _ in range(V)]
    for i in range(E):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
    
    obj = Solution()
    ans = obj.dfs_Of_Graph(V, adj)
    print(*ans, sep = " ")
    print()