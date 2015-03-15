#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <ctime>
#include <string.h>

class Board: public Line, public Circle{
    protected:
    static const float box_len = 4.0f;

    public:
    

    Board(){
        drawBoundary();
        drawMiddle();
        drawArrows();
        drawPositionCircle();
        drawPositionFillCircle();
        drawThinLines();
        drawThickLines();
        drawCornerCircle();
        make_pattern_triangle();
        
    }
    void drawBox(float len) {
   
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBegin(GL_QUADS);
        glVertex2f(-len/2 , -len/2);
        glVertex2f(len / 2, -len / 2);
        glVertex2f(len / 2, len / 2);
        glVertex2f(-len / 2, len / 2);
        glEnd();    
    }

    void drawBoundary(){
        glTranslatef(0.0f, 0.0f, -5.0f);
        glColor3f(0 ,0 ,0);
        drawBox(box_len);
        glColor3f(243.0f/255.0f, 198.0f/255.0f, 156.0f/255.0f);
        drawBox(box_len*0.8);
    }

    void drawMiddle(){
        glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.0f);
        DrawCircle(ratio*8.5f);       
        
        glColor3f(207.0f/256.0f, 23.0f/256.0f, 21.0f/256.0f);
        drawBall(ratio*1.59f);
        glPopMatrix();
    }

    void drawPositionFillCircle(){
        glPushMatrix();
        glTranslatef(ratio*21.91f , -1.6+ratio*11.74f ,0);
        glColor3f(207.0f/256.0f, 23.0f/256.0f, 21.0f/256.0f);
        drawBall(ratio*1.225f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-ratio*21.91f , -1.6+ratio*11.74f ,0);
        glColor3f(207.0f/256.0f, 23.0f/256.0f, 21.0f/256.0f);
        drawBall(ratio*1.225f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(ratio*21.91f , 1.6-ratio*11.74f ,0);
        glColor3f(207.0f/256.0f, 23.0f/256.0f, 21.0f/256.0f);
        drawBall(ratio*1.225f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-ratio*21.91f , 1.6-ratio*11.74f ,0);
        glColor3f(207.0f/256.0f, 23.0f/256.0f, 21.0f/256.0f);
        drawBall(ratio*1.225f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef( 1.6-ratio*11.74f, -ratio*21.91f ,0);
        glColor3f(207.0f/256.0f, 23.0f/256.0f, 21.0f/256.0f);
        drawBall(ratio*1.225f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef( 1.6-ratio*11.74f, ratio*21.91f ,0);
        glColor3f(207.0f/256.0f, 23.0f/256.0f, 21.0f/256.0f);
        drawBall(ratio*1.225f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.6+ratio*11.74f,ratio*21.91f ,0);
        glColor3f(207.0f/256.0f, 23.0f/256.0f, 21.0f/256.0f);
        drawBall(ratio*1.225f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef( -1.6+ratio*11.74f,-ratio*21.91f  ,0);
        glColor3f(207.0f/256.0f, 23.0f/256.0f, 21.0f/256.0f);
        drawBall(ratio*1.225f);
        glPopMatrix();

    }

    void drawPositionCircle(){
        glPushMatrix();
        glTranslatef(ratio*21.91f , -1.6+ratio*11.74f ,0);
        glColor3f(0,0,0);
        DrawCircle(ratio*1.59f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-ratio*21.91f , -1.6+ratio*11.74f ,0);
        glColor3f(0,0,0);
        DrawCircle(ratio*1.59f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(ratio*21.91f , 1.6-ratio*11.74f ,0);
        glColor3f(0,0,0);
        DrawCircle(ratio*1.59f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-ratio*21.91f , 1.6-ratio*11.74f ,0);
        glColor3f(0,0,0);
        DrawCircle(ratio*1.59f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef( 1.6-ratio*11.74f, -ratio*21.91f ,0);
        glColor3f(0,0,0);
        DrawCircle(ratio*1.59f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef( 1.6-ratio*11.74f, ratio*21.91f ,0);
        glColor3f(0,0,0);
        DrawCircle(ratio*1.59f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.6+ratio*11.74f,ratio*21.91f ,0);
        glColor3f(0,0,0);
        DrawCircle(ratio*1.59f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef( -1.6+ratio*11.74f,-ratio*21.91f  ,0);
        glColor3f(0,0,0);
        DrawCircle(ratio*1.59f);
        glPopMatrix();

    }

    void drawCornerCircle(){
        glPushMatrix();
        glTranslatef(1.6-ratio*2.225f + 0.025, 1.6-ratio*2.225f + 0.025,0);
        glColor3f(0,0,0);
        drawBall(ratio*2.225f);
        glTranslatef((ratio*2.225f)/1.414, (ratio*2.225f)/1.414,0);
        drawBall(0.005f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(1.6-ratio*2.225f + 0.025, -1.6+ratio*2.225f - 0.025,0);
        glColor3f(0,0,0);
        drawBall(ratio*2.225f);
        glTranslatef((ratio*2.225f)/1.414, -(ratio*2.225f)/1.414,0);
        drawBall(0.005f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.6+ratio*2.225f - 0.025, -1.6+ratio*2.225f - 0.025,0);
        glColor3f(0,0,0);
        drawBall(ratio*2.225f);
        glTranslatef(-(ratio*2.225f)/1.414, -(ratio*2.225f)/1.414,0);
        drawBall(0.005f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.6+ratio*2.225f - 0.025, 1.6-ratio*2.225f + 0.025,0);
        glColor3f(0,0,0);
        drawBall(ratio*2.225f);
        glTranslatef(-(ratio*2.225f)/1.414, (ratio*2.225f)/1.414,0);
        drawBall(0.005f);
        glPopMatrix();
    }

    void drawArrows(){
        glPushMatrix();
        glTranslatef( 1.6 - ratio*(22.8f/1.414f), 1.6 - ratio*(22.8f/1.414f), 0);
        glRotatef(45, 0, 0, 1);
        glColor3f(0,0,0);
        drawLine(ratio*26.7 );
        
        glTranslatef(ratio*13.35, 0, 0);
        
        
        glBegin(GL_TRIANGLES);
        glVertex2f(-ratio*0.7,-ratio*0.7);
        glVertex2f(-ratio*0.7,ratio*0.7);
        glVertex2f(0, 0);
        
        glEnd();

        
        //drawLine(ratio*2);
        glPopMatrix();
                //arrow
        glPushMatrix();
        glTranslatef( 1.6 - ratio*(32.975f/1.414f), 1.6 - ratio*(32.975f/1.414f), 0);
        drawSector(ratio*3.175, 1);
        

        glPopMatrix();

        glPushMatrix();
        glTranslatef( -1.6 + ratio*(22.8f/1.414f), 1.6 - ratio*(22.8f/1.414f), 0);
        glRotatef(315, 0, 0, 1);
        glColor3f(0,0,0);
        drawLine(ratio*26.7 );
        glRotatef(180, 0, 0, 1);
        glTranslatef(ratio*13.35, 0, 0);
        
        
        glBegin(GL_TRIANGLES);
        glVertex2f(-ratio*0.7,-ratio*0.7);
        glVertex2f(-ratio*0.7,ratio*0.7);
        glVertex2f(0, 0);
        
        glEnd();
        glPopMatrix();
                //arrow
        glPushMatrix();
        glTranslatef( -1.6 + ratio*(32.975f/1.414f), 1.6 - ratio*(32.975f/1.414f), 0);
        drawSector(ratio*3.175, 2);
        glPopMatrix();

        glPushMatrix();
        glTranslatef( -1.6 + ratio*(22.8f/1.414f), -1.6 + ratio*(22.8f/1.414f), 0);
        glRotatef(45, 0, 0, 1);
        glColor3f(0,0,0);
        drawLine(ratio*26.7 );
        glRotatef(180, 0, 0, 1);
        glTranslatef(ratio*13.35, 0, 0);
        
        
        glBegin(GL_TRIANGLES);
        glVertex2f(-ratio*0.7,-ratio*0.7);
        glVertex2f(-ratio*0.7,ratio*0.7);
        glVertex2f(0, 0);
        
        glEnd();
        glPopMatrix();
                //arrow
        glPushMatrix();
        glTranslatef( -1.6 + ratio*(32.975f/1.414f), -1.6 + ratio*(32.975f/1.414f), 0);
        drawSector(ratio*3.175, 3);
        glPopMatrix();

        glPushMatrix();
        glTranslatef( 1.6 - ratio*(22.8f/1.414f), -1.6 + ratio*(22.8f/1.414f), 0);
        glRotatef(315, 0, 0, 1);
        glColor3f(0,0,0);
        drawLine(ratio*26.7);
        glTranslatef(ratio*13.35, 0, 0);
        
        
        glBegin(GL_TRIANGLES);
        glVertex2f(-ratio*0.7,-ratio*0.7);
        glVertex2f(-ratio*0.7,ratio*0.7);
        glVertex2f(0, 0);
        
        glEnd();
        glPopMatrix();
                //arrow
        glPushMatrix();
        glTranslatef( 1.6 - ratio*(32.975f/1.414f), -1.6 + ratio*(32.975f/1.414f), 0);
        drawSector(ratio*3.175, 4);
        glPopMatrix();
    }

    void drawThinLines(){
        glPushMatrix();
        glTranslatef(0,-1.6 + ratio*13.33f, 0.0f);
        drawLine(ratio*43.82f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,1.6 - ratio*13.33f, 0.0f);
        drawLine(ratio*43.82f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.6 + ratio*13.33f, 0, 0.0f);
        glRotatef(90, 0, 0, 1);
        drawLine(ratio*43.82f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(1.6 - ratio*13.33f, 0, 0.0f);
        glRotatef(90, 0, 0, 1);
        drawLine(ratio*43.82f);
        glPopMatrix();
    }

    void drawThickLines(){
        
        glPushMatrix();
        glTranslatef(0,-1.6 + ratio*10.15f, 0.0f);
        drawWideLine(ratio*43.82f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,1.6 - ratio*10.15f, 0.0f);
        drawWideLine(ratio*43.82f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.6 + ratio*10.15f, 0, 0.0f);
        glRotatef(90, 0, 0, 1);
        drawWideLine(ratio*43.82f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(1.6 - ratio*10.15f, 0, 0.0f);
        glRotatef(90, 0, 0, 1);
        drawWideLine(ratio*43.82f);
        glPopMatrix();
    }
    void make_pattern_triangle(){

        glPushMatrix();

        float ball_rad = 2*ratio;
        for(int i=0;i<8;i++)

        {



            glRotatef(((float)360/(float)8)*i,0,0,1);
            glPushMatrix();
            glBegin(GL_TRIANGLES);

            if(i==1||i==2||i==5||i==6)
                glColor3f(1,0,0);
            else
                glColor3f(0,0,0);


                glVertex3f(-ball_rad,0, 0.0f);
            glVertex3f(0,0, 0.0f);
            //glColor3f(0, 0.0, 0.0);
            glVertex3f(0,0.389, 0.0f);
            glEnd();
            glPopMatrix();
            glPushMatrix();
            glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.89f, 0.70f);
            glVertex3f(ball_rad,0, 0.0f);
            glColor3f(1, 01, 01);
            glVertex3f(0,0, 0.0f);
            glColor3f(01, 01, 01);
            glVertex3f(0,0.389, 0.0f);
            glEnd();
            glPopMatrix();
        }


        glPopMatrix();

        glPushMatrix();
        
        
        for(int i=1;i<=8;i++)

        {
         glRotatef(((float)360/(float)8)*i,0,0,1);
           
            glPushMatrix();
            glTranslatef(ball_rad,ball_rad,0);
            glRotatef(180,0,0,1);
            glBegin(GL_TRIANGLES);

            //glColor3f(1,1,0);
            glVertex3f(-0.045,0,0);
            glVertex3f(0.045, 0,0);
            //glColor3f(0, 0.0, 0.0);
            glVertex3f(0,0.0656, 0.0f);
            glEnd();
            glPopMatrix();
        }
        glColor3f(1, 1, 1);
        drawBall(0.1);
        glColor3f(1, 0, 0);
        drawBall(ratio*1.59);

        glPopMatrix();

    }

    
};