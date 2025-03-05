#include <ESP32Firebase.h>

#define timeSeconds 10
#define LIGHT_SENSOR_PIN 36


#define _SSID "iot"
#define _PASSWORD "iot@123@"
#define REFERENCE_URL "https://nome-7eaf2-default-rtdb.firebaseio.com/"


const int led = 4;
const int motionSensor = 25;

unsigned long now = millis();
volatile boolean motionDetected = false;
unsigned long lastTrigger = 0;
boolean startTimer = false;
int lightSum = 0;
int lightValueAvr = 0;
unsigned long lastTime = 0;
unsigned long interval = 5000;

Firebase firebase(REFERENCE_URL);

void IRAM_ATTR detectsMovement() {
  digitalWrite(led, HIGH);
  startTimer = true;
  lastTrigger = millis();
  motionDetected = true;
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(_SSID);
  WiFi.begin(_SSID, _PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("-");
  }

  Serial.println("");
  Serial.println("WiFi Connected");

  Serial.print("IP Address: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  firebase.setString("Teste/123", "456");

  pinMode(motionSensor, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(motionSensor), detectsMovement, RISING);

  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  int analogValue = analogRead(LIGHT_SENSOR_PIN);
  unsigned long currentTime = millis();

  Serial.print("Analog Value = ");
  Serial.print(analogValue);  

  if (analogValue < 500) {
    lightSum = lightSum + analogValue;
    Serial.println(" => Bem Clara");
  } else if (analogValue < 2000) {
    lightSum = lightSum + analogValue;
    Serial.println(" => Clara");
  } else if (analogValue < 2500) {
    lightSum = lightSum + analogValue;
    Serial.println(" => Escura");
  } else if (analogValue < 4500) {
    lightSum = lightSum + analogValue;
    Serial.println(" => Bem Escura");
  }

  delay(100);
  
  if (motionDetected) {
    Serial.println("Motion detected");
    digitalWrite(led, HIGH);
    motionDetected = false;
  }

  if (startTimer && (millis() - lastTrigger > (unsigned long) 1000)) {
    Serial.println("Motion not detected");
    digitalWrite(led, LOW);
    startTimer = false;
  }

  if (currentTime - lastTime >= interval) {
    lightValueAvr = lightSum/5;
    if (lightValueAvr < 500) {
      firebase.setString("realTime/Luminosidade", "Bem Clara");
      Serial.println(" ===============> Bem Clara");
    } else if (lightValueAvr < 2000) {
      firebase.setString("realTime/Luminosidade", "Clara");
      Serial.println(" ===============> Clara");
    } else if (lightValueAvr < 2500) {
      firebase.setString("realTime/Luminosidade", "Escura");
      Serial.println(" ===============> Escura");
    } else if (lightValueAvr < 4500) {
      firebase.setString("realTime/Luminosidade", "Bem Escura");
      Serial.println(" ===============> Bem Escura");
    }
    if (motionDetected) {
      motionDetected = false;
      firebase.setString("realTime/Movimento", "Sim");
      Serial.println(" ===============> Sim");
    } else {
      firebase.setString("realTime/Movimento", "Não");
      Serial.println(" ===============> Não");
    }
    lastTime = currentTime;
    lightSum = 0;
    lightValueAvr = 0;
  }
}