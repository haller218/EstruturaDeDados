#include <string>

/*
#### Formalização da BolsaDeValores
###$
##$

flag *= muito(a)s
flag & endereço


  #  A Bolsa de  Valores possui varios bancos, cada banco possui algumas *=companias, *=traders e *=Contratos e cada banco possui endereço do proximo &banco

  # Cada Acao tem seu valor de negociacao assim com o tempo em que foi comprada e a &compania que e dona da ação assim como o &trader que fez a operacao com o con

  # Contrato

##$
###$
#### ===============================

*/



typedef struct Compania {

  string nomeCompania;
  int Id;
  int numeroDeContratos;
} Compania;

typedef struct Trader {

  string nomeCompleto;
  string senha;
  Trader* __NextTrader;
} Trader;

typedef struct Acao {

  unsigned double valor;
  unsigned long time;
  Trader* __Trader;
  Compania* __Compania;
  Acao* __NextAcao;
} Acao;


typedef struct Contrato {

  unsigned double valor;
  unsigned double balanco;
  Trader* __Trader;
  Acao* __Acaoes;
  bool Tipo;
} Contrato;

typedef struct Banco {

  Acao* Bolsa;
  Compania Companias[80];
  Banco* __NextBanco;
} Banco;

class BolsaDeValores {

  Banco* Bancos;
  Acao** PonteiroParaPonteiroDaUltimaAcaoNext;
  Compania companias[90];
  Trader* Traders;

  public:

    Acao*
    CriaAcao ( unsigned double valor
              ,unsigned long time
              ,Compania* compania
              ,Acao* next
              ) {

      Acao news;

      news.valor = valor;
      news.time = time;
      news.__Compania = compania;
      news.__Next = valor;

      return news;
    }
}
