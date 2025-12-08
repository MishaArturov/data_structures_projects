#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
void removeChar(char* string, int index){
  int length =  strlen(string);
  if(index>=length || index<0) return;
  for(int x=index; x<length; x++){ //moves all characters after the index down one
    string[x] = string[x+1];}
}
int main(){
  char input[81]; //the input string
  int indexies[81]; //the indexies of all characters that will be removed
  int indexcount = 0;
  char punctuation[]= R"(!"#$%&'( )*+,-./:;<=>?@[\]^_`{|}~)"; // took this line from chatpt cause i aint typing allat
  cin.getline(input,81);
  for(int c=0;c<strlen(input);c++){ //runs through the whole input string to check if each character is a punctuation
    for(int p=0; p<strlen(punctuation);p++){
      if(input[c]==punctuation[p]){ 
        // cout<<'('<<input[c]<<')'<<endl;
        indexies[indexcount]=c; //stores the indexies of punctuation in a list
        indexcount++;
        break;
      }
    }
  }
  for(int i=indexcount-1;i>=0;i--){ //runs through the index list backwards so that when input string moves down the other indexies still work
    removeChar(input, indexies[i]); //removes character
  }
  int length = strlen(input);
  char reverse[length+1]; //creates the reverse string
  for(int x=0; x<length;x++){
    reverse[x] = input[length-1-x];//reverses the string
  }
  reverse[length]='\0'; //makes the last character the null terminatr
  // cout<<reverse<<endl<<input<<endl;
  for(int i=0; input[i] != '\0'; i++){ //makes the input lowercase
    input[i] = tolower(input[i]);
  }
  for(int i=0; reverse[i] != '\0'; i++){ //makes the reverse lowercase
    reverse[i] = tolower(reverse[i]);
  }
  // cout<<reverse<<endl<<input<<endl;
  if(strcmp(reverse, input) == 0){ //compares the reverse with the input
    cout<<"Is a palindrome"<<endl;
  }
  else{
    cout<<"Not a palindrome"<<endl;
  }
  return 0;
}
