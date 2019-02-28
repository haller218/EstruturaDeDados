// #include <stdio.h>
#include <iostream>
//#include <algorithm>
//#include <functional>

#define TAM 50


int 
init_begin_arrays (  ) {

  int i = 0;
  int vt1[TAM],vt2[TAM],vt3[TAM*2];

  for (i = 0; i < TAM; i++) {
    vt1[i] = i*TAM;
    vt2[i] = i*TAM*21;
  }

  for (i = 0; i < TAM; i++) {
    vt3[i] = vt1[i];
    vt3[TAM+i] = vt2[i];
  }

  int lixoconta = 0;
  for (i = 0; i< TAM*2;i++) {
    //std::cout << vt3[i] << ' ';
    printf("%d ",vt3[i]);
    
    if (lixoconta >= 9) {
      printf ("\n ");
      lixoconta=0;
    }
    lixoconta++;
  }
  return 0;
}

int 
vet_cons_array (  ) {

  int i = 0;
  double vet1[TAM];

  for (i = 0; i< TAM; i++) {
    std::cout<<"Digite um numero: ";
    std::cin >> vet1[i];
  }
  
  double maior = vet1[0];

  for (i = 0; i < TAM; i++) {

    if (vet1[i] > maior) {
      maior = vet1[i];
    }
  }
  std::cout << "O Maior Numero eh: "<<maior << '\n';

  return 0;
}

#define TMAX 64

int 
matrix_vecta (  ) {

  int matrixs [TMAX][TMAX];

  int count = 0;

  for (int i = 0; i < TMAX; i++)
    for (int j = 0; j < TMAX; j++)
      matrixs[j][i] = count++;


  for (int i = 0; i < TMAX; i++)
    for (int j = 0; j < TMAX; j++)
      std::cout << matrixs[j][i] << " ";
  


  return 0;
}

int
vecta_razao_binary (  ) { // # TODO
  /**
  
    informe um nu
    cin > num 

    informe razao
    cin > num 

    
  
  */

  int s = 0;
  /*


  int numes = 0;

  std::cout << "digite o numero de digitos : ";
  std::cin >> numes;

  int numA [numes];
  int numB [numes];

  for (int i = 0; i < numes; i++) {
    
    for (int j = 0; j < numes; j++) {
     
      std::cout << "diogite um numero : ";
      std::cin >> 
    }


  }

  for (int i = 0; i < numes; i++)
    for (int j = 0; j < numes; j++)
      std::cout << numA[j][i] << " ";*/
  return 0;
}


struct cadastro
{

    char nome[20];
    char end [50];
    char telefone [11];

};

int 
trabalhandoComStruct (  ) {

  struct cadastro c[2];
  
  for (int i = 0; i < 2; i++) {
      
    std::cout << "Digite seu nome: " << std::endl;
    std::cin >> c[i].nome;
    std::cout << "\nDigite seu endereco: " << std::endl;
    std::cin >> c[i].end;
    std::cout << "\nDigite seu Telefone: " << std::endl;
    std::cin >> c[i].telefone;
  }
  
  for ( int i = 0; i < 2; i++ ) {
    
    std::cout << "\n Nome : " << c[i].nome << std::endl;
    std::cout << "\n Endereco : " << c[i].end << std::endl;
    std::cout << "\n Telefone : " << c[i].telefone << std::endl;
    std::cout << "\n\n" << c[i].nome << std::endl;
  }

  return 0;
}

typedef struct Data {

  int dia;
  char mes;
  int ano;
} Data;

typedef struct aniversarioDoAno {
  char nome[20];
  Data nascimento;
} Aniversario;


int
struc_data_inception_handler ()
{
    
    // Aniversario alguem;
    struct aniversarioDoAno alguem;
    
    std::cout<< "Digite o nome de alguem" << std::endl;
    std::cin.getline(alguem.nome, 50);
    
    std::cout << "Digite o dia que a pessoa nasceu" << std::endl;
    std::cin >> alguem.nascimento.dia;
    
    std::cout << "Digite o mes que a pessoa nasceu" << std::endl;
    std::cin >> alguem.nascimento.mes;

    std::cout << "Digite o ano que a pessoa nasceu" << std::endl;
    std::cin >> alguem.nascimento.ano;

    system("clear");
    
    std::cout << alguem.nome << std::endl;
    std::cout << alguem.nascimento.dia << std::endl;
    std::cout << alguem.nascimento.mes << std::endl;
    std::cout << alguem.nascimento.ano << std::endl;
    
    
  return 0;
}


/*

Defina uma estrutura que irá representar bandas de música. Essa
estrutura deve ter o nome da banda, que tipo de música ela toca, o
número de integrantes e em que posição do ranking essa banda está
dentre as suas 5 bandas favoritas.

*/
typedef struct integrantes {

  char nomeIntegrante[20];

} Musicos;


typedef struct banda {

  char Nome[20];
  char EstiloMusical [60];
  Musicos Integrantes[20];
  int Posicao;

} BandaMusical;



int 
bandasDeMusica (  ) {

  const int numeroDeBandasFavoritas = 2;
  const int numeroDeIntegrantesEmCadaBanda = 2;

  BandaMusical bandas[60];

  for (int i = 0; i < numeroDeBandasFavoritas; i++)   {
    
    std::cout << "Digite o nome da sua " << i+1 << " banda: "; 
    
    std::cin.getline(bandas[i].Nome,20);

    std::cout << std::endl;

    std::cout << "Digite o tipo musical da sua " << i+1 << " banda: ";

    std::cin.getline(bandas[i].EstiloMusical,60);
    
    std::cout << std::endl;

    for ( int j = 0; j < numeroDeIntegrantesEmCadaBanda; j++ ) {

      std::cout << "Digite o Integrante " << (j+1) << " da sua " << i+1 << " banda: "; 

      std::cin.getline(bandas[i].Integrantes[j].nomeIntegrante,20);

      std::cout << std::endl;

    }
    
    std::cout << "Digite o possicao da sua " << i+1 << " banda: "; 
    
    std::cin >> bandas[i].Posicao;

    std::cout << std::endl;
    
    std::cin.clear();
    std::cin.ignore(80, '\n');

  }

  // visualizar dados

  for (int i = 0; i < numeroDeBandasFavoritas; i++)   {

    std::cout << "Banda " << (i+1) << std::endl;
    std::cout << "BandaNome: " << bandas[i].Nome << std::endl;

    std::cout << "BandaEstiloMusical: " << bandas[i].EstiloMusical << std::endl;
  

    for ( int j = 0; j < numeroDeIntegrantesEmCadaBanda; j++ ) {

      std::cout << "BandaIntegrantes: " << bandas[i].Integrantes[j].nomeIntegrante << std::endl;

    }

    std::cout  << "BandaPossicao: " << bandas[i].Posicao << std::endl;

  }
  
  return 0;
}

/*
  3 - Construa uma declaração de struct em C++ que possa acomodar
  dados provenientes de uma tabela conforme o exemplo a seguir:
*/

typedef struct tabela {

  char Nome[20];
  char Rua[30];
  int Numero;
  char Bairro[30];
  char Complemento;
  char CEP[11];
  char Cidade[20];
  char UF[2];
  char Telefone[12];
  char Telefone2[12];
  char Telefone3[12];

} Tabelada;


int 
olharATabelinha (  ) {


  Tabelada tab[2];

  for (int i = 0; i < 2; i++) {

    std::cout<< "Campo: " << i+1 << std::endl;

    std::cout << "Digite o Nome para ser colocado na tabela: " ;

    std::cin.getline(tab[i].Nome,20);

    std::cout << "Digite o Rua para ser colocado na tabela: " ;

    std::cin.getline(tab[i].Rua,30);

    std::cout << "Digite o Numero para ser colocado na tabela: " ;

    std::cin >> tab[i].Numero;

    std::cout << "Digite o Bairro para ser colocado na tabela: " ;

    std::cin.getline(tab[i].Bairro,30);

    std::cout << "Digite o nome para ser colocado na tabela: " ;

    std::cin.getline(tab[i].Nome,20);

    std::cout << "Digite o Complemento para ser colocado na tabela: " ;

    std::cin >> tab[i].Complemento;

    std::cout << "Digite o CEP para ser colocado na tabela: " ;

    std::cin.getline(tab[i].CEP,11);

    std::cout << "Digite o Cidade para ser colocado na tabela: " ;

    std::cin.getline(tab[i].Cidade,20);

    std::cout << "Digite o UF para ser colocado na tabela: " ;

    std::cin.getline(tab[i].UF,2);

    std::cout << "Digite o Telefone para ser colocado na tabela: " ;

    std::cin.getline(tab[i].Telefone,12);

    std::cout << "Digite o Telefone 2 para ser colocado na tabela: " ;

    std::cin.getline(tab[i].Telefone2,12);

    std::cout << "Digite o Telefone 3 para ser colocado na tabela: " ;

    std::cin.getline(tab[i].Telefone3,12);

    std::cin.clear();
    std::cin.ignore(80, '\n');
  }



  for (int i = 0; i < 2; i++)   {

      std::cout << "Campo : " << (i+1) << std::endl ;
      std::cout << "Nome : " << tab[i].Nome << std::endl;
      std::cout << "Rua : " << tab[i].Rua << std::endl;
      std::cout << "Numero : " << tab[i].Numero << std::endl;
      std::cout << "Bairro : " << tab[i].Bairro << std::endl;
      std::cout << "Complemento : " << tab[i].Complemento << std::endl;
      std::cout << "Nome : " << tab[i].Nome << std::endl;
      std::cout << "CEP : " << tab[i].CEP << std::endl;
      std::cout << "Cidade : " << tab[i].Cidade << std::endl;
      std::cout << "UF : " << tab[i].UF << std::endl;
      std::cout << "Telefone : " << tab[i].Telefone << std::endl;
      std::cout << "Telefone2 : " << tab[i].Telefone2 << std::endl;
      std::cout << "Telefone3 : " << tab[i].Telefone3 << std::endl;

  }


  return 0;
}






int 
lambdaTest (  ) {

  // lambda resul.tas c++ 11
  // https://www.youtube.com/watch?v=uk0Ytomv0wY


  [](){}();

  []() {

    std::cout << "Hello, World!!!!" << std::endl;

  }();

  ///fff();

  return 0;
}


int
main_begin (  ) {

  std::cout << "begin" << std::endl;
  
  // init_begin_arrays (  );

  // vet_cons_array (  );

  // matrix_vecta (  );

  // lambdaTest (  );

  // trabalhandoComStruct (  );
  // struc_data_inception_handler (  );
  
  
  /// bandasDeMusica (  );


  olharATabelinha (  ) ;

  return 0;
}
