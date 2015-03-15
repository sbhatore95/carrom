//file inclusions
#include "global.h"
#include "line.cpp"
#include "circle.cpp"
#include "board.cpp"
#include "object.cpp"
#include "striker.cpp"
#include "coin.cpp"
#include "bar.cpp"
#include "score.cpp"
#include "dirnarrow.cpp"

// Function Declarations
void drawScene();
void update(int value);
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
float gl2mou(float a, float b);
void fun(int x, int y);

// Global Variables
float box_len = 3.2f;
float tri_x = 0.0f;
float tri_y = 0.0f;
float theta = 0.0f; 


int flag = 0, mark = 0, mem =0;
time_t start, past=51;

Striker striker;
Coin coin[19] = {Coin(0), Coin(1), Coin(2), Coin(3), Coin(4), Coin(5), Coin(6), Coin(7), Coin(8), Coin(9), Coin(10), Coin(11), Coin(12), Coin(13), Coin(14), Coin(15), Coin(16), Coin(17), Coin(18) };
DirnArrow line;
Bar bar;
Score score;
char str[5] = {'\0'};

int points = 51;

int main(int argc, char **argv) {

    

    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    int w = glutGet(GLUT_SCREEN_WIDTH);
    int h = glutGet(GLUT_SCREEN_HEIGHT);
    int windowWidth = w * 2 / 3;
    int windowHeight = h * 2 / 3;

    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition((w - windowWidth) / 2, (h - windowHeight) / 2);

    glutCreateWindow("Carrom");  // Setup the window
    initRendering();

    // Register callbacks
    glutDisplayFunc(drawScene);
    glutIdleFunc(drawScene);
    glutKeyboardFunc(handleKeypress1);
    
    glutSpecialFunc(handleKeypress2);
    glutMotionFunc(fun);
    glutMouseFunc(handleMouseclick);
    glutReshapeFunc(handleResize);
    glutTimerFunc(10, update, 0);

    glutMainLoop();
    return 0;
}

// Function to draw objects on the screen
void drawScene() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glClearColor(100.0f/255.0f, 33.0f/255.0f, 16.0f/255.0f, 1);
    glutPostRedisplay();

    // Draw Board
    Board board;

    //Energy Bar draw
    bar.draw(bar.currv);    
    
     //Draw Score Board
    score = Score();
    drawString(GLUT_BITMAP_HELVETICA_18, str, 2.65, 1.7, 0);

    //striker
    glPushMatrix();
    striker.setpos(striker.x, striker.y);
    striker.draw();
    glPopMatrix();

    //carrommen
    for(int i=0;i<19;i++){
        glPushMatrix();
        coin[i].setpos(coin[i].x, coin[i].y);        
        coin[i].draw();
        glPopMatrix();
    }

    //Direction Arrow;
    glPushMatrix();    
    glTranslatef(striker.x, striker.y , 0);
    glRotatef(line.angle, 0, 0, 1);
    glTranslatef(0.3, 0, 0);
    if(flag == 0){
        glLineWidth(2);
        line.drawLine(0.4);
        glLineWidth(1.f);
    }
    glPopMatrix();
    
    //Draw Score Board
    
    drawString(GLUT_BITMAP_HELVETICA_18, str, 2.65, 1.7, 0); 
    
    glPopMatrix();
    glutSwapBuffers();
}

// Function to handle all calculations in the scene
// updated evry 10 milliseconds
void update(int value) {

    if(!mem){
        start = time(0);
        mem = 1;
    }
    time_t now = time(0);
    if(51-(now- start) < past){

        points-=1;
        cout << points << endl;
        past = 51-(now-start);
        if(points <0){
            str[0] = '-';
            str[1] = -points/100 +'0';
            str[2] = -points/10%10 + '0';
            str[3] = -points%10 + '0';
            str[4] = '\0';
        }
        else{
            str[0] = points/100 +'0';
            str[1] = points/10%10 + '0';
            str[2] = points%10 + '0';
            str[3] = '\0';
        }

    }
    
    
    float dist[100];
    for(int i=0;i<19;i++)
        dist[i] = pow(striker.x-coin[i].x,2) + pow(striker.y-coin[i].y,2);

    //distance b/w striker and each coin
    float cdis = pow(striker.rad+coin[0].rad, 2);    
    
    //Setting striker back to position
    int feed = 1;
    for(int i=0;i<19;i++){
        if(coin[i].velx == 0 && coin[i].vely == 0)
            continue;
        else{
            feed = 0;
            break;
        }
    }
    if(feed && striker.velx == 0 && striker.vely ==0 && mark == -1){
        if(obj_count(0) == 9 && coin[0].stat == 0){
            flag = 114;
        }
        striker.setpos(striker.memx, -ratio*25.26f);
        striker.setvel(0, 0);
        mark = 0;

    }

    // space
    if(flag==32){ 
        if(mark != -1){
            striker.memx = striker.x;
            striker.setvel((0.02*bar.currv) * cos(DEG2RAD(line.angle)), (0.02*bar.currv) * sin(DEG2RAD(line.angle)));
        }
        mark = -1;
        flag = 1;
    }
    //Left Arrow key
    if(flag==1001){ 
        striker.moveleft();
        flag=0;
    }
    //Right Arrow Key
    if(flag == 1002){ 
        striker.moveright();
        flag = 0;
    }
    // 'c' clockwise
    if(flag == 99){ 
        line.clockrot();
        flag = 0;
    }
    //Reset 'r'
    if(flag == 114){ 
        for(int i=0;i<19;i++){
            coin[i] = Coin(i);
            striker = Striker();
            points = 51;
        }
    }
    // 'a' couter-clockwise
    if(flag == 97){ 
        line.anticlockwise();
        flag = 0;
    }
    // Up arrow Key
    if(flag == 1003){         
        bar.up();
        flag = 0;
    }
    // Down Arrow Key
    if(flag == 1004){
        bar.down();        
        flag = 0;
    }
    
    //Looping for coin skip at high speeds
    for(int k=0;k<1000;k++){
        //Collision
        for(int i=0;i<19;i++){
            if(dist[i] <= cdis && ((striker.x - coin[i].x)*(striker.velx - coin[i].velx) + (striker.y - coin[i].y)*(striker.vely-coin[i].vely) < 0)){
                collision(i);
                //break;                   
            }            
        }
        // Handle striker collisions with box
        if(striker.x + striker.rad > box_len/2 || striker.x - striker.rad < -box_len/2)
            striker.velx *= -1;
        if(striker.y + striker.rad > box_len/2 || striker.y - striker.rad < -box_len/2)
            striker.vely *= -1;

        //Friction and speed increment
        striker.friction();
        striker.x += striker.velx/1000;
        striker.y += striker.vely/1000;     
    }

    //looping for coin skip problem at high velocities
    for(int k=0;k<1000;k++){

        //Collision
        for(int i=0;i<19;i++){
            for(int j=i+1;j<19;j++){
                if(pow(coin[j].x-coin[i].x,2) + pow(coin[j].y-coin[i].y,2) <= 4*coin[i].rad*coin[i].rad &&
                ((coin[j].x - coin[i].x)*(coin[j].velx - coin[i].velx) + (coin[j].y - coin[i].y)*(coin[j].vely-coin[i].vely) < 0)){
                    collision_coin(i, j);
                }
            }
        }
        // Handle ball collisions with box
        for(int i=0;i<19;i++){
            if(coin[i].x + coin[i].rad > box_len/2 || coin[i].x - coin[i].rad < -box_len/2)
                coin[i].velx *= -1;
            if(coin[i].y + coin[i].rad > box_len/2 || coin[i].y - coin[i].rad < -box_len/2)
                coin[i].vely *= -1; 
        }

        //Friction and velocity increase
        for(int i=0;i<19;i++){
            coin[i].friction();
            coin[i].x += coin[i].velx/1000;
            coin[i].y += coin[i].vely/1000;
        } 
    }
    //Coin in the hole condition
    for(int i=0;i<19;i++){
        if(coin[i].checkin()&&coin[i].stat){
            coin[i].stat = 0;
            points+=coin[i].newpos();
            coin[i].setvel(0, 0);
        }        
    }
    //Striker in the hole
    if(striker.checkin()){
        points-=5;
        striker.setvel(0,0);
    }

    glutTimerFunc(10, update, 0);
}


void collision(int i){
    
    
    float dis = sqrt(pow(striker.x-coin[i].x,2) + pow(striker.y - coin[i].y,2));
    float px, py;
   
    px = (striker.x-coin[i].x)/dis;
    py = (striker.y - coin[i].y)/dis;

    float u1 = striker.velx*px + striker.vely*py;
    float u2 = coin[i].velx*px + coin[i].vely*py;
    float c1 = striker.velx*py - striker.vely*px;
    float c2 = coin[i].velx*py - coin[i].vely*px;
    float v1 = (2* coin[i].m * u2 + u1 * (striker.m - coin[i].m))/(striker.m + coin[i].m);
    float v2 = (2* striker.m * u1 + u2 * (coin[i].m - striker.m))/(striker.m + coin[i].m);
    striker.setvel(v1*px + c1*py, v1*py-c1*px);
    coin[i].setvel(v2*px + c2*py, v2*py-c2*px);    
}



void collision_coin(int i, int j){
    
    float dis = sqrt(pow(coin[j].x-coin[i].x,2) + pow(coin[j].y - coin[i].y,2));
    float px, py;
    
    px = (coin[j].x-coin[i].x)/dis;
    py = (coin[j].y - coin[i].y)/dis;       
    
    float u1 = coin[j].velx*px + coin[j].vely*py;
    float u2 = coin[i].velx*px + coin[i].vely*py;
    float c1 = coin[j].velx*py - coin[j].vely*px;
    float c2 = coin[i].velx*py - coin[i].vely*px;
    float v1 = (2* coin[i].m * u2 + u1 * (coin[j].m - coin[i].m))/(coin[j].m + coin[i].m);
    float v2 = (2* coin[j].m * u1 + u2 * (coin[i].m - coin[j].m))/(coin[j].m + coin[i].m);
    coin[j].setvel(v1*px + c1*py, v1*py-c1*px);
    coin[i].setvel(v2*px + c2*py, v2*py-c2*px);   
}


int obj_count(int j){
    int count=0;
    for(int i=1 + j;i<=9+j;i++){
        if(coin[i].stat == 0)
            count++;
    }
    return count;
}

// Initializing some openGL 3D rendering options
void initRendering() {

    glEnable(GL_DEPTH_TEST);        // Enable objects to be drawn ahead/behind one another
    glEnable(GL_COLOR_MATERIAL);    // Enable coloring
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);   // Setting a background color
}

// Function called when the window is resized
void handleResize(int w, int h) {

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void handleKeypress1(unsigned char key, int x, int y) {

    if (key == 27) {
        exit(0);     // escape key is pressed
    }    

    flag=key;

}

void handleKeypress2(int key, int x, int y) {
    if(key == GLUT_KEY_LEFT)
        flag = 1001;
    else if(key ==  GLUT_KEY_RIGHT)
        flag = 1002;
    else if(key == GLUT_KEY_UP)
        flag = 1003;
    else if(key == GLUT_KEY_DOWN)
        flag = 1004;    
}

void handleMouseclick(int button, int state, int x, int y) {

    if (state == GLUT_DOWN)
    {

        if (button == GLUT_LEFT_BUTTON){
            cout << "centre" << x << " " << y << endl;
            float y1 = float(-y+371)*(1.6/285.0f);
            float x1 = float(x-685)*(1.6/285.0f);

            float angle = (180.0f/(PI))*atan((striker.y - y1)/(striker.x - x1));
            cout << angle;
            if(angle <0)
                angle= 180 + angle;
            if(y1<striker.y){
                if(x1<striker.x)
                    angle = 180;
                else
                    angle = 0;
            }

            line.setangle(angle);
        }
        else if (button == GLUT_RIGHT_BUTTON)
            theta -= 15;
    }
}

void fun(int x, int y){
    

        float temp = float(x-685)*(1.6/285.0f);
        if(temp > -ratio*21.91f && temp < ratio*21.91f)
            striker.x = temp;
        flag = 0;
}

void drawString (void * font, char *s, float x, float y, float z){
     unsigned int i;
     glRasterPos3f(x, y, z);

     for (i = 0; i < strlen (s); i++)
          glutBitmapCharacter (font, s[i]);
}