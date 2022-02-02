#include <iostream>

class veiculos {
private:
    int rodas{};
    int passageiros{};

public:
    void setRodas(int rodas) {
        this->rodas = rodas;
    }

    void setPassageiros(int passageiros) {
        this->passageiros = passageiros;
    }

    int getPassageiros() {
        return this->passageiros;
    }

};

class caminhao : public veiculos {
private:
    int carga{};

public:
    void setCarga(int quilos) {
        this->carga = quilos;
    }

    int getCarga() {
        return this->carga;
    }

};

class carro : public veiculos {
private:
    std:: string modelo{" "};
    int airbag{4};
    bool cinto = false;
public:
    void setModelo(std::string modelo) {
        this->modelo = modelo;
    }
    std::string getModelo() {
        return this->getModelo();
    }
    bool setCinto() {
        return this->cinto = true;
    }
    bool esta_de_cinto(){
        if(this->cinto == true) {
            return true;
        } else {
            return false;
        }
    }
    void bater() {
        if(airbag == 0 && esta_de_cinto() == false) {
            std::cout << "Seu acidente foi fatal pois seu carro nao estava com airbag e voce estava sem cinto" << '\n'
        } 
        if(airbag != 0 && esta_de_cinto() == false) {
            airbag--;
            std::cout << "Seu airbag lhe salvou poois voce estava sem cinto. Mais cuidado da proxima vez!" << '\n';
        }
        if(airbag == 0 && esta_de_cinto() == true) {
            std::cout << "Seu airbag falhou mas o seu cinto lhe salvou. Leve o carro na manutencao para evitar essas falhas!" << '\n';
        }
        if(airbag != 0 && esta_de_cinto() == true) {
            airbag--;
            std::cout << "Cuidados exemplares! Estava de cinto e com o airbag em dia! Nada grave aconteceu!" << '\n';
        }
    }

};