#include <DHT11.h>

int pin = 2;
DHT11 dht11(pin);

String cmd = "temp";
String input = "";

void setup() {
  Serial.begin(9600);
}

void loop() {
  float temp, humi;

  if(Serial.available()){
    input = Serial.readStringUntil('\n');
  }

  if(Serial.available()==0 && input == cmd) {
    dht11.read(humi, temp);
    Serial.print(temp);
    Serial.print(" ");
    Serial.println(humi);
    input = "";
  }

  delay(1000);
}
