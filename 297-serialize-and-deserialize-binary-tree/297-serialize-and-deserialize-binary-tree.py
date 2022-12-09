# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        l = []
        def dfs(node):
            if not node:
                l.append("N")
                return
            l.append(str(node.val))
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        return ",".join(l)
            
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        l = data.split(",")
        self.i = 0
        def traverse():
            if l[self.i] == "N":
                self.i += 1
                return None
            node = TreeNode(int(l[self.i]))
            self.i+=1
            node.left = traverse()
            node.right = traverse()
            return node
        return traverse()
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))