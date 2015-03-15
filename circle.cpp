class Circle{
    public:

    void DrawCircle(float r)
    {
        
        glLineWidth(1.5);
        glBegin(GL_LINE_STRIP);
        
        for(int i=0 ; i<360 ; i++) {
            glVertex2f(r * cos(DEG2RAD(i)), r * sin(DEG2RAD(i)));
        }
        glEnd();
        glLineWidth(1.f);
        
    }

    void drawBall(float rad) {        
       
        glBegin(GL_TRIANGLE_FAN);
        for(int i=0 ; i<360 ; i++) {
            glVertex2f(rad * cos(DEG2RAD(i)), rad * sin(DEG2RAD(i)));
        }
        glEnd();
        glColor3f(0, 0, 0);
        DrawCircle(rad);
    }

    void drawSector(float r, int no){
        int var;
        if(no==1)
            var = 0;
        else if(no==2)
            var = 90;
        else if(no==3)
            var = 180;
        else
            var = 270;
        
        
        glBegin(GL_LINE_STRIP);
        for(int i=var;i<15+var;i++){
            glVertex2f(r * cos(DEG2RAD(i)), r * sin(DEG2RAD(i)));
        }
        glEnd();


        glBegin(GL_LINE_STRIP);
        for(int i=75+var ; i<360+var ; i+=1) {
            
            glVertex2f(r * cos(DEG2RAD(i)), r * sin(DEG2RAD(i)));
        }
        glEnd();
        glLineWidth(1.f);

    }

    
};
