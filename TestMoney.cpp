#include <iostream>
#include "Monney.h"


// # https://books.google.com.br/books?id=mxZBPSjSEYUC&pg=PA403&lpg=PA403&dq=show+structs+c%2B%2B11&source=bl&ots=IGpMtjGSue&sig=ACfU3U0Ewqn3OjQnyDEuVQ62U6Dos41Uiw&hl=pt-BR&sa=X&ved=2ahUKEwim08S_6KDhAhWtIrkGHdyxDscQ6AEwBXoECAgQAQ#v=onepage&q=show%20structs%20c%2B%2B11&f=false

int 
testClassTransactionWallet (  ) {

  Monney* as = new Monney();
  
  std::cout << std::endl << "begin" << std::endl;

  char passwd[] = "asdfasdfasdf";
  /// ****** DEPRECATED ******
  Wallet *vv = NULL, *vy = NULL, *vm = NULL;
  vm = as->MakeWallet ( passwd ); // lixo
  vv = as->MakeWallet ( passwd ); // to
  vy = as->MakeWallet ( passwd ); // from
  (*vy).id += 1;

  long double values = 111111111111.65;

  Transaction* ff;

  std::cout << "id vv " << (*vv).id << std::endl;

  (*vv).balance = 6666666066666.66;

  std::cout << "Balance vv : " << (*vv).balance << std::endl;
  std::cout << "Balance vy : " << (*vy).balance << std::endl;
  std::cout << "id vy "<< (*vy).id << std::endl;

  /////// ******
                 /// to, from, value
  ff = as->CreateTransaction(vv,vy, values);

  std::cout << "Transacionando : 128 : " << values << std::endl;

  for (int i = 0; i < 128; i++) {
  
    Transaction* fv = as->CreateTransaction(vv,vy, values);

    // std::cout << "Contagem -T- : " << i << std::endl;

    if ( fv == (Transaction*) NULL) {

        std::cout << "Transacao negada." << std::endl;
        break;
    }
  }

  std::cout << std::endl;
  std::cout << "vv : " << vv << std::endl;
  std::cout << "vv.id : " << (*vv).id << std::endl;
  std::cout << "&vv : " << &vv << std::endl;
  std::cout << "vy : " << vy << std::endl;
  std::cout << "vy.id : " << (*vy).id << std::endl;
  std::cout << "&vy : " << &vy << std::endl;

  std::cout << std::endl;

  std::cout << (*ff).__To << std::endl;
  std::cout << "vv : " << vv << std::endl;

  std::cout << (*ff).__From << std::endl;
  std::cout << "vy : " << vy << std::endl;

  std::cout << "id To ff: " << (*((*ff).__To)).id << std::endl;

  std::cout << "id From ff: " << (*((*ff).__From)).id << std::endl;


  std::cout << "Balance vy : " << (*vy).balance << std::endl;
  std::cout << "Balance vv : " << (*vv).balance << std::endl;

  std::cout << std::endl;



  std::cout << "Value ff : " << (*ff).value << std::endl;

  std::cout << (*((*ff).__To)).passwd << std::endl;

  char passwd2[] = "ASDFASDFASDadgsdfg5a1d6g51 651 6 51 6 15 FASDfasdfasdfsfasdfa f afjnfiejhbfiuy3h8unbv9iujn 9uhn 9iu hniquwhnfiuwhnfujmoiek oi j98 y7 h674 83h 7u9 hjn9 uih ny8 ug bf8vi hunejfvisujgi  ruh938h98 h87uh n u9j sodijfg oiuej 948hj9587h58778374983y8572639428308293742863425347618738274hu2i n iu nisudjnhsgiufjoawifkmowkeriweyuwyrqtwieurhwqnekrqjwkqwerm";

  as->genHash(passwd2);

  std::cout << passwd2 << std::endl;

  std::cout << "PasswdHash vv : " << (*(*ff).__To).passwd << std::endl;

  char* ppp = (char*)"sdfasdf";

  Wallet* vhs = as->MakeWallet( ppp );

  std::cout << (*vhs).passwd << std::endl;

  unsigned int hashp = as->genHash(ppp);

  std::cout << hashp << std::endl;

  bool testP = as->CheckPasswd(vhs,&hashp);

  std::cout << testP << std::endl;

/*
  std::cout << "Value id of vy : " << (*vv).id << std::endl;
  std::cout << "To de ff" << std::endl;
  std::cout << &(*(*ff).__From) << std::endl;
  std::cout << &(*vy) << std::endl;
  std::cout << (*ff).value << std::endl;
  std::cout << as->getCount (  ) << std::endl;
*/
  return 0;
}


int 
testStructs (  ) {

  std::cout << "Create Wallet" << std::endl;
  Wallet my;

  std::cout << "Create *Wallet" << std::endl;
  Wallet* pmy;

  std::cout << "Create Block" << std::endl;
  Block b1;

  std::cout << "Create *Block" << std::endl;
  Block* b0;

  long double vvv = 5416546541.512;
/*
  b1.__To = pmy;
  b1.__From = pmy;
  b1.value = vvv;
*/

  //pmy.id = 12;

  std::cout << "*Block->Block" << std::endl;
  b0 = &b1;

  // (*b0).__To = &pmy;

  std::cout << &(*b0) << std::endl;
  std::cout << &b1 << std::endl;

  std::cout << "Work!" << std::endl;

  // std::cout << ((*b0).__To).id << std::endl;

  std::cout << std::endl;

  return 0;
}


int
testClassBlock (  ) {

  std::cout << "Begin" << std::endl;

  Monney* as = new Monney (  );

  char pass1[] = "Values32";
  char pass2[] = "Valuess31";
  
  Account* wm = as->CreateAccount (pass1);
  Account* wb = as->CreateAccount (pass2);
  
  std::cout << (*wm).id << std::endl;
  std::cout << (*wb).id << std::endl;
  
  for (int i = 0; i<230; i++) {
  
    Account* bb = as->CreateAccount(pass1);
    // std::cout << "Wallet : " << (*bb).id << std::endl;      
    
  }

  unsigned long long int v = 199;
  Account* pop = as->SearchAcount( v );

  if (pop != NULL) {
    std::cout << "Encontrado: " << (*pop).id << std::endl;
    std::cout << "Pub : " << (*pop).pubId << std::endl << std::endl;
  } else
    std::cout << "Nao Encontrado" << std::endl;

  Account* b = as->Login( 200, pass1 );

  
  if (b != NULL) {
    
    std::cout << "Id: " << (*b).id << std::endl;
    
    std::cout << "Login Efetuado" << std::endl;

    std::cout << "Balance : " << (*b).balance << std::endl;

    std::cout << "Passwd : " << (*b).passwd << std::endl;

    std::cout << "PubId : " << (*b).pubId << std::endl;

    
  } else {
   
    std::cout << "Login Nao Efetuado" << std::endl;
  }


  return 0;
}

int 
main (  ) {


  testStructs (  );
  testClassTransactionWallet (  );
  testClassBlock (  );


  return 0;
}
