//line class
class Line{
    public:
    
    
    void drawLine(float len){
        glEnable (GL_LINE_SMOOTH);
        glEnable (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
        
        glBegin(GL_LINES);

        glVertex2f(-len/2 , 0);
        glVertex2f(len/2 , 0);
        glEnd();
        
    }

    void drawWideLine(float len){
        glEnable (GL_LINE_SMOOTH);
        glEnable (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
        glLineWidth(3.0);
        drawLine(len);
        glLineWidth(1.f);
    }    
};