#include "NQueens.hpp"
#include <iostream>
using namespace std;
NQueens::NQueens(int numQueens){
  m_numQueens = numQueens;
  numsolutions = 0;
  m_board = new int[numQueens];
  m_previousSolution = new int[numQueens];
  cout << "Queens:" << numQueens << endl;
  cout << "Deck Size:" << numQueens << "x" << numQueens << endl;
}
void NQueens::computeSolutions(bool printAll){
  if(printAll == true) cout << "Buckle up. Printing All solutions" << endl;
  solveNQ(0, printAll);
  cout << "Total possible solutions:  " << numsolutions << endl;
  if(!printAll){
    m_board = m_previousSolution;
    printboard();
  } 
}
void NQueens::solveNQ(int row, bool printAll){
  //this is a recursive call. first find an exit condition
  //all queens placed. 
  if(row >= m_numQueens){
    numsolutions++;
    memcpy(m_previousSolution, m_board, m_numQueens * sizeof(int));
    //to-do write code to print the board if all solutions are requested
    if(printAll){
      printboard();
    }
    return; 
  }

  //check if a queen can be placed for every column value for the said row
  for(int i = 0; i < m_numQueens ; i++){
    //todo: check safety
    if(isSafe(row, i)){
      m_board[row] = i; //place the queen
      solveNQ(row + 1, printAll);
    }
  }
}
bool NQueens::isSafe(int row, int col){
  for(int i = 0; i< row ; i++){
    if(m_board[i] == col) return false; //if any value on board is same as column
    if(m_board[i] == col - (row - i)) return false; //check for queen in upper left diagonal
    if(m_board[row - 1 - i] == col + i + 1) return false; //check for queen in upper right diagonal
  }
  return true;
}

void NQueens::printboard(){
  int row, col = 0;
  // for (row = 0; row < m_numQueens; row++)
  //   {
  //       cout << m_board[row];
  //   }
  // cout << endl;

  for(int dash = 0; dash < m_numQueens * 4 + 1; dash++)
    cout << "-";
  cout << endl;
  for(row = 0; row < m_numQueens ; row++){
    cout << "|";
    for(col = 0; col < m_numQueens ; col++){
      if(m_board[row] == col)
        cout << " Q |";
      else
        cout << "   |";
    }
    cout << endl;
    for(int dash = 0; dash < m_numQueens * 4 + 1 ; dash++)
      cout << "-";
    cout << endl;
  }
 
}