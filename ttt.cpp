#include <iostream>
#include <vector>
#include "ttt_functions.hpp"

int main() {

  std::vector<std::vector<std::string>> board = {{"   ", "   ", "   "}, 
                                                 {"   ", "   ", "   "}, 
                                                 {"   ", "   ", "   "}};
                      
  std::vector<std::vector<std::string>> boardPositions = {{" 1 ", " 2 ", " 3 "}, 
                                                          {" 4 ", " 5 ", " 6 "}, 
                                                          {" 7 ", " 8 ", " 9 "}};
                                                          
  int turn = 0;
  int maxTurnNumber = 9;
  std::cout << "\n";
  introduction();
  updateBoardDrawing(board, boardPositions);
  
  // game is played while keeping track of turns. 
  while (turn < maxTurnNumber) {

    board = updateBoard(board);
    boardPositions = updateBoardPositions(boardPositions);
    updateBoardDrawing(board, boardPositions);

    // check if a player (X or O) has won after each turn.
    if (checkWin(board) == true) {
      turn = maxTurnNumber; // turn = 9 (or any turn > 9) exits the while loop.
      // reset board so players can play again.
      //board = resetGameBoard(board); uncomment this along with main() if you want to continue playing without the code exiting.
      //main(); uncomment this line if you want to continue playing without the code exiting.

    } else if (checkWin(board) == false && (turn == (maxTurnNumber-1))) {
      std::cout << "No one wins! Try again.";
      std::cout << "\n";
      // reset board so players can play again.
      board = resetGameBoard(board);
      main();
    }
    turn ++;
  }
  return 0;
}

// Written by AAMD5 (Ahmed Abdelwahab) 18/12/2021.