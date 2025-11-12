# Define a class for the Graph
class Graph:
    def _init_(self):
        # Dictionary to store adjacency list
        self.graph = {}

    # Function to add a vertex
    def add_vertex(self, vertex):
        if vertex not in self.graph:
            self.graph[vertex] = []

    # Function to add an edge (undirected graph)
    def add_edge(self, vertex1, vertex2):
        if vertex1 in self.graph and vertex2 in self.graph:
            self.graph[vertex1].append(vertex2)
            self.graph[vertex2].append(vertex1)
        else:
            print("Error: One or both vertices not found!")

    # Display the graph as adjacency list
    def display_adj_list(self):
        print("\nGraph represented as an Adjacency List:")
        for vertex in self.graph:
            print(vertex, "->", " -> ".join(map(str, self.graph[vertex])))

    # Display the graph as adjacency matrix
    def display_adj_matrix(self):
        print("\nGraph represented as an Adjacency Matrix:")
        vertices = list(self.graph.keys())
        print("   ", "  ".join(vertices))
        for v1 in vertices:
            row = []
            for v2 in vertices:
                if v2 in self.graph[v1]:
                    row.append("1")
                else:
                    row.append("0")
            print(v1, "  ", "  ".join(row))


# ---- Main Program ----
g = Graph()

# Insert vertices
vertices = ['A', 'B', 'C', 'D', 'E']
for v in vertices:
    g.add_vertex(v)

# Insert edges
edges = [('A', 'B'), ('A', 'C'), ('B', 'D'), ('C', 'D'), ('D', 'E')]
for v1, v2 in edges:
    g.add_edge(v1, v2)

# ---- Choose one display operation below ----
g.display_adj_list()     # Display using adjacency list
# g.display_adj_matrix() # Display using adjacency matrix
