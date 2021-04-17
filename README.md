# Proyecto de Ascensores

## Acerca del proyecto 

Este es un sistema inteligente controlado por un Arduino Mega, y su función es controlar dos cabinas de ascensores que se movilizan a través de 6 niveles.


## Modelo 3D

El modelo 3D fue diseñado en una aplicación web llamada Tinkercad. Esta aplicación permite realizar diseños en 3D de forma online. El diseño creado se muestra en la siguiente imagen:

<p align="center"><img src="https://user-images.githubusercontent.com/70342537/115101896-a23d7b80-9f15-11eb-9824-1d20e81637a6.png" width="500"></p>


## Tableros

Una de las funciones es controlar un tablero de botones externos que estará ubicado en su piso correspondiente, estos botones tienen el siguiente aspecto:

<p align="center"><img src="https://user-images.githubusercontent.com/70342537/115100970-8edae200-9f0e-11eb-8bf5-03c43831340b.png" width="600"></p>

El tablero de los botones internos que tendrá cada una de las cabinas será el siguiente:

<p align="center"><img src="https://user-images.githubusercontent.com/70342537/115101059-2dffd980-9f0f-11eb-9924-2deb46dc43e5.png" length="800"></p>

Y también posee un tablero en la parte superior de las puertas del piso de Planta baja (PB) para indicar la ubicación del ascensor.

<p align="center"><img src="https://user-images.githubusercontent.com/70342537/115101281-aca94680-9f10-11eb-8383-bfceb3c9ffa6.png" width="600"></p>

## Controlador

El controlador utilizado en este proyecto es el Arduino Mega. Este Arduino, a diferencia de otros, posee 54 entradas/salidas digitales, 16 entradas analógicas (que también pueden ser usadas como entradas y salidas digitales) y 4 pines para comunicación serial.

<p align="center"><img src="https://user-images.githubusercontent.com/70342537/115101486-8c7a8700-9f12-11eb-81a4-48f34ccc685c.png" width="800"></p>

## Código

Debido a que el controlador es un Arduino, el código fuente del programa esta escrito en lenguaje C++ con las reglas especiales de estructuración que posee el Arduino.  
