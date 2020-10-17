#ifndef LISTNODE_H
#define LISTNODE_H
template <class T> class ListNode {
    public:
        T element;
        ListNode<T>* next;
        ListNode (T e) {
            element=e;
            next=NULL;
        }
        ListNode (T e,ListNode *n) {
            element=e;
            next=n;
        }
}; 
#endif /* LISTNODE_H */

