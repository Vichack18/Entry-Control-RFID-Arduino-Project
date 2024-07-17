#include <MFRC522.h>
#include <SPI.h>

#define RST_PIN 9 // pin reset en el pin numero 9 //
#define SS_PIN 10 // donde lo conectamos //

MFRC522 mfrc522 (SS_PIN, RST_PIN);

byte LecturaUID[4];

boolean estadov=false;
boolean estador=false:
boolean estadoa=false;

int ledv=4;
int ledr=2;
int leda=3;
int buzzer =5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  SPI.begin ();
  mfrc522.PCD_Init();
  Serial.println("Ingrese tarjeta");
  pinMode (ledv , OUTPUT);
  pinMode (ledr , OUTPUT);
  pinMode (leda , OUTPUT);
  pinMode (buzzer , OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    if (! mfrc522.PICC_IsNewCardPresent()){  // si lee una tarjeta, nos va a dar un valor verdadero, si no, seguira return hasta que si sea //
      return;
    }
    if (! mfrc522.PICC_ReadCardSerial()){
      return;
    }

    Serial.print("UID:  ");

    for(byte i=0; i<mfrc522.uid.size; i++){
      if (mfrc522.uid.uidByte[i]<0x10){
        Serial.print(" 0");
      }
      else {
        Serial.print(" ");
      }
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      LecturaUID[i]= mfrc522.uid.uidByte[i];
    }

    Serial.println("");
    delay(1000); // lee cada un segundo los datos de una tarjeta que se apoye //
}
