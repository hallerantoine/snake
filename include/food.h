#pragma once



class food{
    public:
    void create(int* snk,int len){
        bool check=true;
        while (check==true){
            check=false;
            fd[0]=rand()%(nx-3) + 2;
            fd[1]=rand()%(ny-3) + 2;
            /*vérifier que la nourriture aparait pas sur le serpent*/
            for (int i=0;i<len;i++){
                if (snk[i]==fd[0] && snk[lenmax+i]==fd[1]){
                    check=true;
                }
            }
        }
    }

    void reset(){
        fd[0]=1;
        fd[1]=1;
    }

    int* get(){
        return fd;
    }

    private:
    const static int ny = 25;
    const static int nx = 50;
    const static int lenmax=200;
    int fd[2]={6,6};

};
