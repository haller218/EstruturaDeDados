#include <iostream>
#include "files_begin.h"
#include "exercice.h"


// C++11 Reference
// https://cplusplus.com
// https://pt.cppreference.com/w/
// https://www.onlinegdb.com/online_c++_compiler
// http://www.eecs.umich.edu/courses/eecs380/HANDOUTS/cppBinaryFileIO-2.html
#include <functional>
#include <string>
 
int 
main_main (  ) {

    std::string str = "Meet the new boss...";
    std::hash<std::string> hash_fn;
    std::size_t str_hash = hash_fn(str);
 
    std::cout <<  hash_fn("Ola, Mundo!") << '\n';
   // printf(">>>> Begin\n\n");
    // main_begin();
    // begin_exercice();

   // printf(">>>> Finsh\n");

   return 0;
}
