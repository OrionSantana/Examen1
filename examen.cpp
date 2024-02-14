#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Rectangulo{
private:
    int ancho;
    int altura;
public:
    int esquinaX;
    int esquinaY;

    Rectangulo();
    Rectangulo(int x,int y);
    Rectangulo(int x,int y,int w, int h);

    int getAncho();
    void setAncho(int w);
    int getAltura();
    void setAltura(int h);
    int getArea();
    void intersecta(Rectangulo rect);
};

int main(){

    Rectangulo v1;
    v1.esquinaX = 3;
    v1.esquinaY = 3;
    v1.setAncho(7);
    v1.setAltura(7);

    Rectangulo v2 = {5,6};
    v2.setAncho(6);
    v2.setAltura(10);

    Rectangulo v3 = {10,15,10,5};

    cout<<endl<<"El rectangulo 1 tiene un area de: "<<v1.getArea()<<endl;
    cout<<endl<<"El rectangulo 2 tiene un area de: "<<v2.getArea()<<endl;
    cout<<endl<<"El rectangulo 3 tiene un area de: "<<v3.getArea()<<endl;
    
    cout<<endl<<"Para los rectangulos 1 y 2:";
    v1.intersecta(v2);

    cout<<endl<<"Para los rectangulos 1 y 3:";
    v1.intersecta(v3);

    cout<<endl<<"Para los rectangulos 2 y 3:";
    v2.intersecta(v3);
    cout<<endl;

return 0;
}
Rectangulo::Rectangulo(){
    ancho = 0;
    altura = 0;
    esquinaX = 0;
    esquinaY = 0;
}
Rectangulo::Rectangulo(int x,int y){
    ancho = 0;
    altura = 0;
    esquinaX = x;
    esquinaY = y;
}
Rectangulo::Rectangulo(int x,int y,int w, int h){
    if (w<0){
        ancho = 0;
    }else{
        ancho = w;
    }
    if (h<0){
        altura = 0;
    }else{
        altura = h;
    }
    esquinaX = x;
    esquinaY = y;
}

int Rectangulo::getAncho(){
    return ancho;
}
void Rectangulo::setAncho(int w){
    if (w<0){
        ancho = 0;
    }else{
        ancho = w;
    }
}
int Rectangulo::getAltura(){
    return altura;
}
void Rectangulo::setAltura(int h){
    if (h<0){
        altura = 0;
    }else{
        altura = h;
    }
}
int Rectangulo::getArea(){
    return altura*ancho;
}
void Rectangulo::intersecta(Rectangulo rect){
    float inter = 0,interX = 0, interY = 0;
    if (esquinaX<=rect.esquinaX + rect.getAncho() && esquinaX + ancho >= rect.esquinaX){
        interX = 1;
        if (esquinaY<=rect.esquinaY + rect.getAltura() && esquinaY + altura >= rect.esquinaY){
            inter = 1;
            interY = 1;
        }
    }
    if (inter==1){
        cout<<endl<<"Los rectangulos intersectan"<<endl;
    }else{
        cout<<endl<<"Los rectangulos no intersectan"<<endl;
    }
    if (interX == 1){
    cout<<". intersectan en X"<<endl;
    }
    if (interY == 1){
    cout<<". intersectan en Y"<<endl;
    }
}
