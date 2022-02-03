#include <iostream>
using namespace std;

int existe (int tamanho, int x, int vetor[]){
  
  for (int i = 0; i < x; i++){
    if (x == vetor[i]){
      return 1;
    } else {
      return -1;
    }
  }
}

void contagem (int cont, int tamanho, int vetor[]){
  int qtd{};
  for (int i = 0; i < tamanho; i++){
    if (vetor[i] == cont){
      qtd++;
    }
  }
  cout << "a quantidade de vezes que o numero aparecs e"<< qtd;
}

int primeiraAparicao(int verifica, int tamanho, int vetor[]){
  int result{};
  for (int i = 0; i < tamanho; i++){
    if (verifica == vetor[i]){
      result = i;
      return result;
    }
  }
    return -1;
}

int proximaAparicao(int n,int verifica ,int tamanho, int vetor[]){
  int apari{};
  for(int i = n; i < tamanho; i++){
    if (verifica == vetor[i]){
      apari = i;
      return apari;
    }
  }
  return -1;
}

int menor(int tamanho, int vetor[]){
  int min{};
  min = vetor[0];

  for(int i = 0; i < tamanho; i++){
   if(vetor[i] < min){
     min = vetor[i];
   }
  }
  return min;
}

int posMenor(int tamanho, int vetor[]){
  int min{};
  int pos{};
 
  for(int i = 0; i < tamanho; i++){
   if(vetor[i] < min){
     min = vetor[i];
     pos = i;
   }
  }
  
  return pos;
}

int buscaMenor(int posicaobusca, int tamanho, int vetor[]){
  int min{};
  int pos{};
  
for(int i = 0; i < tamanho; i++){
  int pos{};
   if(vetor[i] < min){
     min = vetor[i];
     pos = i;
    }
  }
return pos;

}

int homemCalmo(int tamanho, int vetor[]){
  int pos{};
  pos = vetor[0];
  
  for(int i = 0; i < tamanho; i++){
    if(vetor[i] > pos){
      pos = vetor[i];
    }
  }
}

int mediaEstresse ( int tamanho, int vetor[]){
  int media;
  for(int i = 0; i < tamanho; i++){
    if (vetor[i] < 0){
      vetor[i] *= -1;
      media += vetor[i];
    }
    media += vetor[i];
  }
  media /= tamanho;
  return media;

}

void MaisHomensOUMulheres(int tamanho, int vetor[]){
  int contH{};
  int contM{};
  
  for (int i = 0; i < tamanho; i++){
    if (vetor[i] < 0){
      contM++;
    }
    else if (vetor [i] > 0){
      contH++;
    }
  }
  
  if(contM > contH){
    cout << "existem mais mulheres";
  } else {
    cout << "existem mais homens";
  }
  
}

void EstresseHomensOuMulheres(int tamanho, int vetor[]){
  int mediaH{};
  int mediaM{};
  
  for(int i = 0; i < tamanho; i++){
    if (vetor[i] < 0){
      vetor[i] *= -1;
      mediaM += vetor[i];
    }
    mediaH += vetor[i];
  }
  
  if (mediaH > mediaM){
    cout << "homens sao mais estressados";
  } else {
    cout << "mulheres sao mais estressadas";
  }
}

void metadeEstressada(int tamanho, int vetor[]){
   int mediaMetade1{};
   int mediaMetade2{};
  
   for(int i = 0; i < tamanho/2; i++){
    if (vetor[i] < 0){
      vetor[i] *= -1;
      mediaMetade1 += vetor[i];
    }
      mediaMetade1 += vetor[i];
  }
  
  for (int i = tamanho/2; i < tamanho; i++){
    if (vetor[i] < 0){
      vetor[i] *= -1;
      mediaMetade2 += vetor[i];
    }
    mediaMetade2 += vetor[i];
  }
 
   mediaMetade1 /= (tamanho/2);
   mediaMetade2 /= (tamanho/2);
   
   if (mediaMetade1 > mediaMetade2){
     cout << "a primeira metade e mais estressada";
   } else {
     cout << "a segunda metade e mais estressada";
   }
  
}

int main(){
  cout << "qual o tamanho do vetor?";
  int x = 0;
 
  cin >> x;
  
  int vetor[x];
  
  
  cout << "quais os elementos do vetor?";
  
  for (int i = 0; i < x; i++){
    cin >> vetor[i];
  }

  cout << "qual elemento você quer verificar se existe no vetor?";
  int existe = 0;
  cin >> existe;
  
  cout << "qual elemento você quer contar no vetor?";
  int contar {};
  cin >> contar;
 
  cout << "qual numero voce quer saber a posicao que aparece?";
  int posicao;
  cin >> posicao;

  cout << "qual a posicao da qual voce deseja iniciar a busca?";
  int busca{};
  cin >> busca;

  cout << "qual a posicao da qual voce deseja iniciar a busca pelo menor valor?";
  int menor{};
  cin >> menor;

}