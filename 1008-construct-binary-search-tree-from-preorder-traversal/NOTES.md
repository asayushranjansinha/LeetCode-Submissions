Approach 1:
Create BST considering preorder as random stream of elements.
Here we do N insertions & N comparison for each insertion so TC: N^2
While SC: O(1)
​
Approach 2:
We can get inorder from sorting preorder & then we can create tree using both.
Here we take N log N time in sorting & N time in creating by visiting each node once.
so, TC: o(n log n)
SC: o(n) for storing inorder.