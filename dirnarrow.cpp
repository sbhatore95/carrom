class DirnArrow: public Line{
    public:
    float angle;
    DirnArrow(){
        angle = 90;
    }
    void clockrot(){
        if(angle > 0)
            angle -= 2;
    }
    void anticlockwise(){
        if(angle < 180)
            angle+=2;
    }
    void setangle(float the){
        angle = the;
    }    
};