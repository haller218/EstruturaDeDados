#include <string>
#include <ctime>

/*
#### Formalização da BolsaDeValores
###$
##$

### Todo o problema reside em criar infraestrutura para o usuario invocar as funcoes criadas para operar no mercado com os outros usuarios/bots.

####$ TODO List
##$

  -!- Create paralel finance block for commodits and money, because the Marcketcap needs variability/conversion of values in time.

  -!- Encapsule any use of Data Love in the individual data are all information the needs for operate in marckets.

  -1- create data sctruct class for any money virtual block chain and using than for the marcket capitalization.

##$
###$$


flag *= muito(a)s
flag & endereço


  #  A Bolsa de  Valores possui varios bancos, cada banco possui algumas *=companias, *=traders e *=Contratos e cada banco possui endereço do proximo &banco

  #  Cada Acao tem seu valor de negociacao assim com o tempo em que foi comprada e a &compania que e dona bem como o &trader que fez a operacao e o contrato que foi utilizado para tirar o blanço para a operação.

  #  Contratos são as propostas sugeridas de negociação e os montantes de compra/vendas atuando no mercado.

  # O Mercado deve ter suas proprias carterias com o valor de todos os usuarios e o identificador de quanto cada um deve ter em sua carteira para efetuar transações entre Moedas diferentes e assim 

##$
###$
#### ===============================

*/


typedef struct Compania {

  string nomeCompania;
  int Id;
  int numeroDeAcoes;
} Compania;

typedef struct Trader {
  
  double balanco;
  unsigned long idTrader;
  string nomeUsuario;
  string nomeCompleto;
  string senha;
  Trader* __NextTrader;
} Trader;

typedef struct Transacao {

  Trader* __deTrader;
  Trader* __paraTrader;
  Transacao* __Next;
} Transacao;

typedef struct Acao {

  unsigned long time;
  Transacao* __operacao;
  Compania* __Compania;
  Acao* __NextAcao;
} Acao;

typedef struct Ativos {

  Acao* __acao;
  Ativos* __NextAtivo;
} Ativos;

typedef struct Contrato {

  bool Tipo;
  unsigned double valor;
  unsigned double balanco;
  Trader* __Trader;
  Ativos* __Ativos;
  Contrato* __NextContrato;
} Contrato;

typedef struct Banco {

  unsigned double balanco;
  Compania Companias[80];
  Banco* __NextBanco;
} Banco;


class Helpers 
{

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


    Banco* 
    CriaBanco (  ) {

      Banco news;

      return news;
    }

}

class BolsaDeValores 
{

  Banco* Bancos;
  Acao** PonteiroParaPonteiroDaUltimaAcaoNext;
  Compania companias[90];
  Trader* Traders;

  public:


}
