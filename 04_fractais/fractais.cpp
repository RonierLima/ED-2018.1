#include <lib/pen.h>


void gelo(Pen& p, int lado){

    if(lado < 1)
        return;

    int ang = 360;

    for (int i = 0; i < 5; ++i) {
        p.walk(lado);
        gelo(p, lado * 0.38);
        p.walk(-lado);
        p.right(ang/5);
    }

}

void circulo(Pen& p, double lado){

    if(lado < 1)
        return;

    for (int i = 0; i < 6; ++i) {
        p.setThickness(1);
        p.circle(lado);
        p.setThickness(0);
        p.walk(lado);
        circulo(p, lado/3);
        p.setThickness(0);
        p.walk(-lado);
        p.right(360/6);
    }
}

void trigo(Pen& p, int lado){

    if(lado < 1)
        return;

    int ang = 35;

    for(int i = 0; i < 4; i++){

        p.walk(lado);
        p.right(ang);
        trigo(p, lado/3);
        p.left(ang*2);
        trigo(p, lado/3);
        p.right(ang);
    }
    p.walk(-lado*4);
}

void arvore(Pen& p, float lado, int dec){

    if(lado < 1)
        return;

    p.setThickness(1);

    if(dec > 5){

        p.setThickness(dec);
        dec-=2;
        p.setColor(165,42,42);

    }else if(dec>3 && dec<=5){
        p.setThickness(dec);
        p.setColor(34,139,34);
        dec-=2;
    }

    int alea = 10 - rand()%15;
    int ang = 35 + alea;

    p.walk(lado);
    p.right(ang);
    arvore(p, lado*0.70, dec);
    p.left(ang*2);
    arvore(p, lado*0.70, dec);
    p.right(ang);
    p.walk(-lado );
    p.setThickness(0);
}


void fractal_gelo(){

    Pen p(1000, 700);
    p.setXY(500, 350);
    p.setHeading(270);
    p.setSpeed(0);
    p.setThickness(1);
    p.setBackColor(255, 255, 255);
    p.setColor(135,206,250);

    gelo(p, 200);

    p.wait();
}

void fractal_circulo(){

    Pen p(1000, 700);
    p.setXY(500, 350);
    p.setHeading(270);
    p.setSpeed(100);
    p.setThickness(2);

    circulo(p, 200);

    p.wait();
}

void fractal_trigo(){
    Pen p(1000, 700);
    p.setXY(500, 690);
    p.setHeading(90);
    p.setSpeed(100);
    p.setThickness(1);
    p.setColor(232, 181, 85);

    trigo(p, 100);

    p.wait();
}

void fractal_arvore(){

    Pen p(1000, 700);
    p.setXY(500, 690);
    p.setHeading(90);
    p.setSpeed(100);

    arvore(p, 200, 12);
    p.wait();
}


void teste(Pen &p, int lado){

    p.circle(lado);
    while (1) {

        for (int i = 0; i < 360; ++i){
            p.walk(lado);
            p.walk(-lado);
            p.right(1);
        }
        p.setColor(rand()%256, rand()%256, rand()%256);
        p.circle(lado);
    }
}

void fractal_teste(){

    Pen p(1000, 700);
    p.setXY(500, 500);
    p.setHeading(90);
    p.setSpeed(500);
    p.setThickness(2);

    teste(p, 100);

    p.wait();
}

int main(){

    fractal_gelo();
//    fractal_circulo();
//    fractal_trigo();
    fractal_arvore();
//    fractal_teste();


    return 0;
}

