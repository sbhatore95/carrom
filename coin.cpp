class Coin: public Circle, public Object{
    public:
    static const float rad = ratio*1.59f;
    

    Coin(int i){
        stat=1;
        id = i;
        if(i==0){
            x = 0;
            y = 0;
        }
        else if(i==1){
            x = -rad*pow(3, 0.5);
            y = rad;
        }
        else if(i==2){
            x = rad*pow(3, 0.5);
            y = rad;
        }
        else if(i==3){
            x = 0;
            y = -2*rad;
        }
        else if(i==4){
            x = -2*rad*pow(3, 0.5);
            y=0;
        }
        else if(i==5){
            x = 2*rad*pow(3, 0.5);
            y=0;
        }
        else if(i==6){
            x = rad*pow(3, 0.5);
            y = 3*rad;
        }
        else if(i==7){
            x = -rad*pow(3, 0.5);
            y = 3*rad;
        }
        else if(i==8){
            x = rad*pow(3, 0.5);
            y = -3*rad;
        }
        else if(i==9){
            x = -rad*pow(3, 0.5);
            y = -3*rad;
        }
        else if(i==10){
            x = 0;
            y = 2*rad;
        }
        else if(i==11){
            x = rad*pow(3, 0.5);
            y = -rad;
        }
        else if(i==12){
            x = -rad*pow(3, 0.5);
            y = -rad;
        }
        else if(i==13){
            x = 0;
            y = 4*rad;
        }
        else if(i==14){
            x = 0;
            y = -4*rad;
        }
        else if(i==15){
            x = -2*rad*pow(3, 0.5);
            y = 2*rad;
        }
        else if(i==16){
            x = -2*rad*pow(3, 0.5);
            y = -2*rad;
        }
        else if(i==17){
            x = 2*rad*pow(3, 0.5);
            y = 2*rad;
        }
        else{
            x = 2*rad*pow(3, 0.5);
            y = -2*rad;
        }

        velx = 0;
        vely = 0;
        m=1;        
    }

    void draw(){
        glPushMatrix();
        
        if(id == 0){            
            glColor3f(255.0f/256.0f,68.0f/256.0f,170.0f/256.0f);
        }
        else if(id>9)
            glColor3f(1, 1, 1);
        else
            glColor3f(0, 0, 0);
        
        glTranslatef(x, y, 0);
        drawBall(rad);
        glPopMatrix();
    }
    int newpos(){
        if(id<=9 && id>0){
            setpos(-2.5,-1.1+ ratio*5*(obj_count(0)-1));
            return -5;
        }
        else if(id>9){
            setpos(2.5,-1.1+ ratio*5*(obj_count(9)-1));
            return 10;
        }
        else{
            setpos(2.5,-1.1 - ratio*5);
            return 50;
        }
        
    }
};
