#include <functional>
#include <sstream>
#include <string>
/*
##$ Classe destinada a implementar sistema de trocas por meio de 
#$     estrutura de dados em lista


  -!- Utilizar estrutura de dados ...

  -1- Criar Classe de operação com arquivos padrão blockchain.

  -2- Construir API de interface com o mundo externo.


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

  public:

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
      //      (*nes).countTransaction = this->IncrementTransactionCount();
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

    Wallet*
    SearchWallet ( unsigned long long int id )
    {

      Wallet* conta = NULL;
      conta = this->Wallets;
      
      do {
	
	if (conta == NULL)
	  break;
	
	if ( (*(conta)).id == id)
	  return conta;
	
	conta = (*conta).__Next;
      
      } while ( conta != NULL ); 

      return conta;
    }

    //Transaction* // TODO
    void 
    MakeTrade ( Wallet* wto
              , Wallet* wfrom
              , long double value ) 
    {


      // return 
    }

    Wallet* 
    CreateAcount ( char* passwdr ) 
    {

      Wallet* wal = NULL;
      wal = this->MakeWallet ( (char*) passwdr );

      Wallet* tempWallet = NULL;
      tempWallet = this->Wallets;
      
       
      this->Wallets = wal;
    

      (*wal).__Next = tempWallet;

      return wal;
    }

    //Wallet* // TODO
    void 
    Login ( unsigned long long int id, char* pass )
    {

      
      



      
      
      
      
      
      // return 
    }

  
};
