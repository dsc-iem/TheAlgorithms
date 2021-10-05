
 
import warnings
from extra.trees.bst import BST


class SplayTr(BST):
    """
    A Splay Tree is a non-linear data structure that can be defined recursively
    using a collection of binary tree nodes, where each node contains a numeric
    value and it has either zero, one or two references to the children binary
    tree nodes. Any node that has been accessed is moved to the root directly
    to make it faster to be accessed again. This operation is called
    "splaying". Hence the name of this data structure... Splay Tree.
    """

    __name__ = "extra.SplayTree()"

    def __init__(self, iterable=None):
        """
        Initializes a `SplayTree()` instance using an optional iterable object
        in time-complexity of O(n) where **n** is the number of elements inside
        the given `iterable`.
        Parameters
        ----------
        iterable: iterable, optional
            An iterable python object that implements the `__iter__` method.
            For example, `list` and `tuple` are both iterables.
        Raises
        ------
        TypeError:
            It can be raised in two cases
                1. In case the given object isn't iterable.
                2. If one of the elements in the iterable is an `Extra` object.
                3. If one of the elements in the iterable is NOT a number.
        ValueError:
            If one of the iterable elements is `None`.
        Examples
        --------
        >>> stree = SplayTree([2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        Using an iterable object with `None` as one of its elements will raise
        `ValueError`
        >>> SplayTree([2, None])
        ValueError: Can't use `None` as an element within `extra.SplayTree()`!!
        Using a non-iterable object will raise `TypeError`
        >>> SplayTree(2)
        TypeError: The given object isn't iterable!!
        Using nested `SplayTree()` objects will raise `TypeError` as well
        >>> stree_1 = SplayTree([1])
        >>> stree_2 = SplayTree([1, stree_1])
        TypeError: Can't create `extra.SplayTree()` using `extra.SplayTree()`!!
        """
        super().__init__(iterable)

    # =============================    LENGTH    ==============================
    def __len__(self):
        """
        Gets the length of the `SplayTree()` instance in constant time.
        Returns
        -------
        int:
            The length of the `SplayTree()` instance. Length is the number of
            tree nodes in the instance.
        Example
        -------
        >>> stree = SplayTree([[2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> len(stree)
        5
        """
        return super().__len__()

    def is_empty(self):
        """
        Checks if the `SplayTree()` instance is empty or not in constant time.
        Returns
        -------
        bool:
            A boolean flag showing if the `SplayTree()` instance is empty or
            not. `True` shows that this instance is empty and `False` shows
            it's not empty.
        Example
        --------
        >>> stree = SplayTree()
        >>> stree.is_empty()
        True
        >>> stree.insert(10)
        >>> stree.is_empty()
        False
        """
        return super().is_empty()

    # =============================      MAX     ==============================
    def get_max(self):
        """
        Gets the maximum value in the `SplayTree()` isntance. The maximum value
        can be found at the right-most tree node in the `SplayTree()` instance.
        Returns
        -------
        int or float:
            The maximum numeric value in the `SplayTree()` instance.
        Raises
        ------
        IndexError:
            In case the `SplayTree()` instance is empty.
        Example
        -------
        >>> stree = SplayTree([[2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.get_max()
        6
        """
        return super().get_max()

    # =============================      MIN     ==============================
    def get_min(self):
        """
        Gets the minimum value in the `SplayTree()` isntance. The minimum value
        can be found at the left-most tree node in the `SplayTree()` instance.
        Returns
        -------
        int or float:
            The maximum numeric value in the `SplayTree()` instance.
        Raises
        ------
        IndexError:
            In case the `SplayTree()` instance is empty.
        Example
        -------
        >>> stree = SplayTree([[2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.get_min()
        2
        """
        return super().get_min()

    # =============================    SPLAY     ==============================
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
        """
        Splays the given subtree whose root is the given `start_node` object.
        Splaying means "moving the node to the root". And this operation is
        done after searching, insertion and deletion.
        Parameters
        ----------
        start_node: BSTNode()
            A reference to the root of the subtree.
        """
        self._root = self.__splaying(start_node)

    # =============================    SEARCH    ==============================
    def __contains__(self, find_val):
        """
        Searches the `SplayTree()` for the given value and returns `True` if
        the value exists and `False` if not.
        Parameters
        ----------
        find_val: int or float
            The value to be searched for in the `SplayTree()` instance.
        Returns
        -------
        bool:
            Returns `True` if the value exists in the `SplayTree()` instance
            and `False` if not.
        Example
        -------
        >>> stree = SplayTree([[2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> 5 in stree
        True
        >>> stree
            __5
           /   \\
          3     6
         / \\
        2   4
        >> 50 in stree
        False
        >>> stree
                6
               /
            __5
           /
          3
         / \\
        2   4
        Note
        ----
        As you can see from the previous example, the `SplayTree()` instance
        changes its structure each time we search for a certain value. If the
        value if found, the found node will be moved to the root. If the value
        isn't found, the last accessed node will be moved to the root. And
        that's what happended when searching for `50`, the last accessed value
        which is the greatest value (`6`) in the splay tree is moved to the
        root.
        """
        super()._validate_item(find_val)
        node = super()._search(find_val, self._root)
        self._splay(node)
        return node.get_data() == find_val

    # =============================    INSERT    ==============================
    def insert(self, value):
        """
        Inserts a numeric value in the SplayTree()` instance according to the
        rules of binary search trees.
        Parameters
        ----------
        value: int or float
            The new numeric value that will be inserted.
        Raises
        ------
        ValueError:
            If the given `value` is `None`.
        TypeError:
            If the given `value` is not a numeric value.
        Example
        -------
        >>> stree = SplayTree()
        >>> stree.insert(10)
        >>> stree
        10
        >>> stree.insert(5)
        >>> stree
        5
         \\
          10
        >>> stree.insert(15)
        >>> stree
            _15
           /
          10
         /
        5
        >>> stree.insert(8)
        >>> stree
          8___
         /    \\
        5     _15
             /
            10
        >>> stree.insert("2")
        TypeError: `extra.SplayTree()` accepts only numbers!!
        """
        super()._validate_item(value)
        if self.is_empty():
            self._root = super()._basic_node(value)
            self._length += 1
        else:
            new_node = super()._insert(value)
            self._splay(new_node)

    # =============================    REMOVAL   ==============================
    def remove(self, del_value):
        """
        Removes the `del_value` from the `SplayTree()` instance.
        Parameters
        ----------
        del_value: int or float
            The value to be deleted from the subtree.
        Raises
        ------
        UserWarning:
            If the `SplayTree()` instance is empty of if the value wasn't found
            in the instance.
        Example
        -------
        >>> stree = SplayTree([2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.remove(5)
        >>> stree
            __6
           /
          3
         / \\
        2   4
        >>> stree.remove(50)
        UserWarning: Couldn't find `50` in `extra.SplayTree()`!!
        """
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
        """
        Removes all nodes within the `SplayTree()` instance in constant time.
        Example
        -------
        >>> stree = SplayTree([[2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.clear()
        >>> stree
        / \\
        >>> stree.is_empty()
        True
        """
        super().clear()

    # ============================= HEIGHT/DEPTH ==============================
    def get_height(self):
        """
        Gets the height of the `SplayTree()` instance. The SplayTree's height
        is the number of edges between the root and the furthest leaf node.
        Returns
        -------
        int:
            A positive integer representing the height of the instance.
        Example
        -------
        >>> stree = SplayTree([2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.get_height()
        2
        >>> 6 in stree
        True
        >>> stree.get_height()
        3
        Note
        ----
        The height of the `SplayTree()` instance is changed after any operation
        such as insertion, removal or even searching as we saw in the previous
        example.
        """
        return super().get_height()

    def get_depth(self):
        """
        Gets the depth of the `SplayTree()` instance.
        Returns
        -------
        int:
            A positive integer representing the depth of the instance.
        Example
        -------
        >>> stree = SplayTree([[2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.get_depth()
        0
        """
        return super().get_depth()

    # =============================  LEAF NODES  ==============================
    def count_leaf_nodes(self):
        """
        Counts the number of leaf nodes in the `SplayTree()` instance. Leaf
        nodes are the tree nodes that have no children.
        Returns
        -------
        int:
            A positive integer representing the number of leaf nodes in the
            `SplayTree()`.
        Example
        -------
        >>> stree = SplayTree([2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.count_leaf_nodes()
        3
        >>> 4 in stree
        True
        >>> stree.count_leaf_nodes()
        2
        Note
        ----
        The number of leaf nodes inside the `SplayTree()` instance is changed
        after any operation such as insertion, removal or even searching as we
        saw in the previous example.
        """
        return super().count_leaf_nodes()

    # =============================    BALANCE   ==============================
    def is_balanced(self):
        """
        Checks if the `SplayTree()` instance is balanced. A `SplayTree()`
        instance is balanced if the difference between the depth of any two
        leaf nodes is less than or equal to one.
        Returns
        -------
        bool:
            `True` if the `SplayTree()` instance is balanced and `False` if it
            is not balanced.
        Raises
        ------
        UserWarning:
            If the `SplayTree()` is empty.
        Example
        -------
        >>> stree = SplayTree([2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.is_balanced()
        True
        >>> 2 in stree
        True
        >>> stree.is_balanced()
        False
        Note
        ----
        The balance of the `SplayTree()` instance is changed after any
        operation such as insertion, removal or even searching as we saw in
        the previous example.
        """
        return super().is_balanced()

    # =============================    PERFECT   ==============================
    def is_perfect(self):
        """
        Checks if the `SplayTree()` instance is perfect. A `SplayTree()`
        instance is perfect if all its levels are completely filled.
        Returns
        -------
        bool:
            `True` if the `SplayTree()` instance is perfect and `False` if it
            is not perfect.
        Raises
        ------
        UserWarning:
            If the `SplayTree()` is empty.
        Example
        -------
        >>> stree = SplayTree([2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.is_perfect()
        False
        Note
        ----
        The perfectness of the `SplayTree()` instance is changed after any
        operation such as insertion, removal or even searching.
        """
        return super().is_perfect()

    # =============================    STRICT    ==============================
    def is_strict(self):
        """
        Checks if the `SplayTree()` instance is strict. A `SplayTree()`
        instance is strict if all its non-leaf nodes have two children (left
        and right).
        Returns
        -------
        bool:
            `True` if the `SplayTree()` instance is strict and `False` if it is
            not strict.
        Raises
        ------
        UserWarning:
            If the `SplayTree()` is empty.
        Example
        -------
        >>> stree = SplayTree([2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.is_strict()
        True
        >>> 2 in stree
        True
        >>> stree.is_strict()
        False
        Note
        ----
        The strictness of the `SplayTree()` instance is changed after any
        operation such as insertion, removal or even searching as we saw in the
        previous example
        """
        return super().is_strict()

    # =============================     ITER     ==============================
    def __iter__(self):
        """
        Iterates over the `SplayTree()` instance and returns a generator of the
        `SplayTreeNode()` values in breadth-first manner.
        Yields
        -------
        int or float:
            The number stored at each node in the instance.
        Example
        -------
        >>> stree = SplayTree([2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> for value in stree:
        ...     print(value, end=',')
        3,2,5,4,6,
        """
        return super().__iter__()

    def to_list(self):
        """
        Converts the `SplayTree()` instance to a `list` where values will be
        inserted in breadth-first manner.
        Returns
        -------
        list:
            A `list` object containing the same elements as the `SplayTree()`
            instance.
        Example
        -------
        >>> stree = SplayTree([2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.to_list()
        [3, 2, 5, 4, 6]
        """
        return super().to_list()

    # =============================     NODES    ==============================
    def get_nodes_per_level(self):
        """
        Retrieves all tree nodes within the `SplayTree()` instance so that all
        tree nodes in a certain level will be concatenated into a separate
        list.
        Returns
        -------
        list:
            A nested list where the first inner-list has all the tree nodes in
            the first level, the second inner-list has all the tree nodes in
            the second level, ... so on.
        Example
        -------
        >>> stree = SplayTree([2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.get_nodes_per_level()
        [[3], [2, 5], [4, 6]]
        """
        return super().get_nodes_per_level()

    # =============================   PRE-ORDER  ==============================
    def preorder_traverse(self):
        """
        Traverses the `SplayTree()` instance in pre-order manner. Which means
        that the **parent** is visited first. Then, the **left subtree** (if
        found), then the **right subtree** (if found).
        Note
        -----
        It's the same as `depth_first_traverse()` method.
        Returns
        --------
        list:
            A list of all values of the pre-order visited nodes.
        Example
        -------
        >>> stree = SplayTree([2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.preorder_traverse()
        [3, 2, 5, 4, 6]
        """
        return super().preorder_traverse()

    def depth_first_traverse(self):
        """
        Traverses the `SplayTree()` instance in depth-first manner. Which means
        that the **parent** is visited first. Then, the **left subtree** (if
        found), then the **right subtree** (if found).
        Note
        -----
        It's the same as `preorder_traverse()` method.
        Returns
        --------
        list:
            A list of all values of the pre-order visited nodes.
        Example
        -------
        >>> stree = SplayTree([2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.depth_first_traverse()
        [3, 2, 5, 4, 6]
        """
        return super().depth_first_traverse()

    # =============================  POST-ORDER  ==============================
    def postorder_traverse(self):
        """
        Traverses the `SplayTree()` instance in post-order manner. Which means
        that the **left subtree** (if found) is visited first. Then, the
        **right subtree** (if found) then the **parent**.
        Returns
        --------
        list:
            A list of all values of the pre-order visited nodes.
        Example
        -------
        >>> stree = SplayTree([2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.postorder_traverse()
        [2, 4, 6, 5, 3]
        """
        return super().postorder_traverse()

    # =============================   IN-ORDER   ==============================
    def inorder_traverse(self):
        """
        Traverses the `SplayTree()` instance in in-order manner. Which means
        that the **left subtree** (if found) is visited first. Then, the
        **parent** then the **right subtree** (if found).
        Returns
        --------
        list:
            A list of all values of the in-order visited nodes.
        Example
        -------
        >>> stree = SplayTree([2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.inorder_traverse()
        [2, 3, 4, 5, 6]
        """
        return super().inorder_traverse()

    # ============================= BREADTH-FIRST==============================
    def breadth_first_traverse(self):
        """
        Traverses the `SplayTree()` instance in breadth-first manner. Which
        means that the tree nodes will be visited level by level.
        Returns
        --------
        list:
            A list of all values of the pre-order visited nodes.
        Example
        -------
        >>> stree = SplayTree([2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.breadth_first_traverse()
        [3, 2, 5, 4, 6]
        """
        return super().breadth_first_traverse()

    # =============================   TRAVERSE   ==============================
    def traverse(self, method="inorder"):
        """
        Traversal is the process to visit all nodes of a SplayTree starting
        from the root as we cannot randomly access any node in a binary tree.
        There are four ways which we use to traverse a `SplayTree()`:
        1. preorder - depth-first
        2. inorder
        3. posteorder
        4. breadth-first
        Parameters
        ----------
        method: str (default="inorder")
            A lower-cased string describing the type of traversal that will be
            used. It could be one of these values: ["inorder", "postorder",
            "preorder", "depth-first", "breadth-first"]
        Returns
        --------
        list:
            A list of all values of the visited nodes according to the
            specified traversal method.
        Raises
        ------
        ValueError:
            If the given method isn't known.
        TypeError:
            If the given method isn't a string.
        Example
        -------
        >>> stree = SplayTree([2, 5, 4, 6, 3])
        >>> stree
          3__
         /   \\
        2     5
             / \\
            4   6
        >>> stree.traverse("preorder")
        [3, 2, 5, 4, 6]
        >>> stree.traverse("inorder")
        [2, 3, 4, 5, 6]
        >>> stree.traverse("postorder")
        [2, 4, 6, 5, 3]
        >>> stree.traverse("breadth-first")
        [3, 2, 5, 4, 6]
        >>> stree.traverse("extra")
        ValueError: Given traverse method has to be one of these:
        {'breadth-first', 'postorder', 'inorder', 'depth-first', 'preorder'}
        """
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
