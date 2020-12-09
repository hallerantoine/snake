
void createFood(int* bg, int food[2], const int& nx, const int& ny);
bool eatFood(int food[2], int* snake);

class food{
    public:
    void create(int* snk,int len){
        bool check=true;
        while (check==true){
            fd[0]=rand()%(nx-2) + 2;
            fd[1]=rand()%(ny-2) + 2;
            /*vérifier que la nourriture aparait pas sur le serpent*/
            check=false;
        }
    }

    int* get(){
        return fd;
    }

    private:
    const static int ny = 25;
    const static int nx = 50;
    int fd[2]={1,1};

};
