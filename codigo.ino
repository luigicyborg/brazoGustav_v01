#include <Servo.h>
#include <EEPROM.h>

int LEVEL_NOISE = 0;

int FACTOR_DELAY_MS = 10;


int ejectButton = 12;
int resetButton = 11;
int grabarButton = 10;
int espacioEeprom = 8;
int sinEspacioEeprom = 9;


int MAXPOS = 20;

int initAddrS0 = 0;
int addrS0 = initAddrS0;
int endAddrS0 = (initAddrS0 + MAXPOS) - 1;
int lastDatoS0 = 0;
int lastSaveAddrS0 = 900;

int initAddrS1 = 100;
int addrS1 = initAddrS1;
int endAddrS1 = (initAddrS1 + MAXPOS) - 1;
int lastDatoS1 = 0;
int lastSaveAddrS1 = 901;

int initAddrS2 = 200;
int addrS2 = initAddrS2;
int endAddrS2 = (initAddrS2 + MAXPOS) - 1;
int lastDatoS2 = 0;
int lastSaveAddrS2 = 902;

int initAddrS3 = 300;
int addrS3 = initAddrS3;
int endAddrS3 = (initAddrS3 + MAXPOS) - 1;
int lastDatoS3 = 0;
int lastSaveAddrS3 = 903;

int initAddrS4 = 400;
int addrS4 = initAddrS4;
int endAddrS4 = (initAddrS4 + MAXPOS) - 1;
int lastDatoS4 = 0;
int lastSaveAddrS4 = 904;


int initAddrS5 = 500;
int addrS5 = initAddrS5;
int endAddrS5 = (initAddrS5 + MAXPOS) - 1;
int lastDatoS5 = 0;
int lastSaveAddrS5 = 905;

int VAR_0 = 0 ;
int VAR_1 = 0 ;
int VAR_2 = 0 ;
int VAR_3 = 0 ;
int VAR_4 = 0 ;
int VAR_5 = 0 ;

int lastVAR_0 = 0;
int lastVAR_1 = 0;
int lastVAR_2 = 0;
int lastVAR_3 = 0;
int lastVAR_4 = 0;
int lastVAR_5 = 0;

Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;


void setup() {



  Serial.begin(9600);

  servo0.attach(2);
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(6);
  servo5.attach(7);

  pinMode(grabarButton, INPUT);
  pinMode(ejectButton, INPUT);
  pinMode(resetButton, INPUT);
  pinMode(espacioEeprom, OUTPUT);
  pinMode(sinEspacioEeprom, OUTPUT);

}

void loop() {


  if (digitalRead(resetButton) == LOW) {
    Serial.println("Borrando EEPROM, espere...");
    for (int addr = 0; addr < EEPROM.length(); addr++) {
      digitalWrite(espacioEeprom,HIGH);
      EEPROM.write(addr, 0);
    }
    digitalWrite(espacioEeprom,LOW);
    addrS0 = initAddrS0;
    addrS1 = initAddrS1;
    addrS2 = initAddrS2;
    addrS3 = initAddrS3;
    addrS4 = initAddrS4;
    addrS5 = initAddrS5;
    Serial.println("EEPROM borrada");
  }

  if (digitalRead(grabarButton) == LOW) {
    delay(100);
    GrabaServo(servo0, A0, 0);
    GrabaServo(servo1, A1, 1);
    GrabaServo(servo2, A2, 2);
    GrabaServo(servo3, A3, 3);
    GrabaServo(servo4, A4, 4);
    GrabaServo(servo5, A5, 5);
  }
  if (digitalRead(ejectButton) == LOW) {

    for (int i = 0; i < MAXPOS; i++) {
      EjecutaServo(servo0, 0, i);
      EjecutaServo(servo1, 1, i);
      EjecutaServo(servo2, 2, i);
      EjecutaServo(servo3, 3, i);
      EjecutaServo(servo4, 4, i);
      EjecutaServo(servo5, 5, i);
    }
  }


  if (digitalRead(ejectButton) == HIGH) {
    delay(50);
    VAR_0 = map ( analogRead(A0) , 0 , 1023 , 0 , 180 ) ;
    if (abs(VAR_0 - lastVAR_0) > LEVEL_NOISE) {
      lastVAR_0 = VAR_0;
      servo0.write( VAR_0 );
    }
    VAR_1 = map ( analogRead(A1) , 0 , 1023 , 0 , 180 ) ;
    if (abs(VAR_1 - lastVAR_1) > LEVEL_NOISE) {
      lastVAR_1 = VAR_1;
      servo1.write( VAR_1 );
    }
    VAR_2 = map ( analogRead(A2) , 0 , 1023 , 0 , 180 ) ;
    if (abs(VAR_2 - lastVAR_2) > LEVEL_NOISE) {
      lastVAR_2 = VAR_2;
      servo2.write( VAR_2 );
    }
    VAR_3 = map ( analogRead(A3) , 0 , 1023 , 0 , 180 ) ;
    if (abs(VAR_3 - lastVAR_3) > LEVEL_NOISE) {
      lastVAR_3 = VAR_3;
      servo3.write( VAR_3 );
    }
    VAR_4 = map ( analogRead(A4) , 0 , 1023 , 0 , 180 ) ;
    if (abs(VAR_4 - lastVAR_4) > LEVEL_NOISE) {
      lastVAR_4 = VAR_4;
      servo4.write( VAR_4 );
    }
    VAR_5 = map ( analogRead(A5) , 0 , 1023 , 0 , 180 ) ;
    if (abs(VAR_5 - lastVAR_5) > LEVEL_NOISE) {
      lastVAR_5 = VAR_5;
      servo5.write( VAR_5 );
    }

  }

  if (Serial.available()) {

    Serial.println("0......");
    Serial.println(EEPROM.read(0));
    Serial.println(EEPROM.read(1));
    Serial.println(EEPROM.read(2));
    Serial.println(EEPROM.read(3));
    Serial.println(EEPROM.read(4));

    Serial.println("100......");
    Serial.println(EEPROM.read(100));
    Serial.println(EEPROM.read(101));
    Serial.println(EEPROM.read(102));
    Serial.println(EEPROM.read(103));
    Serial.println(EEPROM.read(104));

    Serial.println("200......");
    Serial.println(EEPROM.read(200));
    Serial.println(EEPROM.read(201));
    Serial.println(EEPROM.read(202));
    Serial.println(EEPROM.read(203));
    Serial.println(EEPROM.read(204));

    Serial.println("300......");
    Serial.println(EEPROM.read(300));
    Serial.println(EEPROM.read(301));
    Serial.println(EEPROM.read(302));
    Serial.println(EEPROM.read(303));
    Serial.println(EEPROM.read(304));

    Serial.println("400......");
    Serial.println(EEPROM.read(400));
    Serial.println(EEPROM.read(401));
    Serial.println(EEPROM.read(402));
    Serial.println(EEPROM.read(403));
    Serial.println(EEPROM.read(404));
    Serial.println("500......");
    Serial.println(EEPROM.read(500));
    Serial.println(EEPROM.read(501));
    Serial.println(EEPROM.read(502));
    Serial.println(EEPROM.read(503));
    Serial.println(EEPROM.read(504));

    Serial.println("900.......");
    Serial.println(EEPROM.read(900));
    Serial.println(EEPROM.read(901));
    Serial.println(EEPROM.read(902));
    Serial.println(EEPROM.read(903));
    Serial.println(EEPROM.read(904));
    Serial.println(EEPROM.read(905));
    Serial.println(EEPROM.read(906));
  }

}

void GrabaServo(Servo servoX, int analogPin, int NumServo) {

  int addr = 0;
  int endAddr = 0;
  int initAddr = 0;
  int lastSaveAddr = 0;
  int lastDato = 0;

  switch (NumServo) {
    case 0: {
        addr = addrS0;
        initAddr = initAddrS0;
        endAddr = endAddrS3;
        lastSaveAddr = lastSaveAddrS0;
        lastDato = lastDatoS0;
      } break;
    case 1: {
        addr = addrS1;
        initAddr = initAddrS1;
        endAddr = endAddrS1;
        lastSaveAddr = lastSaveAddrS1;
        lastDato = lastDatoS1;
      } break;
    case 2: {
        addr = addrS2;
        initAddr = initAddrS2;
        endAddr = endAddrS2;
        lastSaveAddr = lastSaveAddrS2;
        lastDato = lastDatoS2;
      } break;
    case 3: {
        addr = addrS3;
        initAddr = initAddrS3;
        endAddr = endAddrS3;
        lastSaveAddr = lastSaveAddrS3;
        lastDato = lastDatoS3;
      } break;
    case 4: {
        addr = addrS4;
        initAddr = initAddrS4;
        endAddr = endAddrS4;
        lastSaveAddr = lastSaveAddrS4;
        lastDato = lastDatoS4;
      } break;
    case 5: {
        addr = addrS5;
        initAddr = initAddrS5;
        endAddr = endAddrS5;
        lastSaveAddr = lastSaveAddrS5;
        lastDato = lastDatoS5;
      } break;

  }

  // Verificar si hay espacio para grabar pasos
  if ((EEPROM.read(lastSaveAddr) + initAddr) != endAddr) {

    Serial.println("Grabando Posicion");
    digitalWrite(sinEspacioEeprom, HIGH);
    delay(250);
    digitalWrite(sinEspacioEeprom, LOW);
    delay(250);

    int dato = analogRead(analogPin);
    if (dato < 0) {
      dato = 0;
    }
    if (dato > 1023) {
      dato = 1023;
    }
    dato = map(dato, 0, 1023, 0, 180);
    lastDato =  dato;
    Serial.print("last dato: ");
    Serial.println(lastDato);

    Serial.print("Valor para grabar");
    Serial.println(dato);
    EEPROM.write(addr, dato);
    EEPROM.write(lastSaveAddr, addr - initAddr);
    addr++;
    digitalWrite(13, LOW);
    Serial.print("GRABADO!...");
    delay(50);

    switch (NumServo) {
      case 0: {
          addrS0 = addr;
          lastDatoS0 = lastDato;
        } break;
      case 1: {
          addrS1 = addr;
          lastDatoS1 = lastDato;
        } break;
      case 2: {
          addrS2 = addr;
          lastDatoS2 = lastDato;
        } break;
      case 3: {
          addrS3 = addr;
          lastDatoS3 = lastDato;
        } break;
      case 4: {
          addrS4 = addr;
          lastDatoS4 = lastDato;
        } break;
      case 5: {
          addrS5 = addr;
          lastDatoS5 = lastDato;
        } break;

    }
    digitalWrite(sinEspacioEeprom, LOW);
 

  } else {
    Serial.print("SIN ESPACIO... o SIN GRABAR");
    digitalWrite(espacioEeprom, HIGH);
    delay(500);
  }


}

void EjecutaServo(Servo servoX, int NumServo, int numStep) {
  int addr = 0;
  int endAddr = 0;
  int initAddr = 0;
  int lastSaveAddr = 0;
  int lastDato = 0;
  switch (NumServo) {
    case 0: {
        Serial.println("Servo 0");
        initAddr = initAddrS0;
        endAddr = endAddrS0;
        lastSaveAddr = lastSaveAddrS0;
        lastDato = lastDatoS0;
      } break;
    case 1: {
        Serial.println("Servo 1");
        initAddr = initAddrS1;
        endAddr = endAddrS1;
        lastSaveAddr = lastSaveAddrS1;
        lastDato = lastDatoS1;
      } break;
    case 2: {
        Serial.println("Servo 2");
        initAddr = initAddrS2;
        endAddr = endAddrS2;
        lastSaveAddr = lastSaveAddrS2;
        lastDato = lastDatoS2;
      } break;
    case 3: {
        Serial.println("Servo 3");
        initAddr = initAddrS3;
        endAddr = endAddrS3;
        lastSaveAddr = lastSaveAddrS3;
        lastDato = lastDatoS3;
      } break;
    case 4: {
        Serial.println("Servo 4");
        initAddr = initAddrS4;
        endAddr = endAddrS4;
        lastSaveAddr = lastSaveAddrS4;
        lastDato = lastDatoS4;
      } break;
    case 5: {
        Serial.println("Servo 5");
        initAddr = initAddrS5;
        endAddr = endAddrS5;
        lastSaveAddr = lastSaveAddrS5;
        lastDato = lastDatoS5;
      } break;

  }


  if (EEPROM.read(lastSaveAddr) != 0) {
    Serial.println("Ëjecutando Posicion");

    addr = initAddr;
    addr = addr + numStep;
    //Serial.println("numStep:");
    //Serial.println(addr);
    //for (addr; addr <= endAddr; addr++ ) {
    int dato = EEPROM.read(addr);

    Serial.print("Valor Leido");
    Serial.println(dato);
    int aux = 0;
    if (addr == initAddr) {
      Serial.print("Primera Vez");
      aux = dato;
    } else {
      aux = EEPROM.read((addr - 1));
    }
    Serial.println("AUX:");
    Serial.println(aux);
    Serial.println("DATO:");
    Serial.println(dato);
    EjecutarPosicion(servoX , aux, dato);
    //servoX.write(dato);    delay(500);

    lastDato =  dato;

    //}
    Serial.println(" y TERMINA");
  } else {
    Serial.println(" NO EXISTEN POSICIONES Q EJECUTAR");
    delay(1000);
  }
}

void EjecutarPosicion(Servo servoX, int posA, int posB) {

  if (posA < posB) {
    for (int i = posA; i <= posB; i++) {
      delay(FACTOR_DELAY_MS);
      servoX.write(i);
    }
  } else if (posA > posB) {
    for (int i = posA; i >= posB; i--) {
      delay(FACTOR_DELAY_MS);
      servoX.write(i);
    }
  }
}
