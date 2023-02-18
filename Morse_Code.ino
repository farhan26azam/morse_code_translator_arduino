int pin1 = 13;
int pin2 = 12;
int seconds = 1000;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  Serial.begin(9600);
}
void on(int sec){
    digitalWrite(pin1, HIGH);   
    digitalWrite(pin2, HIGH);
    delay(sec *seconds);
}
void off(int sec){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    delay(sec *seconds);
}
void loop() {
  char code[]="- .... .     -... .. .-. -..     .-- .- ...     ..-. .-.. -.-- .. -. --.     - --- .-- .- .-. -.. ...     - .... .     .-. --- --- --   ";
  int i=0;
  for(i; i< sizeof(code)/sizeof(code[0]); i++){
    if(code[i]=='-'){
      on(3);
      off(1);
    }
    else if(code[i]==' ' && code[i+1] != ' '){
      off(2);
    }
    else if(code[i] =='.'){
      on(1);
      off(1);
    }
    else if(code[i]==' ' && code[i+1]==' ' && code[i+2]==' '){
      off(4);
      i+=4;
    }
  }
}
