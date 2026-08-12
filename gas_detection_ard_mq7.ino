// --- Pin Definitions ---
const int MQ2_PIN = A0;   
const int MQ7_PIN = A1;  
const int BUZZER_PIN = 11; 
const int LED_PIN = 12;   

const int MQ2_THRESHOLD = 300; // Example threshold for MQ-2 (LPG, Smoke)
const int MQ7_THRESHOLD = 550; // Example threshold for MQ-7 (CO)

void setup() {

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  

  Serial.begin(9600); 

  Serial.println("Gas Detection System Starting Up...");
  Serial.println("Please wait 60 seconds for sensors to warm up...");
  

  digitalWrite(BUZZER_PIN, LOW); 
  digitalWrite(LED_PIN, LOW);


  delay(60000); 

  Serial.println("Sensors Ready.");
}

void loop() {

  int mq2_value = analogRead(MQ2_PIN);
  int mq7_value = analogRead(MQ7_PIN);


  Serial.print("MQ-2 (Smoke/LPG): ");
  Serial.print(mq2_value);
  Serial.print(" | MQ-7 (CO): ");
  Serial.println(mq7_value);
  

  if (mq2_value > MQ2_THRESHOLD || mq7_value > MQ7_THRESHOLD) {

    Serial.println("*** GAS LEAK DETECTED! ALARM ACTIVE! ***");
    digitalWrite(BUZZER_PIN, HIGH); 
    digitalWrite(LED_PIN, HIGH);   
  } else {

    digitalWrite(BUZZER_PIN, LOW); 
    digitalWrite(LED_PIN, LOW);   
  }

  delay(1000); 
}

