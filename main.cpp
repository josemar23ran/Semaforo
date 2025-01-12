#include <iostream>
#include <thread>
#include <windows.h>
#include "graphics.h"
#include <chrono>

using namespace std;

char imagenes[4][25]={  "imagenes\\1.jpg",//Led apagado
                        "imagenes\\2.jpg",//Led azul
                        "imagenes\\3.jpg", //Led Rojo
                        "imagenes\\4.jpg"}; //Led rosa

class multimedia
{
public:
    void ventana(void)
    {
        initwindow(241,81,"Ventana Nueva",300,150);  //Inicialización de la ventana
        setbkcolor(15);cleardevice();
    }

    void imp_imagen(char *ima, int xi, int yi, int xf, int yf) //Imprime ula imagen deacuerdo a las coordenadas
    {
        readimagefile(ima,xi,yi,xf,yf);  //abre la imagen y la muestra
    }
};

void tiempo(int t, int *v)
   {
       while(!kbhit())
       {
           this_thread::sleep_for(chrono::milliseconds(t));  //Se crea un tiempo desde thread para evitar percanses con sleep()

           *v+=1;

       }
   }

int main()
{
    int d=0, h=0, g=0;

    multimedia G;
    G.ventana();
    G.imp_imagen(imagenes[0], 0, 0, 80, 80);
    G.imp_imagen(imagenes[0], 80, 0, 160, 80);
    G.imp_imagen(imagenes[0], 160, 0, 240, 80);  //Se inicializa con los focos apagados "0"
    // Crea tres hilos para manejar los intervalos de encendido/apagado de los LEDs.
    thread led_1(tiempo, 250, &d);
    thread led_2(tiempo, 500, &h);
    thread led_3(tiempo, 1000, &g);  //Se inicializan los leds a tra vez de los hilos y recibe un tiempo de encendido

    while(!kbhit())  //Bucle infinito hasta que se presione una techa
    {
        G.imp_imagen(imagenes[d%2], 0,0,80,80); //Led azul
        G.imp_imagen(imagenes[(h%2)*2], 80,0,160,80); //Led Rojo
        G.imp_imagen(imagenes[(g%2)*3], 160,0,240,80); //Led rosa
    }
    // Espera a que los hilos terminen antes de cerrar el programa.
    led_1.join();
    led_2.join();
    led_3.join();

    getch();

    return 0;
}
