/*
 Name:    Arduino_RGB_Mosfet_Relay.ino
 Created: 4/6/2018 9:15:11 PM
 Author:  Jay Suthar
*/


int ledred = 10;
int ledgreen = 9;
int ledblue = 11;
int tx = 1;
int rx = 0;
char inSerial[15];
int r = 0, g = 0, b = 0;
int r1=7,r2=6,r3=5,r4=4;  
void setup() {
  Serial.begin(9600);
  pinMode(ledred, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(ledblue, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  allpinsLOW();
}

void loop() {
  int i = 0;
  int m = 0;
  delay(500);
  if (Serial.available() > 0) {
    while (Serial.available() > 0) {
      inSerial[i] = Serial.read();
      i++;
    }
    inSerial[i] = '\0';
    Check_Protocol(inSerial);
    UpdateLED(r,g,b);
  }
}

void allpinsLOW()
{
  digitalWrite(ledred, LOW);
  digitalWrite(ledgreen, LOW);
  digitalWrite(ledblue, LOW);
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, HIGH);
}

void Check_Protocol(char inStr[]) {
  int i = 0;
  int m = 0;
  Serial.println(inStr);

  if(!strcmp(inStr,"off")){      //Blackout
    r=0;
    g=0;
    b=0;
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, HIGH);
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;
       }
  if(!strcmp(inStr,"redonly")){      //Ledred ON
    r=255;
    b=0;
    g=0;
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;
       }     
  if(!strcmp(inStr,"greenonly")){      //Ledgreen ON
    g=255;
    b=0;
    r=0;
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;}
  if(!strcmp(inStr,"blueonly")){      //Ledblue ON
    b=255;
    g=0;
    r=0;
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;}
  if(!strcmp(inStr,"redgreen")){      //Led Red Green
    r=255;
    b=0;
    g=255;
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;
       }
  if(!strcmp(inStr,"greenblue")){      //Led Green blue
    
    r=0;
    b=255;
    g=255;
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;
       }      
  if(!strcmp(inStr,"redblue")){      //Led Red blue 
    r=255;
    b=255;
    g=0;
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;
       }    
  if(!strcmp(inStr,"white")){    //Led white
    r=255;
    b=255;
    g=255;
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;
       } 
  
  if (!strcmp(inStr, "red+")) {      //Ledred ++
    if (r<255) {
    r=r+10;
    UpdateLED(r,g,b);
    }
    else{
      r=0;
    }
  }
  if (!strcmp(inStr, "red-")) {      //Ledred --
    if (r>0) {
    r=r-10;
    UpdateLED(r,g,b);
    }
    else{
      r=127;
    }
  }

  if (!strcmp(inStr, "green+")) {      //Ledgreen ++
    if (g<255) {
    g=g+10;
    UpdateLED(r,g,b);
    }
    else{
      g=0;
    }
  } 
   if (!strcmp(inStr, "green-")) {      //Ledgreen --
    if (g>0) {
    g=g-10;
    UpdateLED(r,g,b);
    }
    else{
      g=127;
    }
  }

  if (!strcmp(inStr, "blue+")) {      //Ledblue ++
    if (b<255) {
    b=b+10;
    UpdateLED(r,g,b);
    }
    else{
      b=0;
    }
  }
  if (!strcmp(inStr, "blue-")) {      //Ledblue --
    if (b>0) {
    b=b-10;
    UpdateLED(r,g,b);
    }
    else{
      b=127;
    }
  }
  
  
  if (!strcmp(inStr, "r1toggle")) { //relay1=toggle
    digitalWrite(r1,!digitalRead(r1));
  }
    if (!strcmp(inStr, "r2toggle")) { //relay1=toggle
    digitalWrite(r2,!digitalRead(r2));
  }
    if (!strcmp(inStr, "r3toggle")) { //relay1=toggle
    digitalWrite(r3,!digitalRead(r3));
  }
    if (!strcmp(inStr, "r4toggle")) { //relay1=toggle
    digitalWrite(r4,!digitalRead(r4));
  }
  else {
    for (m = 0; m<11; m++) {
      inStr[m] = 0;
    }
    i = 0;

  }
}


void UpdateLED(int a,int b,int c)
{
 analogWrite(ledred, a);
 analogWrite(ledgreen, b);
 analogWrite(ledblue, c); 
}
