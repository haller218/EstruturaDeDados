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
polindro (  ) { /// # TODO


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


void 
imprimeVelha ( int *p ) {
/*
  for (int i = 0; i < 3; i++) {

    std::endl;
  }
*/
}


int
jogodavelha (  ) {


  return 0;
}

struct compania {

  char nomeCompania [30];
  char atuacaoCompania [50];

} CompaniaBolsa;

struct acao {

  int valor;
  int CompaniaBolsa;

} AcaoBolsa;



int 
bolsaDeValores (  ) {







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

  // jogodavelha (  ); // 005

  // bolsaDeValores (  ); // 101



  return 0;
}
