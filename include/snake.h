#pragma once



class snake{
    public:

    void create (){
        for (int i=0;i<len;i++){
            pos[i]=1+i;
            pos[i+lenmax]=1;
        }
    }

    int afficher (){
        return pos[1];
    }

    bool isVivant(){
        return vivant;
    }

    void check_vivant(){
        int xlast=pos[len-1];
        int ylast=pos[len-1+lenmax];
        if (xlast==0 || xlast==nx-1||ylast==0||ylast==ny-1){
            vivant=false;
        }
        else {
            for (int i=0;i<len-1;i++){
                if (xlast==pos[i] && ylast==pos[lenmax+i]){
                    vivant=false;
                }
            }

        }
    }

    bool eat(int* fdpos){
        int xlast=pos[len-1];
        int ylast=pos[len-1+lenmax];
        return (xlast==fdpos[0] && ylast==fdpos[1]);
    }

    /*décide si la direction peut aller*/
    bool check_direction(char key){
        if (key=='z'&& dxdy[0]==0 && dxdy[1]==1){
            return false;
        }
        else if (key=='q'&& dxdy[0]==1 && dxdy[1]==0){
            return false;
        }
        else if (key=='s'&& dxdy[0]==0 && dxdy[1]==-1){
            return false;
        }
        else if (key=='d'&& dxdy[0]==-1 && dxdy[1]==0){
            return false;
        }   
        else{
            return true;
        }
    }



    void deplacement(char key){
        bool dir=check_direction(key);
        if (dir==false){
            if (dxdy[0]==0 && dxdy[1]==1){
                key='s';
            }
            else if (dxdy[0]==1 && dxdy[1]==0){
                key='d';
            }
            else if (dxdy[0]==0 && dxdy[1]==-1){
                key='z';
            }
            else if (dxdy[0]==-1 && dxdy[1]==0){
                key='q';
            }
        }
        if (key=='s'){
            dxdy[0]=0;
            dxdy[1]=1;
        }
        else if (key=='d'){
            dxdy[0]=1;
            dxdy[1]=0;
        }
        else if (key=='z'){
            dxdy[0]=0;
            dxdy[1]=-1;
        }
        else if (key=='q'){
            dxdy[0]=-1;
            dxdy[1]=0;
        }

    }

    void mvt(char key,bool eat){

        if (eat){
            len++;
            pos[len-1]=pos[len-2]+dxdy[0];
            pos[len+lenmax-1]=pos[len+lenmax-2]+dxdy[1];
        }
        else{
            for (int i=0;i<len-1;i++){
                pos[i]=pos[i+1];
                pos[i+lenmax]=pos[lenmax+i+1];
            }
            pos[len-1]=pos[len-2]+dxdy[0];
            pos[len+lenmax-1]=pos[len+lenmax-2]+dxdy[1];
            
        }
        

    }

    int getlen(){
        return len;
    }

    int* getpos(){
        return pos;
    }



    private:
    const static int lenmax=200;
    const static int nx = 50;
    const static int ny = 25;
    bool vivant=true;
    int len=5;
    int dxdy[2]={0,1};
    int pos[2*lenmax];


};