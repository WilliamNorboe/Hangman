#include "function.h"

void printMan(int lives){

  std::cout<<"   __"<<std::endl;
  std::cout<<"  |  |"<<std::endl;
  std::cout<<"  | ";
  if(lives <= 5){
      std::cout<<" O";
    }


  std::cout<<std::endl;

  std::cout<<"  | ";
  if(lives <= 4){
    if(lives == 4){
      std::cout<<" |";
    }
    else{
      std::cout<<"-|";
    }
  }
  if(lives <= 2){
    std::cout<<"-";
  }
  std::cout<<std::endl;

  std::cout<<"  | ";
  if(lives <= 1){
    std::cout<<"/";
  }
  if(lives == 0){
    std::cout<<" \\";
  }
  std::cout<<std::endl;

  std::cout<<"__|__"<<std::endl;
}

std::string filterOut(std:: string str) {
    int wordLen = str.length();   //get the lenght of the string
    std:: string newString = "";  // variable to store the lenght
    // run a for loop to only check for lowercase & upcase letters
    for(int i=0;i < wordLen; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
          // add them to new string
            newString += tolower(str[i]);
        }
    }

    return newString;
}

bool whiteSpaceCheck(std:: string str) {
    int wordLen = str.length();   //get the lenght of the string
    // run a for loop to only check for whitspace
    for(int i=0;i < wordLen; i++) {
        if (str.at(i) != ' ' && str.at(i) != '\t') {
            return false;
        }
    }

    return true;
}