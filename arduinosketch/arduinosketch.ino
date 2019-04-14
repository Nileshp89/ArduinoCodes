
int ledPin = 13; // choose the pin for the LED
int inPin = 7;   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  // declare LED as output
  //pinMode(inPin, INPUT);
}

void loop() {
//  val = digitalRead(inPin);
 
  //if(val == LOW){
    delay(1000);
    //  if(val == LOW){
          
           Serial.println("1 Cup of coffee");
      //     digitalWrite(ledPin,HIGH);
        //   delay(500);
          // digitalWrite(ledPin,LOW);
       //}
   //}
}
