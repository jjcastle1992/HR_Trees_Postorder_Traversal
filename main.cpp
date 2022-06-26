#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if(root == NULL) {
            return new Node(data);
        } else {
            Node* cur;
            if(data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            } else {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

/* you only have to complete the function given below.
Node is defined as

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
    /* Post-Order Traversal "visits":
     * 1. LEFT
     * 2. RIGHT
     * 3. ROOT
     *
     * Time Complexity O(n)
     * Space Complexity O(n)
     */

    void postOrder(Node *root) {
        //Check to see if the root is null
        if (root) {
            //Go left as far as you can
            postOrder(root->left);
            //Go right as far as you can
            postOrder(root->right);
            //Print your payload when you've gone to a leaf node.
            std::cout << root->data << " ";
        }
        else {
            return;
        }
    }

}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.postOrder(root);
    return 0;
}
