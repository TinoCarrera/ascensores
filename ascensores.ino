// estableciendo pines a los periféricos
// 2 sensores de nivel
const int sensorPBA1 = 28;		    // sensor de ubicación PB A1
const int sensorPBA2 = 29;           // sensor de ubicación PB A2
// 6 sensores de puertas
const int sensorCierreA1 = 24;       // sensor de cierre de puertas A1
const int sensorAperturaA1 = 22;     // sensor de la apertura de puertas A1
const int sensorObstA1 = 26;		    // sensor de obstáculos de puertas A1
const int sensorCierreA2 = 25;       // sensor de cierre de puertas A2
const int sensorAperturaA2 = 23;     // sensor de la apertura de puertas A2
const int sensorObstA2 = 27;	        // sensor de obstáculos de puertas A2
// 4 motores
const int motorPuertasA1 = 11;	    // pin de velocidad de motor de Puertas A1
const int motorCabinaA1 = 13;		// pin de velocidad de motor de cabina A1
const int motorPuertasA2 = 10;	    // pin de velocidad de motor de Puertas A2
const int motorCabinaA2 = 12;		// pin de velocidad de motor de cabina A2
// 3 salidas al Decodificador
const int DecoDir1 = 14;              // pin A0 del Decodificador/Demultiplexor
const int DecoDir2 = 15;              // pin A1 del Decodificador/Demultiplexor
const int DecoDir3 = 16;              // pin A2 del Decodificador/Demultiplexor
// Matriz de botones 3x4
// 10 Botones Externos
const int fila1Botones = 60;         //  PHBa, P4Su, P4Ba, P3Su 
const int fila2Botones = 61;         //  P3Ba, P2Su, P2Ba, P1Su
const int fila3Botones = 62;         //  P1Ba, PBSu, NADA, NADA
const int columna1Botones = 66;          
const int columna2Botones = 67;
const int columna3Botones = 68;
const int columna4Botones = 69;
// 10 Leds externos
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

// declarando variables
int inicio = true;     // al iniciar el controlador reinicio = 1
int velocidadPuertas = 127;         // velocidad del motor de puertas
int velocidadCabina = 255;          // velocidad de motor de cabina
int delayInicio = 3000;
unsigned long tiempoEsperaA1;   // tiempo de espera para cerrar puertas A1
unsigned long tiempoEsperaA2;   // tiempo de espera para cerrar puertas A2

// Arreglo para sensores
byte sensoresPisosA1[] = {sensorPBA1};
byte sensoresPuertasA1[] = {sensorCierreA1, sensorAperturaA1, sensorObstA1};
byte sensoresPisosA2[] = {sensorPBA2};
byte sensoresPuertasA2[] = {sensorCierreA2, sensorAperturaA2, sensorObstA2};
const int cuentaSenPisos = sizeof(sensoresPisosA1);
const int cuentaSenPuertas = sizeof(sensoresPuertasA1);

// Arreglo para motores
byte pinesMotores[] = {motorPuertasA1, motorPuertasA2, motorCabinaA1, motorCabinaA2, DecoDir1, DecoDir2, DecoDir3};
const int cuentaPinMotor = sizeof(pinesMotores);

// Arreglo para matriz de botones
byte filBotonesExt[] = {fila1Botones, fila2Botones, fila3Botones};
byte colBotonesExt[] = {columna1Botones, columna2Botones, columna3Botones, columna4Botones};
const int cuentaFil = sizeof(filBotonesExt);
const int cuentaCol = sizeof(colBotonesExt);

// Arreglo para ledsExternos
byte ledsExternos[] = {ledPHBa, ledP4Su, ledP4Ba, ledP3Su, ledP3Ba, ledP2Su, ledP2Ba, ledP1Su, ledP1Ba, ledPBSu};
const int cuentaLedExt = sizeof(ledsExternos);

void setup() {  // estableciendo entradas y salidas   
    
    for (int x = 0; x < cuentaSenPisos; x++) {
        pinMode(sensoresPisosA1[x], INPUT_PULLUP);
    }
    for (int x = 0; x < cuentaSenPisos; x++) {
        pinMode(sensoresPisosA2[x], INPUT_PULLUP);
    }
    for (int x = 0; x < cuentaSenPuertas; x++) {
        pinMode(sensoresPuertasA1[x], INPUT_PULLUP);
    }
    for (int x = 0; x < cuentaSenPuertas; x++) {
        pinMode(sensoresPuertasA2[x], INPUT_PULLUP);
    }
    for (int x = 0; x < cuentaPinMotor; x++) {
        pinMode(pinesMotores[x], OUTPUT);
    }
    for (int x = 0; x < cuentaFil; x++) {
        pinMode(filBotonesExt[x], INPUT);
    }
    for (int x = 0; x < cuentaCol; x++) {
        pinMode(colBotonesExt[x], INPUT_PULLUP);
    }
    for (int x = 0; x < cuentaLedExt; x++) {
        pinMode(ledsExternos[x], OUTPUT);
    }
    Serial.begin(9600);
}

void loop() {   // bucle

    Serial.println("Inicia Arduino");
    if (inicio) {     // si el controlador se acaba de iniciar
        delay(delayInicio);
        Serial.println("Inicia Prevencion");
        prevencion();
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
}

void prevencion() {

    Serial.println("Inicia prevencion 1");
    prevencionA1();
    Serial.println("Inicia prevencion 2");
    prevencionA2();
}

void prevencionA1() {

    Serial.println("El ascensor 1 esta en PB?");
    if (digitalRead(sensorPBA1)) {  // si ascensor no está en PB

        Serial.println("No esta en PB");
        Serial.println("Las puertas de A1 estan abiertas?");
        if (!digitalRead(sensorAperturaA1)) {   // si las puertas están abiertas
            Serial.println("Si, estan abiertas, inicia cerrar puertas");
            cerrarPuertasA1();  // cerrar puertas
        }
        Serial.println("Va hacia funcion de bajar ascensor a PB");
        bajarPBA1();    // bajar ascensor 1 a PB
        Serial.println("Va hacia la funcion de abrir puertas A1");
        abrirPuertasA1();

    } else {    // si el ascensor está en PB
        Serial.println("El ascensor esta en PB");
        if (!digitalRead(sensorCierreA1)) { // si las puertas están cerradas
            Serial.println("Va hacia funcion abrir puertas");
            abrirPuertasA1();
        }
    }
}

void prevencionA2() {

    if (digitalRead(sensorPBA2)) {  // si ascensor no está en PB

        if (!digitalRead(sensorAperturaA2)) {   // si las puertas están abiertas
            cerrarPuertasA2();  // cerrar puertas
        }
        bajarPBA2();    // bajar ascensor 2 a PB
        abrirPuertasA2();

    } else {    // si el ascensor está en PB

        if (!digitalRead(sensorCierreA2)) { // si las puertas están cerradas
            abrirPuertasA2();
        }
    }
}

void cerrarPuertasA1() {
    Serial.println("Inicia funcion de cerrar puertas");
    while (digitalRead(sensorCierreA1)) {   // si las puertas no estan cerradas
        Serial.println("Establece sentido de giro");
        digitalWrite(DecoDir1, HIGH);    // direccion derecha para cerrar
        digitalWrite(DecoDir2, LOW);
        digitalWrite(DecoDir3, HIGH);
        Serial.println("Arranca motor puertas 1");
        analogWrite(motorPuertasA1, velocidadPuertas);  // cierra puertas
        Serial.println("Hay obstaculos?");
        verificarPuertasA1();
    }
    analogWrite(motorPuertasA1, 0); // detiene puertas
}

void cerrarPuertasA2() {

    while (digitalRead(sensorCierreA2)) {  // si las puertas no estan cerradas
        digitalWrite(DecoDir1, HIGH);    // direccion derecha para cerrar
        digitalWrite(DecoDir2, HIGH);
        digitalWrite(DecoDir3, HIGH);
        analogWrite(motorPuertasA2, velocidadPuertas);  // cierra puertas
        verificarPuertasA2();
    }
    analogWrite(motorPuertasA2, 0); // detiene puertas
}

void verificarPuertasA1() {

    if (!digitalRead(sensorObstA1)) {   // si hay un obstáculo
        Serial.println("Hay un obstaculo, deten el motor de puertas de a1");
        analogWrite(motorPuertasA1, 0); // detiene puertas
        Serial.println("Va hacia la funcion de abrir puertas");
        abrirPuertasA1();
    }
}

void verificarPuertasA2() {

    if (!digitalRead(sensorObstA2)) {   // si hay un obstáculo
        analogWrite(motorPuertasA2, 0); // detiene puertas
        abrirPuertasA2();
    }
}

void abrirPuertasA1() {

    Serial.println("Establece sentido de giro abriendo puertas");
    digitalWrite(DecoDir1, HIGH);    // dirección izquierda para abrir
    digitalWrite(DecoDir2, LOW);
    digitalWrite(DecoDir3, LOW);

    while (digitalRead(sensorAperturaA1)) {    // entra en bucle hasta abrir las puertas
        Serial.println("Acciona puertas abriendo");
        analogWrite(motorPuertasA1, velocidadPuertas);  // abre puertas
    } 
    analogWrite(motorPuertasA1, 0); // detiene puertas
    Serial.println("Deten motores de puerta a1 al llegar al final del recorrido");
    tiempoEsperaA1 = millis();
}

void abrirPuertasA2() {

    while (digitalRead(sensorAperturaA2)) {    // entra en bucle hasta abrir las puertas
        digitalWrite(DecoDir1, HIGH);    // dirección izquierda para abrir
        digitalWrite(DecoDir2, HIGH);
        digitalWrite(DecoDir3, LOW);
        analogWrite(motorPuertasA2, velocidadPuertas);  // abre puertas
    }
    analogWrite(motorPuertasA2, 0); // detiene puertas
    tiempoEsperaA2 = millis();
}

void bajarPBA1() {
    bajandoA1();
    while (digitalRead(sensorPBA1)) {   // si el ascensor no ha llegado a PB
        Serial.println("Acciona motor de cabina A1");
        analogWrite(motorCabinaA1, velocidadCabina);    // baja cabina
    }
    Serial.println("Detiene motor de cabina A1");
    analogWrite(motorCabinaA1, 0);  // detiene cabina
}

void bajarPBA2() {

    while (digitalRead(sensorPBA2)) {   // si el ascensor no ha llegado a PB
        bajandoA2();
        analogWrite(motorCabinaA2, velocidadCabina);    // baja cabina
    }
    analogWrite(motorCabinaA2, 0);  // detiene cabina
}

void bajandoA1() {

    Serial.println("Establecer sentido de giro para bajar ascensor");
    digitalWrite(DecoDir1, LOW); // direccion derecha para bajar A1
    digitalWrite(DecoDir2, LOW);
    digitalWrite(DecoDir3, HIGH);
}

void subiendoA1() {

    digitalWrite(DecoDir1, LOW); // direccion izquierda para subir A1
    digitalWrite(DecoDir2, LOW);
    digitalWrite(DecoDir3, LOW);
}

void bajandoA2() {

    digitalWrite(DecoDir1, LOW); // direccion derecha para bajar A2
    digitalWrite(DecoDir2, HIGH);
    digitalWrite(DecoDir3, HIGH);
}

void subiendoA2() {

    digitalWrite(DecoDir1, LOW); // direccion izquierda para subir A2
    digitalWrite(DecoDir2, HIGH);
    digitalWrite(DecoDir3, LOW);
}

void botonesExternos() {

    for (int filaActiva = 0; filaActiva < cuentaFil; filaActiva++) {
        byte fila = filBotonesExt[filaActiva];
        pinMode(fila, OUTPUT);
        digitalWrite(fila, LOW);
        for (int colActiva = 0; colActiva < cuentaCol; colActiva++) {
            byte col = colBotonesExt[colActiva];
            if (!digitalRead(col)) {
                botonPresionado(col, fila);
            }
        }
        pinMode(fila, INPUT);
    }
}

void botonPresionado(int col, int fila) {

    if (fila == fila1Botones && col == columna1Botones) {
        llamadoPHBa();
    }
    if (fila == fila1Botones && col == columna2Botones) {
        llamadoP4Su();
    }
    if (fila == fila1Botones && col == columna3Botones) {
        llamadoP4Ba();
    }
    if (fila == fila1Botones && col == columna4Botones) {
        llamadoP3Su();
    }
    if (fila == fila2Botones && col == columna1Botones) {
        llamadoP3Ba();
    }
    if (fila == fila2Botones && col == columna2Botones) {
        llamadoP2Su();
    }
    if (fila == fila2Botones && col == columna3Botones) {
        llamadoP2Ba();
    }
    if (fila == fila2Botones && col == columna4Botones) {
        llamadoP1Su();
    }
    if (fila == fila3Botones && col == columna1Botones) {
        llamadoP1Ba();
    }
    if (fila == fila3Botones && col == columna2Botones) {
        llamadoPBSu();
    }
}

void llamadoPHBa() {

    digitalWrite(ledPHBa, HIGH); 
}

void llamadoP4Su() {

    digitalWrite(ledP4Su, HIGH);
}

void llamadoP4Ba() {

    digitalWrite(ledP4Ba, HIGH);
}

void llamadoP3Su() {

    digitalWrite(ledP3Su, HIGH);
}

void llamadoP3Ba() {

    digitalWrite(ledP3Ba, HIGH);
}

void llamadoP2Su() {

    digitalWrite(ledP2Su, HIGH);
}

void llamadoP2Ba() {

    digitalWrite(ledP2Ba, HIGH);
}

void llamadoP1Su() {
 
    digitalWrite(ledP1Su, HIGH);
    
}

void llamadoP1Ba() {

    digitalWrite(ledP1Ba, HIGH);
    
}

void llamadoPBSu() {

    if (!digitalRead(sensorPBA1)) { // si el ascensor 1 está en PB abre puertas
        abrirPuertasA1();
    } else if (!digitalRead(sensorPBA2)) {  // sino, si el ascensor 2 está en PB abre puertas
        abrirPuertasA2();
    } else {    // sino enciende led
        digitalWrite(ledPBSu, HIGH);
    }
}
