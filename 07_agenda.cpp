#include <iostream>
#include <vector>

class Contato {

private:
    std::string nome;
    std::string numero;

public:

 Contato(std::string nome, std::string numero) : nome(nome), numero(numero) {}  
   
    std:: string getNumero() {
        return numero;
    }
   
    std:: string getNome() {
        return nome;
    }

   static bool validar(std:: string numero) {
       for(auto x : numero) {
           if((x < '0' || x >'9') && (x != '.') && (x != '(') && (x != ')')) {
               return false;
           }
            return true;
       }
   }
      
    void setNumero(std:: string numero) {
        this->numero = numero;
    }

    void setNome(std:: string nome) {
        this->nome = nome;
    }

    std:: string ContatotoString() {
        return this->getNome() + ":" + this->getNumero();
    }
    




};

class Agenda {
private:
    std::string nome;
    std::vector<Contato> contatos;

protected:

std::string prefixo = "-";

public:

    Agenda(std:: string nome = "", std:: vector<Contato> contatos = {}) : nome(nome), contatos(contatos) {};  
    void novo_contato (Contato cnt) {
        
        if(validar(cnt.getNumero())) {
            std:: cout << "Numero adicionado a agenda!" << '\n';
        } else {
            std:: cout << "Nao foi possivel adicionar o numero a agenda pois ele nao e um numero valido" << '\n';
        }
        
        
        this->contatos.push_back(cnt);
    }

    void excluir_contato(int indice) {
        if(indice < 0 || indice >= (int) contatos.size()) {
            std:: cout << "O numero nao foi encontrado na agenda" << '\n';
        } else {
            contatos.erase(contatos.begin() + indice);
        }
    }

    std::vector<Contato> getContato() {
        return this->contatos;
    }
 
   
      static bool validar(std:: string numero) {
       for(auto x : numero) {
           if((x < '0' || x >'9') && (x != '.') && (x != '(') && (x != ')')) {
               return false;
           }
       }
        return true;

   }
   
    std::string AgendatoString () {
        std::string vazia = "";
        int indice = 0;

        for(auto numero : this->getContato()) {
            vazia += " [" + std::to_string(indice) + ":" + numero.ContatotoString() + "]";
            indice++;
        }

        return prefixo + " " + this->nome + vazia;

    }


};



int main () {
    
    
    Agenda contato("Roberto");

    std:: cout << contato.AgendatoString() << '\n';

    contato.novo_contato(Contato("oi", "88"));
    contato.novo_contato(Contato("Fernando", "88"));
    contato.novo_contato(Contato("David", "88"));
    contato.novo_contato(Contato("Jessica", "88"));

    contato.excluir_contato(3);

    std:: cout << contato.AgendatoString() << '\n';
    
    
    
    
    
    
    return 0;

}


