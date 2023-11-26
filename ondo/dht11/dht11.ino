#include <DHT11.h>

int pin = 2;
DHT11 dht11(pin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float temp, humi;
  dht11.read(humi, temp);
  Serial.print(temp);
  Serial.print(" ");
  Serial.println(humi);
  

  delay(1000);
}
