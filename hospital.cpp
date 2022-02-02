#include <iostream>
#include <map>
#include <vector>

class Medico;
class Paciente;
class Hospital;

class Medico {
    std::string id;
    std::string especialidade;
    std::map<std::string, Paciente*> pacientes;
public:

    Medico(std::string id, std::string especialidade) : id(id), especialidade(especialidade) {}

    void adicionarPaciente(Paciente* paciente) {
        if(pacientes.find(paciente->getId()) != pacientes.end()) {
            throw std::runtime_error("O paciente ja esta sendo atendido pelo medico");
        }
        pacientes.insert(std::pair<std::string, Paciente*>(paciente->getId(), paciente));
    }

    void removerPaciente(std:: string id) {
        if(pacientes.find(id) == pacientes.end()) {
            throw std::runtime_error("O paciente nao esta sendo atendido por esse medico");
        }
        pacientes.erase(id);
    }

    std::string getId() {
        return this->id;
    }

    std::string getEspecialidade() {
        return this->especialidade;
    }

    std::vector<Paciente> getPacientes() {
        std::vector<Paciente> pacientes;
        for(auto it = this->pacientes.begin(); it != this->pacientes.end(); it++) {
            pacientes.push_back(it->second);
        }
        return pacientes;
    }

    std::string tostring() {
        std::string concatenacao = "medico: " + id + " especialidade: " + especialidade + " pacientes: ["; 
        for(auto it = pacientes.begin(); it != pacientes.end(); it++) {
            concatenacao += it->second.getId() + " ";
        }
        concatenacao += " ]";
        return concatenacao;
    }


};


class Paciente {
    std::string id;
    std::string problema;
    std::map<std::string, Medico*> medicos;

public:
Paciente(std::string id, std::string problema) : id(id), problema(problema) {}

void addMedico(Medico* medico) {
    if(medicos.find(medico->getId()) != medicos.end()) {
        throw std::runtime_error("O paciente ja esta sendo atendido pelo medico");
    }
    medicos.insert(std::pair<std::string, Medico*>(medico->getId(), medico));
}

void removerMedico(std::string id) {
    if(medicos.find(id) == medicos.end()) {
        throw std::runtime_error("O medico nao esta atendendo o paciente");
    }
    medicos.erase(id);
}

std::string getId() {
    return this->id;
}

std::string getProblema() {
    return this->problema;
}

std::vector<Medico> getMedicos() {
    std::vector<Medico>medicos;
    for(auto it = this->medicos.begin(); it != this->medicos.end(); it++) {
        medicos.push_back(it->second);
    }
}


std::string toString() {
    std::string concatenacao = "Paciente: " + id + "dianostico: " + problema + " medicos: [";
    for(auto it = medicos.begin(); it != medicos.end(); it++) {
        concatenacao += it->second.getId() + " ";
    }
    concatenacao += "]";
    
    }

};

class Hospital {
    std::map<std::string, Paciente*> pacientes;
    std::map<std::string, Medico*> medicos;

public:

Hospital() {}

void addPaciente(std::string id, std::string problema) {
    Paciente* paciente(id, problema);
    if(pacientes.find(id) != pacientes.end()) {
        throw std::runtime_error("O paciente ja esta no hospital");
    }
    pacientes.insert(std::pair<std::string, Paciente*>(id, paciente));
}

void addMedico (std::string id, std:: string especialidade) {
    Medico* medico(id, especialidade);

    if(medicos.find(id) != medicos.end()) {
        throw std::runtime_error("O medico ja esta no hospital");
    }
    medicos.insert(std::pair<std::string, Medico*>(id, medico));
}

    void removerPaciente(std::string id) {
        if(pacientes.find(id) == pacientes.end()) {
            throw std::runtime_error("O paciente nao etsa no hospital ou nao foi encontrado");
        }
        pacientes.erase(id);
    }

void removerMedico(std::string id) {
        if(medicos.find(id) == medicos.end()) {
            throw std::runtime_error("O medico nao etsa no hospital ou nao foi encontrado");
        }
        medicos.erase(id);
    }

void atendimento(std:: string medId, std::string pacId) {
    if(pacientes.find(pacId) == pacientes.end()) {
        throw std::runtime_error("Paciente nao esta no hospital ou nao foi encontrado");
    }
    if(medicos.find(pacId) == medicos.end()) {
        throw std::runtime_error("Medico nao esta no hospital ou nao foi encontrado");
    }
    pacientes[pacId]->addMedico(medicos[medId]);
    medicos[medId]->adicionarPaciente(pacId);
}

Paciente* getPaciente(std::string id) {
    if(pacientes.find(id) == pacientes.end()) {
        throw std::runtime_error("Paciente nao esta no hospital ou nao foi encontrado");
    }
    return pacientes[id];
}

Medico* getMedico(std::string id) {
    if(medicos.find(id) == medicos.end()) {
        throw std::runtime_error("Medico nao esta no hospital ou nao foi encontrado");
    }
    return medicos[id];
}

std::string tostring() {
    std:: string concatenacao = "";
    for(auto it = pacientes.begin(); it != pacientes.end(); it++) {
        concatenacao += it->second.toString() + "\n";
    }

    for(auto it = medicos.begin(); it != medicos.end(); it++) {
        concatenacao += it->second.toString() + "\n";
    }

    return concatenacao;
}

};




