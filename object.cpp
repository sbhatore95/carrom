class Object{
    public:
    float x;
    float y;
    float velx;
    float vely;
    float vslope;
    float m;
    int id;
    int stat;
    float mu;

    Object(){
        mu = 0.001;
    }
     

    void setpos(float a, float b){
        x = a;
        y = b;
    }
    void setvel(float a, float b){
        velx = a;
        vely = b;
    }
    int checkin(){
        if(sqrt(x*x+y*y) >= 1.6*sqrt(2)-ratio*4.45){
            
            return 1;
        }
        else
            return 0;
    }
    float getlocslope(Object a, Object b){
        if(fabs(a.x - b.x) > 0.01)
            return (a.y - b.y)/(a.x - b.x);
        else{
            if(a.x - b.x < 0)
                return -999.0f;
            else
                return 999.0f;
        }
    }
    float getvelslope(Object a){
        return a.vely/a.velx;
    }
    void friction(){
     if(velx >0){
            velx-=(m*mu*fabs(velx/sqrt(pow(velx,2)+pow(vely, 2))))/1000;
            if(velx < 0)
                velx = 0;
        }
        else if(velx<0){
            
            velx+=(m*mu*fabs(velx/sqrt(pow(velx,2)+pow(vely, 2))))/1000;
            
            if(velx>0)
                velx = 0;
        }
        if(vely >0){
            
            vely-=(m*mu*fabs(vely/sqrt(pow(velx,2)+pow(vely, 2))))/1000;
            if(vely <0)
                vely = 0;
        }
        else if(vely <0){
            
            vely+=(m*mu*fabs(vely/sqrt(pow(velx,2)+pow(vely, 2))))/1000;
            
            if(vely >0)
                vely = 0;
        }
    }
};