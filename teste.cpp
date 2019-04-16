#include <iostream>
#include "Monney.h"
#include <cmath>
#include <fstream>
#include <cstdlib> 
#include <ctime> 



void 
test_Daath_Row ( int digi ) {

  std::string buf = "";
  char str[20];

  std::cout << buf << std::endl;
}



void 
test_MathFunctions (  ) {


  unsigned long long int a = 339;

  char b = a;

  char c = (char)a;

  int d = (int)b;

  int e = a & 0xff;

  std::cout << a << " " << b << " " << c << " " << d << " " << e << std::endl;

  std::cout << std::pow(a,7) << std::endl;

}


int 
test_Hash (  ) {


  char nts1[] = "Test";
  char nts2[] = "Test";
  std::string str1 (nts1);
  std::string str2 (nts2);

  std::hash<char*> ptr_hash;
  std::hash<std::string> str_hash;

  std::cout << str_hash(nts1) << std::endl;

  std::cout << "same hashes:\n" << std::boolalpha;
  std::cout << "nts1 and nts2: " << (ptr_hash(nts1)==ptr_hash(nts2)) << '\n';
  std::cout << "str1 and str2: " << (str_hash(str1)==str_hash(str2)) << '\n';

  return 0;
}

int 
test_Class (  ) {


  Monney coin;

  std::cout << "Works!" << std::endl;
  return 0;
}


int 
test_io () {

  std::ofstream myfile;
  myfile.open ("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();

  return 0;
}

int
test_iobin (  ) {


  std::ofstream myfile;

  // myfile.open ("example.bin", ios::out | ios::app | ios::binary); 
  myfile.open("example.bin", std::ios::out);
  myfile.close();

  return 0;
}

struct Person {

  char name[50];
  int age;
  char phone[24];
};

int 
test_binary_write (  ) {

  Person me = {"Robert", 28, "853312548"};
  Person book[30];
  
  int x = 123;
  double fx = 38.6666;

  std::ofstream outfile;

  //outfile.open("binary.test.bin",  ios::binary | ios::out);
  outfile.open("binary.test.bin", std::ios::binary | std::ios::out);

  outfile.write((const char *)(&x), sizeof(int));
  outfile.write((const char *)(&fx), sizeof(double));
  outfile.write((const char *)(&me), sizeof(me));
  outfile.write((const char *)(book), 30*sizeof(Person));


  outfile.close();

  return 0;
}

struct Headerr {

  int x;
  double fx;
};

int 
test_binary_read (  ) {

  std::ifstream infile;

  int x;
  double fx;

  Person m;

  infile.open("binary.test.bin", std::ios::binary | std::ios::in );

  infile.read((char *)(&x), sizeof(x));
  infile.read((char *)(&fx), sizeof(fx));
  // infile.seek(sizeof(x), std::ios::beg);
  infile.read((char *)(&m), sizeof(m));

  std::cout << "ValueX: " << x << std::endl;
  std::cout << "ValueFx: " << fx << std::endl;
  std::cout << "Strct name: " << m.name << std::endl;
  std::cout << "Strct age: " << m.age << std::endl;
  std::cout << "Strct phone: " << m.phone << std::endl;

  infile.close();

  return 0;
}

int 
test_nolocalAcessBinaryData_read (  ) {
/*
  std::ifstream infile;

  Person m;

  infile.open("binary.test.bin", std::ios::binary | std::ios::in );

  infile. seek(12, std::ios::beg);
  infile.read((char *)(&m), sizeof(m));

  infile.close();
*/

  return 0;
}


int 
RandomTest (  ) {

  srand((unsigned)time(0)); 
  int i;
  for (int j = 0; j < 60; j++) {
   
    i = (rand()%9)+1; 
    std::cout << i << "\n"; 
  }

  return 0;
}


int 
main_ASDFtasdianofkjas (  ) {

  std::cout << "begin" << std::endl;
  /* test_binary_write (  );
  // test_iobin();
  test_binary_read (  );
  // test_nolocalAcessBinaryData_read (  );
  */

  // test_MathFunctions (  );
  RandomTest (  );

  test_Daath_Row (64); 

  std::cout << "end" << std::endl;
  
  return 0;
}

