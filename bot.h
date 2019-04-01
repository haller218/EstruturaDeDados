#include <cmath>

/*
**

-!- Nota, criar estrutura de dados com classes para neuronios

*
*/



#define MAX_LAIER 8

#define MAX_NETWORK 1

struct Laier {
  
  const unsigned int __MAX__ = MAX_LAIER;
  long double* Laier; 
};

struct Network {
  
  const unsigned int __MAX__ = MAX_NETWORK;
  Laier* net;
};


class Bot {
  
 private:

  Network* net = NULL;
  
 public:

  Laier*
  genLaier (  )
  {
    
    Laier* line = NULL;
    line = new Laier (  );
      
          
    (*line).Laier = (long double *)(calloc(((*line).__MAX__),sizeof(long double) ));
    
    return line;
  }
  
  Network*
  genNet (  )
  {

    Network* now = NULL;
  
    now = new Network (  );
    
    (*now).net = (Laier*)(malloc(sizeof(Laier*)*((*now).__MAX__) ));
    
    for (int i = 0; i < (*now).__MAX__; i++)
      (*now).net[i] = this->genLaier (  );
	   	   
	   
    return now;
  }
  
  int 
  ~Bot (  ) {
  
    std::cout << "DEL" << std::endl;
    return 0;
  }
  
  //public:

};
