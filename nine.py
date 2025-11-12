class Node:
    def _init_(self, data):
        self.data = data
        self.left = None
        self.right = None

class BST:
    def _init_(self):
        self.root = None

    def insert(self, data):
        if not self.root:
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

    def display_parents(self, root):
        if root:
            if root.left or root.right:
                print(root.data, end=" ")
            self.display_parents(root.left)
            self.display_parents(root.right)

    def display_children(self, root):
        if root:
            if root.left:
                print(root.left.data, end=" ")
            if root.right:
                print(root.right.data, end=" ")
            self.display_children(root.left)
            self.display_children(root.right)

    def display_leaves(self, root):
        if root:
            if not root.left and not root.right:
                print(root.data, end=" ")
            self.display_leaves(root.left)
            self.display_leaves(root.right)

    def height(self, root):
        if not root:
            return 0
        return 1 + max(self.height(root.left), self.height(root.right))

bst = BST()
print("Enter 8 node values:")
for i in range(8):
    val = int(input(f"Enter value {i+1}: "))
    bst.insert(val)

print("\nParent Nodes:")
bst.display_parents(bst.root)

print("\nChild Nodes:")
bst.display_children(bst.root)

print("\nLeaf Nodes:")
bst.display_leaves(bst.root)

print("\nTree Level (Height):", bst.height(bst.root))
