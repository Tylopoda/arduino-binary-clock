int led_total = 13;

unsigned short seconds = 59;
unsigned short minutes = 40;
unsigned short hours = 22;  

long last_tick = 0;

void setup(){
  Serial.begin(9600);
  
  for( int i = 1; i <= led_total; i++ ){
    pinMode( i, OUTPUT );
  }
  
}

void loop(){
  
if( millis()-last_tick >= 1000 ){
    last_tick = millis();
    seconds++;
  }
  
  int val0 = analogRead(A0) / 4;
  int val1 = analogRead(A1) /   4;
 
  
  if(val0 > 250) { minutes++; }
  if(val1 > 250) { hours++; }
  
  
  if( seconds >= 60 ){
    minutes++;
    seconds = 0; 
  }
  
  if( minutes >= 60 ){
    hours++;
    minutes = 0;
  }
  
  if( hours >= 24 ){
    hours = 0;
    minutes = 0;
    seconds = 0;
  }


  long temp_hours = hours%10;
  for( short i = 3; i >= 0; i-- ){
    if( temp_hours >= pow( 2, i )){
      temp_hours -= pow( 2, i );
      digitalWrite( 8+i, HIGH );
      
    }else{
      digitalWrite( 8+i, LOW );
    }
  }
  
  temp_hours = hours/10;
  for( short i = 1; i >= 0; i-- ){
    if( temp_hours >= pow( 2, i )){
      temp_hours -= pow( 2, i );
      digitalWrite( 8+4+i, HIGH );
      
    }else{
      digitalWrite( 8+4+i, LOW );
    }
  }
  
  long temp_minutes = minutes%10;
  for( short i = 3; i >= 0; i-- ){
    if( temp_minutes >= pow( 2, i )){
      temp_minutes -= pow( 2, i );
      
      digitalWrite( 1+i, HIGH );
      
    }else{
      digitalWrite( 1+i, LOW );
    }
  }
  
  temp_minutes = minutes/10;
  for( short i = 2; i >= 0; i-- ){
    if( temp_minutes >= pow( 2, i )){
      temp_minutes -= pow( 2, i );

      digitalWrite( 5+i, HIGH );
      
    }else{
      digitalWrite( 5+i, LOW );
    }
    
  }
   

	Serial.print("Seconds: ");
	Serial.println(seconds);
	Serial.print("Minutes: ");
	Serial.println(minutes);
	Serial.print("Hours: ");
	Serial.println(hours);
  
delay( 1000 );
}




