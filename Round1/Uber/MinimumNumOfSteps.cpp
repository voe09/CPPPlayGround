/*
I am learning data Structures from few days.Suppose, we have a Data structure that is built from layer of nodes. All layers start with 'start' node and end with a null value instead of last node. Each node has a 'value', 'foll' pointer to next node and 'down' pointer to the next node in the same layer. On each layer, values are sorted in ascending order.

Example:

S ---- 9 -------------------------------------->NULL

   | 
S -----9---------27---------51-------------->NULL

   |       |        |
S -----9---23---27--29---51----53------->NULL

Data Structure for Node:

       `      Class Node {
                      int value;
                       Node foll;
                          Node down;
                      }                 `
Write a function findNode that will get a starting node head and a search value value and will return the minimum number of jumps that are needed in order to either reach node with that value or to determine that it does not exist in the data structure.

Input : Number of layers, followed by a list of new nodes for each layer and finally the number that should be found. All of the values are integers larger than zero.

4

7

27 51

24 80

4 32 54 69 82

54
will result in data structure described above and value to be found is 54

Output

7
Can anyone please tell me, what should be following function in Java?

static int findNode(Node start, int value) { }
 */
