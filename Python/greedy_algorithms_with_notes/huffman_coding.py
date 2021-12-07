class Node:

    def __init__(self, char, freq, left=None, right=None):
        self.char = char
        self.freq = freq
        self.left = left
        self.right = right
        self.huff = ""


chars = ["a", "b", "c", "d", "e"]
freq = [2, 3, 5, 6, 7]
nodes = []

def print_huffman(node, val=''):
    new_val = val + str(node.huff)
    if node.left:
        print_huffman(node.left, new_val)
    if node.right:
        print_huffman(node.right, new_val)
    if (not node.left and not node.right):
        print(f"{node.char} -> {new_val}")

    

for i in range(len(chars)):
    nodes.append(Node(chars[i], freq[i]))

while len(nodes) > 1:
    nodes = sorted(nodes, key=lambda x: x.freq)

    left = nodes[0]
    right = nodes[1]

    left.huff = 0
    right.huff = 1

    # adding the nodes to create the parent node.
    new_node = Node(left.char+right.char, left.freq+right.freq, left, right)

    nodes.remove(left)
    nodes.remove(right)
    nodes.append(new_node)


print_huffman(nodes[0])