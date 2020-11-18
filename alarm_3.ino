
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);

char incomingByte;
String inputString;
int led = 10;
bool active = false;
int button1 = 8 ;//Button pin, on the other pin it's wired with GND
int button2 = 9;
int button3 = 10;
bool button_State; //Button state

void setup()
{
      pinMode(led, OUTPUT);
      pinMode(LED_BUILTIN, OUTPUT);
      //Serial.begin(9600);
      mySerial.begin(9600);
      // Check if you're currently connected to mySerial
      while(!mySerial.available()){
        mySerial.println("AT");
        delay(1000);
        ////Serial.println("connecting....");
        }
      ///Serial.println("Connected.."); 
      mySerial.println("AT+CMGF=1\r\n");  //Set SMS Text Mode
      delay(1000); 
      mySerial.println("AT+CNMI=1,2,0,0,0");  //procedure, how receiving of new messages from the network
      delay(1000);
      mySerial.println("AT+CMGL=\"REC UNREAD\""); // Read unread messages
      delay(1000);
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000); 

      pinMode(button1, INPUT_PULLUP); //The button is always on HIGH level, when pressed it goes LOW
        mySerial.begin(9600);   //Module baude rate, this is on max, it depends on the version
        Serial.begin(9600);   
        delay(1000);


                        
     }

void loop()

{ 
  
  
 
    button_State = digitalRead(button1);   //We are constantly reading the button State
 

            if (button_State == HIGH) {            //And if it's pressed
              Serial.println("Button pressed");   //Shows this message on the serial monitor
              delay(200);                         //Small delay to avoid detecting the button press many times
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  mySerial.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  mySerial.print("AT+CMGS=\"+48799722162\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  delay(500);
  mySerial.print("alarm1");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  mySerial.print((char)26);// (required according to the datasheet)
  delay(500);
  mySerial.println();
  Serial.println("Text Sent.");
  delay(500);
            }
            if (button_State == LOW)
            delay(100);
            button_State = digitalRead(button2);   //We are constantly reading the button State
 
            if (button_State == HIGH) {            //And if it's pressed
              Serial.println("Button pressed");   //Shows this message on the serial monitor
              delay(200);                         //Small delay to avoid detecting the button press many times
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  mySerial.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  mySerial.print("AT+CMGS=\"+48799722162\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  delay(500);
  mySerial.print("alarm2");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  mySerial.print((char)26);// (required according to the datasheet)
  delay(500);
  mySerial.println();
  Serial.println("Text Sent.");
  delay(500);
            }
            if (button_State == LOW)
            delay(100);
            button_State = digitalRead(button3);   //We are constantly reading the button State
 
            if (button_State == HIGH) {            //And if it's pressed
              Serial.println("Button pressed");   //Shows this message on the serial monitor
              delay(200);                         //Small delay to avoid detecting the button press many times
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  mySerial.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  mySerial.print("AT+CMGS=\"+48799722162\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  delay(500);
  mySerial.print("alarm3");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  mySerial.print((char)26);// (required according to the datasheet)
  delay(500);
  mySerial.println();
  Serial.println("Text Sent.");
  delay(500);
            }
            if (button_State == LOW)
            delay(500);
      }
