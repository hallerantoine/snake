#pragma once

class background{
    public:

    void create(){
        for (int i=0; i<nx;i++){
            for (int j=0; j<ny; j++){
                if (i==0 || i==nx-1 || j==0 || j==ny-1){
                    grille[i+j*nx]=1;
                }
                else{
                    grille[i+j*nx]=0;
                }
            }
            
        }
    }

    int* getbg(){
        return grille;
    }

    void addsnake(int len, int* snk){
        for (int i=0;i<len;i++){
            int x= snk[i];
            int y= snk[lenmax+i];
            grille[x+y*nx]=1;
        }
        
    }

    void removesnake(int len, int* snk){
        for (int i=0;i<len;i++){
            int x= snk[i];
            int y= snk[lenmax+i];
            grille[x+y*nx]=0;
        }
        
    }


    void addfood(int* fd){
        int x = fd[0];
        int y = fd[1];
        grille[x+y*nx]=2;
    }


    private:
    const static int ny = 25;
    const static int nx = 50;
    const static int lenmax=200;
    const static int taille=nx*ny;
    int grille[taille];


};