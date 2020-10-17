#ifndef QUADRATICPROBINGHASHTABLE_H
#define QUADRATICPROBINGHASHTABLE_H
#include "HashEntry.h"
using namespace std;
template <class T> class QuadraticProbingHashTable {
private:
    int m_size;
    int m_tableSize;
    HashEntry<T>** array;
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
public:
    QuadraticProbingHashTable () {
            this(11);
    }
    QuadraticProbingHashTable (int tableSize) {
        m_tableSize=tableSize;
        array=new HashEntry<T>*[tableSize];
        m_size=0;
        clear();
    }
    void clear( ) {
        m_size = 0;
        for(int i=0;i<m_tableSize;i++ ) {
             delete array[i];
             array[i]=NULL;
        }
    }
    int hash(T x) {  
	return x.hashCode()% m_tableSize;
    }
    int findPos(T x) {
        int currentPos = hash(x);
        int i= 0;     
        while(array[currentPos]!=NULL && !(array[currentPos]->element==x)) {
            currentPos += 2 * ++i-1;              // Calcula a i-ésima sondagem
            if (currentPos >= m_tableSize )       // verifica limite da tabela
                currentPos -= m_tableSize;
        }
        return currentPos;
    } 
    bool isActive(int currentPos) {
        return (array[currentPos]!=NULL) && (array[currentPos]->isActive);
    }
    T find(T x) {
        int currentPos = findPos(x);
        return isActive(currentPos) ? array[currentPos]->element : throw "Elemento não está na tabela";
    } 
    void insert(T x) {
        int currentPos = findPos(x);
        if (isActive(currentPos))  // se x já está na tabela não faz nada
            return;
        array[currentPos] = new HashEntry<T>(x,true);  // insere x como uma entrada ativa
        // limita o fator de carga a 0.5
        if(++m_size>m_tableSize/2)
           rehash();  
    }
    void remove(T x) {
        int currentPos = findPos(x);
        if( isActive( currentPos ) )
            array[currentPos]->isActive = false;  // define x como uma entrada inativa
    }

    void rehash() {
            // cria uma nova referência para o array atual
            HashEntry<T>** oldArray = array; 
            int old_tableSize=m_tableSize;            
            
            // cria um array vazio com o dobro da capacidade
            m_tableSize=nextPrime(m_tableSize*2);
            array=new HashEntry<T>*[m_tableSize];
            for (int i=0;i<m_tableSize;i++)
                array[i]=NULL;
            // zera o número de elementos no novo array
            m_size=0;   
            // copia os elementos ativos utilizando o método insert
            for(int i=0;i<old_tableSize;i++) {
                if(oldArray[i]!=NULL && oldArray[i]->isActive ) {
                    cout<<oldArray[i]->element<<endl;
                    insert(oldArray[i]->element);
                    //delete oldArray[i];
                }                     
            }
            delete[] oldArray;
            return;
    } 
    void print() {
        cout<<"<------------Início----------->"<<endl;
        for(int i=0;i<m_tableSize;i++ )
            if (array[i]!=NULL && array[i]->isActive)
                cout<<"i="<<i<<"-"<<array[i]->element<<endl;   
            else 
                cout<<"i="<<i<<"- Vazio"<<endl;                
        cout<<"<------------FIM----------->"<<endl;
    }
 
};
#endif /* QUADRATICPROBINGHASHTABLE_H */

