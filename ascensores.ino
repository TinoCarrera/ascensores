// Estableciendo pines de los periféricos
// 12 Sensores de nivel
const int sensorPBA1 = 28;        // sensor de ubicación PB A1
const int sensorPBA2 = 29;        // sensor de ubicación PB A2
const int sensorP1A1 = 30;        // sensor de ubicación P1 A1
const int sensorP1A2 = 31;        // sensor de ubicación P1 A2
const int sensorP2A1 = 32;        // sensor de ubicación P2 A1
const int sensorP2A2 = 33;        // sensor de ubicación P2 A2
const int sensorP3A1 = 34;        // sensor de ubicación P3 A1
const int sensorP3A2 = 35;        // sensor de ubicación P3 A2
const int sensorP4A1 = 36;        // sensor de ubicación P4 A1
const int sensorP4A2 = 37;        // sensor de ubicación P4 A2
const int sensorPHA1 = 38;        // sensor de ubicación PH A1
const int sensorPHA2 = 39;        // sensor de ubicación PH A2
// 6 Sensores de puertas
const int sensorAperturaA1 = 22;    // sensor de la apertura de puertas A1
const int sensorAperturaA2 = 23;    // sensor de la apertura de puertas A2
const int sensorCierreA1 = 24;      // sensor de cierre de puertas A1
const int sensorCierreA2 = 25;      // sensor de cierre de puertas A2
const int sensorObstA1 = 26;        // sensor de obstáculos de puertas A1
const int sensorObstA2 = 27;        // sensor de obstáculos de puertas A2
// 4 Motores
const int motorPuertasA1 = 11;      // pin de velocidad de motor de Puertas A1
const int motorCabinaA1 = 13;       // pin de velocidad de motor de cabina A1
const int motorPuertasA2 = 10;      // pin de velocidad de motor de Puertas A2
const int motorCabinaA2 = 12;       // pin de velocidad de motor de cabina A2
// 10 Salidas a Decodificadores 74138
const int decoEnable = 6;               // Habilitar decodificador
const int decoMotoresC = 14;            // pin C del Decodificador de motores
const int decoMotoresB = 15;            // pin B del Decodificador de motores
const int decoMotoresA = 16;            // pin A del Decodificador de motores
const int decoA1C = 7;                  // pin C del Decodificador de visualizador A1
const int decoA1B = 42;                 // pin B del Decodificador de visualizador A1
const int decoA1A = 5;                  // pin A del Decodificador de visualizador A1
const int decoA2C = 4;                  // pin C del Decodificador de visualizador A2
const int decoA2B = 3;                  // pin B del Decodificador de visualizador A2
const int decoA2A = 2;                  // pin A del Decodificador de visualizador A2
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
const int botonPararA1 = 41;
const int botonPararA2 = 40;
// 1 interruptor para cuando sea horario pico
const int horaBajada = 20;
// Declarando variables
bool inicio = true;             // al iniciar el controlador reinicio = 1
byte velocidadPuertas = 60;    // velocidad del motor de puertas
byte velocidadCabina = 117;     // velocidad de motor de cabina
int llamadoExt;                 // variable de llamado externo
int pisoA1;                     // variable de piso A1
int pisoA2;                     // variable de piso A2
int pisoActA1;                  // variable de piso actual A1
int pisoActA2;                  // variable de piso actual A2
unsigned long tiempoEsperaA1;   // tiempo de espera para A1
unsigned long tiempoEsperaA2;   // tiempo de espera para A2
// Arrays para sensores
byte sensoresPisosA1[] = {sensorPBA1, sensorP1A1, sensorP2A1, sensorP3A1, sensorP4A1, sensorPHA1};
byte sensoresPuertasA1[] = {sensorCierreA1, sensorAperturaA1, sensorObstA1};
byte sensoresPisosA2[] = {sensorPBA2, sensorP1A2, sensorP2A2, sensorP3A2, sensorP4A2, sensorPHA2};
byte sensoresPuertasA2[] = {sensorCierreA2, sensorAperturaA2, sensorObstA2};
const int cuentaSenPisos = sizeof(sensoresPisosA1);
const int cuentaSenPuertas = sizeof(sensoresPuertasA1);
// Array para motores
byte pinesMotores[] = {motorPuertasA1, motorPuertasA2, motorCabinaA1, motorCabinaA2, decoMotoresC, decoMotoresB, decoMotoresA};
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
// Arrays para leds Internos
byte ledsInternos[] = {ledPBA1, ledP1A1, ledP2A1, ledP3A1, ledP4A1, ledPHA1, ledPBA2, ledP1A2, ledP2A2, ledP3A2, ledP4A2, ledPHA2};
byte ledsInternosA1[] = {ledPBA1, ledP1A1, ledP2A1, ledP3A1, ledP4A1, ledPHA1};
byte ledsInternosA2[] = {ledPBA2, ledP1A2, ledP2A2, ledP3A2, ledP4A2, ledPHA2};
const int cuentaLedInt = sizeof(ledsInternos);
const int cuentaLed = sizeof(ledsInternosA1);
// Array para visualizadores
byte visualizadores[] = {decoA1C, decoA1B, decoA1A, decoA2C, decoA2B, decoA2A};
const int cuentaVisualizadores = sizeof(visualizadores);

void setup() {  // estableciendo entradas y salidas
    Serial.begin(9600);
    pinMode(decoEnable, OUTPUT);    // Pin del Enable como salida
    digitalWrite(decoEnable, HIGH);   // Se desabilita el Decodificador
    pinMode(botonPararA1, INPUT_PULLUP);
    pinMode(botonPararA2, INPUT_PULLUP);
    pinMode(horaBajada, INPUT_PULLUP);    // interruptor horario de bajada como entrada pullup
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
    for (int x = 0; x < cuentaVisualizadores; x++) { // Pines de visualizadores A1 y A2 como salidas
        pinMode(visualizadores[x], OUTPUT);
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

void loop() {   // bucle principal
    prevencion();  
    botonesInternos(); 
    botonesExternos();
    movimientoInt();
    movimientoExt();
}

void prevencion() {
    if (inicio) {     // si el controlador se acaba de iniciar
        Serial.println("Inicia el Arduino");
        delay(5000);    // delay de inicio
        digitalWrite(decoEnable, LOW);  // Se habilita el decodificador
        Serial.println("Inicia Prevencion A1");
        prevencionA1();
        Serial.println("Inicia prevención A2");
        prevencionA2();
        inicio = false;
    }
}

void prevencionA1() {
    if (digitalRead(sensorPBA1)) {  // si ascensor no está en PB
        Serial.println("El ascensor A1 no está en PB");
        if (digitalRead(sensorCierreA1)) {   // si las puertas no están cerradas
            Serial.println("Las puertas de A1 no están cerradas");
            cerrarPuertasA1();  // cerrar puertas
        }
        Serial.println("Bajando A1 a PB");
        bajandoA1();
        while (digitalRead(sensorPBA1)) {   // si el ascensor no ha llegado a PB
            analogWrite(motorCabinaA1, velocidadCabina);    // baja cabina
            visualizadorA1();
        }
        analogWrite(motorCabinaA1, 0);  // detiene cabina
        visualizadorA1();
        abrirPuertasA1();
    } else {    // si el ascensor está en PB
        Serial.println("El ascensor A1 está en PB");
        if (!digitalRead(sensorCierreA1)) { // si las puertas están cerradas
            Serial.println("Las puertas de A1 no están cerradas");
            abrirPuertasA1();
        }
    }
}

void prevencionA2() {
    if (digitalRead(sensorPBA2)) {  // si ascensor no está en PB
        Serial.println("El ascensor A2 no está en PB");
        if (digitalRead(sensorCierreA2)) {   // si las puertas no están cerradas
            Serial.println("Las puertas de A2 no están cerradas");
            cerrarPuertasA2();  // cerrar puertas
        }
        Serial.println("Bajando A2 a PB");
        bajandoA2();
        while (digitalRead(sensorPBA2)) {   // si el ascensor no ha llegado a PB
            analogWrite(motorCabinaA2, velocidadCabina);    // baja cabina
            visualizadorA2();
        }
        analogWrite(motorCabinaA2, 0);  // detiene cabina
        visualizadorA2();
        abrirPuertasA2();
    } else {    // si el ascensor está en PB
        Serial.println("El ascensor A2 está en PB");
        if (!digitalRead(sensorCierreA2)) { // si las puertas están cerradas
            Serial.println("Las puertas de A2 no están cerradas");
            abrirPuertasA2();
        }
    }
}

void cerrarPuertasA1() {
    Serial.println("Cerrando puertas de A1");
    while (digitalRead(sensorCierreA1)) {   // si las puertas no estan cerradas
        digitalWrite(decoMotoresC, HIGH);    // direccion derecha para cerrar
        digitalWrite(decoMotoresB, LOW);
        digitalWrite(decoMotoresA, HIGH);
        analogWrite(motorPuertasA1, velocidadPuertas);  // cierra puertas
        verificarPuertasA1();
    }
    Serial.println("Puertas de A1 cerradas");
    analogWrite(motorPuertasA1, 0); // detiene puertas
}

void cerrarPuertasA2() {
    Serial.println("Cerrando puertas de A2");
    while (digitalRead(sensorCierreA2)) {  // si las puertas no estan cerradas
        digitalWrite(decoMotoresC, HIGH);    // direccion derecha para cerrar
        digitalWrite(decoMotoresB, HIGH);
        digitalWrite(decoMotoresA, HIGH);
        analogWrite(motorPuertasA2, velocidadPuertas);  // cierra puertas
        verificarPuertasA2();   
    }
    Serial.println("Puertas de A2 cerradas");
    analogWrite(motorPuertasA2, 0); // detiene puertas
}

void verificarPuertasA1() {
    while (!digitalRead(sensorObstA1) || !digitalRead(botonPararA1)) {   // si hay un obstáculo
        Serial.println("Hay un obstáculo en A1 o se presionó el botón de abrir A1");
        analogWrite(motorPuertasA1, 0); // detiene puertas
        abrirPuertasA1();
    }
}

void verificarPuertasA2() {
    while (!digitalRead(sensorObstA2) || !digitalRead(botonPararA2)) {   // si hay un obstáculo
        Serial.println("Hay un obstáculo en A2 o se presionó el botón de abrir A2");
        analogWrite(motorPuertasA2, 0); // detiene puertas
        abrirPuertasA2();
    }
}

void abrirPuertasA1() {
    Serial.println("Abriendo puertas de A1");
    digitalWrite(decoMotoresC, HIGH);    // dirección izquierda para abrir
    digitalWrite(decoMotoresB, LOW);
    digitalWrite(decoMotoresA, LOW);
    while (digitalRead(sensorAperturaA1)) {    // entra en bucle hasta abrir las puertas
        analogWrite(motorPuertasA1, velocidadPuertas);  // abre puertas
    } 
    Serial.println("Puertas de A1 abiertas");
    analogWrite(motorPuertasA1, 0); // detiene puertas
    tiempoEsperaA1 = millis();      // Al abrir puertas inicia el tiempo de espera
}

void abrirPuertasA2() {
    Serial.println("Abriendo puertas de A2");
    digitalWrite(decoMotoresC, HIGH);    // dirección izquierda para abrir
    digitalWrite(decoMotoresB, HIGH);
    digitalWrite(decoMotoresA, LOW);
    while (digitalRead(sensorAperturaA2)) {    // entra en bucle hasta abrir las puertas
        analogWrite(motorPuertasA2, velocidadPuertas);  // abre puertas
    }
    Serial.println("Puertas de A2 abiertas");
    analogWrite(motorPuertasA2, 0); // detiene puertas
    tiempoEsperaA2 = millis();      // Al abrir puertas inicia el tiempo de espera
}

void bajandoA1() {
    digitalWrite(decoMotoresC, LOW); // direccion derecha para bajar A1
    digitalWrite(decoMotoresB, LOW);
    digitalWrite(decoMotoresA, HIGH);
}

void subiendoA1() {
    digitalWrite(decoMotoresC, LOW); // direccion izquierda para subir A1
    digitalWrite(decoMotoresB, LOW);
    digitalWrite(decoMotoresA, LOW);
}

void bajandoA2() {
    digitalWrite(decoMotoresC, LOW); // direccion derecha para bajar A2
    digitalWrite(decoMotoresB, HIGH);
    digitalWrite(decoMotoresA, HIGH);
}

void subiendoA2() {
    digitalWrite(decoMotoresC, LOW); // direccion izquierda para subir A2
    digitalWrite(decoMotoresB, HIGH);
    digitalWrite(decoMotoresA, LOW);
}

void botonesExternos() {
    Serial.println("Lectura de botones externos");
    for (int filaActiva = 0; filaActiva < cuentaFil; filaActiva++) {
        byte fila = filBotonesExt[filaActiva];
        pinMode(fila, OUTPUT);
        digitalWrite(fila, LOW);
        for (int colActiva = 0; colActiva < cuentaCol; colActiva++) {
            byte col = colBotones[colActiva];
            if (!digitalRead(col)) {
                Serial.println("Un botón externo fue presionado");
                botonExtPresionado(col, fila);
            }
        }
        pinMode(fila, INPUT);
    }
}

void botonExtPresionado(int col, int fila) {
    if (fila == fila3Botones && col == columna2Botones) {
        Serial.println("Botón PB subiendo");
        int ledPresionado = 0;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila3Botones && col == columna1Botones) {
        Serial.println("Botón P1 bajando");
        int ledPresionado = 1;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila2Botones && col == columna4Botones) {
        Serial.println("Botón P1 subiendo");
        int ledPresionado = 2;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila2Botones && col == columna3Botones) {
        llamadoExt = 2;
        Serial.println("Botón P2 bajando");
        int ledPresionado = 3;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila2Botones && col == columna2Botones) {
        llamadoExt = 2;
        Serial.println("Botón P2 subiendo");
        int ledPresionado = 4;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila2Botones && col == columna1Botones) {
        Serial.println("Botón P3 bajando");
        int ledPresionado = 5;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila1Botones && col == columna4Botones) {
        Serial.println("Botón P3 subiendo");
        int ledPresionado = 6;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila1Botones && col == columna3Botones) {
        Serial.println("Botón P4 bajando");
        int ledPresionado = 7;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila1Botones && col == columna2Botones) {
        Serial.println("Botón P4 subiendo");
        int ledPresionado = 8;
        llamadoExterno(ledPresionado);
    }
    if (fila == fila1Botones && col == columna1Botones) {
        Serial.println("Botón PH bajando");
        int ledPresionado = 9;
        llamadoExterno(ledPresionado);
    }
}

void llamadoExterno(int ledPresionado) {
    asignacionLlamadoExt(ledPresionado);
    byte llamadoA1 = sensoresPisosA1[llamadoExt];
    byte llamadoA2 = sensoresPisosA2[llamadoExt];
    if (!digitalRead(llamadoA1) && !digitalRead(sensorAperturaA1)) { // si el ascensor 1 está en PH abre puertas
        Serial.println("A1 está en el piso del botón externo presionado");
    } else if (!digitalRead(llamadoA2) && !digitalRead(sensorAperturaA2)) {  // sino, si el ascensor 2 está en PH abre puertas
        Serial.println("A2 está en el piso del botón externo presionado");
    } else {
        Serial.println("Enciende el botón externo presionado");
        byte led = ledsExternos[ledPresionado]; 
        digitalWrite(led, HIGH);
    }
}

void movimientoExt() {
    if ((millis() - tiempoEsperaA1) >= 5000 || (millis() - tiempoEsperaA2) >= 5000) { // Si algun ascensor está disponible
        if (horaBajada) { // Si es horario pico
            Serial.println("Lectura de botones externos encendidos (horario de bajada)");
            horarioBajando();
        } else {
            Serial.println("Lectura de botones externos encendidos (horario de subida)");
            horarioSubiendo();
        }
    } else {
        Serial.println("Ambos ascensores en espera. Función llamado externo saltada");
    }
}

void horarioBajando() {
    for (int ledLeido = cuentaLedExt; ledLeido >= 0; ledLeido--) { // Bucle for para leer cada led
        asignacionLlamadoExt(ledLeido);
        byte led = ledsExternos[ledLeido];
        if (digitalRead(led)) {  // Si hay led encendido
            Serial.println("Botón externo encendido");
            botonExtEncendido(led);
            break;  // Si encuentra led activo sale del bucle for
        }
    }
}

void horarioSubiendo() {
    for (int ledLeido = 0; ledLeido < cuentaLedExt; ledLeido++) { // Bucle for para leer cada led
        asignacionLlamadoExt(ledLeido);
        byte led = ledsExternos[ledLeido];
        if (digitalRead(led)) {  // Si hay led encendido
            Serial.println("Botón externo encendido");
            botonExtEncendido(led);
            break;  // Si encuentra led activo sale del bucle for
        }
    }
}

void botonExtEncendido(int led) {
    if ((millis() - tiempoEsperaA1) >= 5000 && (millis() - tiempoEsperaA2) >= 5000) {    // Si ambos ascensores están disponibles 
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
        if (difA1 < 0) { // Si la resta es negativo se hace positivo
            difA1 = difA1*-1;
        }
        if (difA2 < 0) { // Si la resta es negativo se hace positivo
            difA2 = difA2*-1;
        }
        if (difA1 <= difA2) {
            Serial.println("A1 se mueve al piso llamado");
            cerrarPuertasA1();
            mueveA1();
            Serial.println("Se apaga botón externo");
            digitalWrite(led, LOW); // Al terminar de mover apaga el led
        } else if (difA1 > difA2) {
            Serial.println("A2 se mueve al piso llamado");
            cerrarPuertasA2();
            mueveA2();
            Serial.println("Se apaga botón externo");
            digitalWrite(led, LOW); // Al terminar de mover apaga el led
        }
    } else if ((millis() - tiempoEsperaA1) >= 5000) { // si solo A1 está disponible
        for (pisoA1 = 0; pisoA1 < cuentaSenPisos; pisoA1++) {
            byte piso = sensoresPisosA1[pisoA1];    
            if (!digitalRead(piso)) {   // Lee dónde está el ascensor
                break;  // Si encuentra el piso del ascensor sale del bucle for
            }
        }
        Serial.println("A1 se mueve al piso llamado");
        cerrarPuertasA1();
        mueveA1();
        Serial.println("Se apaga botón externo");
        digitalWrite(led, LOW); // Al terminar de mover apaga el led  
    } else if ((millis() - tiempoEsperaA1) >= 5000) {   // si solo A2 está disponible
        for (pisoA2 = 0; pisoA2 < cuentaSenPisos; pisoA2++) {
            byte piso = sensoresPisosA2[pisoA2];    
            if (!digitalRead(piso)) {   // Lee dónde está el ascensor
                break;  // Si encuentra el piso del ascensor sale del bucle for
            }
        }
        Serial.println("A2 se mueve al piso llamado");
        cerrarPuertasA2();
        mueveA2();
        Serial.println("Se apaga botón externo");
        digitalWrite(led, LOW); // Al terminar de mover apaga el led
    }
    Serial.println("Finaliza Lectura de botones externos encendidos");
}

void asignacionLlamadoExt(int ledLeido) {
    if (ledLeido == 0) {
        llamadoExt = 0;
    }
    if (ledLeido == 1 || ledLeido == 2) {
        llamadoExt = 1;
    }
    if (ledLeido == 3 || ledLeido == 4) {
        llamadoExt = 2;
    }
    if (ledLeido == 5 || ledLeido == 6) {
        llamadoExt = 3;
    }
    if (ledLeido == 7 || ledLeido == 8) {
        llamadoExt = 4;
    }
    if (ledLeido == 9) {
        llamadoExt = 5;
    }
}

void mueveA1() {
    if (pisoA1 < llamadoExt) {   // Si el ascensor está abajo
        Serial.println("A1 sube al piso llamado");
        subiendoA1();
        byte llamadoA1 = sensoresPisosA1[llamadoExt];
        while (digitalRead(llamadoA1)) {   // sube A1 al piso llamado
            analogWrite(motorCabinaA1, velocidadCabina);
            visualizadorA1();
            botonesExternos();
            botonesInternos();
        }
        Serial.println("A1 llegó al piso llamado");
        analogWrite(motorCabinaA1, 0);  // Detiene la cabina
        visualizadorA1();
        abrirPuertasA1(); // Abre puertas
    } else if (pisoA1 > llamadoExt) {    // Si el ascensor está arriba
        Serial.println("A1 baja al piso llamado");
        bajandoA1();
        byte llamadoA1 = sensoresPisosA1[llamadoExt];
        while (digitalRead(llamadoA1)) {   // baja A1 al piso llamado
            analogWrite(motorCabinaA1, velocidadCabina);
            visualizadorA1();
            botonesExternos();
            botonesInternos();
        }
        Serial.println("A1 llegó al piso llamado");
        analogWrite(motorCabinaA1, 0);  // Detiene la cabina
        visualizadorA1();
        abrirPuertasA1(); // Abre puertas
    }
}

void mueveA2() {
    if (pisoA2 < llamadoExt) {   // Si el ascensor está abajo
        Serial.println("A2 sube al piso llamado");
        subiendoA2();
        byte llamadoA2 = sensoresPisosA2[llamadoExt];
        while (digitalRead(llamadoA2)) {   // sube A2 al piso llamado
            analogWrite(motorCabinaA2, velocidadCabina);
            visualizadorA2();
            botonesExternos();
            botonesInternos();
        }
        Serial.println("A2 llegó al piso llamado");
        analogWrite(motorCabinaA2, 0);  // Detiene la cabina
        visualizadorA2();
        abrirPuertasA2(); // Abre puertas
    } else if (pisoA2 > llamadoExt) {    // Si el ascensor está arriba
        Serial.println("A2 baja al piso llamado");
        bajandoA2();
        byte llamadoA2 = sensoresPisosA2[llamadoExt];
        while (digitalRead(llamadoA2)) {   // baja A2 al piso llamado
            analogWrite(motorCabinaA2, velocidadCabina);
            visualizadorA2();
            botonesExternos();
            botonesInternos();
        }
        Serial.println("A2 llegó al piso llamado");
        analogWrite(motorCabinaA2, 0);  // Detiene la cabina
        visualizadorA2();
        abrirPuertasA2(); // Abre puertas
    }
}

void botonesInternos() {
    Serial.println("Lectura de botones internos");
    for (int filaActiva = 0; filaActiva < cuentaFil; filaActiva++) {
        byte fila = filBotonesInt[filaActiva];
        pinMode(fila, OUTPUT);
        digitalWrite(fila, LOW);
        for (int colActiva = 0; colActiva < cuentaCol; colActiva++) {
            byte col = colBotones[colActiva];
            if (!digitalRead(col)) {
                Serial.println("Un botón interno fue presionado");
                botonIntPresionado(col, fila);
            }
        }
        pinMode(fila, INPUT);
    }
}

void botonIntPresionado(int col, int fila) {
    if (fila == fila4Botones && col == columna1Botones) {
        int ledPresionado = 5;
        Serial.println("Botón PH de A1");
        llamadoInternoA1(ledPresionado);
    }
    if (fila == fila4Botones && col == columna2Botones) {
        int ledPresionado = 4;
        Serial.println("Botón P4 de A1");
        llamadoInternoA1(ledPresionado);
    }
    if (fila == fila5Botones && col == columna1Botones) {
        int ledPresionado = 3;
        Serial.println("Botón P3 de A1");
        llamadoInternoA1(ledPresionado);
    }
    if (fila == fila5Botones && col == columna2Botones) {
        int ledPresionado = 2;
        Serial.println("Botón P2 de A1");
        llamadoInternoA1(ledPresionado);
    }
    if (fila == fila6Botones && col == columna1Botones) {
        int ledPresionado = 1;
        Serial.println("Botón P1 de A1");
        llamadoInternoA1(ledPresionado);
    }
    if (fila == fila6Botones && col == columna2Botones) {
        int ledPresionado = 0;
        Serial.println("Botón PB de A1");
        llamadoInternoA1(ledPresionado);
    }
    if (fila == fila4Botones && col == columna3Botones) {
        int ledPresionado = 5;
        Serial.println("Botón PH de A2");
        llamadoInternoA2(ledPresionado);
    }
    if (fila == fila4Botones && col == columna4Botones) {
        int ledPresionado = 4;
        Serial.println("Botón P4 de A2");
        llamadoInternoA2(ledPresionado);
    }
    if (fila == fila5Botones && col == columna3Botones) {
        int ledPresionado = 3;
        Serial.println("Botón P3 de A2");
        llamadoInternoA2(ledPresionado);
    }
    if (fila == fila5Botones && col == columna4Botones) {
        int ledPresionado = 2;
        Serial.println("Botón P2 de A2");
        llamadoInternoA2(ledPresionado);
    }
    if (fila == fila6Botones && col == columna3Botones) {
        int ledPresionado = 1;
        Serial.println("Botón P1 de A2");
        llamadoInternoA2(ledPresionado);
    }
    if (fila == fila6Botones && col == columna4Botones) {
        int ledPresionado = 0;
        Serial.println("Botón PB de A2");
        llamadoInternoA2(ledPresionado);
    }
}

void llamadoInternoA1(int ledPresionado) {
    byte pisoElegido = sensoresPisosA1[ledPresionado];
    byte led = ledsInternosA1[ledPresionado];
    if (!digitalRead(pisoElegido) && !digitalRead(sensorAperturaA1)) {
        Serial.println("A1 está en el piso del botón interno presionado");
    } else {
        Serial.println("Enciende el botón interno presionado");
        digitalWrite(led, HIGH);
    }
}

void llamadoInternoA2(int ledPresionado) {
    byte pisoElegido = sensoresPisosA2[ledPresionado];
    byte led = ledsInternosA2[ledPresionado];
    if (!digitalRead(pisoElegido) && !digitalRead(sensorAperturaA2)) {
        Serial.println("A2 está en el piso del botón interno presionado");
    } else {
        Serial.println("Enciende el botón interno presionado");
        digitalWrite(led, HIGH);
    }
}

void movimientoInt() {
    if ((millis() - tiempoEsperaA1) >= 5000) {     // Si A1 está disponible
        Serial.println("Lectura de botones internos encendidos de A1");
        movimientoIntA1();
    } else {
        Serial.println("El ascensor A1 está en espera. Función llamado interno A1 saltada");
    }
    if ((millis() - tiempoEsperaA2) >= 5000) {     // Si A2 está disponible
        Serial.println("Lectura de botones internos encendidos de A2");
        movimientoIntA2();
    } else {
        Serial.println("El ascensor A2 está en espera. Función llamado interno A2 saltada");
    }
}

void movimientoIntA1() {
    for (int ledLeido = 0; ledLeido < cuentaLed; ledLeido++) { // Bucle for para leer botones internos de A1
        byte led = ledsInternosA1[ledLeido];
        if (digitalRead(led)) {  // Si hay led encendido
            Serial.println("Botón interno de A1 encendido");
            botonIntA1Encendido(ledLeido, led);
            break;  // luego de atender un llamado interno de A1 sale de la lectura
        }
    }
}

void movimientoIntA2() {
    for (int ledLeido = 0; ledLeido < cuentaLed; ledLeido++) { // Bucle for para leer botones internos de A2
        byte led = ledsInternosA2[ledLeido];
        if (digitalRead(led)) {  // Si hay led encendido
            Serial.println("Botón interno de A2 encendido");
            botonIntA2Encendido(ledLeido, led);
            break;  // luego de atender un llamado interno de A1 sale de la lectura
        }
    }
}

void botonIntA1Encendido(int ledLeido, int led) {
    for (pisoA1 = 0; pisoA1 < cuentaSenPisos; pisoA1++) {
        byte piso = sensoresPisosA1[pisoA1];    
        if (!digitalRead(piso)) {   // Lee dónde está el ascensor
            break;  // Si encuentra el piso del ascensor sale del bucle for
        }
    }
    cerrarPuertasA1();
    if (ledLeido < pisoA1) {
        Serial.println("A1 baja al piso del botón interno presionado");
        bajandoA1();
        byte pisoElegido = sensoresPisosA1[ledLeido];
        while (digitalRead(pisoElegido)) {   // baja A1 al piso llamado
            analogWrite(motorCabinaA1, velocidadCabina);
            visualizadorA1();
            botonesExternos();
            botonesInternos();
            byte piso = sensoresPisosA1[pisoActA1];
            byte led = ledsInternosA1[pisoActA1];
            if (digitalRead(piso) && digitalRead(led)) {
                break;
            }
        }
        Serial.println("A1 llegó al piso del botón interno presionado");
        analogWrite(motorCabinaA1, 0);  // Detiene la cabina
        visualizadorA1();
        abrirPuertasA1(); // Abre puertas
        Serial.println("Apaga botón interno de A1");
        byte led = ledsInternosA1[pisoActA1];
        digitalWrite(led, LOW); // Al terminar de mover apaga el led
    } else {
        Serial.println("A1 sube al piso del botón interno presionado");
        subiendoA1();
        byte pisoElegido = sensoresPisosA1[ledLeido];
        while (digitalRead(pisoElegido)) {   // baja A1 al piso llamado
            analogWrite(motorCabinaA1, velocidadCabina);
            visualizadorA1();
            botonesExternos();
            botonesInternos();
            byte piso = sensoresPisosA1[pisoActA1];
            byte led = ledsInternosA1[pisoActA1];
            if (digitalRead(piso) && digitalRead(led)) {
                break;
            }
        }
        Serial.println("A1 llegó al piso del botón interno presionado");
        analogWrite(motorCabinaA1, 0);  // Detiene la cabina
        visualizadorA1();
        abrirPuertasA1(); // Abre puertas
        Serial.println("Apaga botón interno de A1");
        byte led = ledsInternosA1[pisoActA1];
        digitalWrite(led, LOW); // Al terminar de mover apaga el led
    }
    Serial.println("Finaliza la lectura de botones internos encendidos de A1");
}

void botonIntA2Encendido(int ledLeido, int led) {
    for (pisoA2 = 0; pisoA2 < cuentaSenPisos; pisoA2++) {
        byte piso = sensoresPisosA2[pisoA2];    
        if (!digitalRead(piso)) {   // Lee dónde está el ascensor
            break;  // Si encuentra el piso del ascensor sale del bucle for
        }
    }
    cerrarPuertasA2();
    if (ledLeido < pisoA2) {
        Serial.println("A2 baja al piso del botón interno presionado");
        bajandoA2();
        byte pisoElegido = sensoresPisosA2[ledLeido];
        while (digitalRead(pisoElegido)) {   // baja A2 al piso llamado
            analogWrite(motorCabinaA2, velocidadCabina);
            visualizadorA2();
            botonesExternos();
            botonesInternos();
            byte piso = sensoresPisosA2[pisoActA2];
            byte led = ledsInternosA2[pisoActA2];
            if (digitalRead(piso) && digitalRead(led)) {
                break;
            }
        }
        Serial.println("A2 llegó al piso del botón interno presionado");
        analogWrite(motorCabinaA2, 0);  // Detiene la cabina
        visualizadorA2();
        abrirPuertasA2(); // Abre puertas
        Serial.println("Apaga botón interno de A2");
        byte led = ledsInternosA2[pisoActA2];
        digitalWrite(led, LOW); // Al terminar de mover apaga el led
    } else {
        Serial.println("A2 sube al piso del botón interno presionado");
        subiendoA2();
        byte pisoElegido = sensoresPisosA2[ledLeido];
        while (digitalRead(pisoElegido)) {   // baja A2 al piso llamado
            analogWrite(motorCabinaA2, velocidadCabina);
            visualizadorA2();
            botonesExternos();
            botonesInternos();
            byte piso = sensoresPisosA2[pisoActA2];
            byte led = ledsInternosA2[pisoActA2];
            if (digitalRead(piso) && digitalRead(led)) {
                break;
            }
        }
        Serial.println("A2 llegó al piso del botón interno presionado");
        analogWrite(motorCabinaA2, 0);  // Detiene la cabina
        visualizadorA2();
        abrirPuertasA2(); // Abre puertas
        Serial.println("Apaga botón interno de A2");
        byte led = ledsInternosA2[pisoActA2];
        digitalWrite(led, LOW); // Al terminar de mover apaga el led
    }
    Serial.println("Finaliza la lectura de botones internos encendidos de A2");
}

void visualizadorA1() {
    for (pisoActA1 = 0; pisoActA1 < cuentaSenPisos; pisoActA1++) {
        byte piso = sensoresPisosA1[pisoActA1];    
        if (!digitalRead(piso)) {   // Lee dónde está el ascensor
            break;  // Si encuentra el piso del ascensor sale del bucle for
        }
    }
    if (pisoActA1 == 0) {
        Serial.println("A1 está en PB");
        digitalWrite(decoA1C, LOW); // Enciende led PB
        digitalWrite(decoA1B, LOW);
        digitalWrite(decoA1A, LOW);
    }
    if (pisoActA1 == 1) {
        Serial.println("A1 está en P1");
        digitalWrite(decoA1C, LOW); // Enciende led P1
        digitalWrite(decoA1B, LOW);
        digitalWrite(decoA1A, HIGH);
    }
    if (pisoActA1 == 2) {
        Serial.println("A1 está en P2");;
        digitalWrite(decoA1C, LOW); // Enciende led P2
        digitalWrite(decoA1B, HIGH);
        digitalWrite(decoA1A, LOW);
    }
    if (pisoActA1 == 3) {
        Serial.println("A1 está en P3");
        digitalWrite(decoA1C, LOW); // Enciende led P3
        digitalWrite(decoA1B, HIGH);
        digitalWrite(decoA1A, HIGH);
    }
    if (pisoActA1 == 4) {
        Serial.println("A1 está en P4");
        digitalWrite(decoA1C, HIGH); // Enciende led P4
        digitalWrite(decoA1B, LOW);
        digitalWrite(decoA1A, LOW);
    }
    if (pisoActA1 == 5) {
        Serial.println("A1 está en PH");
        digitalWrite(decoA1C, HIGH); // Enciende led PH
        digitalWrite(decoA1B, LOW);
        digitalWrite(decoA1A, HIGH);
    }
}

void visualizadorA2() {
    for (pisoActA2 = 0; pisoActA2 < cuentaSenPisos; pisoActA2++) {
        byte piso = sensoresPisosA2[pisoActA2];    
        if (!digitalRead(piso)) {   // Lee dónde está el ascensor
            break;  // Si encuentra el piso del ascensor sale del bucle for
        }
    }
    if (pisoActA2 == 0) {
        Serial.println("A2 está en PB");
        digitalWrite(decoA2C, LOW); // Enciende led PB
        digitalWrite(decoA2B, LOW);
        digitalWrite(decoA2A, LOW);
    }
    if (pisoActA2 == 1) {
        Serial.println("A2 está en P1");
        digitalWrite(decoA2C, LOW); // Enciende led P1
        digitalWrite(decoA2B, LOW);
        digitalWrite(decoA2A, HIGH);
    }
    if (pisoActA2 == 2) {
        Serial.println("A2 está en P2");
        digitalWrite(decoA2C, LOW); // Enciende led P2
        digitalWrite(decoA2B, HIGH);
        digitalWrite(decoA2A, LOW);
    }
    if (pisoActA2 == 3) {
        Serial.println("A2 está en P3");
        digitalWrite(decoA2C, LOW); // Enciende led P3
        digitalWrite(decoA2B, HIGH);
        digitalWrite(decoA2A, HIGH);
    }
    if (pisoActA2 == 4) {
        Serial.println("A2 está en P4");
        digitalWrite(decoA2C, HIGH); // Enciende led P4
        digitalWrite(decoA2B, LOW);
        digitalWrite(decoA2A, LOW);
    }
    if (pisoActA2 == 5) {
        Serial.println("A2 está en PH");
        digitalWrite(decoA2C, HIGH); // Enciende led PH
        digitalWrite(decoA2B, LOW);
        digitalWrite(decoA2A, HIGH);
    }
}
