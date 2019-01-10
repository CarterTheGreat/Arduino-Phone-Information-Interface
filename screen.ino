//#include <SD.h>
#include <TFT.h> // Hardware-specific library
#include <SPI.h>

#define CS   10
#define DC   9
#define RESET  8

//END DEF & INC

TFT lcd = TFT(CS, DC, RESET);
int height = lcd.height()/2-7;

String data = "";
String message = "";
char messagePrint[10];
char character;

int textNum;
String textNumS;
char textNumC [10];

int missedCallsNum;
String missedCallsS;
char missedCallsC[10];

int ind1;
int ind2;
int messageLength;

int noteRep = 10;


//END VARS


void setup() {
  
  lcd.begin();
  lcd.setRotation(3);
  lcd.background(0, 0, 0);

  lcd.stroke(255,255,255);
  lcd.textSize(2);

  Serial.begin(9600);
  lcd.text("Hello.", 0 ,height);
  delay(2500);
  clear();
}


//END SETUP


void loop() {
//INPPUT ALLOCATION-------------------------------------------------------------  
  while(Serial.available()){
    character = Serial.read();
    data.concat(character);
    
    if(character == '#'){ // if end of message received
      ind1 = data.indexOf('/');
      ind2 = data.indexOf('#');
      message = data.substring(ind1+1,ind2);
      data = data.substring(0,ind1);
      Serial.print("Data: |"+data+"|");
      Serial.println();
      Serial.print("message: |"+message+"|");
      Serial.println();
      messageLength = ind2 - ind1;
    } 
  }


//CALL-------------------------------------------------------------
   if(data == "call"){
    Serial.print("call accepted");Serial.println();
    call(message);
  }
//SMS-------------------------------------------------------------
   if(data == "sms"){
    Serial.print("sms accepted");Serial.println();
    call(message);
  }
//TEST-------------------------------------------------------------
   if(data == "test"){
    Serial.print("Test accepted");Serial.println();
    test(message);
  }
  
//DEFAULT-------------------------------------------------------------  
  
  defaultScreen();
   
//-------------------------------------------------------------  
}


//END LOOP


//DEFAULT------------------------------------------------------------
void defaultScreen(){
  textNumS = (String) textNum;
  textNumS.toCharArray(textNumC,10);
  if(textNum > 0){
    lcd.text("Texts:",0,0);
    lcd.text(textNumC,70,0);
  }
  
  missedCallsS = (String) missedCallsNum;
  missedCallsS.toCharArray(missedCallsC,10);
  if(missedCallsNum > 0){
    lcd.text("Calls:",0,20);
    lcd.text(missedCallsC,70,20);
  }
}

//CALL M-------------------------------------------------------------
void call(String message){
  clear();
  message.toCharArray(messagePrint,messageLength);
  
  for(int i = 0;i<noteRep;i++){
      lcd.text("Incoming Call",0,height);
      lcd.text("From: ",0,height+20);
      lcd.text(messagePrint,0,height+40);
      delay(1000);
      lcd.background(0,0,0);
      
    }
    clear();
}
//SMS M-------------------------------------------------------------
void sms(String message){
  clear();
  message.toCharArray(messagePrint,messageLength);
  
  for(int i = 0;i<noteRep;i++){
      lcd.text("Incoming Text",0,height);
      lcd.text("From: ",0,height+20);
      lcd.text(messagePrint,0,height+40);
      delay(1000);
      lcd.background(0,0,0);
      
    }
    clear();
}
//TEST M-------------------------------------------------------------
void test(String message){
  clear();
   message.toCharArray(messagePrint,messageLength);
  
   for(int i = 0;i<3;i++){
     lcd.text("Test",0,height);
     lcd.text(messagePrint, 0, height +20);
     delay(1000);
     lcd.background(0,0,0);
   }
   clear();
}
//CLEAR M-------------------------------------------------------------
void clear(){

  lcd.background(0,0,0); //clear screen
  data = ""; 
  message = "";
  messagePrint[10];
}

