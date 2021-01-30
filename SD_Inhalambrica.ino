/********************************************
 *                                          *
 *            SD Inhalambrica               *
 *     https://labuhardilladelloco.xyz      *
 *                                          *
 ********************************************/

const char* ssid     = "Nombre_red_wifi";
const char* password = "Password_red_wifi";


#include <ESP8266WiFi.h>
#include <SD.h>
#include "ESP8266FtpServer.h"

#include "ESP8266_Utils.hpp"

FtpServer ftpSrv; //Establezcer #define FTP_DEBUG en ESP8266FtpServer.h para ver en detalle el servidor Ftp por consola.

void setup(void){
  Serial.begin(115200);
  Serial.println("");
  
  ConnectWiFi_STA(); //Conectar a red wifi

  //ConnectWiFi_AP();//Crear red wifi
  
  //2 indica el pin de selección de chip
  if (SD.begin(2)) {
    Serial.println("SD abierta!");
    ftpSrv.begin("admin","admin");    //nombre de usuario, contraseña para ftp. establecer puerto en ESP8266FtpServer.h (predeterminado 21, 50009 para PASV)
  } 
}

void loop(void){
  ftpSrv.handleFTP();        //Asegurate de llamar a handleFTP() en el void loop!!   
}
