// #include <stdio.h>
#include <iostream>
//#include <algorithm>
//#include <functional>

int 
hellworld (  ) {

  std::cout << "Hello, World!" << std::endl;

  return 0;
}

int 
exibe_Veta ( int *vetor, int tamanho, bool flag = false ) {

  for (int i = 0; i < tamanho; i++) {

    std::cout << vetor[i];
    
    if ( flag )
      std::cout << " ";
    else 
      std::cout << std::endl;
  }

  return 0;
}

int 
acha_maior ( int *veta, int tamanho) {

  int maior = veta[0];

  for (int i = 1; i < tamanho; i++) {

    if (maior < veta[i])
      maior = veta[i];
  }

  return maior;
}


int 
acha_menor ( int *veta, int tamanho) {

  int menor = veta[0];

  for (int i = 1; i < tamanho; i++) {

    if (menor > veta[i]) 
      menor = veta[i];
  }

  return menor;
}

int 
maior_vecta ( ) {

  int NUM;

  std::cout << "Digite um numero: ";
  std::cin >> NUM;


  int vet[NUM];


  for (int i = 0; i< NUM; i++) {

    std::cout << "Digite o numero" << i + 1 << ": ";
    std::cin >> vet[i];
  }

  int maior = acha_maior ( vet, NUM );

  std::cout << "O Maior numero é: " << maior << std::endl;

  return 0;
}


int 
exer02_maior_menor (  ) {


  int NUM;

  std::cout << "Digite um numero: ";
  std::cin >> NUM;


  int vet[NUM];


  for (int i = 0; i< NUM; i++) {

    std::cout << "Digite o numero" << i + 1 << ": ";
    std::cin >> vet[i];
  }

  int maior = acha_maior ( vet, NUM );
  int menor = acha_menor ( vet, NUM );

  std::cout << "O Maior numero é: " << maior << std::endl;
  std::cout << "O Menor numero é: " << menor << std::endl;
  return 0;
}

int 
Pow ( int valor, int exponente ) {

  int acomulador = 1;

  for ( int i = 0; i < exponente; i++) {
  
    acomulador *= valor;
  }

  return acomulador;
}

int 
calcula_pg ( int sequencia,int inicio,int razao ) {

  return (inicio * Pow(razao, (sequencia-1)));
}

int progress_PG (  ) {

  const int COM = 10;

  int veta_pg [COM];

  int valor;

  std::cout << "Digite um numero: ";
  std::cin >> valor;

  int razao;

  std::cout << "Digite uma razao: ";
  std::cin >> razao;

  for(int i = 0; i < COM; i++) {

    veta_pg [i] = calcula_pg(i, valor, razao); 
  }

  exibe_Veta ( veta_pg, COM );

  return 0;
}

int 
descovery_len_poli ( int *p, int max ) {

  int contar = 0;

  for (int i = 0; i < max; i++ ) { 

    if (p[i] != 0) {
      contar = i;
    }
  }

  return contar+1;
}


int 
polindro (  ) {


  int numero;

  std::cout << "Digite um numero: ";
  std::cin >> numero;

  const int max = 12;
  
  int percent = 0;

  static int vet[max];
  
  for (int i = 0; i < max; i++) {

    int aux = int (( numero%(Pow(10,percent)*10) - (numero%(Pow(10,percent)))) / (Pow(10,percent)) );

    vet[i] = aux;

    percent++;
  }

  int numerol = descovery_len_poli ( vet, max );


  int novoVecta[numerol];

  bool flag = true;

  for (int i = 0; i < numerol/2; i++){ 

    if (vet[i] != vet[numerol-i-1]) {
      flag = false;
      break;
    }
  }

  if (flag) {
    
    std::cout << "polindro!";
  } else {

    std::cout << "Não é um polindro!";
  }

  return 0;
}


int 
imprimeVelha ( int *p, int *possicoes ) {

  std::cout << std::endl << "###############" << std::endl;

  for (int i = 0; i < 3; i++) {

    for (int j = 0; j < 3; j++) {

      std::cout << "#";
      std::cout << " ";
    
      int lixo_possicao = j+(3*i);

      if ((possicoes[lixo_possicao] == 1) || 
          (possicoes[lixo_possicao] == 2)) {

        if (possicoes[lixo_possicao] == 1) {
          
          std::cout << 'X';
        } else {

          std::cout << 'O';
        }
          
      } else {

        std::cout << p[lixo_possicao];
      }

      std::cout << " ";
      std::cout << "#";
    }

    std::cout << std::endl << "###############" ;
    std::cout << std::endl;
  }

  return 0;
}

bool 
verificaJogadaValida ( int *jogada, int possicao ) {

  if (jogada[possicao-1] == 0) {

    return true;
  }

  return false;
}

bool 
verificaSeGanhou ( int *jogadas ) {

  int CON = 9;

  int contador = 0;

  for (int jogo = 1; jogo <= 2; jogo++ ) {

    contador = 0;

    for (int j = 0; j < 3; j++) {

      for (int i = 0; i < CON; i+=3) {

        int lixo_possicao = i+j;

        if (jogadas[lixo_possicao] == jogo) {

          contador++;
        } else {

          contador = 0;
        }
      }
      if (contador == 3) {

        return true;
      }
    }

    int contador = 0;

     for (int j = 0; j < 3; j+=3) {

      for (int i = 0; i < CON; i++) {

        int lixo_possicao = i+j;

        if (jogadas[lixo_possicao] == jogo) {

          contador++;

          if (contador == 3) {

            return true;
          }
        } else {
          
          contador = 0;
        }
      }

      contador = 0;
     }

      if ( ( (jogadas[0] == jogo) && (jogadas[4] == jogo) && (jogadas[8] == jogo) ) ||
            ( (jogadas[2] == jogo) && (jogadas[4] == jogo) && (jogadas[6] == jogo) )
          ) {
        
        return true;
      } 

  }

  return false;
}

int
jogodavelha (  ) {

  int flag = true;
  
  int vet [9] = { 1,2,3,4,5,6,7,8,9 };
  int jogadas [9] = { 0,0,0,0,0,0,0,0,0 };
  int jogo = 0;

  std::cout << "Digite -1 para sair: " << std::endl;

  imprimeVelha (vet, jogadas);

  while ( jogo >= 0 ) {

    std::cout << "Digite uma possicao: ";
    std::cin >> jogo;

    if ( ( jogo >= 1 ) && ( jogo <= 9 ) ) {

      if ( verificaJogadaValida ( jogadas, jogo ) ) {

        int caracter = 0;

        if (flag) {

          caracter = 1; // X
        } else {

          caracter = 2; // O
        }

        jogadas[jogo-1] = caracter;
      } else {

        std::cout << "Digite uma possicao valida" <<
                         std::endl;
                         
        flag = !flag;
      }

    } else {

      std::cout << "Digite um numero entre 1 e 9" <<
                         std::endl;
    }

    if ( verificaSeGanhou ( jogadas ) ) {

      char caracter;

      if (flag) {

        caracter = 'X'; // X
      } else {

        caracter = 'O'; // O
      }

      imprimeVelha (vet, jogadas);

      std::cout << "Parabéns, o Jogador " << caracter << " Ganhou! \n \n" << std::endl;

      std::cout << "Deseja Continuar? \n(digite qualquer numero diferente de -1) \n:";
      std::cin >> jogo;

      if (jogo != -1) {
      
        for (int i = 0; i < 9; i++) {
      
          jogadas[i] = 0;
        }
      }
    }
    
    std::cin.clear();
    std::cin.ignore(80, '\n');

    imprimeVelha (vet, jogadas);

    flag = !flag;
  }
  

  return 0;
}


int 
testaSeJogadorGanhou (  ) {

  int vet [9] =     { 1,2,3,4,5,6,7,8,9 }; // OK To verify horizontal values of game velha
  int jogadas [9] = { 2,0,2,1,2,1,2,1,2 };

  if (  verificaSeGanhou ( jogadas ) ) {

    std::cout << "Ganhou" << std::endl;
  } else {

    std::cout << "Não Ganhou" << std::endl;
  }
  return 0;
}



int 
bolsaDeValores (  ) { // TODO

  long unsigned time;





  return 0; 

}





int
begin_exercice (  ) {

  // hellworld (  );

  std::cout << "begin" << std::endl;


  // maior_vecta (  ); // 001 // OK

  // exer02_maior_menor (  ); // 002 // OK

  // progress_PG (  ); // 003 // OK

  // polindro (  ); // 004 // OK

  jogodavelha (  ); // 005 // OK

  // bolsaDeValores (  ); // 101

  std::cout << "end" << std::endl;

  return 0;
}
