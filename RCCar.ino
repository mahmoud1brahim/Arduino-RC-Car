int speedPin = 10 , mot1 = 8 , mot2 = 9;
int speedPin1 = 11 , mot3 = 5 , mot4 = 6;
int curSpeed = 0 , dir = 0 ;
//const int buzzer = 3 ;   
//Leds connected to Arduino UNO Pin 12
  const int lights  = 12;
//Buzzer to Arduino UNO Pin 3
  const int buzzer =   3 ;   
//Bluetooth (HC-05 JY-MCU) State pin on pin 2 of Arduino
 // const int BTState = 2;
// Use it to make a delay... without delay() function!
  long previousMillis = -1000*10;// -1000*10=-10sec. to read the first value. If you use 0 then you will take the first value after 10sec.  
  long interval = 1000*10;       // interval at which to read battery voltage, change it if you want! (10*1000=10sec)
  unsigned long currentMillis;   //unsigned long currentMillis;
//Useful Variables
  int i=0;
  int j=0;
  int state;
  //int curSpeed=255;     // Default speed, from 0 to 255

void setup() {
    // Set pins as outputs:
    pinMode(speedPin , OUTPUT );
    pinMode(mot1 , OUTPUT ) ;
    pinMode(mot2 , OUTPUT ) ;
    pinMode(speedPin , OUTPUT );
    pinMode(mot3 , OUTPUT ) ;
    pinMode(mot4 , OUTPUT ) ;
    pinMode(speedPin1 , OUTPUT );
    pinMode(lights, OUTPUT); 
       
    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}
 
void loop() {
  //Stop car when connection lost or bluetooth disconnected
     //if(digitalRead(BTState)==LOW) { state='S'; }

  //Save income data to variable 'state'
    if(Serial.available() > 0){     
      state = Serial.read();   
    }
  
  //Change speed if state is equal from 0 to 10. Values must be from 0 to 255 (PWM)
    if (state == '0'){
      curSpeed=0;}
    else if (state == '1'){
      curSpeed=50;}
    else if (state == '2'){
      curSpeed=75;}
    else if (state == '3'){
      curSpeed=100;}
    else if (state == '4'){
      curSpeed=125;}
    else if (state == '5'){
      curSpeed=155;}
    else if (state == '6'){
      curSpeed=180;}
    else if (state == '7'){
      curSpeed=200;}
    else if (state == '8'){
      curSpeed=225;}
    else if (state == '9'){
      curSpeed=255;}
    else if (state == 'q'){
      curSpeed=255;}
 	  
  /***********************Forward****************************/
  //If state is equal with letter 'F', car will go forward!
    if (state == 'F') {
    	digitalWrite(mot1 ,  dir) ;
        digitalWrite(mot2 , !dir) ;
        analogWrite(speedPin , curSpeed) ;
        digitalWrite(mot3 ,  dir) ;
        digitalWrite(mot4 , !dir) ;
        analogWrite(speedPin1 , curSpeed) ;
    }
  
  /***********************Backward****************************/
  //If state is equal with letter 'B', car will go backward
    else if (state == 'B') {
    	digitalWrite(mot1 ,  !dir) ;
        digitalWrite(mot2 , dir) ;
        analogWrite(speedPin , curSpeed) ;
        digitalWrite(mot3 ,  !dir) ;
        digitalWrite(mot4 ,  dir) ;
        analogWrite(speedPin1 , curSpeed) ;
    }

  /***************************Left*****************************/
  //If state is equal with letter 'L', wheels will turn left
    else if (state == 'L') {
    	digitalWrite(mot1 ,  dir) ;
        digitalWrite(mot2 , !dir) ;
        analogWrite(speedPin , curSpeed) ;
        digitalWrite(mot3 ,  !dir) ;
        digitalWrite(mot4 , !dir) ;
        analogWrite(speedPin1 , curSpeed) ;
    	}
  /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn right
    else if (state == 'R') {
    	digitalWrite(mot1 ,  !dir) ;
        digitalWrite(mot2 , !dir) ;
        analogWrite(speedPin , curSpeed) ;
        digitalWrite(mot3 ,  dir) ;
        digitalWrite(mot4 , !dir) ;
        analogWrite(speedPin1 , curSpeed) ;		
    }
  /**********************Horn sound***************************/
  //If state is equal with letter 'V', play (or stop) horn sound
    else if (state == 'V'){
      if (j==0){  
         tone(buzzer , 1500);//Speaker on 
         j=1;
      }
      else if (j==1){
         noTone(buzzer);  //Speaker off 
         j=0;
      }
      state='n';  
    }
  /************************Stop*****************************/
  //If state is equal with letter 'S', stop the car
    else if (state == 'S'){
        digitalWrite(mot1 ,  !dir) ;
        digitalWrite(mot2 , !dir) ;
        analogWrite(speedPin , curSpeed) ;
        digitalWrite(mot3 ,  !dir) ;
        digitalWrite(mot4 , !dir) ;
        analogWrite(speedPin1 , curSpeed) ;
    }
 
}




