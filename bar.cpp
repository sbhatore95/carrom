class Bar: public Line{
    public:
    int currv;
    Bar(){
        currv = 1;
    }
    
    void draw(int value){
        
        glPushMatrix();
        glTranslatef(3.3, 0, 0);
        glRotatef(90, 0, 0, 1);
        glColor3f(0, 1, 0);
        drawLine(2.8);
        glTranslatef(0, -0.3, 0);
        drawLine(2.8);
        glTranslatef(-1.4, 0.15, 0);
        glRotatef(-90, 0, 0, 1);
        drawLine(0.3);
        glTranslatef(0, 2.8, 0);
        drawLine(0.3);

        
        
        for(int i=0;i<8;i++){
            
            drawWideLine(0.3);
            glTranslatef(0, -0.4, 0);
        }
        glColor3f(196.0f/256.0f, 247.0f/256.0f, 56.0f/256.0f);
        for(int i=0;i<100;i++){
            glTranslatef(0, 0.004, 0);
            drawWideLine(0.3);
        }

        if(value>=2){
            glColor3f(210.0f/256.0f, 250.0f/256.0f, 26.0f/256.0f);
            for(int i=0;i<100;i++){
                glTranslatef(0, 0.004, 0);
                drawWideLine(0.3);
            }
        }
        if(value>=3){
            glColor3f(220.0f/256.0f, 253.0f/256.0f, 0.0f/256.0f);
            for(int i=0;i<100;i++){
                glTranslatef(0, 0.004, 0);
                drawWideLine(0.3);
            }
        }
        if(value >= 4){
            
            glColor3f(255.0f/256.0f, 225.0f/256.0f, 3.0f/256.0f);
            for(int i=0;i<100;i++){
                glTranslatef(0, 0.004, 0);
                drawWideLine(0.3);
            }
        }
        if(value >= 5){
            glColor3f(252.0f/256.0f, 177.0f/256.0f, 0);
            for(int i=0;i<100;i++){
                glTranslatef(0, 0.004, 0);
                drawWideLine(0.3);
            }
        }
        if(value >= 6){
            glColor3f(254.0f/256.0f, 108.0f/256.0f, 23.0f/256.0f);
            for(int i=0;i<100;i++){
                glTranslatef(0, 0.004, 0);
                drawWideLine(0.3);
            }
        }
        if(value >= 7){
            glColor3f(255.0f/256.0f, 64.0f/256.0f, 36.0f/256.0f);
            for(int i=0;i<100;i++){
                glTranslatef(0, 0.004, 0);
                drawWideLine(0.3);
            }
        }
        if(value == 8){
            glColor3f(255.0f/256.0f, 31.0f/256.0f, 43.0f/256.0f);
            for(int i=0;i<100;i++){
                glTranslatef(0, 0.004, 0);
                drawWideLine(0.3);
            }
        }


        glPopMatrix();

    }
    void down(){
        if(currv > 1){
            currv--;            
        }
    }
    void up(){
        if(currv < 8){
            currv++;            
        }
    }
};