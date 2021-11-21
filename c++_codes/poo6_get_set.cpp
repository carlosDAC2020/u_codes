# include <iostream>
# include <stdlib.h>
using namespace std;

class punto{
    private: // atributos
        int x,y;
    public: // metodos
        punto(); // constructor
        void set_punto(int, int); // set para asiganr valores a los atributos
        int get_punto_x(); // getters para mostrar los valores de los atributos
        int get_punto_y();
};

punto::punto(){    
}

// establecemos valores a los atributos
void punto::set_punto(int _x, int _y){
    x = _x;
    y = _y;
}

int punto::get_punto_x(){
    return x;
}

int punto::get_punto_y(){
    return y;
}

int main(){
    punto punto1;

    punto1.set_punto(20,10);
    cout<<" valor de x: "<<punto1.get_punto_x()<<endl;
    cout<<" valor de y: "<<punto1.get_punto_y()<<endl;

    system("pause");
    return 0;
}