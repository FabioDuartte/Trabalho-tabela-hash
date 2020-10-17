#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "ListNode.h"
using namespace std;
template <class T> class LinkedList {    
    private:       
        ListNode<T>* m_head;
        ListNode<T>* m_tail;     
        int m_size;       
    public:
        LinkedList() {
            m_size=0;
            m_head=NULL;
            m_tail=NULL;
        }
        bool isEmpty() {
            return m_size==0;
        }
        int size() {
            return m_size;
        } 
        void add(T elem) {
                ListNode<T> *newElement=new ListNode<T>(elem);
                if (m_size==0)          // insere em uma lista vazia
                    m_head=newElement;
                else                    // a lista possui pelo menos um elemento
                    m_tail->next=newElement;
                m_tail=newElement;
                m_size++;
        }   
        bool add (T elem, int index) {
            if (index<0 || index>m_size) 
                return false;
            else {
                if (index==0) {     //insere o elemento na posicao head
                    if (m_size==0)  {        // insere em uma lista vazia
                        ListNode<T> *newElement=new ListNode<T>(elem);
                        m_head=m_tail=newElement;
                    }
                    else {                  // insere em uma lista com um ou mais elementos
                        ListNode<T> *newElement=new ListNode<T>(elem,m_head);
                        m_head=newElement;    
                    }
                }
                else {
                    ListNode<T> *previous=findPrevious(index);
                    ListNode<T> *newElement=new ListNode<T>(elem,previous->next);
                    previous->next=newElement;
                    if (index==m_size)  // o novo elemento e o novo tail
                        m_tail=newElement;
                }
            }
            m_size++;
            return true;
        }   
        T get (int index) {
        if (index<0 || index>=m_size) {
            throw "Índice fora dos limites da lista!";
        }
            ListNode<T> *itr=m_head; 
            for (int i=0;i<index;i++) {
                itr=itr->next;
            }                  
            return itr->element;
        }
        ListNode<T> *findPrevious (int index) {
            ListNode<T> *itr=m_head;
            ListNode<T> *previous=NULL;
            for (int i=0;i<m_size;i++) {
                if (i==index)
                    break;
                previous=itr;
                itr=itr->next;
            }
            return previous;
        }
        int indexOf (T elem ) {
            ListNode<T> *itr=m_head;
            for (int i=0;i<m_size;i++) {
                if (itr->element==elem) 
                    return i;
                itr=itr->next;       
            }
            return -1;
        }
        void clear() {
            if (isEmpty())
                return;
            ListNode<T> *itr=m_head;
            for (int i=0;i<m_size;i++) {
                ListNode<T> *nodeToBeDeleted=itr;
                itr=itr->next;
                delete nodeToBeDeleted;
            } 
            m_size=0;
        }
        bool remove (T elem) {
            int index=indexOf(elem);
            if (index==-1) 
                return false;
            else 
                return remove(index);
        }
        bool remove (int index) {    
            if (index<0 || index>m_size-1) //  o elemento nao esta na lista
                return false;  

            if (index==0) {  // remove o no head
                if (m_size==1) { // caso especial: somente um elemento na lista
                    delete m_head;
                }   
                else {
                    ListNode <T> *nodeToBeDeleted=m_head;
                    m_head=m_head->next;
                    delete nodeToBeDeleted;
                }
            }
            else {		// remove um elemento diferente do head
                ListNode <T> *previous=findPrevious(index);
                ListNode<T> *nodeToBeDeleted=previous->next;
                previous->next=previous->next->next; 
                delete nodeToBeDeleted;
                if (index==m_size-1) // remoção do tail
                    m_tail=previous;
            }
            m_size--; 
            return true;
        } 
        void print() {
            if (isEmpty()) {
                cout<<"Lista Vazia"<<endl;  
                return;
            }
            cout<<"--------Início da lista------"<<endl;
            ListNode<T> *itr=m_head;
            for (int i=0;i<m_size;i++) {
                cout<<itr->element<<endl;
                itr=itr->next;
            } 
            cout<<"--------Fim da lista---------"<<endl;
       }            
};
#endif /* LINKEDLIST_H */

