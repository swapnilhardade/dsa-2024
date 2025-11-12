class Graph:
    def _init_(self, vertices):
        self.V = vertices
        self.graph = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def add_edge(self, u, v, w):
        """Add an undirected edge with weight w"""
        self.graph[u][v] = w
        self.graph[v][u] = w

    def print_graph(self):
        print("Adjacency Matrix Representation of Graph:")
        for row in self.graph:
            print(row)

    def min_key(self, key, mst_set):
        """Find the vertex with the minimum key value"""
        min_val = float('inf')
        min_index = -1

        for v in range(self.V):
            if key[v] < min_val and not mst_set[v]:
                min_val = key[v]
                min_index = v

        return min_index

    def prim_mst(self):
        key = [float('inf')] * self.V
        parent = [-1] * self.V
        key[0] = 0
        mst_set = [False] * self.V

        for _ in range(self.V):
            u = self.min_key(key, mst_set)
            mst_set[u] = True

            for v in range(self.V):
                if 0 < self.graph[u][v] < key[v] and not mst_set[v]:
                    key[v] = self.graph[u][v]
                    parent[v] = u

        self.print_mst(parent)

    def print_mst(self, parent):
        print("\nEdges in the Minimum Spanning Tree using Prim's Algorithm:")
        total_weight = 0
        for i in range(1, self.V):
            print(f"{parent[i]} - {i} \tWeight: {self.graph[i][parent[i]]}")
            total_weight += self.graph[i][parent[i]]
        print("Total Minimum Cost =", total_weight)


# ---- Main Program ----
n = int(input("Enter number of vertices in graph: "))
g = Graph(n)

edges = int(input("Enter number of edges: "))
for _ in range(edges):
    u = int(input("Enter starting vertex (0 to n-1): "))
    v = int(input("Enter ending vertex (0 to n-1): "))
    w = int(input("Enter weight of edge: "))
    g.add_edge(u, v, w)

print("\nGraph Created Successfully!\n")
g.print_graph()

# Finding MST using Prim's algorithm
g.prim_mst()
