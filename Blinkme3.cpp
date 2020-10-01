int ledpin=5;
int btnpin=2;
void setup() {

//Serial.begin(9600);
//pinMode(btnpin,INPUT_PULLUP);
//pinMode(ledpin,OUTPUT);
DDRD = B00100000; // sets the pin to input or output 
PORTD = B00000100; // firstly checks the state of pin in DDRD register.
                   // in case of input enables or disables internal pullup register...in case of output sets the pin to high or low .
}

void loop() {
  int btn = (_BV(btnpin)&PIND)>>2; // reading the state of btn pin 
  if(btn==HIGH){
    PORTD=_BV(ledpin)|PORTD;// turning led high and setting the bits 
  }
  else{
    PORTD = ~_BV(ledpin)&PORTD; // turning the led off and clearing the bits 
    };
 // Serial.println(btn);
}
