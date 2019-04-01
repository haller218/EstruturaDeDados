#include <functional>
#include <sstream>
#include <string>
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
  
    int Pow ( int num, int exp )
    {
  
      int acu = 1;
      
      for ( int i = 0; i < exp; i++ ) 
	acu *= num;
      
      return acu;
    }
  
    int 
    SLen ( char* str ) 
    {
    
      int conta = 0;
      
      while ( str[conta] != '\0' ) {
      
	conta++;
      }
    
      return conta;
    }
  
    char* StrCopy ( char* sto, char* sfrom )
    {
    
      int lenTo = this->SLen ( sto );
      int lenFrom = this->SLen ( sfrom );
      
      if (lenFrom < lenTo)
	return (char*) NULL;
      else {
	
	for ( int i = 0; i < lenTo; i++ )
	  sfrom[i] = sto[i];
	
	return sfrom;
      }

    }


  public:
  
 
    unsigned long long int 
    setUh ( int un ) 
    {
    
      return (unsigned long long int) un;
    }
  

    unsigned int  
    genHash ( char* pass )
    {
     
      std::stringstream ss;
      std::string target;

      ss << pass;
      ss >> target;

      std::hash<std::string> hash_fn;
      std::size_t value = hash_fn(target);

      return (unsigned int) value;
    }

    char*
    IntToChar ( unsigned int numero)
    {
      
      char world [MAX_PASS];
      
      for (int i = 0; i < MAX_PASS; i++) {


	world[i] = char ((numero%(this->Pow(10,i)*10)) -
			 (numero%(this->Pow(10,i))) / 
			 (this->Pow(10, i)));
      }

      world[MAX_PASS-1] = '\0';
      
      return world;
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
      
      char* idd = this->IntToChar((*Acon).id);
      
      (*Acon).pubId = this->genHash( idd );
				      
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
