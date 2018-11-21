#define D7 13 //Bestämmer vilka pinnar vi ska arbeta på


#include <ESP8266WiFi.h>   //https://github.com/esp8266/Arduino


#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>   
#include <ArduinoJson.h> //https://github.com/tzapu/WiFiManager // inkluderar de libraries vi laddat ned

String Lampname="lamp";
int Lamptemp=0;
int Strenghtvalue=0;
bool LampExist=false;
bool OnOff=false;
bool GottenValues= false; //sätter variablar där vi i vissa fall vill ha någonting att gå efter och i vissa fall t.ex. inte vill skriva "lamp" överallt om vi skulle vilja ändra

String SendtoDB(String host){
 String type ="POST ";  //Väljer att datan är av typen POST
 if(GottenValues==true)
 {
 String url= "/lights/"; //väljer att vi ska skriva lights vilket är namnet på backenden i url:en
 Serial.println("Skickar värde första gången");
 StaticJsonBuffer<300> jsonBuffer; //Skapar en buffert som sparar undan 300Mb så att inte mängden data som skickas in i mikrodatorn överstigen den mängd som den klarar
 JsonObject& root = jsonBuffer.createObject(); // sparar bufferten som json-objekt också så att vi kan läsa den
 root["name"] = Lampname; 
 root["lighttemperature"] = Lamptemp;
 root["lightstrenght"] = Strenghtvalue; //Säger att t.ex. Lampnamn är det som heter "name" i databasen
 root["onoff"] = OnOff;
 String buffer; 
 root.printTo(buffer); 
 if(LampExist==true)
 {
 type ="PATCH "; //om lampan redan finns blir typen istället PATCH så att det inte ska bli hur många värden som helst 
 Serial.println("Uppdaterar värdet!");
 }

 String Output =type+url + " HTTP/1.1\r\n" + 
 "Host: " + host+ "\r\n" + 
 "Content-Type: application/json\r\n" + 
 "Content-Length: " + buffer.length() + "\r\n" +
 "\r\n" + 
 buffer + "\n"; 
return Output; 
 }
 else
 return ""; //skriver in vilka som type, hosat och lenght i url:en
}

String GetfromDB(String host){
String url= "/lights/"+Lampname; 
 String Output ="GET "+ url + " HTTP/1.1\r\n" +
 "Host: " + host+ "\r\n" + 
 "\r\nConnection: close\r\n\r\n"; 
return Output; //?????
}

 void UpdateValues(String json){
  StaticJsonBuffer<400>jsonBuffer;
  JsonObject&root=jsonBuffer.parseObject(json);
  String dataL=root["name"];
  if(dataL!="none") {
    int datat = root["lighttemperature"];
    int datas = root["lightstrenght"];
    Lampname=dataL;
    Lamptemp=datat;
    Strenghtvalue=datas;
    LampExist=true; 
  } else {
    String Mess=root["message"];
    Serial.print(Mess);
  }
  GottenValues=true;  //uppdaterar värden när vi andänder oss av typen UPDATE
  }
  
 void ConnecttoDB(String input){

      const int httpPort=3000;
      const char*host="iot.abbindustrigymnasium.se"; //databasen på iot servern
      Serial.print("connecting to ");
      Serial.println(host);

      WiFiClient client;
      if(!client.connect(host,httpPort)){
        Serial.println("connection failed"); // om connection inte finns så printar den connection failed
        return;
      }

      if(input=="GET")
      client.print(GetfromDB(host));
      else
      client.print(SendtoDB(host));
        unsigned long timeout= millis(); 
        while(client.available()==0){
        if (millis()- timeout >10000){
          Serial.println(">>>Client Timeout!");
          client.stop();
          return; //om vi hämtar värden och ingenting händer på 10 sekunder timear clienten ut 
    
String json = "";
boolean httpBody = false; 
while (client.available()) {
 String line = client.readStringUntil('\r'); //clienten läser igenom ? tills den hittar \r och och karaktären efter är { så blir httpBody true
 if (!httpBody && line.charAt(1) == '{') {
 httpBody = true; 
 }
 if (httpBody) {
 json += line;
 }
}
 Serial.println("Got data:");
 Serial.println(json);
 if(input =="GET") 
 UpdateValues(json);
 Serial.println();
 Serial.println("closing connection"); //använder funktionen update values och och serial printar sådant som vi behöver veta
}
 }
 }   

void UpdatingLamp(){
  if(OnOff=true)
  digitalWrite(13, HIGH);
  else
  digitalWrite(13, LOW); //En funktion som används för att tända lampan då om OnOff är på
}
 
void setup() {

  pinMode(13, OUTPUT);
  

    
    Serial.begin(115200);

   
    WiFiManager wifiManager;

    //wifiManager.resetSettings();
    
    wifiManager.autoConnect("InetelligentKanin"); //Ger oss ett nätverk att ansluta sig till genom telefonen 
    
    
   
    Serial.println("connected...yeey :)");
}

void loop() {
  ConnecttoDB("GET");
    UpdatingLamp(); //runnar våra funktioner som vi skrivit in innan setup
    delay(1000);
   }
 

