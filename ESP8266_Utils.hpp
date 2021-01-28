const char* hostname = "SD_INHALAMBRICA";

IPAddress ip(192, 168, 0, 200);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

void ConnectWiFi_STA(bool useStaticIP = false)
{
   Serial.println("");
   WiFi.mode(WIFI_STA);
   WiFi.begin(ssid, password);
   if(useStaticIP) WiFi.config(ip, gateway, subnet);
   while (WiFi.status() != WL_CONNECTED) 
   { 
     delay(100);  
     Serial.print('.'); 
   }
 
   Serial.println("");
   Serial.print("Conectado a:\t");
   Serial.println(ssid);
   Serial.print("Dirección IP:\t");
   Serial.println(WiFi.localIP());
}




void ConnectWiFi_AP(bool useStaticIP = false)
{ 
   Serial.println("");
   WiFi.mode(WIFI_AP);
   while(!WiFi.softAP(ssid, password))
   {
     Serial.println(".");
     delay(100);
   }
   if(useStaticIP) WiFi.softAPConfig(ip, gateway, subnet);

   Serial.println("");
   Serial.print("Red wifi creada:\t");
   Serial.println(ssid);
   Serial.print("Dirección IP:\t");
   Serial.println(WiFi.softAPIP());
}
