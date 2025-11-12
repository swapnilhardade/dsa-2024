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

    # Function to insert a new node
    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self._insert(self.root, data)

    # Helper function for insertion
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

    # In-Order Traversal (Left, Root, Right)
    def inorder(self, root):
        if root:
            self.inorder(root.left)
            print(root.data, end=' ')
            self.inorder(root.right)

    # Pre-Order Traversal (Root, Left, Right)
    def preorder(self, root):
        if root:
            print(root.data, end=' ')
            self.preorder(root.left)
            self.preorder(root.right)

    # Post-Order Traversal (Left, Right, Root)
    def postorder(self, root):
        if root:
            self.postorder(root.left)
            self.postorder(root.right)
            print(root.data, end=' ')

# ---- Main Program ----
bst = BST()

# Insert 8 nodes into BST
nodes = [50, 30, 70, 20, 40, 60, 80, 35]
for n in nodes:
    bst.insert(n)

# Display the BST using one traversal
print("In-Order Traversal of BST:")
bst.inorder(bst.root)

# To try others, uncomment below:
# print("\nPre-Order Traversal of BST:")
# bst.preorder(bst.root)
# print("\nPost-Order Traversal of BST:")
# bst.postorder(bst.root)
