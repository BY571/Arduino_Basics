
int trigger = 9;
int echo = 8;
long dauer = 0;
long entfernung = 0;



void setup(){
  Serial.begin(9600); // starten der seriellen Kommunication
  pinMode(trigger, OUTPUT); //define Trig as Output
  pinMode(echo, INPUT);

}

void loop(){
  digitalWrite(trigger, LOW); // Trigger auf low für rauschfreies Signal
  delay(5);                   // 5 ms
  digitalWrite(trigger, HIGH); // High für senden des Ultraschalls
  
  delay(10);
  digitalWrite(trigger, LOW); //Trigger auf low um senden zu beenden
  dauer = pulseIn(echo, HIGH); // Zeit messen bis die Ultraschallw. zurückk.
  entfernung = (dauer/2)/29.1; // dauer durch 2 da zeit zum hindernis und zurück!
                               //Ultraschallwelle benötigt 29,1 Millisekunden um sich einen Zentimeter fortzubewegen
  Serial.print(entfernung);
  Serial.println(" cm");
  delay(10); // Wiederholen nach 1000 = 1 sec


}
