#include "Aluno.h"

Aluno::Aluno() {
    m_nome="João Ninguém";
    m_matricula="000000";
}
Aluno::Aluno(string nome) {
    m_nome=nome;
    m_matricula="000000";
}
Aluno::Aluno(string nome,string matricula) {
    m_nome=nome;
    m_matricula=matricula;
}
void Aluno::setNome(string nome) {
    m_nome=nome;
}
string Aluno::getNome() {
    return m_nome;
}
void Aluno::setMatricula(string matricula) {
    m_nome=matricula;
}
string Aluno::getMatricula() {
    return m_matricula;
}
int Aluno::hashCode() {
    int hashValue=0;
    // resolve o polinômio para x=31
    for (int i=0;i<m_nome.length();i++)
        hashValue=31*hashValue+m_nome[i];
    // trata um possível int overflow
    if (hashValue<0)
        hashValue=-hashValue;        
    return  hashValue;          
}