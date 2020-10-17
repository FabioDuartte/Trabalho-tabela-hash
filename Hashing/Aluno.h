#include <string>
#include <ostream>
#ifndef ALUNO_H
#define ALUNO_H
using namespace std;
class Aluno {
private:
    string m_nome; 
    string m_matricula;
public:
    Aluno();
    Aluno(string);
    Aluno(string,string);
    string getNome();
    void setNome(string);
    string getMatricula();
    void setMatricula(string);  
    int hashCode();
    friend bool operator==(Aluno aluno1, Aluno aluno2) {
        return (aluno1.getNome().compare(aluno2.getNome())==0 , aluno1.getMatricula().compare(aluno2.getMatricula())==0);
    }
    friend ostream& operator<<(std::ostream &strm, const Aluno &aluno) {
        return strm << "O nome do aluno é "<<aluno.m_nome<<endl << "A matricula do aluno " <<aluno.m_matricula <<endl;
    }
};
#endif /* ALUNO_H */