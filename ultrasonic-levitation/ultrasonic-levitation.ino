byte TP = 0b10101010; // every 2nd port gets the reverse signal 
void setup() 
{ 
DDRC = 0b11111111; // define all analog ports as output 
  // initialize timer 1 
  noInterrupts(); // Disable interrupts 
  TCCR1A = 0; 
  TCCR1B = 0; 
  TCNT1 = 0; 
  OCR1A = 200; // Set Compare Match Register(16MHz / 200 = 80kHz square wave -> 40kHz full wave) 
  TCCR1B |= (1 << WGM12); // CTC mode 
  TCCR1B |= (1 << CS10); // Prescaler to 1 ==> no prescaling 
  TIMSK1 |= (1 << OCIE1A); // Enable compare timer interrupt 
  interrupts(); // Enable interrupts 
} 
ISR(TIMER1_COMPA_vect)          
{ 
  PORTC = TP; // send the value TP to the outputs 
  TP = ~TP; // invert TP for the next run 
} 
void loop(){ 
  // nothing left to do here :-( 
}