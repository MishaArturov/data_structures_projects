#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int charToInt(char value){
    if(value == 'a'||value == 'A' ||value == '1'){
        return 0;
    } else if(value == 'b'||value == 'B' ||value == '2'){
        return 1;
    } else if(value == 'c'||value == 'C' ||value == '3'){
        return 2;}
    else{return -1;}}
char intToChar(int value){
    
    if(value==1){
        return 'x';
    } else if(value == 2){
        return 'o';
    } else{
        return ' ';}}
void printMap(int grid[3][3]){
    
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
    cout<<endl;
}

int main()
{
    int grid[3][3];
    char input[3];
    int first=-1;
    int second=-1;
    // grid[1][2] = 1;
    // grid[0][1] = 2;
    printMap(grid);
    // for(int i=0;i<3;i++){
    //     for(int c=0;c<3;c++){
    //         cout<<grid[i][c]<<", ";

    //     }
    // }
    while(true){
        cin >> input;
        if(input[0]>input[1]){
            first = charToInt(input[1]);
            second = charToInt(input[0]);
        }else{
            first = charToInt(input[0]);
            second = charToInt(input[1]);
        }
        if(first!=-1&&second!=-1){
            grid[first][second] = 1;
            printMap(grid);
        }
        else{
            cout<<"Not correct coordinates"<<endl;
        }
    }
    return 0;
}
