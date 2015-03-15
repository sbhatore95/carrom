class Striker: public Circle, public Object{
    
    public:
    static const float rad = ratio*2.065f;
    int turn;
    float memx;
    
    
    public:

    Striker(){
        id=-1;
        x = 0;
        y = -ratio*25.26f;
        velx = 0;
        vely = 0;
        m = 2;
        turn = 0;
        stat=1;
        memx = 0;        
    }
    
    void draw(){
        glPushMatrix();
        glTranslatef(x, y, 0);
        glColor3f(0,0,1);
        drawBall(ratio*2.065f);
        glPopMatrix();
    }
    void moveright(){
        if(x < ratio*21.91f)
            x+=ratio*0.4f;
    }
    void moveleft(){
        if(x >-ratio*21.91f){
            x -= ratio*0.4f;
        }
    }    

};