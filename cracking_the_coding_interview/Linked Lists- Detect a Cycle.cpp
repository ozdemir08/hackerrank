/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
    struct Node {
        int data;
        struct Node* next;
    }
*/

int visited;

bool has_cycle(Node* head) {
    if(head == NULL) {
        visited = 0;
        return false;
    }
    if(visited > 100) {
        visited = 0;
        return true;
    }
    visited ++;
    return has_cycle(head -> next);

    // Complete this function
    // Do not write the main method
}
