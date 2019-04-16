#include <functional>
#include <sstream>
#include <string>
#include <cmath>

#include <cstdlib> 
#include <ctime> 

#include "sha256.h"

/*
##$ Classe destinada a implementar sistema de trocas por meio de 
#$     estrutura de dados em lista

  -!- Utilizar estrutura de dados ...
  -1- Criar Classe de operação com arquivos padrão blockchain.
  -2- Construir API de interface com o mundo externo.
  -!- Criar estrutura para volume de transacoes
  -!- Implementar Multi-nivel public andress in future coin
  -3- criar sistema de transação baseado em altenticação do enviador não das duas partes.
  -!- Somar o id do cliente com numero randomico para gerar chave publica, ocasionalmente mudar codigo para percorrer ids.


#$
##$
#  http://www.cplusplus.com/forum/general/37962/
#  http://www.cplusplus.com/forum/general/37962/
*/

#define MAX_PASS 32

#define MAX_BLOCK 64

#define MAX_RAND_KEY 3232323

#define MAX_SUPPLAY 5232323232323.5

#define FACTOR_DECRESS_CONST 0.5

#define BEGIN_FALCET 0.002

struct Wallet {

  unsigned long long int id;
  long double balance;
  unsigned int passwd;
  int rand;
  Wallet* __Next;
};

struct Account {
  
  unsigned long long int id;
  long double balance;
  unsigned int passwd;
  int rand;
  std::string pubId;
};

struct Transaction {

  std::string idd;
  unsigned int groupId;
  long double value;
  Wallet* __To;
  Wallet* __From;
  Transaction* __Next;
};

struct Block {

  std::string iddr;
  unsigned long int idBlock;
  Transaction* __Transactions;
  Block* __Next;
};


class Monney 
{

  private:

    long double suplay = MAX_SUPPLAY;

    Block* Blocks = NULL;
    Wallet* Wallets = NULL;

    bool randoness = true;

    long double 
    setUn ( double value ) {

      return ( long double ) value;
    }

    unsigned long long int
    getCountWallets (  )
    {

      return ((*(this->Wallets)).id);
    }

    Wallet*
    SearchWallet ( unsigned long long int id )
    {
    
      Wallet* conta = NULL;
      conta = this->Wallets;
      
      while ( conta != NULL ) {

        if ( (*(conta)).id == id )
          return conta;
        
	      conta = (*conta).__Next;
      }
      
      return conta;
    }

    Wallet*
    AccountToWallet ( Account* lon )
    {
      
      Wallet* wal = NULL;
      wal = this->SearchWallet ( (*lon).id ); 
    
      return wal;
    }

    std::string 
    MakePubId ( unsigned long long int id, int rand ) 
    {

      return this->shasum( this->intToString( id ) + this->intToString ( rand ) );
    }

    void 
    SeedRandom (  )
    {

      this->randoness = false;
      srand ( ( unsigned ) time ( 0 ) );
    }

    size_t 
    getRandom ( int range = 10 ) 
    {
      if ( this->randoness )
        this->SeedRandom (  );

      return ((rand()%range)+1); 
    }

    // ******* DEPRECATED ********
    unsigned int 
    genPubId_old ( unsigned long long int id, unsigned int pass )
    {
      
      id = std::pow ( id, 3 );

      std::string idr = this->intToString ( id );
      std::string poss = this->intToString ( pass );      
      std::string target = idr + poss;
       
      char* idd = NULL;

      idd = this->stringToChar ( target );
      
      return this->genHash ( idd );
    }
    //=  

    unsigned long long int 
    getIdFromPub ( std::string pubId ) 
    {

      Wallet* conta = NULL;
      conta = this->Wallets;
      
      while ( conta != NULL ) {

        if ( this->MakePubId ( (*conta).id
            , (*conta).rand ) == pubId )
          return (*conta).id;
        
	      conta = (*conta).__Next;
      }
      return 0;
    }

    bool 
    transferMoney ( Wallet* Operate
                  , long double operand )
    {

      if (operand < 0)
        if (! ((*Operate).balance >= (-1*(operand))) )
          return false;
          
      return ((*Operate).balance += operand);
    }
  
    Block*
    makeBlock (  ) 
    {

      if ( this->Blocks != NULL )
        return this->Blocks;

      return new Block (  );
    }

    unsigned long int 
    getCountBlock (  )
    {

      if ((this->Blocks) != NULL )
        return (*Blocks).idBlock;
      
      return 0;
    }

    void 
    setGroupIdTransactions ( unsigned int newid )
    {
      
      if ( this->checkBlock (  ) )
        if ( this->checkTransactions (  ) )
         (*((*Blocks).__Transactions)).groupId = newid;
    }

    unsigned long int 
    GetGroupIdTransactions (  )
    {
      
      if ( this->checkBlock (  ) )
        if ( this->checkTransactions (  ) )
          return (*((*Blocks).__Transactions)).groupId;

      return (unsigned long int) 0;
    } 

    bool 
    checkTransactions (  )
    {

      return ((*(this->Blocks)).__Transactions != (Transaction*)NULL);
    }

    bool 
    IncressGroupTransaction ( Transaction* tr ) 
    {

      return (*tr).groupId = (this->GetGroupIdTransactions()+1);
    }

    bool 
    checkBlock (  ) 
    {

      return ((this->Blocks) != NULL );
    }

    bool 
    SalveTransactions ( Transaction* trans )
    {

      if ( this->checkBlock (  ) ) {

          (*trans).__Next = (*this->Blocks).__Transactions;

          this->IncressGroupTransaction ( trans );

          (*this->Blocks).__Transactions = trans;

      }

      return true;
    }


  public:


    unsigned long long int 
    setUh ( int un ) 
    {
    
      return (unsigned long long int) un;
    }

    std::string
    charToString ( char* str )  
    {
    
      std::stringstream ss;
      std::string target;

      ss << str;
      ss >> target;
      
      return target; 
    }

    std::string
    intToString ( int value )
    {

      std::string s;
      std::stringstream out;
      out << value;
      s = out.str();

      return s;
    }


    std::string
    doubleToString ( long double value )
    {

      std::string s;
      std::stringstream out;
      out << value;
      s = out.str();

      return s;
    }


    char*
    stringToChar ( std::string str ) 
    {

      char* fine = NULL;
      fine =  &str[0u];

      return fine; 
    }

    // ******* DEPRECATED ********
  // but stay where her
    unsigned int  
    genHash ( char* pass )
    {
     
      std::string target;
      target = this->charToString ( pass );

      std::hash<std::string> hash_fn;
      std::size_t value = hash_fn(target);

      return (unsigned int) value;
    }
    //=

    std::string
    shasum ( std::string str )
    {

      return sha256 ( str );
    }

    bool 
    CheckPasswd ( Wallet* wal, unsigned int* pass ) 
    {

      if ((*wal).passwd == (*pass))
        return true;

      return false;
    }

    Wallet* 
    MakeWallet ( char* pass ) 
    {

      Wallet* nes = NULL;
      nes = new Wallet (  );

      if ( this->Wallets != NULL ) 
	      (*nes).id = ( 1 + this->getCountWallets (  ) );
      
      (*nes).balance = this->setUn ( 0.0 );
      (*nes).rand = this->getRandom ( MAX_RAND_KEY );
      (*nes).passwd = this->genHash ( pass );
    
      return nes;
    }

    Transaction* 
    CreateTransaction ( Wallet* To
                      , Wallet* From
                      , long double value ) 
    {
    
      Transaction* nes = NULL;
      nes = new Transaction (  );

      if ( ( this->transferMoney ( To, (-1*(value)) ) )
            && ( value > 0.0 )
          ) {

        (*nes).value = value;
        (*nes).__To = To;
        (*nes).__From = From;

        this->transferMoney ( From, value );

        return nes;
      } else return (Transaction*) NULL;

    }

    Block* // TODO
    BuildBlock ( Wallet* To
               , Wallet* From
               , long double value ) 
    {

      Block* bol = NULL;

      std::cout << "bLOCK" << std::endl;

      bol = this->makeBlock (  );
      
      Transaction* nsc = NULL;

      nsc = CreateTransaction ( To, From, value );

      if ( ( this->SalveTransactions ( nsc ) ) ) {

        (*bol).idBlock = (this->getCountBlock (  )+1);



        return bol;
            
      }      
      
      return (Block*) NULL;
    }

    unsigned long long int // TODO 
    SearchTransactions ( unsigned long long int id )
    {


      return id;
    }

    Account*
    SearchAcount ( unsigned long long int id )
    {
    
      Wallet* nux = NULL;
      nux = this->SearchWallet ( id );
      
      if ( nux == NULL)
	      return (Account*) NULL;
      
      Account* Acon = NULL;
      Acon = this->WalletToAccount ( nux );
      
      return Acon;
    }


    bool
    SaveBlock ( Block* bb )
    {
      
      if ( this->GetGroupIdTransactions (  ) > MAX_BLOCK) {

        if ( this->checkBlock (  ) ) {
          (*bb).__Next = (this->Blocks);

          std::cout << "########### bLOCK" << std::endl;

          (*this->Blocks).__Next = bb;
        } return true;
      } return false;
    }


    bool // TODO*
    MakeTrade ( unsigned long long int id
              , char* passwd
              , long double value
              , std::string pubIdFrom ) 
    {

      Account* non = NULL;
      non = this->Login ( id, passwd );

      if ( non != NULL ) {

        Wallet* From = NULL;

        From = this->SearchWallet ( this->getIdFromPub ( pubIdFrom ) );

        Wallet* To = NULL;

        To = this->SearchWallet ( (*non).id );

        Block* now = NULL;

        now = this->BuildBlock ( To, From, value );

        return true;
      } else return false;
    }


    Account*
    WalletToAccount ( Wallet* wal )
    {

      Account* Acon = NULL;
      Acon = new Account (  );
      
      (*Acon).balance = (*wal).balance;
      (*Acon).passwd = (*wal).passwd;
      (*Acon).rand = (*wal).rand;
      (*Acon).id = (*wal).id;
      
      (*Acon).pubId = this->MakePubId ( (*Acon).id
            , (*Acon).rand );

      return Acon;
    }

    Wallet* 
    CreateWallet ( char* passwdr ) 
    {

      Wallet* wal = NULL;
      wal = this->MakeWallet ( (char*) passwdr );

      Wallet* tempWallet = NULL;
      tempWallet = this->Wallets;
      
       
      this->Wallets = wal;
    

      (*wal).__Next = tempWallet;
      
      return wal;
    }
  
    Account*
    CreateAccount ( char* passwdr ) 
    {
      
      Wallet* wal = NULL;
      wal = this->CreateWallet ( passwdr );
      
      Account* lon = NULL;
      lon = this->WalletToAccount ( wal );
      
      return lon;     
    }


    Account* 
    Login ( unsigned long long int id, char* pass )
    {

      unsigned int poss = this->genHash ( pass );

      Wallet* nux = this->SearchWallet( id );
      
      if (nux == NULL)
      	return (Account*) NULL;

      if ( this->CheckPasswd (nux, &poss) ) {
	
	      Account* lon = NULL;
	
	      lon = this->WalletToAccount ( nux );

	      return lon;
      } else return (Account*) NULL; 

    }

  /// while to understand saveblock
    Wallet*
    SearchWalletPub ( unsigned long long int id )
    {

      return this->SearchWallet ( id );
    }

  
};
