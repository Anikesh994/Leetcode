class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;

        Node* leftmost = root;

        while (leftmost->left) {
            Node* curr = leftmost;

            while (curr) {
                // Connect left child to right child
                curr->left->next = curr->right;

                // Connect right child to next node's left child
                if (curr->next) {
                    curr->right->next = curr->next->left;
                }

                curr = curr->next;
            }

            // Move to next level
            leftmost = leftmost->left;
        }

        return root;
    }
};