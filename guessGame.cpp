#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
  srand(time(NULL));
  char play = 'y';
  while(play=='y'){
  int secretNum = rand()%100+1;
  int Guess = -1;
  //cout<<"the number is "<<secretNum<<endl;
  while(Guess!=secretNum){
    cout<<"Enter a number 1-100 ";
    cin>>Guess;
    if(Guess<secretNum){
      cout<<"too low"<<endl;
    }
    else if(Guess>secretNum){
      cout<<"too high"<<endl;
    }
  }
  cout<<"Congrats! you guessed the number"<<endl<<"Do you want to play again? (y/n) "<<endl;
  cin>>play;
  }
  cout<<"Thanks for playing the Guessing game";
}
