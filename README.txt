# Binary-Search-Tree
In the ninth part, you will extend the binary search tree in the eighth part to support the deletion of a node. The deletion of a node is slightly trickier compared to the search and insert in the eighth
6
part.
The deletion is straightforward if the node to be deleted has only one child. You make the parent of the node to be deleted point to that child. In this scenario, special attention must be paid only when the node to be deleted is the root.
Deleting a node with two children requires some more work. In this case, you must find the minimum element in the right subtree of the node to be deleted. This is the left-most node in the right subtree. Then you insert that node in the place where the node to be deleted was. The moved node may have a right child. You need to update the parent of the moved node to point to this child instead of the moved node.
In either case, if the node to be deleted is the root, you must update the pointer to the root to point to the new root node.
Input format: This program takes a file name as argument from the command line. The file is either blank or contains successive lines of input. Each line contains a character, ’i’, ’s’, or ’d’, followed by a tab and an integer. For each line that starts with ’i’, your program should insert that number in the binary search tree if it is not already there. Your program should print ”duplicate” and not insert anything if that value is already present in the binary search tree. If the line starts with a ’s’, your program should search for that value. If the line starts with a ’d’, your program should delete that value from the tree.
Output format: For each line in the input file, your program should print the status/result of the operation. For insert and search, the output is the same as in the Eighth Part: For an insert operation, the program should print either “inserted” followed by a number, the height of the inserted node in the tree, or ”duplicate” if the value is already present in the treee. The height of the root node is 1. For a search, the program should either print ”present”, followed by the height of the node, or ”absent” based on the outcome of the search. For a delete, the program should print ”success” or ”fail” based on the whether the value was present or not. Again, as in the Eight Part, your program should print ”error” (and nothing else) if the file does not exist or for input lines with improper structure.
Example Execution:
Lets assume we have a file file1.txt with the following contents:
i5 i3 i4 i1 i6 i2 s1 d3 s4
Executing the program in the following fashion should produce the output shown below:
./ninth file1.txt
inserted 1
7
inserted 2
inserted 3
inserted 3
inserted 2
inserted 4
present 3
success
present 2
