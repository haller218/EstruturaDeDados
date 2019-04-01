#include <functional>
#include <sstream>
#include <string>
#include <cmath>

/*
##$ Classe destinada a implementar sistema de trocas por meio de 
#$     estrutura de dados em lista

  -!- Utilizar estrutura de dados ...
  -1- Criar Classe de operação com arquivos padrão blockchain.
  -2- Construir API de interface com o mundo externo.
  -!- Criar estrutura para volume de transacoes

#$
##$
#  http://www.cplusplus.com/forum/general/37962/
#  http://www.cplusplus.com/forum/general/37962/
*/

#define MAX_PASS 32

#define MAX_BLOCK 64

struct Wallet {

  unsigned long long int id;
  long double balance;
  unsigned int passwd;
  Wallet* __Next;
};

struct Account {
  
  unsigned long long int id;
  long double balance;
  unsigned int passwd;
  unsigned int pubId;
};

struct Transaction {

  long double value;
  Wallet* __To;
  Wallet* __From; 
};

struct Block {

  Transaction _Transactions[MAX_BLOCK];
  Block* __Next;
};


class Monney 
{

  private:

    Block* Blocks = NULL;
    Wallet* Wallets = NULL;

    // ******* DEPRECATED ********
    unsigned long long int countTransactions;
    unsigned long int countBlocks;
    //=

    long double 
    setUn ( double value ) {

      return ( long double ) value;
    }

    unsigned long long int
    IncrementWallets (  )
    {

      return 1 + ((*(this->Wallets)).id);
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
    
      if (wal == NULL)
	      return (Wallet*) NULL;
      else
      	return wal;
    }

    unsigned int 
    genPubId ( unsigned long long int id, unsigned int pass )
    {
      
      id = std::pow ( id, 2 );

      std::string idr = this->intToString ( id );
      std::string poss = this->intToString ( pass );      
      std::string target = idr + poss;
       
      char* idd = NULL;

      idd = this->stringToChar ( target );
      
      return this->genHash ( idd );
    }

    unsigned int 
    getIdFromPub ( long int pubId ) 
    {

      for (unsigned long long int i = 0; i < this->getCountWallets (  ); i++) {
        if ( pubId == this->genPubId ( i ) )
          return i;
      }

      return -1;
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

    char*
    stringToChar ( std::string str ) 
    {

      char* fine = NULL;
      fine =  &str[0u];

      return fine; 
    }

    unsigned int  
    genHash ( char* pass )
    {
     
      std::string target;
      target = this->charToString ( pass );

      std::hash<std::string> hash_fn;
      std::size_t value = hash_fn(target);

      return (unsigned int) value;
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
	      (*nes).id = this->IncrementWallets(  );
      
      (*nes).balance = this->setUn ( 0.0 );
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

      (*nes).value = value;
      (*nes).__To = To;
      (*nes).__From = From;

      return nes;
    }

    Block* // TODO
    BuildBlock (  ) 
    {
      Block* bol = NULL;
      

      return bol;
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


    //Transaction* // TODO
    void
    MakeTrade ( unsigned long long int idTo
	            , char* passwdTo
              , unsigned long long int idFrom
              , char* passwdFrom ) 
    {


      // return 
    }


    Account*
    WalletToAccount ( Wallet* wal )
    {

      Account* Acon = NULL;
      Acon = new Account (  );
      
      (*Acon).balance = (*wal).balance;
      (*Acon).passwd = (*wal).passwd;
      (*Acon).id = (*wal).id;
      
      (*Acon).pubId = this->genPubId( (*Acon).id, (*Acon).passwd );

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


  
};
