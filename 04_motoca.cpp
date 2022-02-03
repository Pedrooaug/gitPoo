#include <iostream>
#include <vector>

using namespace std;

struct train { 
    int time = 0;
    int potencia{1};
    static const int tamanho_maximo {5};
    person* pessoas[tamanho_maximo];
    int tamanho_atual {};
    train() {
        for(int i = 0; i < tamanho_maximo; i++){
            pessoas[i] = nullptr;
        }
    }

    string buzinar(){
        return "P" + string(this->potencia, 'e') + "m"
    }
    
    bool subir_no_trem(person *p) {
        if(this->tamanho_atual == this->tamanho_maximo){
            cout << "Nosso trem está lotado!" << "\n";
            return false;
        }
        pessoas[tamanho_atual] = p;
        tamanho_atual++;
        return true;
    }

    bool descer_do_trem() {
        if(this->tamanho_atual == 0){
            cout << "Não estamos com passageiros no momento" << "\n";
            return false;
        }
        pessoas[0] = nullptr;

        for(int i = 0; i < tamanho_maximo - 1; i++){
            swap(pessoas[i], pessoas[i + 1]);
        }
        tamanho_atual--;
        return true;

    }
    
    void tempo_no_trem(int time){
        this->time += time;
    }
    
    bool dirirgir(int time) {
        if(this->tamanho_atual == 0) {
            cout << "Estamos sem motorista!" << "\n";
            return false;
        }        
        if(time > this->time){
            cout << "Vamos dirigir somente por" << this->time << "minutos" << "\n";
            this->time = 0;
            return true;
        }
        cout << "Vamos rodar bastante hoje! Nosso tempo será de" << this->time << "minutos" <<"\n";
        this->time -= time;    
        return true;
    }




};


struct person {
    string nome;
    int idade;

    person(string nome = " ", int idade = 0) {
        this->nome = nome;
        this->idade = idade; 
    }

    // friend ostream& operator<<(ostream& os, const person&pessoas) {
    //     os << "Nome do nosso motorista: " << *pessoas[0].nome << "Idade do nosso motorista: " << pessoas[0].idade;
    //     for(int i = 1; i < (int) pessoas.; i++){
    //         cout << "Nome: " << *pessoas[i]->nome << "Idade: " << *pessoas[i]->idade << "\n";
    //     }
    //     return os;
    // } 


};


    // ostream& operator<<(ostream& os, const train& t) {
    //     for(int i = 0; i < tamanho_maximo)
    //     os << t.pessoas;
    //     return os;
    // }