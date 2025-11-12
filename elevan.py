class Graph:
    def _init_(self, vertices):
        self.V = vertices  # Number of vertices
        self.edges = []    # List to store edges (u, v, weight)

    # Function to add an edge to the graph
    def add_edge(self, u, v, w):
        self.edges.append([u, v, w])

    # Function to find the set of an element (uses path compression)
    def find(self, parent, i):
        if parent[i] != i:
            parent[i] = self.find(parent, parent[i])
        return parent[i]

    # Function to perform union of two sets (uses union by rank)
    def union(self, parent, rank, x, y):
        xroot = self.find(parent, x)
        yroot = self.find(parent, y)

        if rank[xroot] < rank[yroot]:
            parent[xroot] = yroot
        elif rank[xroot] > rank[yroot]:
            parent[yroot] = xroot
        else:
            parent[yroot] = xroot
            rank[xroot] += 1

    # Function to find MST using Kruskal’s algorithm
    def kruskal_mst(self):
        result = []  # Store the resulting MST
        i, e = 0, 0  # i - edge index, e - count of edges in MST

        # Step 1: Sort all edges by weight
        self.edges = sorted(self.edges, key=lambda item: item[2])

        parent = []
        rank = []

        # Create subsets
        for node in range(self.V):
            parent.append(node)
            rank.append(0)

        # Number of edges in MST will be V-1
        while e < self.V - 1:
            u, v, w = self.edges[i]
            i += 1
            x = self.find(parent, u)
            y = self.find(parent, v)

            # If including this edge doesn’t cause a cycle
            if x != y:
                e += 1
                result.append([u, v, w])
                self.union(parent, rank, x, y)

        # Display the resulting MST
        print("\nEdges in the Minimum Spanning Tree:")
        total_weight = 0
        for u, v, weight in result:
            total_weight += weight
            print(f"{u} -- {v} == {weight}")
        print("Total weight of MST:", total_weight)


# ---------------------- MAIN PROGRAM ----------------------
if _name_ == "_main_":
    V = int(input("Enter number of vertices: "))
    g = Graph(V)

    E = int(input("Enter number of edges: "))
    for i in range(E):
        print(f"Enter edge {i+1} details (u v w):")
        u, v, w = map(int, input().split())
        g.add_edge(u, v, w)

    print("\nGraph edges:")
    for edge in g.edges:
        print(edge)

    g.kruskal_mst()
