#include <iostream>
#include <vector>
#include <memory>
#include <list>

using namespace std;

class kid {
private:
string nome;
int idade;

friend ostream& operator << (ostream& os, const kid& p) {
    os << p.nome;
    return os;
}

public:

string get_nome() {
    return this->nome;
}

int get_idade() {
    return this->idade;
}
};

class pula_pula {
kid *p;

list<shared_ptr<kid>> fila;
list <shared_ptr<kid>> brincando;

bool kid_brincando( shared_ptr<kid>& kid) {
    if(this->brincando.size() >= 3) {
        cout << "o pulapula já está lotado!" << "\n";
        return false;
    }
    if(this->fila.empty()) {
        cout << "Não temos criancas para subir no pula-pula!" << "\n";
        return false;
    }
    
    this->brincando.front() = fila.front();
    this->fila.pop_front();
    return true;

}

bool kid_saindo(shared_ptr<kid>& kid) {
        if(this->fila.empty()) {
        cout << "Não temos criancas para descer do pula-pula!" << "\n";
        return false;
    }    
 
    cout << "A crianca " << p.nome << "esta saindo do pula-pula" <<"\n";

    fila.push_back(p);
    brincando.remove(p);
    return true;
}

void kid_chegando(shared_ptr<kid>& kid) {
    fila.push_back(kid);
};

