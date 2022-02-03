#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> unico_valor_na_fila(const vector<int>& vetor){
    vector<int> vetor_teste;
    for(int i = 0; i < (int) vetor.size(); i++){
        if(count(vetor_teste.begin(),vetor_teste.end(),vetor[i]) == 1 && count(vetor_teste.begin(),vetor_teste.end(),-vetor[i]) == 0) {
            vetor_teste.push_back(abs(vetor[i]));
        }
    }
    return vetor_teste;
}


int vai_dar_briga(const vector<int>& vetor){
    int verifica{0};
    for(int i = 1; i < (int) vetor.size() -1; i++){
        if(vetor[i -1] >abs(30) && vetor[i] >abs(50) && vetor[i + 1] > abs(30)){
            verifica++;
        }
    }
    return verifica;
}


vector<int> vai_dar_paz(const vector<int>& vetor){
   vector<int> apaziguado;
    for(int i = 1; i < (int) vetor.size() -1; i++){
        if((vetor[i -1] < abs(10) && vetor[i] > abs(80)) || (vetor[i] > 80 && vetor[i + 1] < abs(10)) ){
            apaziguado.push_back(i);
        }
    }
   return apaziguado;
}

int casais(vector<int>& vetor){
    int casal{};
    for(int i = 0; i < (int) vetor.size() - 1; i++){
        for(int k = i + 1; k < (int) vetor.size(); k++){
        if(abs(vetor[i]) == abs(vetor[k]) && vetor[i] != vetor[k]){
            casal++;
            }
        }    
    }
    return casal;
}

int trios(const vector<int>& vetor){
     int trios{};
     for(int j = 0; j < (int) vetor.size() - 2; j++){
        for(int i = j + 1; i < (int) vetor.size() - 1; i++){
            for(int k = i + 1; k < (int) vetor.size(); k++){
                if(abs(vetor[i]) == abs(vetor[j]) == abs(vetor[k])){
                    trios++;
                }       
            }    
    
        }
    }
    return trios;
}

vector<int> excluir_elemento(vector<int>& vetor, int numero){
    for(int i = 0; i < (int) vetor.size(); i++){
        if(vetor[i] == numero){
            vetor.erase(vetor.begin() + i, vetor.begin() + i + 1);
        }
    }
    return vetor;
}

void troca_valor(vector<int>& vetor, int posicao, int numero){
   vetor.insert(vetor.begin() + posicao, numero);
}

int ocorrencias(const vector<int>& vetor){
    int maior_ocorrencia{-99};
    int teste{};
    for(int i = 0; i < (int) vetor.size(); i++){
        teste = count(vetor.begin(), vetor.end(), vetor[i]) + count(vetor.begin(), vetor.end(), -vetor[i]);
        if(teste > maior_ocorrencia){
            maior_ocorrencia = teste;
        }
    }
    return maior_ocorrencia;
}

vector<int> recorrente(const vector<int>& vetor){
    int maior_ocorrencia{ocorrencias(vetor)};
    int teste{};
    vector<int> recorrente;
    for(int i = 0; i < (int) vetor.size(); i++){
       teste = count(vetor.begin(), vetor.end(), vetor[i]) + count(vetor.begin(), vetor.end(), -vetor[i]);;
        if(teste == maior_ocorrencia){
            if(find(recorrente.begin(), recorrente.end(), vetor[i]) != recorrente.end()){
            recorrente.push_back(abs(vetor[i]));
            }
        }
    }   
    return recorrente;
}

int qtde_times(const vector<int>& vetor){
    vetor.push_back(0);
    int quantos_times_contador {0};
    int time_m {0};
    int time_h {0};

    for(int i = 0; i < (int) vetor.size(); i++) {
        if(vetor[i] < 0) {
            if(time_h > 1) quantos_times_contador++;
            time_m++;
            time_h = 0;
        } else if(vetor[i] > 0) {
            if(time_m > 1) quantos_times_contador++;
            time_m = 0;
            time_h++;
        } else if(vetor[i] == 0) {
            if(time_m > 1 || time_h > 1) quantos_times_contador++;
        }
    }  
    return maior_time;
}

int maior_time(const vector<int>& vetor){
    vetor.push_back(0);
    int maior_time { 0 };
    int time_m { 0 };
    int time_h { 0 };

    for(int i = 0; i < (int) vetor.size(); i++) {
        if(vetor[i] < 0) {
            if(time_h > 1 && time_h > maior_time) {
                maior_time = time_h;
            }
            time_m++;
            time_h = 0;
        } else if(vetor[i] > 0) {
            if(time_m > 1 && time_m > maior_time){
                maior_time = time_m;
            } 
            time_m = 0;
            time_h++;
        } else if(vetor[i] == 0) {
            if(time_m > 1 && time_m > maior_time){
               maior_time = time_m;
            }   
            if(time_h > 1 && time_h > maior_time){
                maior_time = time_h;
            }
        }
    } 
    return maior_time;
}

vector<int> sem_time(vector<int>& vetor){
vector<int> sem_time {0};

    for(int i = 1; i < (int) vetor.size() - 1; i++) {
        if(vetor[i] > 0 && vetor[i - 1] < 0 && vetor[i + 1] < 0) {
            sem_time.push_back(vetor[i]);
        }

        if(vetor[i] < 0 && vetor[i - 1] > 0 && vetor[i + 1] > 0) {
            sem_time.push_back(vetor[i]);
        }
    }
if(vetor[0] > 0 && vetor[1] < 0){
    sem_time.push_back(vetor[0]);
    } 
    if(vetor[vetor.size() - 1] > 0 && vetor[vetor.size() - 2] < 0){
        sem_time.push_back(vetor[vetor.size() - 1]);
    } 
    if(vetor[0] < 0 && vetor[1] > 0){
        sem_time.push_back(vetor[0]);
    }
    
    if(vetor[vetor.size() - 1] < 0 && vetor[vetor.size() - 2] > 0) {
        sem_time.push_back(vetor[vetor.size() - 1]);
    }
    return sem_time;
}


vector<int> dance(vector<int>& vetor){
    for(int i = 0; i < (int) vetor.size() - 1; i++){
        if(abs(vetor[i]) == abs(vetor[i + 1])){
            vetor.erase(vetor.begin() + i, vetor.begin() + i + 2);
            i = -1;
            }
        }    
    return vetor;
}


int main(){
vector<int> vetor;
int elemento {};
cout << "digite os elementos que você deseja inserir no vetor" << "\n";
for(int i = 0; i < (int) vetor.size(); i++){
    cin >> elemento;
    vetor.push_back(elemento);
    }

    cout << "digite o elemento que você quer excluir do vetor" << "\n";
    int valor{};
    cin >> valor;   
        
    cout << "digite o valor que voce deseja trocar de posicao" << "\n";
    int numero{};
    cin >> numero;

    cout << "digite a posicao que voce deseja trocar o valor" << "\n";
    int posicao{};
    cin >> posicao;
    
}