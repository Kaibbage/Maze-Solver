//Kai Sundararaj
//ICS4U
//June 12, 2021
//Mrs. Cullum
//This program takes in the maze and solves it through DFS, shows the first found way to solve maze going if possible North, East, South, then West in that order
//It will ask the user the dimensions of the maze and act accordingly
//The program will also display a display of the maze using colours and shapes on allegro, the maze will keep displaying until the maze is solved or
//the maze is determined to be unsolvable

#include <iostream>
#include <apmatrix.h>
#include <fstream>
#include <string>
#include "maze.h"

using namespace std;


//Function to read file, I had a hard time getting it to work in maze.cpp so I just put it here
void readfile(ifstream &inputFile, apmatrix <char> &mazesym, const int &width, const int &height);


int main()
{
    //Opening file
    ifstream inputFile("maze1.txt");

    //Declaring class maze1
    maze maze1;

    //Declaring variables for dimensions of maze
    int w1;
    int h1;
    float dt1;

    //Asking user what dimensions
    cout << "What are the dimensions of your maze?" << endl;
    cout << "Width:";
    cin >> w1;
    cout << "Height:";
    cin >> h1;
    cout << "How many seconds per step would you like:";
    cin >> dt1;

    //Setting the dimensions
    maze1.setwidth(w1);
    maze1.setheight(h1);
    maze1.setdisplaytime(dt1);


    //Declaring variables for the maze values
    apmatrix <char> mazesym(maze1.getwidth(), maze1.getheight());
    apmatrix <int> mazenum(maze1.getwidth(), maze1.getheight());
    apmatrix <bool> used(maze1.getwidth(), maze1.getheight(), false);

    //Reading the file
    readfile(inputFile, mazesym, maze1.getwidth(), maze1.getheight());

    //Defining the matrix of symbols as numbers so that 'S', 'G', and '.' are the same
    maze1.definemaze(mazesym, mazenum);

    //Running recursive function to display and solve maze
    maze1.DFS(mazenum, mazesym, used, maze1.getSTX(), maze1.getSTY());

    return 0;
}

void readfile(ifstream &inputFile, apmatrix <char> &mazesym, const int &width, const int &height){
    int x = 0;
    int y = 0;

    //Checking if file is open
    if (!inputFile.is_open()){
        cout << "error" << endl;
    }

    //Reading file
    while(y < height){
        x = 0;
        while(x < width){
            inputFile >> mazesym[x][y];
            x++;
        }
        y++;
    }
    //Closing file
    inputFile.close();
}


