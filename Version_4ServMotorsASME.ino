#include <Servo.h>
#include <EEPROM.h>

//CONSTANTES

int LEVEL_NOISE = 3;

int FACTOR_DELAY_MS = 30;

//ServoSG90 0-->180 = 180
//ServoASME 0-->300 = 300

int DEGRES_Servo = 300;


int ejectButton = 12;
int resetButton = 11;
int grabarButton = 10;
int LEDespacioEeprom = 9;
int LEDsinespacioEeprom = 8;

int Pin_0_19 = 0;
int Pin_20_39 = 1;
int Pin_40_59 = 6;
int Pin_60_79 = 7;

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

int VAR_0 = 0 ;
int VAR_1 = 0 ;
int VAR_2 = 0 ;
int VAR_3 = 0 ;

int lastVAR_0 = 0;
int lastVAR_1 = 0;
int lastVAR_2 = 0;
int lastVAR_3 = 0;

Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;

void setup() {
  

  servo0.attach(2);
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);

  pinMode(grabarButton, INPUT);
  pinMode(ejectButton, INPUT);
  pinMode(resetButton, INPUT);
  pinMode(LEDespacioEeprom, OUTPUT);
  pinMode(LEDsinespacioEeprom, OUTPUT);
  
  pinMode(Pin_0_19,INPUT);
  pinMode(Pin_20_39,INPUT);
  pinMode(Pin_40_59,INPUT);
  pinMode(Pin_60_79,INPUT);


  if (digitalRead(resetButton) == LOW ) {
    if (digitalRead(grabarButton) == LOW) {
      for (int addr = 0; addr < EEPROM.length(); addr++) {
        EEPROM.write(addr, 0);
        digitalWrite(LEDsinespacioEeprom,HIGH);
        delay(10);
        digitalWrite(LEDsinespacioEeprom,LOW);
        delay(10);
        
      }
    }
  }

  if (digitalRead(Pin_0_19) == LOW) {
    initAddrS0 = 0;
    addrS0 = initAddrS0;
    endAddrS0 = (initAddrS0 + MAXPOS) - 1;
    lastDatoS0 = 0;
    lastSaveAddrS0 = 900;
    
    initAddrS1 = 100;
    addrS1 = initAddrS1;
    endAddrS1 = (initAddrS1 + MAXPOS) - 1;
    lastDatoS1 = 0;
    lastSaveAddrS1 = 901;
    
    initAddrS2 = 200;
    addrS2 = initAddrS2;
    endAddrS2 = (initAddrS2 + MAXPOS) - 1;
    lastDatoS2 = 0;
    lastSaveAddrS2 = 902;

    initAddrS3 = 300;
    addrS3 = initAddrS3;
    endAddrS3 = (initAddrS3 + MAXPOS) - 1;
    lastDatoS3 = 0;
    lastSaveAddrS3 = 903;

  }
  if (digitalRead(Pin_20_39) == LOW) {
    initAddrS0 = 20;
    addrS0 = initAddrS0;
    endAddrS0 = (initAddrS0 + MAXPOS) - 1;
    lastDatoS0 = 0;
    lastSaveAddrS0 = 904;
    initAddrS1 = 120;
    addrS1 = initAddrS1;
    endAddrS1 = (initAddrS1 + MAXPOS) - 1;
    lastDatoS1 = 0;
    lastSaveAddrS1 = 905;
    initAddrS2 = 220;
    addrS2 = initAddrS2;
    endAddrS2 = (initAddrS2 + MAXPOS) - 1;
    lastDatoS2 = 0;
    lastSaveAddrS2 = 906;
    initAddrS3 = 320;
    addrS3 = initAddrS3;
    endAddrS3 = (initAddrS3 + MAXPOS) - 1;
    lastDatoS3 = 0;
    lastSaveAddrS3 = 907;
  }
  if (digitalRead(Pin_40_59) == LOW) {
    initAddrS0 = 40;
    addrS0 = initAddrS0;
    endAddrS0 = (initAddrS0 + MAXPOS) - 1;
    lastDatoS0 = 0;
    lastSaveAddrS0 = 908;
    initAddrS1 = 140;
    addrS1 = initAddrS1;
    endAddrS1 = (initAddrS1 + MAXPOS) - 1;
    lastDatoS1 = 0;
    lastSaveAddrS1 = 909;
    initAddrS2 = 240;
    addrS2 = initAddrS2;
    endAddrS2 = (initAddrS2 + MAXPOS) - 1;
    lastDatoS2 = 0;
    lastSaveAddrS2 = 910;
    initAddrS3 = 340;
    addrS3 = initAddrS3;
    endAddrS3 = (initAddrS3 + MAXPOS) - 1;
    lastDatoS3 = 0;
    lastSaveAddrS3 = 911;
  }
  if (digitalRead(Pin_60_79) == LOW) {
    initAddrS0 = 60;
    addrS0 = initAddrS0;
    endAddrS0 = (initAddrS0 + MAXPOS) - 1;
    lastDatoS0 = 0;
    lastSaveAddrS0 = 912;
    initAddrS1 = 160;
    addrS1 = initAddrS1;
    endAddrS1 = (initAddrS1 + MAXPOS) - 1;
    lastDatoS1 = 0;
    lastSaveAddrS1 = 913;
    initAddrS2 = 260;
    addrS2 = initAddrS2;
    endAddrS2 = (initAddrS2 + MAXPOS) - 1;
    lastDatoS2 = 0;
    lastSaveAddrS2 = 914;
    initAddrS3 = 360;
    addrS3 = initAddrS3;
    endAddrS3 = (initAddrS3 + MAXPOS) - 1;
    lastDatoS3 = 0;
    lastSaveAddrS3 = 915;
  }
}

void loop() {
  if (digitalRead(resetButton) == LOW) {
    digitalWrite(LEDespacioEeprom, HIGH);
    //Borrando Region definida por el selector para el Servo0
    for (int addr = initAddrS0; addr <= endAddrS0; addr++) {
      EEPROM.write(addr, 0);
    }
    //Borrando Region definida por el selector para el Servo0
    for (int addr = initAddrS1; addr <= endAddrS1; addr++) {
      EEPROM.write(addr, 0);
    }
    //Borrando Region definida por el selector para el Servo0
    for (int addr = initAddrS2; addr <= endAddrS2; addr++) {
      EEPROM.write(addr, 0);
    }
    //Borrando Region definida por el selector para el Servo0
    for (int addr = initAddrS3; addr <= endAddrS3; addr++) {
      EEPROM.write(addr, 0);
    }
    EEPROM.write(lastSaveAddrS0,0);
    EEPROM.write(lastSaveAddrS1,0);
    EEPROM.write(lastSaveAddrS2,0);
    EEPROM.write(lastSaveAddrS3,0);
    
    digitalWrite(LEDespacioEeprom, LOW);
    addrS0 = initAddrS0;
    addrS1 = initAddrS1;
    addrS2 = initAddrS2;
    addrS3 = initAddrS3;
  }

  if (digitalRead(grabarButton) == LOW) {
    GrabaServo(servo0, A0, 0);
    GrabaServo(servo1, A1, 1);
    GrabaServo(servo2, A2, 2);
    GrabaServo(servo3, A3, 3);
  }
  if (digitalRead(ejectButton) == LOW) {

    for (int i = 0; i < MAXPOS; i++) {
      EjecutaServo(servo0, 0, i);
      EjecutaServo(servo1, 1, i);
      EjecutaServo(servo2, 2, i);
      EjecutaServo(servo3, 3, i);
    }
  }


  if (digitalRead(ejectButton) == HIGH) {
    delay(50);
    VAR_0 = map ( analogRead(A0) , 0 , 1023 , 0 , DEGRES_Servo ) ;
    if (abs(VAR_0 - lastVAR_0) > LEVEL_NOISE) {
      lastVAR_0 = VAR_0;
      servo0.write( VAR_0 );
    }
    VAR_1 = map ( analogRead(A1) , 0 , 1023 , 0 , DEGRES_Servo ) ;
    if (abs(VAR_1 - lastVAR_1) > LEVEL_NOISE) {
      lastVAR_1 = VAR_1;
      servo1.write( VAR_1 );
    }
    VAR_2 = map ( analogRead(A2) , 0 , 1023 , 0 , DEGRES_Servo ) ;
    if (abs(VAR_2 - lastVAR_2) > LEVEL_NOISE) {
      lastVAR_2 = VAR_2;
      servo2.write( VAR_2 );
    }
    VAR_3 = map ( analogRead(A3) , 0 , 1023 , 0 , DEGRES_Servo ) ;
    if (abs(VAR_3 - lastVAR_3) > LEVEL_NOISE) {
      lastVAR_3 = VAR_3;
      servo3.write( VAR_3 );
    }
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
        endAddr = endAddrS0;
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
  }
  // Verificar si hay espacio para grabar pasos
  if ((EEPROM.read(lastSaveAddr) + initAddr) != endAddr) {
    int dato = analogRead(analogPin);
    if (dato < 0) {
      dato = 0;
    }
    if (dato > 1023) {
      dato = 1023;
    }
    dato = map(dato, 0, 1023, 0, DEGRES_Servo);
    lastDato =  dato;

    EEPROM.write(addr, dato);
    EEPROM.write(lastSaveAddr, addr - initAddr);
    addr++;
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
    }
    digitalWrite(LEDespacioEeprom, HIGH);
    delay(250);
    digitalWrite(LEDespacioEeprom, LOW);
    delay(250);
  } else {
    digitalWrite(LEDsinespacioEeprom, HIGH);
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
        initAddr = initAddrS0;
        endAddr = endAddrS0;
        lastSaveAddr = lastSaveAddrS0;
        lastDato = lastDatoS0;
      } break;
    case 1: {
        initAddr = initAddrS1;
        endAddr = endAddrS1;
        lastSaveAddr = lastSaveAddrS1;
        lastDato = lastDatoS1;
      } break;
    case 2: {
        initAddr = initAddrS2;
        endAddr = endAddrS2;
        lastSaveAddr = lastSaveAddrS2;
        lastDato = lastDatoS2;
      } break;
    case 3: {
        initAddr = initAddrS3;
        endAddr = endAddrS3;
        lastSaveAddr = lastSaveAddrS3;
        lastDato = lastDatoS3;
      } break;
  }


  if (EEPROM.read(lastSaveAddr) != 0) {

    addr = initAddr;
    addr = addr + numStep;
    int dato = EEPROM.read(addr);

    int aux = 0;
    if (addr == initAddr) {
      aux = dato;
    } else {
      aux = EEPROM.read((addr - 1));
    }
    EjecutarPosicion(servoX , aux, dato);
    lastDato =  dato;
  } else {
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
