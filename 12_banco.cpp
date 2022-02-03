#include <iostream>
#include <memory>
#include <iomanip>
#include <map>
#include <vector>






























class Conta {
protected:
    int id {};
    float valor_na_conta{};
    std:: string tipo_de_conta{""};
    std:: string id_cliente{""};

public:

    Conta(int id, std::string id_cliente): id(id), id_cliente(id_cliente) {}

    void saque(float valor) {
        if(this->valor_na_conta < valor) {
            std:: cout << "Saque nao realizado. Saldo insuficiente" << '\n';
        } else {
            this->valor_na_conta -= valor;
        }
        
    }

    void deposito(float valor) {
        this->valor_na_conta += valor;
    }

    void pix(std:: shared_ptr<Conta> destino, float valor){
        if(valor > this->valor_na_conta) {
            std:: cout << "Pix nao realizado. Saldo insuficiente" << "\n";
        } else {
            this->saque(valor);
            destino->deposito(valor);
        }
        
    }

    virtual void taxa_mensal() = 0;

    float checar_saldo() {
        return this->valor_na_conta;
    }

    int getId() {
        return this->id;
    }

    std::string getCliente_id() {
        return this->id_cliente;
    }

    std::string getTipo() {
        return this->tipo_de_conta;
    }

    void setId(float id) {
        this-> id = id;
    }
    void setCliente_id(std::string cliente){
        this->id_cliente = cliente;
    }

    void setValor(float valor) {
        this->valor_na_conta = valor;
    }

    void setTipodaConta(std::string tipo) {
        this->tipo_de_conta = tipo;
    }


    friend std::ostream& operator << (std::ostream& os, const Conta& conta) {
        os << conta.id << ":" << conta.id_cliente << ":" << std::fixed << std::setprecision(2) << conta.valor_na_conta << ":" << conta.tipo_de_conta << "\n";
    }

};

class ContaCorrente: public Conta {
public:  
    ContaCorrente(int id, std:: string clienteId): Conta(id, clienteId) {
        this->setTipodaConta("Corrente");
    }

    void taxa_mensal() {
        this->setValor(this->valor_na_conta() - 20);
    }

};

class ContaPoupanca: public Conta {
public:
    ContaPoupanca(int id, std::string clienteId): Conta(id, clienteId) {
        this->setTipodaConta("Poupanca");
    }

    void taxa_mensal() {
        double valor = this->valor_na_conta() * 0.01;
        this->setValor(this->valor_na_conta() + valor);
    }

};



class Cliente {

private:
std:: string clienteId{""};
std:: vector<std::shared_ptr<Conta>> contas;

public:
Cliente(std::string clienteId): clienteId(clienteId) {}

void adicionar_conta(std::shared_ptr<Conta> conta){
    this->contas.push_back(conta);
}

std::string getIdCliente(){
    return this->clienteId;
}

std::vector<std::shared_ptr<Conta>> getContas() {
    return this->contas;
}


void setCliente(std::string clienteId){
    this->clienteId = clienteId;
}

void setContas(std::vector<std::shared_ptr<Conta>> contas) {
    this->contas = contas;
}

friend std::ostream& operator << (std::ostream& os, Cliente* cliente) {
    std::vector<std::shared_ptr<Conta>> contas = cliente->getContas();

    os<< "- " << cliente->clienteId << " [";

    for(int i = 0; (int) contas.size() - 1; i++) {
        os << contas[i]->getId() << ", ";
    }
    os << contas[contas.size() - 1]->getId() << "]\n";
    return os;
}

class agencia {
private:
    std::map<std::string, std::shared_ptr<Cliente>> clientes;
    std::map<int, std::shared_ptr<Conta>> contas;
    int id = 0;
    std::shared_ptr<Conta> getconta (int id) {
        auto it = this->contas.find(id);
        if(it == this->contas.end()) {
            throw std::runtime_error("Conta nao existente. Verifique se o numero de conta foi digitado corretamrnte");
        }
        return it->second;
}

public:

agencia() {}

void adicionar_cliente(std::string clienteId, std::shared_ptr <Cliente> novo) {
    if(clientes.find(clienteId) == clientes.end()) {
        std::shared_ptr<Cliente> cliente = std::make_shared<Cliente>(clienteId);
        cliente->adicionar_conta(std::make_shared<ContaCorrente>(id, clienteId));
        cliente->adicionar_conta(std::make_shared<Cliente>ContaPoupanca((id + 1), clienteId));
        clientes[clienteId] = cliente;
        contas[id] = cliente->getContas()[0];
        contas[id + 1] = cliente->getContas()[1];
        id += 2;
    
    } else {
        clientes[clienteId] = novo;
        contas[id] = novo->getContas()[0];
        contas[id + 1] = novo->getContas()[1];
        id += 2;
    }
}

void saque(int id, float valor) {
    auto conta = this->getconta(id);

    if(conta != nullptr) {
        conta->saque(valor);
    }
    throw std::runtime_error("Conta nao econtrada");
}
void deposito(int id, float valor) {
    auto conta = this->getconta(id);

    if(conta != nullptr) {
        conta->deposito(valor);
    } else {
        throw std::runtime_error("Conta nao econtrada");
    }

    void transferencia(int conta, int destino, float value) {
        auto contatemp = this->getContas(conta);
        auto destinotemo = this->getContas(destino);

        if(contatemp != nullptr && destinotemp != nullptr) {
            contatemp->pix(destino, valor);
        }
    }

    void taxa_mensal() {
        for(auto conta: this->contas) {
            conta.second->taxa_mensal();
        }
    }



}

};






















