#include "maze.h"
#include <iostream>
#include <fstream>
#include <string>
#include <apmatrix.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

//Function to see if the path is a dead end in obstacles or in used paths
int maze::countpath(const apmatrix <int> &mazenum, apmatrix <bool> &used, int &edgecount, const int &x, const int &y){

    if(mazenum[x][y] == 3){
        if(0 <= y-1){
            if(mazenum[x][y-1] == 3){
                edgecount++;            }
        }

        if(width > x+1){
            if(mazenum[x+1][y] == 3){
                edgecount++;            }
        }

        if(height > y+1){
            if(mazenum[x][y+1] == 3){
                edgecount++;            }
        }

        if(0 <= x-1){
            if(mazenum[x-1][y] == 3){
                edgecount++;

            }
        }
    }


    int counter = 0;

    if(mazenum[x][y] == 3){
        if(0 <= y-1){
            if(mazenum[x][y-1] == 3 && used[x][y] == false){
                counter++;
            }
        }

        if(width > x+1){
            if(mazenum[x+1][y] == 3 && used[x][y] == false){
                counter++;
            }
        }

        if(height > y+1){
            if(mazenum[x][y+1] == 3 && used[x][y] == false){
                counter++;
            }
        }

        if(0 <= x-1){
            if(mazenum[x-1][y] == 3 && used[x][y] == false){
                counter++;

            }
        }
    }
    return counter;
}

//Recursive function to find path
void maze::DFS(const apmatrix <int> &mazenum, apmatrix <char> &mazesym, apmatrix <bool> &used, const int &x, const int &y){

    //Things to do at the start
    if(mazesym[x][y] == 'S'){
        //Drawing the mazes in allegro and console
        drawmaze(mazesym);
        drawmazesym(mazesym);
        //Telling the user the points where the coordinates are referring to
        cout << "Coordinates of path being checked. Top left is (0, 0). Bottom right is ("<< width - 1 << "," << height - 1 << ")." << endl;
    }

    //Pausing to watch the display
    al_rest(displaytime);

    //Showing the user which coordinate the path is headinng too
    cout << "(" << x << "," << y << ")"<< endl;

    //Drawing the path
    if(used[x][y] == false){
        drawpath(x, y);
    }

    //Letting the program know if that tile has been used
    used[x][y] = true;

    //Changing '.' to '+' when the path passes through that tile
    if(mazesym[x][y] == '.'){
        mazesym[x][y] = '+';
    }



    //Ending the path if the path is found
    if(mazesym[x][y] == 'G'){
        cout << endl << "The maze has been completed" << endl;
        drawmazesym(mazesym);
        al_rest(5);

        exit(0);
    }


    //Variable to count if it as intersection
    int pcount = 0;

    //Recursion, checking and then if possible moving North, East, South, West, in that order
    if(mazenum[x][y] == 3){
        if(0 <= y-1){
            if(mazenum[x][y-1] == 3 && used[x][y-1] == false){
                pcount++;
                DFS(mazenum, mazesym, used, x, y-1);
            }
        }

        if(width > x+1){
            if(mazenum[x+1][y] == 3 && used[x+1][y] == false){
                pcount++;
                if(pcount > 1){
                    cout << "(" << x << "," << y << ")"<< endl;
                }
                DFS(mazenum, mazesym, used, x+1, y);
            }
        }

        if(height > y+1){
            if(mazenum[x][y+1] == 3 && used[x][y+1] == false){
                pcount++;
                if(pcount > 1){
                    cout << "(" << x << "," << y << ")"<< endl;
                }
                DFS(mazenum, mazesym, used, x, y+1);
            }
        }

        if(0 <= x-1){
            if(mazenum[x-1][y] == 3 && used[x-1][y] == false){
                pcount++;
                if(pcount > 1){
                    cout << "(" << x << "," << y << ")"<< endl;
                }
                DFS(mazenum, mazesym, used, x-1, y);

            }
        }
    }






    //If the tile makes it here, erasing the path going there and changing '+' back to '.'
    if(used[x][y] == true){
        undrawpath(x, y);
        if(mazesym[x][y] == '+'){
            mazesym[x][y] = '.';
        }
    }


    //Variable for how many edges are surrounding the tile
    int edgecount = 0;

    //If it is in a dead end, showing the path before it leaves
    if(countpath(mazenum, used, edgecount, x, y) == 0){
        if(edgecount == 1){
            drawpath(x, y);
            al_rest(displaytime);
            undrawpath(x, y);
        }
    }

    //If the original function makes it here after all the recursion, ending and then saying the maze cannot be solved
    if(mazesym[x][y] == 'S'){
        cout << "(" << x << "," << y << ")"<< endl;
        cout << "There was no solution to this maze" << endl;
        al_rest(5);
    }



}

