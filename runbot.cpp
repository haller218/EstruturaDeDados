#include <iostream>
#include "bot.h"



int testLaier (  ) {

  // std::cout << "Hello, World!" << std::endl;

  Bot* bet = new Bot();

  Laier* set = bet->genLaier(); 

  for (int j = 0; j < (*set).__MAX__; j++)
    (*set).Laier[j] = j * 0.22;
  
  for (int i = 0; i < (*set).__MAX__; i++) {
 
    std::cout << "Data Alocation : " << (*set).Laier[i] << std::endl;
  }
  std::cout << "Sizeof : " << sizeof((*set)) << std::endl;

  
  free((*set).Laier);

  
  return 0;
}


void 
testNet (  ) {
  
  Bot bet = new Bot (  );
  
  Network* fy = NULL;
  //  fy = bet->genNet (  );

  delete(bet);



}



int main (  ) {


  //  testLaier (  );
  testNet (  );


  return 0;
}
