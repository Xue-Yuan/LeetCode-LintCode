struct Node {
    int val;
    Node *next;
    Node(int _val): val(_val), next(nullptr) {}    
};

Node* solution(Node *head, int val) {
    Node *ret = new Node(val);
    if (!head) {
        ret->next = ret;
    } else {
        Node *pre = head;
        while (true) {
            if (pre->val <= val && val <= pre->next->val) {
                break;
            } else if (pre->next->val < pre->val && (pre->val < val || pre->next->val < val)) {
                break;
            }
            pre = pre->next;
        }
        ret->next = pre->next;
        pre->next = ret;
    }
    return ret;
}
