#include "function.h"
#include "game.h"

// g++ main.cpp function.cpp game.cpp

int main(int argc, char *argv[]) {
  std::string filename;
  if(argc == 1){
    // std::cout<<"File not specified ending program";
    // exit(1);
     filename = "large.txt";
  }
  else{
    filename = argv[1];
  }

  
  std::string playAgain;
  do {
    gamePlay(filename);
    std::cout<< std::endl << "If You Want to play again enter 'y': ";
    std::cin>>playAgain;
  } while(playAgain == "y");
  std::cout<<"Game Quit";
}



