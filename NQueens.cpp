#include "NQueens.hpp"
NQueens::NQueens(int numQueens){
  m_numQueens = numQueens;
  cout << "Queens:" << numQueens << endl;
  cout << "Deck Size:" << numQueens << "x" << numQueens << endl;
}
void NQueens::computeSolutions(bool printAll){
  if(printAll == true) cout << "Buckle up. Printing All solutions" << endl;
}