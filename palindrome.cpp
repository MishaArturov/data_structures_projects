
#include <iostream>
#include <cstring>
using namespace std;
void removeChar(char* string, int index){
  int length =  strlen(string);
  if(index>=length || index<0) return;
  for(int x=index; x<length; x++){
    string[x] = string[x+1];}
}
int main(){
  char input[80];
  int indexies[80];
  int indexcount = 0;
  char punctuation[]= R"(!"#$%&'( )*+,-./:;<=>?@[\]^_`{|}~)"; // took tis line from chatpt cause i aint typing allat
  getline(cin,input);
  for(int c=0;c<strlen(input);c++){
    for(int p=0; p<strlen(punctuation);p++){
      if(input[c]==punctuation[p]){
	cout<<'('<<input[c]<<')'<<endl;
	indexies[indexcount]=c;
	indexcount++;
	break;
      }
    }
  }
  cout<< input<<endl<<indexies[0]<<endl;
  return 0;
}
