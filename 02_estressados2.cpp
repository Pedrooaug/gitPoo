#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;


vector<int> pegarHomens(vector<int>& vetor){
    vector<int> homens;  
    for(int i = 0; i < vetor.size(); i++){
        if(vetor[i] > 0){
          homens.push_back(vetor[i]);
        }
    }
     
     return homens;
}


vector<int> pegarCalmos(vector<int>& vetor){
    vector<int> calmos;  
    for(int i = 0; i < vetor.size(); i++){
        if (abs(vetor[i]) < 10){
          calmos.push_back(vetor[i]);
        }
    }
     
     return calmos;
}


vector<int> mulheresCalmas(vector<int>& vetor){
  vector <int> calmas;
  for(int i = 0; i < vetor.size(); i++){
    if(vetor[i] < 0 && abs(vetor[i]) < 10){
      calmas.push_back(vetor[i]);
    }
  }
}


 void embaralhar(vector<int>& vetor){
  for(int i = 0; i < vetor.size(); i++){
    int posicao { rand() % vetor.size() };
    swap(vetor[i], vetor[posicao]);
     }
  
  
  }

vector<int> inverter(vector<int>& vetor){
  vector<int> vetorInvertido;
  
  for(int i = (int)vetor.size(); i > 0; i--){
    vetorInvertido.push_back(vetor[i]);
  }
  
  return vetorInvertido;
}

void reverterInplace(vector<int>& vetor){
  for(int i = 0; i < (int)vetor.size()/2; i++){
    swap(vetor[i], vetor[ (int)vetor.size() - i - 1]);
  }
}

int sortearNumero(vector<int>& vetor){
  int tamanhoVetor { (int)vetor.size() };
  int posicaoSorteada {rand() % vetor.size()};
  
  return posicaoSorteada;
}

void ordenarVetor(vector<int>& vetor){
  sort(vetor.begin(), vetor.end());
}

vector<int> exclusivoDaFila(vector<int>& vetor){
  vector<int> vetorTeste;
  
  for(int i = 0; i < vetor.size(); i++){
    if(find(vetorTeste.begin(), vetorTeste.end(), vetor[i]) == vetorTeste.end() )
       vetorTeste.push_back(vetor[i]);
  }
    return vetorTeste;
}



vector<int> diferenteDaFila(vector<int>& vetor){
  vector<int> vetorTeste;
  
  for(int i = 0; i < vetor.size(); i++){
    if(find(vetorTeste.begin(), vetorTeste.end(), vetor[i]) == vetorTeste.end() )
       vetorTeste.push_back(abs(vetor[i]));
  }
    return vetorTeste;
}


vector<int> excluidosDaFila(vector<int>& vetor){
  vector<int> vetorTeste = vetor;
  vector<int> vetorDosExcluidos;
  
  int c {0};
  for(int i = 0; i < vetor.size(); i++){
    if(find(vetorTeste.begin(), vetorTeste.end(), vetor[i]) == vetorDosExcluidos.end() )
       vetorDosExcluidos.push_back(vetor[i]);
       vetorTeste.erase(vetorTeste.begin() +i -c++);
  
  }
  return vetorTeste;
}





int main()
{
    srand(time(0));
   
    
    cout << "quais os elementos do vetor?";
    
   vector<int> vetor;
    int x{};
    
    for (int i = 0; i < (int) vetor.size(); i++ ) {
          cin >> x;
          vetor.push_back(x);
    }
  
   rand() % vetor.size();
   
}