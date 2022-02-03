#include <Servo.h> // Benötigte Servo Bibliothek 


Servo Horizontal;//Dimensionierung des Horizontalen Servos
int hori = 90; //Standard Position des Hori Servos

int Hori_Limit_Links = 180; //Linkes Bewegungs Limit des Hori Servos
int Hori_Limit_Rechts = 65; //Rechts Bewegungs Limit des Hori Servos

Servo Vertikal;//Dimensionierung des Vertikalen Servos
int verti = 90; //Standard Position des Verti Servos

int Verti_Limit_Oben = 120; //Oberes Bewegungs Limit des Verti Servos
int Verti_Limit_Unten = 70; //Unteres Bewegungs Limit des Verti Servos



int LDR_OR = 0; //Oben Rechts auf Anlog Pin 0
int LDR_OL = 1; //Oben Links auf Analog Pin 1
int LDR_UR = 2; //Unten Rechts auf Analog Pin 2
int LDR_UL = 3; //Unten Links auf Analog Pin 3


void setup() {
  Serial.begin(9600); //Test um die Werte auszugeben Quelle: https://forum.arduino.cc/t/printing-on-screen-analogue-values/48017
  //noch nicht fertig, deswegen habe ich den Rest auch noch nicht kommentiert
  //Pin Belegung der Servos
  Horizontal.attach(5);
  Vertikal.attach(6);
  Horizontal.write(100);
  Vertikal.write(100);
  delay(3000);
}


void loop() {
  //Die Werte der LDRs werden in die jeweilige Variable gepackt
  int OR = analogRead(LDR_OR);
  int OL = analogRead(LDR_OL);
  int UR = analogRead(LDR_UR);
  int UL = analogRead(LDR_UL);

  int Verzoegerung = 1; //Verzögerung zwischen den Bewegungen
  int Toleranz = 50; //Toleranz zwischen den LDR Werten

  int MwO = (OL + OR) / 2;
  int MwU = (UL + UR) / 2;
  int MwL = (OL + UL) / 2;
  int MwR = (OR + UR) / 2;
  int MwVerti = MwO - MwU; //Mw von Oben und Unten
  int MwHori = MwL - MwR; //Mw von Links und Rechts

  //*****************************************************************
  Serial.print(OL);
  Serial.print(" ");
  Serial.print(OR);
  Serial.print(" ");
  Serial.print(UL);
  Serial.print(" ");
  Serial.print(UR);
  Serial.print("  ");
  Serial.print(MwO);
  Serial.print(" ");
  Serial.print(MwU);
  Serial.print(" ");
  Serial.print(MwL);
  Serial.print(" ");
  Serial.print(MwR);
  Serial.print("  ");
  Serial.print(verti);
  Serial.print("   ");
  Serial.print(hori);
  Serial.println(" ");
  //***************************************************************

  if (Toleranz > MwVerti || MwVerti > Toleranz) { //Überprüft ob die Toleranz größer als MwVerti oder ob MwVerti größer als die Toleranz ist
    if (MwO > MwU) {  
      verti = ++verti;
      if (verti > Verti_Limit_Oben) {
        verti = Verti_Limit_Oben;
      }
    }
    else if (MwO < MwU) { //
      verti = --verti;
      if (verti < Verti_Limit_Unten) {
        verti = Verti_Limit_Unten;
      }
    }
    Vertikal.write(verti); //Der Vertikale Servo bewegt sich zu dem Wert von verti
  }
  if (Toleranz > MwHori || MwHori > Toleranz) { //Überprüft ob die Toleranz größer als MwHori oder ob MwHori größer als die Toleranz ist
    if (MwL > MwR) { 
      hori = --hori;
      if (hori < Hori_Limit_Rechts) { 
        hori = Hori_Limit_Rechts;
      }
    }
    else if (MwL < MwR) { 
      hori = ++hori;
      if (hori > Hori_Limit_Links) {
        hori = Hori_Limit_Links;
      }
    }
    else if (MwL = MwR) { 
      //nichts
    }
    Horizontal.write(hori); //Der Horizontale Servo bewegt sich zu den Wert von Hori  
  }
  delay(Verzoegerung); 
}
