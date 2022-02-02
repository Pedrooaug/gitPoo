#include <iostream>
#include <list>
#include <memory>

using namespace std;

class pessoa {
private:
std::string nome;
int idade;

friend ostream& operator << (ostream& os, const pessoa& p) {
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


class cinema {
    pessoa *p;
    list<shared_ptr<pessoa>> sala;

    bool comprar_ingresso(int cadeira) {

        if(sala.max_size()) {
            cout << "Desculpe, a sessao ja esta lotada!" << "\n";
            return false;
        }

    
    
    
    }




};