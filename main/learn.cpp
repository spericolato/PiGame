#include <iostream>
#include <conio.h>
#include "../includes/maps.h"

using namespace std;

enum Direction{Top=122,Down=115,Left=113,Right=100,Exit=27};
bool gameOver = false;
const int height = 20;
const int width = 40;
int keys = 0;
int pY = height/2;
int pX = width/2;
int levels = 0;

char map[height][width];

void draw(){
    system("cls");
    cout<<keys<<"/4"<<endl;
    cout<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(i==pY && j==pX){
                cout<<'P';
            }else{
                cout<<map[i][j];
            }
        }
        cout<<endl;
    }
};

void move(){
    switch (_getch())
    {
    case Top:
        if(map[pY-1][pX] == '=' || map[pY-1][pX] == '|' && keys != 4){
            pY = pY;
        }else if(map[pY-1][pX] != '#'){
            pY--;
        }
        break;
    case Down:
        if(map[pY+1][pX] == '=' || map[pY+1][pX] == '|' && keys != 4){
            pY = pY;
        }else if(map[pY+1][pX] != '#'){
            pY++;
        }
        break;
    case Left:
        if(map[pY][pX-1] == '=' || map[pY][pX-1] == '|' && keys != 4){
            pX = pX;
        }else if(map[pY][pX-1] != '#'){
            pX--;
        }
        break;
    case Right:
        if(map[pY][pX+1] == '=' || map[pY][pX+1] == '|' && keys != 4){
            pY = pY;
        }else if(map[pY][pX+1] != '#'){
            pX++;
        }
        break;
    case Exit:
        gameOver = true;
        break;
    
    default:
        break;
    }
}

void  logic(){

    setMap(levels,map);

    if(map[pY][pX] == 'F'){
        map[pY][pX] = ' ';
        keys++;
    }else if(map[pY][pX] == '*'){
        levels++;
        pX = width/2;
        pY = height/2;
    }
}

int main(){
    while (!gameOver)
    {
            logic();
            draw();
            move();
    }
    
}

