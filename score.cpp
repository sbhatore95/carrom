class Score: public Line{
    public:
    int len;
    Score(){
        len = 2;
        drawBoundary();
    }
    void drawBoundary(){

        glPushMatrix();
        glTranslatef(2.5, 1.5, 0);
        glColor3f(1, 1, 1);
       /* drawLine(0.5);
        glTranslatef(0, 0.5, 0);
        drawLine(0.5);
        glRotatef(90, 0, 0, 1);
        glTranslatef(-0.25 ,0.25, 0);
        drawLine(0.5);
        glTranslatef(0, -0.5, 0);
        drawLine(0.5);
        */glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBegin(GL_QUADS);
        glVertex2f(0,0.5);
        glVertex2f(0,0);
        glVertex2f(0.5, 0);
        glVertex2f(0.5,0.5);
        glEnd();

        glPopMatrix();    
    }
};