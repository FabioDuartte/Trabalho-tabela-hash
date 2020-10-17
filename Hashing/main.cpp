#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include<sstream>
#include "SeparateChainingHashTable.h"
#include "QuadraticProbingHashTable.h"
#include "Aluno.h"

using namespace std;
int hash0 (int key, int tableSize) {
	return key%tableSize;
}
int hash1 (string key, int tableSize) {
     int hashValue=0;
     for (int i=0;i<key.length();i++) {
           hashValue+=key[i];
      }
      return hashValue%tableSize;
}
int hash2 (string key, int tableSize) {
     int hashValue;
     hashValue=key[0]+key[1]*27+key[2]*729;     
     return hashValue%tableSize;
}
int hash3 (string key, int tableSize) {
     int hashValue=0;
     // resolve o polinômio para x=37
     for (int i=0;i<key.length();i++)
           hashValue=37*hashValue+key[i];
     // calcula o código hash
     hashValue%=tableSize;
     // trata um possível int overflow
     if (hashValue<0)
 	hashValue+=tableSize;        
     return  hashValue;          
}        


main(int argc, char** argv) { 
    SeparateChainingHashTable<Aluno> hashTable=SeparateChainingHashTable<Aluno>(2357);
 //   hashTable.print();
    
    fstream arquivo;
    string linha;
    string mat ;
    string nome;
    // FUNÇÃO PARA ESCREVER NA TABELA
    
    arquivo.open("listadealunos.csv",ios::out);
    
    // INSERÇÕES NA TABELA
    
    hashTable.insert(Aluno("Fábio Duarte Freitas, 12359"));
    hashTable.insert(Aluno("Harry Potter, 2000"));
    hashTable.insert(Aluno("Sirus Black, 39101112"));
    hashTable.insert(Aluno("James Hetfield, 32656678"));
    hashTable.insert(Aluno("Corey Taylor, 99875678")); 
    hashTable.insert(Aluno("Avalon, 12345678"));
    
    // REMOÇÕES DA TABELA
    /*
    hashTable.remove(Aluno("Fábio Duarte Freitas, 12359"));
    hashTable.remove(Aluno("Harry Potter, 2000"));
    hashTable.remove(Aluno("Sirus Black, 39101112"));
    hashTable.remove(Aluno("James Hetfield, 32656678"));
    hashTable.remove(Aluno("Corey Taylor, 99875678"));
    hashTable.remove(Aluno("Avalon, 12345678"));
    
    */
    arquivo.close();
    
    // LEITURA DA TABELA 
   
    arquivo.open("listadealunos.csv",ios::in);
    if(arquivo.is_open()){
        while(getline(arquivo, linha)){   
            mat =  linha.substr(0,7);
            nome = linha.substr(9,linha.find("\n"));  
            Aluno* al = new Aluno(nome, mat);
            hashTable.insert(*al);          
         }
        arquivo.close();
    }else{
        cout << "Não foi possível abrir o arquivo" << endl;    
    }
    // IMPRESSÃO DA TABELA
   hashTable.print();
   // IMPRESSÃO DO N´MERO DE COLISÕES PARA UM DETERMINADO FATOR DE COLISÃO (0.25, 0.5 , 1 , 2 e 10)
   hashTable.size();
   
           
    
   
      
    
   /*
    
    hashTable.remove(Aluno("Jorge"));
    hashTable.print();
     */
}
