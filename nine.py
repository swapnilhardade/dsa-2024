# Define a class for each node in the BST
class Node:
    def _init_(self, data):
        self.data = data
        self.left = None
        self.right = None


# Define a class for the Binary Search Tree
class BST:
    def _init_(self):
        self.root = None

    # Function to insert nodes into BST
    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self._insert(self.root, data)

    def _insert(self, root, data):
        if data < root.data:
            if root.left is None:
                root.left = Node(data)
            else:
                self._insert(root.left, data)
        elif data > root.data:
            if root.right is None:
                root.right = Node(data)
            else:
                self._insert(root.right, data)

    # Display all parent nodes
    def display_parents(self, root):
        if root:
            if root.left or root.right:
                print(root.data, end=' ')
            self.display_parents(root.left)
            self.display_parents(root.right)

    # Display all child nodes
    def display_children(self, root):
        if root:
            if root.left:
                print(root.left.data, end=' ')
            if root.right:
                print(root.right.data, end=' ')
            self.display_children(root.left)
            self.display_children(root.right)

    # Display all leaf nodes
    def display_leaves(self, root):
        if root:
            if root.left is None and root.right is None:
                print(root.data, end=' ')
            self.display_leaves(root.left)
            self.display_leaves(root.right)

    # Display tree level (level-order traversal)
    def display_level(self):
        if self.root is None:
            return
        queue = [self.root]
        while queue:
            node = queue.pop(0)
            print(node.data, end=' ')
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)


# ---- Main Program ----
bst = BST()

# Insert 8 nodes into BST
nodes = [50, 30, 70, 20, 40, 60, 80, 35]
for n in nodes:
    bst.insert(n)

# --- Choose one display operation below ---

print("Parent Nodes:")
bst.display_parents(bst.root)

# print("Child Nodes:")
# bst.display_children(bst.root)

# print("Leaf Nodes:")
# bst.display_leaves(bst.root)

# print("Tree Level (Level-Order Traversal):")
# bst.display_level()
