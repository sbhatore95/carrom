// Global Variables
/*extern float box_len = 3.2f;

extern int flag = -1, mark = 0, mem =0;
extern time_t start, past=51;
extern char str[5] = {'\0'};
extern float mu = 0.001;
extern int points = 51;
extern float theta = 0.0f;
*/
#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <ctime>
#include <string.h>
using namespace std;

#define PI 3.141592653589
#define DEG2RAD(deg) (deg * PI / 180)


//board vs reference ratio. Basicallly 3.2 of opengl is 74 cm of actual board
#define ratio 3.2f/74.0f 

void drawString (void * font, char *s, float x, float y, float z);
void drawBox(float len);

void drawTriangle();
void initRendering();
void handleResize(int w, int h);
void handleKeypress1(unsigned char key, int x, int y);
void handleKeypress2(int key, int x, int y);
void handleMouseclick(int button, int state, int x, int y);
void keypress(unsigned char key, int x, int y);

void collision(int i);
void collision_coin(int i, int j);

int obj_count(int j);
void output(int x, int y, float r, float g, float b, int font, char *string);
/*
extern float box_len = 3.2f;
extern float tri_x = 0.0f;
extern float tri_y = 0.0f;
extern float theta = 0.0f; 


extern int flag = -1, mark = 0, mem =0;
extern time_t start, past=51;

extern Striker striker;
extern Coin coin[19] = {Coin(0), Coin(1), Coin(2), Coin(3), Coin(4), Coin(5), Coin(6), Coin(7), Coin(8), Coin(9), Coin(10), Coin(11), Coin(12), Coin(13), Coin(14), Coin(15), Coin(16), Coin(17), Coin(18) };
extern DirnArrow line;
extern Bar bar;
extern Score score;
extern char str[5] = {'\0'};

extern int points = 51;


*/
