// 1. No global variables. (Global constants are all right.)
// 2. No strings. Not ever. (You can use cstrings/character arrays, and the cstring and cctype libraries are okay. In fact, I recommend using strcmp and strlen in your projects.)
// 3. You should include <iostream>, not stdio. (This applies more to C programmers.) Also, use "new" and "delete" instead of "malloc" and "free".
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
  srand(time(NULL)); //generates random seed
  char play = 'y'; //character that confims player wants to play again, yes on start
  while(play=='y'){ //first loop that makes the game run multiple times
    int countGuess=1;
    int secretNum = rand()%100+1; //secre number player guesses
    int Guess = -1; //the integer that is used to store the guesses
  //cout<<"the number is "<<secretNum<<endl;
    while(Guess!=secretNum){ //second loop for guesses
    cout<<"Enter a number 1-100 ";
    cin>>Guess; //takes players number
    if(Guess<secretNum){ //checs if number too low
      cout<<"too low"<<endl;
      countGuess++;
    }
    else if(Guess>secretNum){  //checks if number too igh
      cout<<"too high"<<endl;
      countGuess++;
    }
  }
    cout<<"Congrats! you guessed the number in "<<countGuess<<" guesses. Do you want to play again? (y/n) "<<endl; //runs when 2nd loop ends and asks to play again
  cin>>play;
  }
  cout<<"Thanks for playing the Guessing game"; //runs when first loop ends
}
