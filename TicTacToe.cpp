//Misha Arturov TicTacToe 10/12/25
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int charToInt(char value,bool number=false){//converts abc and 123 to 012 used to as indexies for grid
    if(number){ //converts only the numbers
        if(value == '1'){
            return 0;
        } else if(value == '2'){
            return 1;
        } else if(value == '3'){
            return 2;
        }
        else{return -1;}
    }
    else{ //converts only letters
        if(value == 'a'||value == 'A'){
            return 0;
        } else if(value == 'b'||value == 'B'){
            return 1;
        } else if(value == 'c'||value == 'C'){
            return 2;
        }
        else{return -1;}
    }
}
char intToChar(int value){ //1=x,2=o
    
    if(value==1){
        return 'x';
    } else if(value == 2){
        return 'o';
    } else{
        return ' ';}}
void printMap(int grid[3][3]){ //prints the grid
    
    cout<<"  1 2 3 "<<endl<<"a ";
    for(int i=0; i<3;i++){
        char letter = intToChar(grid[i][0]);
        cout<<letter<<" ";}
    cout<<endl<<"b ";
    for(int i=0; i<3;i++){
        char letter = intToChar(grid[i][1]);
        cout<<letter<<" ";}
    cout<<endl<<"c ";
    for(int i=0; i<3;i++){
        char letter = intToChar(grid[i][2]);
        cout<<letter<<" ";}
    cout<<endl;}

int wincheck(int grid[3][3], int x1, int y1, int x2, int y2, int x3, int y3){//didn't want to learn tuples in c++ therefor 6-7 parameters
    if(grid[x1][y1]==grid[x2][y2]&&grid[x1][y1]==grid[x3][y3]){ //compares 3 coordinates outputs the value
        return grid[x1][y1];}
    else{return 0 ;}}
int allchecks(int grid[3][3]){//checks the 8 possible winning situations
    if(wincheck(grid,0,0,0,1,0,2)!=0){return wincheck(grid,0,0,0,1,0,2);}
    if(wincheck(grid,2,0,2,1,2,2)!=0){return wincheck(grid,2,0,2,1,2,2);}
    if(wincheck(grid,1,0,1,1,1,2)!=0){return wincheck(grid,1,0,1,1,1,2);}
    if(wincheck(grid,0,0,1,0,2,0)!=0){return wincheck(grid,0,0,1,0,2,0);}
    if(wincheck(grid,0,2,1,2,2,2)!=0){return wincheck(grid,0,2,1,2,2,2);}
    if(wincheck(grid,0,1,1,1,2,1)!=0){return wincheck(grid,0,1,1,1,2,1);}
    if(wincheck(grid,0,0,1,1,2,2)!=0){return wincheck(grid,0,0,1,1,2,2);}
    if(wincheck(grid,2,0,1,1,0,2)!=0){return wincheck(grid,2,0,1,1,0,2);}
    return 0; //returns 0 if no wins
}
int main()
{
    bool play=true;
    int score[2];

    while(play){
        bool notWOn = true;
        int move = 0;
        int grid[3][3]; //2d list!
        memset(grid, 0, sizeof(grid)); // snippet from chat that resets the grid with 0s
        char input[3];//input 3 characters just in case
        int first=-1; 
        int second=-1;
        cout<<"x="<<score[0]<<", o="<<score[1]<<endl; //prints score
        printMap(grid); 
        while(notWOn){
            int winner = allchecks(grid);
            if(winner>0){ //runs if winner exists
                cout<<intToChar(winner)<<" wins"<<endl;
                score[winner-1]++;
                cout<<"x="<<score[0]<<", o="<<score[1]<<endl;
                notWOn = false;
            }
            else if(move==9){ //runs if tie
                cout<<"Tie!"<<endl;
                cout<<"x="<<score[0]<<", o="<<score[1]<<endl;
                notWOn = false;
            }
            else{
                cout<<intToChar(move%2+1)<<"'s turn"<<endl;
                cin >> input;
                if(input[0]>input[1]){//i really wanted to be able to take in coordinates both as number,letter and letter,number
                    first = charToInt(input[1],true);
                    second = charToInt(input[0]);
                }else{
                    first = charToInt(input[0],true);
                    second = charToInt(input[1]);
                }
                if(first!=-1&&second!=-1){//checks that chartoint worked correctly meaning input actually had real coords
                    if(grid[first][second]==0){//if cell is empty
                        grid[first][second] = move%2+1; //replce the 0 in 2d list with either 1 for x and 2 for o
                        move++;
                        printMap(grid);
                    }
                    else{
                        cout<<"Cell already taken"<<endl;
                    }
                }
                else{
                    cout<<"Not correct coordinates"<<endl;
                }
            }
        }
        cout<<endl<<"Play again> (y/n)"<<endl;
        char yes = 'a';
        cin>>yes;
        yes = tolower(yes);
        if(yes != 'y'){play = false;}
    }
    cout<<"thanks for playing tic tac toe";
    return 0;
}
//the lion does not concern himself with good coding practices
