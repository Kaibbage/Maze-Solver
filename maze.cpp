#include "maze.h"
#include <iostream>
#include <fstream>
#include <string>
#include <apmatrix.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

//Constructor
maze::maze(){

}

//Deconstructor
maze::~maze(){

}

//Some getters
int maze:: getSTY(){
    return startpointy;
}

int maze:: getSTX(){
    return startpointx;
}
int maze::getheight(){
    return height;
}

int maze::getwidth(){
    return width;
}

//Some setters, setwidth and setheight also set the display size
void maze::setwidth(const int &w){
    width = w;
    pixwidth = 60 * w;
}
void maze::setheight(const int &h){
    height = h;
    pixheight = 60 * h;
}

void maze::setdisplaytime(const float &dt){
    displaytime = dt;
}

//Changing maze symbols to integer values to make 'S', 'G', and '.' the same
void maze::definemaze(const apmatrix <char> &mazesym, apmatrix <int> &mazenum){
    int x = 0;
    int y = 0;

    //Changing the values accordingly
     while(y < height){
        x = 0;
        while(x < width){
            if (mazesym[x][y] == 'S'){
                mazenum[x][y] = 3;
                //Taking note of start point
                startpointx = x;
                startpointy = y;
            }
            else if(mazesym[x][y] == 'G'){
                mazenum[x][y] = 3;
            }
            else if(mazesym[x][y] == '.'){
                mazenum[x][y] = 3;
            }
            else if(mazesym[x][y] == '#'){
                mazenum[x][y] = 9;
            }
        x++;
        }

        y++;
    }
}

//Initializing allegro colours
static ALLEGRO_COLOR red;
static ALLEGRO_COLOR green;
static ALLEGRO_COLOR blue;
static ALLEGRO_COLOR turqoise;
static ALLEGRO_COLOR white;

//Drawing the maze in allegro
void maze::drawmaze(const apmatrix <char> &mazesym){
    int x1 = 0;
    int y1 = 0;

    al_init();
    al_init_primitives_addon();

    //Declaring the colours
    red = al_map_rgb(255,0,0);
    green = al_map_rgb(0,255,0);
    blue = al_map_rgb(0,0,255);
    turqoise = al_map_rgb(0, 200, 200);
    white = al_map_rgb(255, 255, 255);

    //Creating display
    ALLEGRO_DISPLAY *display = al_create_display(pixwidth, pixheight);
    al_clear_to_color(white);

    al_flip_display();

    //Drawing display
    while(y1 < height){
        x1 = 0;
        while(x1 < width){
            if(mazesym[x1][y1] == '#'){
                al_draw_filled_rectangle((pixwidth/width) * x1, (pixheight/height) *y1, (pixwidth/width) * (x1 + 1), (pixheight/height) * (y1 + 1), blue);
                al_flip_display();
            }
            else if(mazesym[x1][y1] == 'S'){
                al_draw_filled_rectangle((pixwidth/width) * x1, (pixheight/height) *y1, (pixwidth/width) * (x1 + 1), (pixheight/height) * (y1 + 1), red);
                al_flip_display();
            }
            else if(mazesym[x1][y1] == 'G'){
                al_draw_filled_rectangle((pixwidth/width) * x1, (pixheight/height) *y1, (pixwidth/width) * (x1 + 1), (pixheight/height) * (y1 + 1), green);
                al_flip_display();
            }
            x1++;
        }
        y1++;
    }

}

//Printing the maze in console
void maze::drawmazesym(const apmatrix <char> &mazesym){
    int x = 0;
    int y = 0;

    while(y < height){
        x = 0;
        while(x < width){
            cout << mazesym[x][y];
            x++;
        }
        cout << endl;

        y++;
    }
    cout << endl;

}




//Drawing the path turqoise in circles
void maze::drawpath(const int &x, const int &y){
    al_draw_filled_circle(pixwidth/width * x + pixwidth/width/2, pixheight/height * y + pixheight/height / 2, ((pixwidth + pixheight)/(width + height)) / 3, turqoise);
    al_flip_display();

}

//Erasing the path by going over it in white
void maze::undrawpath(const int &x, const int &y){
    al_draw_filled_circle(pixwidth/width * x + pixwidth/width/2, pixheight/height * y + pixheight/height / 2, ((pixwidth + pixheight)/(width + height)) / 3, white);
    al_flip_display();

}



