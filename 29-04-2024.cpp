
/*

Author : mrpankajpandey
Date : 29/04/2024
Problem : Remove every kth node
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/remove-every-kth-node/1
Video Solution : NA

*/

class Solution {
    public:
    Node* deleteK(Node *head,int K){
      //Your code here
      if (!head || K <= 1) // If list is empty or K is 1, remove all nodes
            return nullptr;

        Node *dummy = new Node(0);
        dummy->next = head;
        Node *prev = dummy;
        int count = 0;

        while (head) {
            count++;
            if (count % K == 0) {
                prev->next = head->next;
                delete head;
                head = prev->next;
            } else {
                prev = head;
                head = head->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};