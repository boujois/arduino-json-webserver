#include <SPI.h>
#include <Ethernet.h>
#include <ArduinoJson.h> // Library AduinoJson version 5 (not 6)

String version  = "1.0.2";

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 0xDE, 0xAD, 0xBD, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,86,183);
EthernetServer server(80);

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/json");
          client.println("Connection: close");
          client.println();
          DynamicJsonBuffer jsonBuffer;
          JsonObject& object = jsonBuffer.createObject();
          object["software_version"] = version;
          object["sensor_readings"]= jsonBuffer.createObject(); // create a nested object for the readings
          for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
            int sensorReading = analogRead(analogChannel);
            object["sensor_readings"][String(analogChannel)]=sensorReading;
          }
          
          object.prettyPrintTo(Serial);
          object.prettyPrintTo(client);
          client.println();
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}
