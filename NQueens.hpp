#include <iostream>
#include <cstring>

class NQueens{
  public:
    NQueens(int numQueens);
    void computeSolutions(bool printAll);
  private:
    int m_numQueens, numsolutions = 0;
    int * m_board = NULL;
    int * m_previousSolution = NULL;
    void solveNQ(int row, bool printAll);
    bool isSafe(int row, int col);
    void printboard();
};


