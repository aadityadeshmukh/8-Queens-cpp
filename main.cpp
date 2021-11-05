#include <iostream>
#include "NQueens.hpp"
using namespace std;

int main(int argc, char* argv[]){
  if(argc < 1)
  {
    cout << "ERROR: Invalid number of arguments" << endl;
    return 1;
  }
  if(atoi(argv[1]) < 4)
  {
    cout << "ERROR: Invalid deck size. Please input a number greater than or equal to 4." << endl;
    return 1;  
  }

  NQueens nq = NQueens(atoi(argv[1]));
  nq.computeSolutions(argv[2]);
}