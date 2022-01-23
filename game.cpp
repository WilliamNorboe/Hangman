#include "game.h"

void gamePlay(std::string argv){

  std::cout<<"Instructions: Computer generates a random words and you have  to guess what it is one letter at a time or the entire ";
  std::cout<<"word. Each time you guess a word wrong you are getting close to killing the hangman. You have 6 guesses to guess the ";
  std::cout<<"word correctly. Welcome to the Game of Doom or Die or Hangman"<<std::endl;
  std::cout<<"If you want to guess the entire word, enter guess " << std::endl;
  
  
  std::string wordSoFar = "";
  std::string hangmanWord = getWord(argv);

  int wordSize = hangmanWord.size();
    for(int i = 0; i < wordSize; ++i){
      wordSoFar += "_";
    }

  int lives = 6;
  int score = 0;
  std::string letter;
  std::vector<char> guesses;
  bool check;
  bool alreadyFound; 
  std::vector<char>::iterator itr;
  std::string whitespace;
  do{

    check = false;
    alreadyFound = false;
    printMan(lives);
    std::cout<<"Current Lives: " << lives <<std::endl;   
    std::cout<<"Current Word: "; //<< wordSoFar <<std::endl;
    for(int i = 0; i < wordSize; ++i){
      std::cout << wordSoFar.at(i) << " ";
    }
    std::cout<<std::endl<<std::endl;
     
    do{
      std::cout<<"Enter a Letter: ";
      std::cin >> letter;
      getline(std::cin, whitespace);
      if(letter == "guess"){
        std::string guess;
        std::cout<<"Enter your guess: ";
        std::cin>>guess;
        if(guess == hangmanWord){
          goto win;
        }
        else{
          goto lose;
        }
      }      
    }while(letter.size() != 1 || !whiteSpaceCheck(whitespace));

    itr = find(guesses.begin(), guesses.end(), tolower(letter.at(0)));
    if (itr == guesses.end()) {
      alreadyFound = true;
    }

  if(alreadyFound){
    guesses.push_back(tolower(letter.at(0)));
    for(int i =0; i<wordSize; ++i){
        if (tolower(hangmanWord.at(i)) == tolower(letter.at(0))){
          score++;
          wordSoFar.at(i) = hangmanWord.at(i);
          check = true;
        }
      }
      if(check){
          std::cout<<"Your guess was right!" << std::endl;
        }
        else if (!check){
          std::cout<<"Your guess was wrong!" <<std::endl;
          lives--;
        }
        
  }
    

  }while (lives != 0 && score != wordSize);
  printMan(lives);

  if(lives == 0){
    lose:
    std::cout<<"You lose" <<std::endl;
  }
  else if(score == wordSize){
    win:
     std::cout<<"You win"<<std::endl;
  }
  
  std::cout<<"The word was: " << hangmanWord;
}


std::string getWord(std::string argv){
  std::mt19937 randomGenerator;
  int seed1 = std::chrono::system_clock::now().time_since_epoch().count();
  randomGenerator.seed(seed1);

  std::ifstream myfile(argv);
  std::vector<std::string> words;
  std::string hangmanWord;

   while (myfile >> hangmanWord) {
     words.push_back(hangmanWord);
   }

   int randomNumber;
   do{
    randomNumber = randomGenerator() % words.size();
    hangmanWord = words.at(randomNumber);
    hangmanWord = filterOut(hangmanWord);
   } while (hangmanWord.size() == 0);

   myfile.close();

   return hangmanWord;
}