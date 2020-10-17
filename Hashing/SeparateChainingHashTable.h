#ifndef SEPARATECHAININGHASHTABLE_H
#define SEPARATECHAININGHASHTABLE_H
#include "LinkedList.h"
#include <iostream>
#include <ostream>
template <class T> class SeparateChainingHashTable {    
    private:       
        LinkedList<T>* theLists;   
        int tableSize;   
        int nextPrime(int n) {
            if( n%2==0)
                n++;
            for( ; !isPrime(n); n+=2)
                ;
            return n;
        }
        bool isPrime(int n) {
            if( n == 2 || n == 3 )
                return true;
            if( n == 1 || n % 2 == 0 )
                return false;
            for( int i = 3; i * i <= n; i+=2)
                if(n%i==0)
                    return false;
            return true;
        }
        int hash(T x) {  
            return x.hashCode()%tableSize;
        }
    public:
        SeparateChainingHashTable() {
            this(11);
        }
        SeparateChainingHashTable(int size) {
            tableSize=nextPrime(size); 
            theLists = new LinkedList<T>[tableSize]; // Garante que o tamanho é primo
            for(int i=0; i<tableSize;i++) {
                theLists[i]=LinkedList<T>();
            }  
        }
        void insert(T x) {
            int index=hash(x);         
            if (theLists[index].indexOf(x)==-1)  
                theLists[index].add(x,0);
        }       
        void remove(T x) {
            theLists[hash(x)].remove(x);
        }
        T find(T x) {    
            try {
                LinkedList<T> whichList = theLists[hash(x)];
                return whichList.get(whichList.indexOf(x));                 
            }
            catch (const char* e) {          
                throw "Elemento não está na tabela!";
            }
        }
        void clear() {
            for(int i=0; i<tableSize;i++) {
                theLists[i].clear;
            } 
        }
        void size(){
            int soma=0;
            for(int i = 0 ; i<tableSize; i++){
                if(theLists[i].size()>0){
                    soma += theLists[i].size()-1;
                }
                
            }
            cout<< soma<<endl;
        }
        void print() {
            for( int i=0; i<tableSize; i++ ) {  
                theLists[i].print(); 
                
                
            }
        }
        ~SeparateChainingHashTable() {
            delete[] theLists;
            
        }
};
#endif /* SEPARATECHAININGHASHTABLE_H */

