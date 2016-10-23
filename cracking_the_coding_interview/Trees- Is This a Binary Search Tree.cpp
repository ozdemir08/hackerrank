/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
#include <climits>
   bool checkBST(Node* root, int minn, int maxx){

      bool result = (root -> data > minn && root -> data < maxx);

      if(root -> left)
          result &= root -> left -> data < root -> data && checkBST(root -> left, minn, root -> data);

      if(root -> right)
          result &= root -> right -> data > root -> data && checkBST(root -> right, root -> data, maxx);
      return result;
   }

   bool checkBST(Node* root) {
        return checkBST(root, INT_MIN, INT_MAX);
   }
