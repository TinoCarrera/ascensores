// Estableciendo pines de los periféricos
// 12 Sensores de nivel
const int sensorPBA1 = 28;		    // sensor de ubicación PB A1
const int sensorPBA2 = 29;           // sensor de ubicación PB A2
const int sensorP1A1 = 30;		    // sensor de ubicación P1 A1
const int sensorP1A2 = 31;           // sensor de ubicación P1 A2
const int sensorP2A1 = 32;		    // sensor de ubicación P2 A1
const int sensorP2A2 = 33;           // sensor de ubicación P2 A2
const int sensorP3A1 = 34;		    // sensor de ubicación P3 A1
const int sensorP3A2 = 35;           // sensor de ubicación P3 A2
const int sensorP4A1 = 36;		    // sensor de ubicación P4 A1
const int sensorP4A2 = 37;           // sensor de ubicación P4 A2
const int sensorPHA1 = 38;		    // sensor de ubicación PH A1
const int sensorPHA2 = 39;           // sensor de ubicación PH A2
// 6 Sensores de puertas
const int sensorAperturaA1 = 22;     // sensor de la apertura de puertas A1
const int sensorAperturaA2 = 23;     // sensor de la apertura de puertas A2
const int sensorCierreA1 = 24;       // sensor de cierre de puertas A1
const int sensorCierreA2 = 25;       // sensor de cierre de puertas A2
const int sensorObstA1 = 26;		    // sensor de obstáculos de puertas A1
const int sensorObstA2 = 27;	        // sensor de obstáculos de puertas A2
// 4 Motores
const int motorPuertasA1 = 11;	    // pin de velocidad de motor de Puertas A1
const int motorCabinaA1 = 13;		// pin de velocidad de motor de cabina A1
const int motorPuertasA2 = 10;	    // pin de velocidad de motor de Puertas A2
const int motorCabinaA2 = 12;		// pin de velocidad de motor de cabina A2
// 4 Salidas al Decodificador/Demultiplexor 74138
const int decoEnable = 0;              // Habilitar decodificador
const int decoInC = 14;              // pin C del Decodificador/Demultiplexor
const int decoInB = 15;              // pin B del Decodificador/Demultiplexor
const int decoInA = 16;              // pin A del Decodificador/Demultiplexor
// 22 Botones Internos/Externos (Matriz de botones 6x4)
const int fila1Botones = 60;         //  PHBa, P4Su, P4Ba, P3Su 
const int fila2Botones = 61;         //  P3Ba, P2Su, P2Ba, P1Su
const int fila3Botones = 62;         //  P1Ba, PBSu, NADA, NADA
const int fila4Botones = 63;         //  PHA1, P4A1, PHA2, P4A2
const int fila5Botones = 64;         //  P3A1, P2A1, P3A2, P2A2
const int fila6Botones = 65;         //  P1A1, PBA1, P1A2, PBA2
const int columna1Botones = 66;          
const int columna2Botones = 67;
const int columna3Botones = 68;
const int columna4Botones = 69;
// 10 Leds Externos
const int ledPHBa = 44;
const int ledP4Su = 46;
const int ledP4Ba = 48;
const int ledP3Su = 50;
const int ledP3Ba = 52;
const int ledP2Su = 53;
const int ledP2Ba = 51;
const int ledP1Su = 49;
const int ledP1Ba = 47;
const int ledPBSu = 45;
// 12 Leds Internos
const int ledPHA1 = 54;
const int ledP4A1 = 55;
const int ledP3A1 = 56;
const int ledP2A1 = 57;
const int ledP1A1 = 58;
const int ledPBA1 = 59;
const int ledPHA2 = 9;
const int ledP4A2 = 8;
const int ledP3A2 = 17;
const int ledP2A2 = 18;
const int ledP1A2 = 19;
const int ledPBA2 = 43;
// 2 Botones para "Parar" las puertas
const int botonPararA1 = 0;
const int botonPararA2 = 0;
// Declarando variables
bool inicio = true;             // al iniciar el controlador reinicio = 1
byte velocidadPuertas = 100;    // velocidad del motor de puertas
byte velocidadCabina = 100;     // velocidad de motor de cabina
unsigned long tiempoEsperaA1;   // tiempo de espera para cerrar puertas A1
unsigned long tiempoEsperaA2;   // tiempo de espera para cerrar puertas A2
int llamadoExt;
int pisoA1;
int pisoA2;
// Arrays para sensores
byte sensoresPisosA1[] = {sensorPBA1, sensorP1A1, sensorP2A1, sensorP3A1, sensorP4A1, sensorPHA1};
byte sensoresPuertasA1[] = {sensorCierreA1, sensorAperturaA1, sensorObstA1};
byte sensoresPisosA2[] = {sensorPBA2, sensorP1A2, sensorP2A2, sensorP3A2, sensorP4A2, sensorPHA2};
byte sensoresPuertasA2[] = {sensorCierreA2, sensorAperturaA2, sensorObstA2};
const int cuentaSenPisos = sizeof(sensoresPisosA1);
const int cuentaSenPuertas = sizeof(sensoresPuertasA1);
// Array para motores
byte pinesMotores[] = {motorPuertasA1, motorPuertasA2, motorCabinaA1, motorCabinaA2, decoInC, decoInB, decoInA};
const int cuentaPinMotor = sizeof(pinesMotores);
// Arrays para matriz 6x4 de botones
byte filBotones[] = {fila1Botones, fila2Botones, fila3Botones, fila4Botones, fila5Botones, fila6Botones};
byte filBotonesExt[] = {fila1Botones, fila2Botones, fila3Botones};
byte filBotonesInt[] = {fila4Botones, fila5Botones, fila6Botones};
byte colBotones[] = {columna1Botones, columna2Botones, columna3Botones, columna4Botones};
const int cuentaFilTot = sizeof(filBotones);
const int cuentaFil = sizeof(filBotonesExt);
const int cuentaCol = sizeof(colBotones);
// Array para leds Externos
byte ledsExternos[] = {ledPBSu, ledP1Ba, ledP1Su, ledP2Ba, ledP2Su, ledP3Ba, ledP3Su, ledP4Ba, ledP4Su, ledPHBa};
const int cuentaLedExt = sizeof(ledsExternos);
// Array para leds Internos
byte ledsInternos[] = {ledPBA1, ledP1A1, ledP2A1, ledP3A1, ledP4A1, ledPHA1, ledPBA2, ledP1A2, ledP2A2, ledP3A2, ledP4A2, ledPHA2};
byte ledsInternosA1[] = {ledPBA1, ledP1A1, ledP2A1, ledP3A1, ledP4A1, ledPHA1};
byte ledsInternosA2[] = {ledPBA2, ledP1A2, ledP2A2, ledP3A2, ledP4A2, ledPHA2};
const int cuentaLedInt = sizeof(ledsInternos);

void setup() {  // estableciendo entradas y salidas
    pinMode(decoEnable, OUTPUT);    // Pin del Enable como salida
    digitalWrite(decoEnable, HIGH);   // Se desabilita el Decodificador
    for (int x = 0; x < cuentaSenPisos; x++) {  // Sensores de piso A1 como entradas pullup
        pinMode(sensoresPisosA1[x], INPUT_PULLUP);
    }
    for (int x = 0; x < cuentaSenPisos; x++) {  // Sensores de piso A2 como entradas pullup
        pinMode(sensoresPisosA2[x], INPUT_PULLUP);
    }
    for (int x = 0; x < cuentaSenPuertas; x++) {
        pinMode(sensoresPuertasA1[x], INPUT_PULLUP);    // Sensores de puerta A1 como entradas pullup
    }
    for (int x = 0; x < cuentaSenPuertas; x++) {
        pinMode(sensoresPuertasA2[x], INPUT_PULLUP);    // Sensores de puerta A2 como entradas pullup
    }
    for (int x = 0; x < cuentaPinMotor; x++) {  // Pines de motores como salidas
        pinMode(pinesMotores[x], OUTPUT);
    }
    for (int x = 0; x < cuentaFilTot; x++) {    // Filas de matriz de botones como entrada
        pinMode(filBotones[x], INPUT);
    }
    for (int x = 0; x < cuentaCol; x++) {   // Columnas de matriz de botones como entrada de pullup
        pinMode(colBotones[x], INPUT_PULLUP);
    }
    for (int x = 0; x < cuentaLedExt; x++) {    // Led externos como salidas
        pinMode(ledsExternos[x], OUTPUT);
    }
    for (int x = 0; x < cuentaLedInt; x++) {    // Led internos como salidas
        pinMode(ledsInternos[x], OUTPUT);
    }
}

void loop() {   // bucle
    if (inicio) {     // si el controlador se acaba de iniciar
        delay(5000);    // delay de inicio
        digitalWrite(decoEnable, LOW);  // Se habilita el decodificador
        prevencionA1();
        prevencionA2();
        inicio = false;
    }
    if ((millis() - tiempoEsperaA1) >= 10000) {     // espera 10 seg con las puertas abiertas de A1
        cerrarPuertasA1();
        tiempoEsperaA1 = millis();
    }
    if ((millis() - tiempoEsperaA2) >= 10000) {     // espera 10 seg con las puertas abiertas de A2
        cerrarPuertasA2();
        tiempoEsperaA2 = millis();
    }
    botonesExternos();
    movimiento();
    botonesInternos();
}

void prevencionA1() {
    if (digitalRead(sensorPBA1)) {  // si ascensor no está en PB
        if (digitalRead(sensorCierreA1)) {   // si las puertas no están cerradas
            cerrarPuertasA1();  // cerrar puertas
        }
        bajandoA1();
        while (digitalRead(sensorPBA1)) {   // si el ascensor no ha llegado a PB
            analogWrite(motorCabinaA1, velocidadCabina);    // baja cabina
        }
        analogWrite(motorCabinaA1, 0);  // detiene cabina
        abrirPuertasA1();
    } else {    // si el ascensor está en PB
        if (!digitalRead(sensorCierreA1)) { // si las puertas están cerradas
            abrirPuertasA1();
        }
    }
}

void prevencionA2() {
    if (digitalRead(sensorPBA2)) {  // si ascensor no está en PB
        if (digitalRead(sensorCierreA2)) {   // si las puertas no están cerradas
            cerrarPuertasA2();  // cerrar puertas
        }
        bajandoA2();
        while (digitalRead(sensorPBA2)) {   // si el ascensor no ha llegado a PB
            analogWrite(motorCabinaA2, velocidadCabina);    // baja cabina
        }
        analogWrite(motorCabinaA2, 0);  // detiene cabina
        abrirPuertasA2();
    } else {    // si el ascensor está en PB
        if (!digitalRead(sensorCierreA2)) { // si las puertas están cerradas
            abrirPuertasA2();
        }
    }
}

void cerrarPuertasA1() {
    digitalWrite(decoInC, HIGH);    // direccion derecha para cerrar
    digitalWrite(decoInB, LOW);
    digitalWrite(decoInA, HIGH);
    while (digitalRead(sensorCierreA1)) {   // si las puertas no estan cerradas
        analogWrite(motorPuertasA1, velocidadPuertas);  // cierra puertas
        verificarPuertasA1();
    }
    analogWrite(motorPuertasA1, 0); // detiene puertas
}

void cerrarPuertasA2() {
    digitalWrite(decoInC, HIGH);    // direccion derecha para cerrar
    digitalWrite(decoInB, HIGH);
    digitalWrite(decoInA, HIGH);
    while (digitalRead(sensorCierreA2)) {  // si las puertas no estan cerradas
        analogWrite(motorPuertasA2, velocidadPuertas);  // cierra puertas
        verificarPuertasA2();
    }
    analogWrite(motorPuertasA2, 0); // detiene puertas
}

void verificarPuertasA1() {
    if (!digitalRead(sensorObstA1) || !digitalRead(botonPararA1)) {   // si hay un obstáculo
        analogWrite(motorPuertasA1, 0); // detiene puertas
        abrirPuertasA1();
    }
}

void verificarPuertasA2() {
    if (!digitalRead(sensorObstA2) || !digitalRead(botonPararA2)) {   // si hay un obstáculo
        analogWrite(motorPuertasA2, 0); // detiene puertas
        abrirPuertasA2();
    }
}

void abrirPuertasA1() {
    digitalWrite(decoInC, HIGH);    // dirección izquierda para abrir
    digitalWrite(decoInB, LOW);
    digitalWrite(decoInA, LOW);
    while (digitalRead(sensorAperturaA1)) {    // entra en bucle hasta abrir las puertas
        analogWrite(motorPuertasA1, velocidadPuertas);  // abre puertas
    } 
    analogWrite(motorPuertasA1, 0); // detiene puertas
    tiempoEsperaA1 = millis();
}

void abrirPuertasA2() {
    digitalWrite(decoInC, HIGH);    // dirección izquierda para abrir
    digitalWrite(decoInB, HIGH);
    digitalWrite(decoInA, LOW);
    while (digitalRead(sensorAperturaA2)) {    // entra en bucle hasta abrir las puertas
        analogWrite(motorPuertasA2, velocidadPuertas);  // abre puertas
    }
    analogWrite(motorPuertasA2, 0); // detiene puertas
    tiempoEsperaA2 = millis();
}

void bajandoA1() {
    digitalWrite(decoInC, LOW); // direccion derecha para bajar A1
    digitalWrite(decoInB, LOW);
    digitalWrite(decoInA, HIGH);
}

void subiendoA1() {
    digitalWrite(decoInC, LOW); // direccion izquierda para subir A1
    digitalWrite(decoInB, LOW);
    digitalWrite(decoInA, LOW);
}

void bajandoA2() {
    digitalWrite(decoInC, LOW); // direccion derecha para bajar A2
    digitalWrite(decoInB, HIGH);
    digitalWrite(decoInA, HIGH);
}

void subiendoA2() {
    digitalWrite(decoInC, LOW); // direccion izquierda para subir A2
    digitalWrite(decoInB, HIGH);
    digitalWrite(decoInA, LOW);
}

void botonesExternos() {
    for (int filaActiva = 0; filaActiva < cuentaFil; filaActiva++) {
        byte fila = filBotonesExt[filaActiva];
        pinMode(fila, OUTPUT);
        digitalWrite(fila, LOW);
        for (int colActiva = 0; colActiva < cuentaCol; colActiva++) {
            byte col = colBotones[colActiva];
            if (!digitalRead(col)) {
                botonExtPresionado(col, fila);
            }
        }
        pinMode(fila, INPUT);
    }
}

void botonExtPresionado(int col, int fila) {
    if (fila == fila1Botones && col == columna1Botones) {
        llamadoExt = 5;
        int ledPresionado = 9;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila1Botones && col == columna2Botones) {
        llamadoExt = 4;
        int ledPresionado = 8;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila1Botones && col == columna3Botones) {
        llamadoExt = 4;
        int ledPresionado = 7;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila1Botones && col == columna4Botones) {
        llamadoExt = 3;
        int ledPresionado = 6;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila2Botones && col == columna1Botones) {
        llamadoExt = 3;
        int ledPresionado = 5;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila2Botones && col == columna2Botones) {
        llamadoExt = 2;
        int ledPresionado = 4;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila2Botones && col == columna3Botones) {
        llamadoExt = 2;
        int ledPresionado = 3;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila2Botones && col == columna4Botones) {
        llamadoExt = 1;
        int ledPresionado = 2;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila3Botones && col == columna1Botones) {
        llamadoExt = 1;
        int ledPresionado = 1;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila3Botones && col == columna2Botones) {
        llamadoExt = 0;
        int ledPresionado = 0;
        llamadoExterno(ledPresionado);
    }
}

void llamadoExterno(int ledPresionado) {
    byte llamadoA1 = sensoresPisosA1[llamadoExt];
    byte llamadoA2 = sensoresPisosA2[llamadoExt];
    if (!digitalRead(llamadoA1)) { // si el ascensor 1 está en PH abre puertas
        abrirPuertasA1();
    } else if (!digitalRead(llamadoA2)) {  // sino, si el ascensor 2 está en PH abre puertas
        abrirPuertasA2();
    } else {
        byte led = ledsExternos[ledPresionado]; 
        digitalWrite(led, HIGH);
    }
}

void movimiento() {
    for (int ledLeido = 0; ledLeido < cuentaLedExt; ledLeido++) { // Bucle for para leer cada led
        byte led = ledsExternos[ledLeido];
        if (digitalRead(led)) {  // Si hay led encendido
            for (pisoA1 = 0; pisoA1 < cuentaSenPisos; pisoA1++) {
                byte piso = sensoresPisosA1[pisoA1];    
                if (!digitalRead(piso)) {   // Lee dónde está el ascensor
                    break;  // Si encuentra el piso del ascensor sale del bucle for
                }
            }
            for (pisoA2 = 0; pisoA2 < cuentaSenPisos; pisoA2++) {
                byte piso = sensoresPisosA2[pisoA2];    
                if (!digitalRead(piso)) {   // Lee dónde está el ascensor
                    break;  // Si encuentra el piso del ascensor sale del bucle for
                }
            }
            int difA1 = llamadoExt - pisoA1;
            int difA2 = llamadoExt - pisoA2;
            if (difA1 < 0) {
                difA1 = difA1*-1;
            }
            if (difA2 < 0) {
                difA2 = difA2*-1;
            }
            if (difA1 <= difA2) {
                mueveA1();
                digitalWrite(led, LOW); // Al terminar de mover apaga el led
            } else if (difA1 > difA2) {
                mueveA2();
                digitalWrite(led, LOW); // Al terminar de mover apaga el led
            }
            break;  // Si encuentra led activo sale del bucle for
        }
    }
}

void mueveA1() {
    if (pisoA1 < llamadoExt) {   // Si el ascensor está abajo
        subiendoA1();
        byte llamadoA1 = sensoresPisosA1[llamadoExt];
        while (digitalRead(llamadoA1)) {   // sube A1 al piso llamado
            analogWrite(motorCabinaA1, velocidadCabina);
        }
        analogWrite(motorCabinaA1, 0);  // Detiene la cabina
        abrirPuertasA1(); // Abre puertas
    } else if (pisoA1 > llamadoExt) {    // Si el ascensor está arriba
        bajandoA1();
        byte llamadoA1 = sensoresPisosA1[llamadoExt];
        while (digitalRead(llamadoA1)) {   // baja A1 al piso llamado
            analogWrite(motorCabinaA1, velocidadCabina);
        }
        analogWrite(motorCabinaA1, 0);  // Detiene la cabina
        abrirPuertasA1(); // Abre puertas
    }
}

void mueveA2() {
    if (pisoA2 < llamadoExt) {   // Si el ascensor está abajo
        subiendoA2();
        byte llamadoA2 = sensoresPisosA2[llamadoExt];
        while (digitalRead(llamadoA2)) {   // sube A2 al piso llamado
            analogWrite(motorCabinaA2, velocidadCabina);
        }
        analogWrite(motorCabinaA2, 0);  // Detiene la cabina
        abrirPuertasA2(); // Abre puertas
    } else if (pisoA2 > llamadoExt) {    // Si el ascensor está arriba
        bajandoA2();
        byte llamadoA2 = sensoresPisosA2[llamadoExt];
        while (digitalRead(llamadoA2)) {   // baja A2 al piso llamado
            analogWrite(motorCabinaA2, velocidadCabina);
        }
        analogWrite(motorCabinaA2, 0);  // Detiene la cabina
        abrirPuertasA2(); // Abre puertas
    }
}

void botonesInternos() {
    for (int filaActiva = 0; filaActiva < cuentaFil; filaActiva++) {
        byte fila = filBotonesInt[filaActiva];
        pinMode(fila, OUTPUT);
        digitalWrite(fila, LOW);
        for (int colActiva = 0; colActiva < cuentaCol; colActiva++) {
            byte col = colBotones[colActiva];
            if (!digitalRead(col)) {
                botonIntPresionado(col, fila);
            }
        }
        pinMode(fila, INPUT);
    }
}

void botonIntPresionado(int col, int fila) {
    if (fila == fila4Botones && col == columna1Botones) {
        int ledPresionado = 0;
        llamadoInternoA1(ledPresionado);
    }
    if (fila == fila4Botones && col == columna2Botones) {
        int ledPresionado = 1;
        llamadoInternoA1(ledPresionado);
    }
    if (fila == fila5Botones && col == columna1Botones) {
        int ledPresionado = 2;
        llamadoInternoA1(ledPresionado);
    }
    if (fila == fila5Botones && col == columna2Botones) {
        int ledPresionado = 3;
        llamadoInternoA1(ledPresionado);
    }
    if (fila == fila6Botones && col == columna1Botones) {
        int ledPresionado = 4;
        llamadoInternoA1(ledPresionado);
    }
    if (fila == fila6Botones && col == columna2Botones) {
        int ledPresionado = 5;
        llamadoInternoA1(ledPresionado);
    }
    if (fila == fila4Botones && col == columna3Botones) {
        int ledPresionado = 0;
        llamadoInternoA2(ledPresionado);
    }
    if (fila == fila4Botones && col == columna4Botones) {
        int ledPresionado = 1;
        llamadoInternoA2(ledPresionado);
    }
    if (fila == fila5Botones && col == columna3Botones) {
        int ledPresionado = 2;
        llamadoInternoA2(ledPresionado);
    }
    if (fila == fila5Botones && col == columna4Botones) {
        int ledPresionado = 3;
        llamadoInternoA2(ledPresionado);
    }
    if (fila == fila6Botones && col == columna3Botones) {
        int ledPresionado = 4;
        llamadoInternoA2(ledPresionado);
    }
    if (fila == fila6Botones && col == columna4Botones) {
        int ledPresionado = 5;
        llamadoInternoA2(ledPresionado);
    }
}

void llamadoInternoA1(int ledPresionado) {
    byte led = ledsInternosA1[ledPresionado];
    digitalWrite(led, HIGH);
}

void llamadoInternoA2(int ledPresionado) {
    byte led = ledsInternosA2[ledPresionado];
    digitalWrite(led, HIGH);
}
