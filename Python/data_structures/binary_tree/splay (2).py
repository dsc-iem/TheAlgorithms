
 
import warnings
from extra.trees.bst import BST


class SplayTr(BST):
    

    __name__ = "extra.SplayTree()"

    def __init__(self, iterable=None):
       
        super().__init__(iterable)

   
    def __len__(self):
        
        return super().__len__()

    def is_empty(self):
        
        return super().is_empty()

   
    def get_max(self):
        
        return super().get_max()

    
    def get_min(self):
        
        return super().get_min()

    
    def __zig_zig(self, start_node):
        assert isinstance(start_node, self._basic_node)
        # print("zig-zig operation")
        child = start_node
        parent = child.get_parent()
        grand_parent = child.get_grand_parent()
        # start zig-zig
        child.set_parent(grand_parent.get_parent())
        grand_parent.set_left(parent.get_right())
        parent.set_right(grand_parent)
        parent.set_left(child.get_right())
        child.set_right(parent)
        # child is now the grand-parent
        return child

    def __zag_zag(self, start_node):
        assert isinstance(start_node, self._basic_node)
        # print("zag-zag operation")
        child = start_node
        parent = child.get_parent()
        grand_parent = child.get_grand_parent()
        # start zag-zag
        child.set_parent(grand_parent.get_parent())
        grand_parent.set_right(parent.get_left())
        parent.set_left(grand_parent)
        parent.set_right(child.get_left())
        child.set_left(parent)
        # child is now the grand-parent
        return child

    def __zig_zag(self, start_node):
        assert isinstance(start_node, self._basic_node)
        # print("zig-zag operation")
        child = start_node
        parent = child.get_parent()
        grand_parent = child.get_grand_parent()
        # start zig-zag
        child.set_parent(grand_parent.get_parent())
        grand_parent.set_left(child.get_right())
        parent.set_right(child.get_left())
        child.set_right(grand_parent)
        child.set_left(parent)
        return child

    def __zag_zig(self, start_node):
        assert isinstance(start_node, self._basic_node)
        # print("zag-zig operation")
        child = start_node
        parent = child.get_parent()
        grand_parent = child.get_grand_parent()
        # start zag-zig
        child.set_parent(grand_parent.get_parent())
        grand_parent.set_right(child.get_left())
        parent.set_left(child.get_right())
        child.set_left(grand_parent)
        child.set_right(parent)
        return child

    def __zig(self, start_node):
        assert isinstance(start_node, self._basic_node)
        # print("zig operation")
        child = start_node
        parent = child.get_parent()
        child.set_parent(parent.get_parent())
        parent.set_left(child.get_right())
        child.set_right(parent)
        return child

    def __zag(self, start_node):
        assert isinstance(start_node, self._basic_node)
        # print("zag operation")
        child = start_node
        parent = child.get_parent()
        child.set_parent(parent.get_parent())
        parent.set_right(child.get_left())
        child.set_left(parent)
        return child

    def __splaying(self, start_node):
        assert isinstance(start_node, self._basic_node)
        child = start_node
        parent = child.get_parent()
        if parent is None:
            return start_node
        grand_parent = child.get_grand_parent()
        # get the operation type
        if grand_parent is None:
            if child.is_left_child():
                root = self.__zig(child)
            else:
                root = self.__zag(child)
        else:
            # left -> left
            if parent.is_left_child() and child.is_left_child():
                grand_parent = self.__zig_zig(child)
            # left -> right
            elif parent.is_left_child() and not child.is_left_child():
                grand_parent = self.__zig_zag(child)
            # right -> left
            elif not parent.is_left_child() and child.is_left_child():
                grand_parent = self.__zag_zig(child)
            # right -> right
            else:
                grand_parent = self.__zag_zag(child)
            if grand_parent.get_parent() is not None:
                root = self.__splaying(grand_parent)
            else:
                root = grand_parent
        return root

    def _splay(self, start_node):
        
        self._root = self.__splaying(start_node)

   
    def __contains__(self, find_val):
        
        super()._validate_item(find_val)
        node = super()._search(find_val, self._root)
        self._splay(node)
        return node.get_data() == find_val

   
    def insert(self, value):
        
        super()._validate_item(value)
        if self.is_empty():
            self._root = super()._basic_node(value)
            self._length += 1
        else:
            new_node = super()._insert(value)
            self._splay(new_node)

   
    def remove(self, del_value):

        if self.is_empty():
            warnings.warn(f"`{self.__name__}` is empty!!", UserWarning)
            return
        elif type(del_value) not in {int, float}:
            warnings.warn(
                f"Couldn't find `{del_value}` in `{self.__name__}`!!",
                UserWarning
            )
            return
        # check if splay tree has only one item and it's the one to be deleted
        elif self._root.is_leaf() and del_value == self._root.get_data():
            self._root = None
            self._length -= 1
        else:
            node = super()._remove(del_value, self._root)
            self._splay(node)

    def clear(self):
        
        super().clear()

    
    def get_height(self):
        
        return super().get_height()

    def get_depth(self):
        
        return super().get_depth()

    
    def count_leaf_nodes(self):
        
        return super().count_leaf_nodes()

   
    def is_balanced(self):
        
        return super().is_balanced()

   
    def is_perfect(self):
        
        return super().is_perfect()

    
    def is_strict(self):
        
        return super().is_strict()

   
    def __iter__(self):
        
        return super().__iter__()

    def to_list(self):
        
        return super().to_list()

    
    def get_nodes_per_level(self):
        
        return super().get_nodes_per_level()

    
    def preorder_traverse(self):
        
        return super().preorder_traverse()

    def depth_first_traverse(self):
        
        return super().depth_first_traverse()

    
    def postorder_traverse(self):
        
        return super().postorder_traverse()

    
    def inorder_traverse(self):
     
        return super().inorder_traverse()

    
    def breadth_first_traverse(self):
        
        return super().breadth_first_traverse()

   
    def traverse(self, method="inorder"):
     
        return super().traverse(method)


if __name__ == '__main__':
    lst = []
 
    # number of elements as input
    n = int(input("Enter number of elements : "))
 
    # iterating till the range
    for i in range(0, n):
       ele = int(input())
 
       lst.append(ele) # adding the element
     
    stree = SplayTr(lst)
    print(stree) 

    while True:
         
         print("Next?")
         n = int(input("1. for insert 2. removal"))

         if n == 1:
             b = int(input("insert what?"))
             stree.insert(b)
             print(stree)

         else :
             c = int(input("remove what?"))
             stree.remove(c)
             print(stree)
