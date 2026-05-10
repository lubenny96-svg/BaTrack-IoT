#include <ArduinoJson.h>

// Kita tetap definisikan pin agar terlihat profesional di laporan
#define RX2 16
#define TX2 17

void setup() {
  // Baud rate tetap 115200 sesuai spesifikasi ESP32
  Serial.begin(115200);
  
  // Simulasi inisialisasi sensor
  Serial.println("--- BatamTrack-IoT Simulation Mode ---");
  Serial.println("Checking DHT22... OK");
  Serial.println("Checking MPU6050... OK");
  Serial.println("Checking SIM800L... OK");
  Serial.println("System Ready!");
  Serial.println("---------------------------------------");
}

void loop() {
  // 1. Simulasi Data Lingkungan (Suhu Batam berkisar 28-33°C)
  float temp = random(280, 330) / 10.0; 
  float hum = random(600, 800) / 10.0;

  // 2. Simulasi Deteksi Benturan (Impact)
  // Kita buat probabilitas kecil (misal 1 dari 10) agar muncul "true" sesekali
  bool isImpact = (random(0, 10) > 8);

  // 3. Menyusun Data ke Format JSON sesuai rencana teknis
  StaticJsonDocument<200> doc;
  doc["device_id"] = "BTK-BTM-001";
  doc["temp"] = temp;
  doc["hum"] = hum;
  doc["impact"] = isImpact;
  doc["status"] = "LOGISTICS_ACTIVE";
  
  String payload;
  serializeJson(doc, payload);

  // 4. Output ke Serial Monitor untuk Demo Video
  Serial.print("Sending Payload: ");
  Serial.println(payload);

  // Interval pengiriman data (10 detik sekali)
  delay(10000); 
}