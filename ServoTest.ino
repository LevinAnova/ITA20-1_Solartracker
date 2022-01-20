#include <Servo.h> // Benötigte Servo Bibliothek

Servo Horizontal; //Dimensionierung des Horizontalen Servos
Servo Vertikal; //Dimensionierung des Vertikalen Servos

int pos = 0; //Pos wird als Integer mit dem Wert 0 dimensioniert
int Verzoegerung = 50; //Verzögerung zwischen den Bewegungen

void setup() {    //Setup des Arduinos
  Horizontal.attach(5); //Der Horizontal Servo wird auf den Pin 5 gelegt
  Vertikal.attach(6); //Der Vertikal Servo wird auf den Pin 6 gelegt
  Horizontal.write(90); //Der Horizontal Servo wird auf die mittlere Position gestzt (90)
  Vertikal.write(90); //Der Vertikal Servo wird auf die mittlere Position gestzt (90
  delay(2000); //Die beiden Servos warten für 2 Sekunden
}

void loop() {   //Start des Hauptprogramms
  
  for (pos = 70; pos <= 110; pos++) { //*
    Horizontal.write(pos);            //*
    delay(Verzoegerung);              //Der Horizontal Servo bewegt sich von 70 bis 110 grad mit einer 15ms großen Verzögerung zwischen den einzelnen Bewegungen
  }                                   //*
  delay(1000);                        //Pause von 1s bis zum nächsten Befehl

  for (pos = 110; pos >= 70; pos--) { //*
    Horizontal.write(pos);            //*
    delay(Verzoegerung);              //Der Horizontal Servo bewegt sich von 70 bis 110 grad mit einer 15ms großen Verzögerung zwischen den einzelnen Bewegungen
  }                                   //*
  delay(1000);                        //*

  for (pos = 70; pos <= 110; pos++) { //*
    Vertikal.write(pos);              //*
    delay(Verzoegerung);              //Der Vertikale Servo bewegt sich von 70 bis 110 grad mit einer 15ms großen Verzögerung zwischen den einzelnen Bewegungen
  }                                   //*
  delay(1000);                        //*
  
  for (pos = 110; pos >= 70; pos--) { //*
    Vertikal.write(pos);              //*
    delay(Verzoegerung);              //Der Vertikal Servo bewegt sich von 110 bis 70 grad mit einer 15ms großen Verzögerung zwischen den einzenlen Bewegungen
  }                                   //*
  delay(1000);                        //*

}                                     //Ende des Programms
