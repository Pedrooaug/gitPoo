#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
class Contato {

private:
   int chave{};
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

    int getChave() {
        return chave;
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
    
    void setChave(int chave) {
        this->chave = chave;
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
            for(int i = 0; i < (int) contatos.size(); i ++) {
                if(cnt.getNome() == contatos[i].getNome()) {
                    mais_um_numero(i, contatos, cnt);
                }
        }
            std:: cout << "Numero adicionado a agenda!" << '\n';
        } else {
            std:: cout << "Nao foi possivel adicionar o numero a agenda pois ele nao e um numero valido" << '\n';
        }
        
        
        this->contatos.push_back(cnt);
    }

    void mais_um_numero(int indice, std:: vector<Contato> contatos, Contato cnt) {
        std::string temp = contatos[indice].getNumero();
        temp.append(cnt.getNumero());
    }

    void excluir_contato(int chave) {
       if(contatos.empty()) {
           std:: cout << "A sua lista de contato está vazia" << '\n';
       }
       
        for(int i = 0; i < (int) contatos.size(); i++) {
           int temp = contatos[i].getChave();
            if(temp == chave) {
                contatos.erase(contatos.begin() + i);
            }
        }
        std:: cout << "A chave para este numero nao existe" << '\n';
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

    std::vector<Contato> buscar_nome( std::string nome) {
        std::vector<Contato> busca;
        for(int i = 0; i < (int)contatos.size(); i++) {
          if(contatos[i].ContatotoString().find(nome) != std::string::npos) {
             Contato temp = contatos[i];
              busca.push_back(temp);
          }
        }
        return busca;
    }

    void ordenar(std:: vector<Contato> contatos) {
        for(int i = 0; i < (int) contatos.size() - 1; i++) {
            if(contatos[i].getNome() > contatos[i + 1].getNome()) {
                std::string temp1 = contatos[i].getNome();
                std::string temp2 = contatos[i + 1].getNome();
                
                contatos[i].setNome(temp2);
                contatos[i + 1].setNome(temp1);
            }
        }
    }



};
int main() {
    Agenda cnt;
    cnt.novo_contato(Contato("oi", "88"));
    cnt.AgendatoString();
    cnt.buscar_nome("oi");

}