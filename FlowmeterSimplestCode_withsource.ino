//SimplestCode
//with source https://www.youtube.com/watch?v=M4MipaQM14A


int flowPin = 2; //declare pin # Question if one of my TX RX is pin 2 or 3 where else should I put my pin for the flow sensor?
double flowRate;
volatile int count; //count is changed in the next function

void setup() {
  pinMode(flowPin, INPUT);         
  attachInterrupt(0, Flow, RISING); //digitalpin2 is interrupt 0, flow is a function increasing the count ++, rising signal goes from low to high
  Serial.begin(9600); 
}
void loop() {
  count = 0;// initial count     
  interrupts();  //enables the input to arduino board
  delay (1000);   //1 sec
  noInterrupts(); //no iput 
  flowRate = (count / 7.75); //7.75 callibration factor datasheet of sensor , count is the frequency
  Serial.println(String(flowRate)+"L/min");      
  
}
 
void Flow()
{
   count++; 
}
