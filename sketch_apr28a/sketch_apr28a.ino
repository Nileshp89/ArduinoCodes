
#define TIME_MSG_LEN  11   // time sync to PC is HEADER followed by unix time_t as ten ascii digits
#define TIME_HEADER  255 

void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if( getPCtime()) {  // try to get time sync from pc
    Serial.print("Clock synced at: ");
    Serial.println(DateTime.now(),DEC);
  }

  if(DateTime.available()) {
  Serial.println(DateTime.now());
  delay(1000);
  }

}

boolean getPCtime() {
  // if time sync available from serial port, update time and return true
  while(Serial.available() >=  TIME_MSG_LEN ){  // time message consists of a header and ten ascii digits
    if( Serial.read() == TIME_HEADER ) {        
      time_t pctime = 0;
      for(int i=0; i < TIME_MSG_LEN -1; i++){   
        char c= Serial.read();          
        if( c >= '0' && c <= '9'){   
          pctime = (10 * pctime) + (c - '0') ; // convert digits to a number    
        }
      }   
      DateTime.sync(pctime);   // Sync Arduino clock to the time received on the serial port
      return true;   // return true if time message received on the serial port
    }  
  }
  return false;  //if no message return false
}


