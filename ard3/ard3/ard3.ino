/////Universal/////
int To;
int T;
/////

/////ACCELORATION/////
int Ao;         //Rest Acceloration Read
int AccConv;   //Converertion factor from analog in to acceloration
int AccPin=0;   //Acceloration read from analogIn 1
int Ax;         //Acceloration Value
int vel;        //velocity
int pos;        //position
/////

/////Temperature/////
int Temp;
int TempPin=1;
/////

/////Pressure/////
int Press;
int PressPin=2;
/////


void setup() {
  Serial.begin(9600);
  
  Ao = analogRead(AccPin);
  vel=0, pos=0, To=0, T=0;  
  AccConv=0;
}

void loop() {
  To=millis();
  Ax = (analogRead(AccPin) - Ao);//      /AccConv;    //current Acc
  vel+=Ax * T;
  pos+=vel * T;
  T=millis()-To;

}
