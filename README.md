# Arduino JSON WebServer

## Getting Started

Open `Ethernet-example-json.ino` in Arduino IDE.

Install `ArduinoJson` Library version `5.13.5`

`Tools` -> `Manage Libraries...` -> search for `arduinojson`, then select Version 5.13.5 from the dropdown:

![libraries manager](manage_libraries.png)

Make up a MAC address if using more than one arduino on the same network:

    byte mac[] = { 0xDE, 0xAD, 0xBD, 0xEF, 0xFE, 0xED };

Change the IP Address to one in your local network:

    IPAddress ip(192,168,86,247);

Upload the Sketch to your board.

You can now access either through a browser at: [http://192.168.86.247](http://192.168.86.247) (this IP will be different if you changed it per the code above).  

Or access through terminal/powershell:

    curl http://192.168.86.247
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


## Notes

If using Google Wifi (Mesh), wired devices with fixed IPs may not show up in the Devices tab (required if port forwarding). Instead get an IP using DHCP, and reserve it. Your Arduino can be identified by the MAC address, or by looking for `WizzNet`.  

Make this change (comment out the first line, uncomment the 2nd):

    //Ethernet.begin(mac, ip);
    Ethernet.begin(mac); // use this line if you want DHCP assigned IP (uncomment and commment out the above line)

Then after IP has been established and reserved, switch back the change to the above and update the line:

    IPAddress ip(192,168,86,247);

To whatever IP was given through DHCP
