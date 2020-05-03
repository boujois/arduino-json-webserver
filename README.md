# Arduino JSON WebServer

## Getting Started

Open `Ethernet-example-json.ino` in Arduino IDE.

Install `ArduinoJson` Library version `5.13.5`

`Tools` -> `Manage Libraries...` -> search for `arduinojson`, then select Version 5.13.5 from the dropdown:

![libraries manager](manage_libraries.png)

Make up a MAC address if using more than one arduino on the same network:

    byte mac[] = { 0xDE, 0xAD, 0xBD, 0xEF, 0xFE, 0xED };

Change the IP Address to one in your local network:

    IPAddress ip(192,168,86,183);

Upload the Sketch to your board.

You can now access either through a browser at: [http://192.168.86.183](http://192.168.86.183) (this IP will be different if you changed it per the code above).  

Or access through terminal/powershell:

    curl http://192.168.86.183
    {
      "software_version": "1.1.0",
      "sensor_readings": {
        "0": 315,
        "1": 322,
        "2": 363,
        "3": 411,
        "4": 333,
        "5": 298
      },
      "uptime_seconds": 66,
      "uptime_human": "0 Days 0 Hours 1 Minutes 6 Seconds"
    }
