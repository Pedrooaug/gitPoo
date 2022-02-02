#include <iostream>
#include <map>
#include <memory>

class Pessoa {
private:
std::string id;
std::string numero;


public:

std:: string get_id() {
    return this->id;
}

std::string get_numero() {
    return this->numero;
}
};


class Cinema {
private:
    std::map<int, std::shared_ptr<Pessoa>> lugares;
public:

    Cinema(int lotacao) {
        std::shared_ptr<Pessoa> pessoas;
        for(int i = 0; i < lotacao; i++) {
            this->lugares.insert(std:: pair<int, std::shared_ptr<Pessoa>>(i, pessoas));
        }

        std:: cout << "A sala foi criada com " << lotacao << " lugares" << '\n';
    }
    void setLugar(int indice, std:: shared_ptr<Pessoa> pessoa) {
        auto it = this->lugares.find(indice);
        if(it != this->lugares.end()) {
            it->second = pessoa;
        }
    }

    int achar_cliente(std:: string id) {
        for(auto it = this->lugares.begin(); it != lugares.end(); i++) {
            if(it->second != nullptr && it->second->get_id() == id) {
                return it->first;
            }
        }

        return 1;
    }
    void sair_do_lugar() {

    }
    bool comprar_ingresso(std::string id, std:: string numero, int indice) {

        auto it = this->lugares.find(indice);
        if(it == this->lugares.end()) {
            std:: cout << "O lugar que voce tentou comprar e invalido" << '\n';
            return false;
        }

        if(achar_cliente(id) != 1) {
            std:: cout << "O lugar ja esta registrado, entao nao foi possivel registrar" << '\n';
        }

        if(it->second != nullptr) {
            std:: cout << "O lugar que voce quis reservar ja esta ocupado, entao nao foi possivel reserva-lo" << '\n';
        }

        std:: cout << "Reservando o local: " << indice << "no nome de " << id << '\n'; 

        std::shared_ptr<Pessoa> pessoa(new Pessoa(id,numero));

        this->setLugar(indice, pessoa);
        this->ToString();
    }

    void cancelar_ingresso(std::string id) {
        int posicao = achar_cliente(id);
        
        if(posicao == 1) {
            std:: cout << "Nao foi possivel cancelar pois essa pessoa nao comprou ingresso" << '\n';
        } else {
            this->setLugar(posicao, nullptr);
            std:: cout << "O " << id << "cancelou a sua reserva" << '\n';
        }

        this->ToString();
    
    }

    void ToString() {
        for(auto it = this->lugares.begin(); it < this->lugares.end(); it++) {
            if(it->second == nullptr) {
                std:: cout<< " - ";
            } else {
                std:: cout << "[" << it->second->get_id() << " " << it->second->get_numero() << "]";
            }
        }
    }
    std:: cout << "\n";
};