#include <string>
#include <iostream>
#pragma once
#include <apmatrix.h>

//Decklaring class
class maze{

public:
    //Constructor and Deconstructor
    maze();
    ~maze();

    //Some getters
    int getSTY();
    int getSTX();
    int getheight();
    int getwidth();

    //Some setters
    void setwidth(const int &w);
    void setheight(const int &h);
    void setdisplaytime(const float &dt);

    //Functions for everything, explained in maze.cpp and maze2.cpp
    void definemaze(const apmatrix <char> &maze1, apmatrix <int> &mazenum);
    void drawmaze(const apmatrix <char> &mazesym);
    void drawmazesym(const apmatrix <char> &mazesym);
    void drawpath(const int &x, const int &y);
    void undrawpath(const int &x, const int &y);
    int countpath(const apmatrix <int> &mazenum, apmatrix <bool> &used, int &edgecount, const int &x, const int &y);

    //Recursive function
    void DFS(const apmatrix <int> &mazenum, apmatrix <char> &mazesym, apmatrix <bool> &used, const int &startpointx, const int &startpointy);


private:
    //Initializing variables
    int height = 0;
    int width = 0;

    int pixwidth = 0;
    int pixheight = 0;

    float displaytime = 0.5;

    int startpointx = 0;
    int startpointy = 0;

};
