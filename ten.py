class Graph:
    def _init_(self):
        self.graph = {}

    def add_vertex(self, v):
        if v not in self.graph:
            self.graph[v] = []

    def add_edge(self, u, v):
        if u in self.graph and v in self.graph:
            self.graph[u].append(v)
            self.graph[v].append(u)

    def display_list(self):
        print("\nGraph using Adjacency List:")
        for v in self.graph:
            print(v, "->", self.graph[v])

    def display_matrix(self):
        vertices = list(self.graph.keys())
        print("\nGraph using Adjacency Matrix:")
        print("   ", end="")
        for v in vertices:
            print(v, end=" ")
        print()
        for i in vertices:
            print(i, end="  ")
            for j in vertices:
                if j in self.graph[i]:
                    print("1", end=" ")
                else:
                    print("0", end=" ")
            print()

g = Graph()
v = int(input("Enter number of vertices: "))
for i in range(v):
    vertex = input(f"Enter vertex {i+1}: ")
    g.add_vertex(vertex)

e = int(input("Enter number of edges: "))
for i in range(e):
    u = input("Enter first vertex: ")
    v = input("Enter second vertex: ")
    g.add_edge(u, v)

print("\n1. Display Adjacency List\n2. Display Adjacency Matrix")
choice = int(input("Enter your choice (1 or 2): "))
if choice == 1:
    g.display_list()
else:
    g.display_matrix()
