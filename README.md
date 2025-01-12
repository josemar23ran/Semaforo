Simulación de LEDs con Gráficos y Hilos

Este proyecto en C++ utiliza la librería graphics.h para crear una ventana gráfica donde se simulan tres LEDs que se encienden y apagan a intervalos de tiempo distintos mediante hilos (std::thread).

Características

Simula el comportamiento de tres LEDs (ázul, rojo y rosa) con diferentes tiempos de encendido y apagado.
Utiliza hilos para manejar los intervalos de tiempo de forma independiente.
Muestra las imágenes de los LEDs en una ventana gráfica.

Tecnologías utilizadas
C++
graphics.h: Para el manejo de gráficos y la visualización de las imágenes.
std::thread: Para el manejo de tareas concurrentes.

Requisitos del sistema
Compilador compatible con graphics.h:
Turbo C++ o Dev-C++ (con configuración para usar graphics.h).
Sistema operativo: Windows (necesario para graphics.h y windows.h).
Carpeta imagenes en la misma ubicación que el archivo ejecutable, que contenga las siguientes imágenes:
1.jpg: Imagen del LED apagado.
2.jpg: Imagen del LED azul encendido.
3.jpg: Imagen del LED rojo encendido.
4.jpg: Imagen del LED rosa encendido.

Cómo ejecutar
Asegúrate de que el compilador soporte graphics.h.
Coloca el código fuente en un archivo main.cpp.
Crea una carpeta llamada imagenes en el mismo directorio que el ejecutable y coloca las imágenes necesarias:
Compila y ejecuta el programa.


Descripción del código

1. Declaración de imágenes
El programa utiliza un arreglo para almacenar las rutas de las imágenes de los LEDs:
char imagenes[4][25]={
    "imagenes\\1.jpg", // Led apagado
    "imagenes\\2.jpg", // Led azul
    "imagenes\\3.jpg", // Led rojo
    "imagenes\\4.jpg"  // Led rosa
};

2. Clase multimedia
ventana: Crea una ventana gráfica de 241x81 píxeles con fondo blanco.
imp_imagen: Muestra una imagen en la ventana dentro de las coordenadas especificadas.

3. Funciones con hilos
tiempo: Incrementa un contador en intervalos regulares definidos por el tiempo en milisegundos.
Cada hilo controla un LED con diferentes intervalos:
LED 1: 250 ms
LED 2: 500 ms
LED 3: 1000 ms

4. Bucle principal
El bucle principal actualiza el estado de los LEDs y muestra las imágenes correspondientes según el estado calculado (“encendido” o “apagado”) hasta que se presione una tecla.
Ejemplo de salida
LED Azul: Se enciende y apaga cada 250 ms.
LED Rojo: Se enciende y apaga cada 500 ms.
LED Rosa: Se enciende y apaga cada 1000 ms.
La ventana muestra los LEDs con las imágenes correspondientes en una fila horizontal.

Autor: Jose Carmen Martínez
