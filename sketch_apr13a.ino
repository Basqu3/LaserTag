/*

*/

#define X 9 // X coords on pin 9
#define Y 10 // Y coords on pin 10
#define Photo 0 //photovoltaic in is connected to pin A0

int lightThreshold = 1020;
int lightVal;
bool recent=false;

int counter = 0; //used to count hits. Display it on lazer
const int dt = 750; // time delay between autograph points, in microseconds.
const int N = 10; // Number of elements each in arrays x and y, following.

const byte x0[] PROGMEM = {112, 112, 143, 143, 112, 112, 143, 143, 112, 143}; //32 as a base width
const byte y0[] PROGMEM = {127, 206, 206, 127, 127, 206, 206, 127, 127, 127}; //80 as a base height

const byte x1[] PROGMEM = {112, 127, 127, 120, 127, 112, 143, 112, 143, 143}; //32 as a base width
const byte y1[] PROGMEM = {127, 127, 206, 206, 206, 127, 127, 127, 127, 127}; //80 as a base height

const byte x2[] PROGMEM = {112, 127, 143, 143, 127, 143, 143, 127, 127, 143}; //32 as a base width
const byte y2[] PROGMEM = {127, 166, 166, 206, 206, 206, 166, 166, 127, 127}; //80 as a base height

const byte x3[] PROGMEM = {112, 143, 143, 127, 143, 143, 112, 143, 143, 143}; //32 as a base width
const byte y3[] PROGMEM = {127, 127, 166, 166, 166, 206, 206, 206, 127, 127}; //80 as a base height

const byte outX[] PROGMEM = {127, 112, 143, 127, 112, 143, 127, 112, 143, 127}; //32 as a base width
const byte outY[] PROGMEM = {166, 127, 206, 166, 206, 127, 166, 127, 206, 166}; //80 as a base height


void setup() {
  TCCR1B = TCCR1B & 0b11111000 | 1;
  Serial.begin(9600);
  pinMode(X, OUTPUT);
  pinMode(Y, OUTPUT);
}

void loop() {
  lightVal = analogRead(Photo);
  Serial.print(lightVal);
  Serial.print("->");
  
  if((lightVal>lightThreshold)&&(recent==false)){ //checking light levels. adjust lightThreshold if too easy to trigger
    counter++;
    recent=true;
  }else{
    recent=false;
  }
  Serial.println(counter);
  
  int j=0;
  if(counter==0){
    do {
      for (int i = 0; i < N; i++) {
       int xT = (int)(pgm_read_byte(&x0[i]));
        int yT = (int)(pgm_read_byte(&y0[i]));
        analogWrite(X, xT);
        analogWrite(Y, yT);
        delayMicroseconds(dt);
      }
      j++;
    } while (j<1000);  
  }
  
  if(counter==1){
    do {
      for (int i = 0; i < N; i++) {
       int xT = (int)(pgm_read_byte(&x1[i]));
        int yT = (int)(pgm_read_byte(&y1[i]));
        analogWrite(X, xT);
        analogWrite(Y, yT);
        delayMicroseconds(dt);
      }
      j++;
    } while (j<1000);  
  }
  
  if(counter==2){
    do {
      for (int i = 0; i < N; i++) {
       int xT = (int)(pgm_read_byte(&x2[i]));
        int yT = (int)(pgm_read_byte(&y2[i]));
        analogWrite(X, xT);
        analogWrite(Y, yT);
        delayMicroseconds(dt);
      }
      j++;
    } while (j<1000);  
  }
  
  if(counter==3){
    do {
      for (int i = 0; i < N; i++) {
       int xT = (int)(pgm_read_byte(&x3[i]));
        int yT = (int)(pgm_read_byte(&y3[i]));
        analogWrite(X, xT);
        analogWrite(Y, yT);
        delayMicroseconds(dt);
      }
      j++;
    } while (j<1000);  
  }

  if(counter>3){
    do {
      for (int i = 0; i < N; i++) {
       int xT = (int)(pgm_read_byte(&outX[i]));
        int yT = (int)(pgm_read_byte(&outY[i]));
        analogWrite(X, xT);
        analogWrite(Y, yT);
        delayMicroseconds(dt);
      }
      j++;
    } while (j<1000);  
  }

  delay(1000);
}
