#define COLUMN_1 1
#define COLUMN_2 2
#define COLUMN_3 3
#define COLUMN_4 4
#define COLUMN_5 5
#define LAYER_1 6
#define LAYER_2 7
#define LAYER_3 8
#define BLUE 9
#define GREEN 10
#define RED 11

#define delayTime 20

struct Pin{
  int column;
  int layer;
};

void setup() {

  for(int i = 2; i < 12; i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,HIGH);
  }
  /*pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(RED, HIGH);
  */
}

// Siyaman
Pin randomPin(){
  Pin newPin;
  newPin.column = random(1,6);
  newPin.layer = random(1,4);
  return newPin;
}
// Siyaman
Pin enableRandomPin(Pin oldPin){
    // Turn off old pin    
    digitalWrite(oldPin.column,LOW);
    digitalWrite(oldPin.layer,LOW);
    oldPin = randomPin();
    // Turn on new random pin
    digitalWrite(oldPin.column,HIGH);
    digitalWrite(oldPin.layer,HIGH);
    return oldPin;
}

int redVal;
int blueVal;
int greenVal;

void loop() {
  pinMode(1, OUTPUT);
  digitalWrite(1, HIGH);

//  Pin enabledPin = randomPin();
  int redVal = 255;
  int blueVal = 0;
  int greenVal = 0;
  for ( int i = 0 ; i < 255 ; i += 1 ) {
    greenVal += 1;
    redVal -= 1;
    analogWrite( GREEN, 255 - greenVal );
    analogWrite( RED, 255 - redVal );
//    enabledPin = enableRandomPin(enabledPin);

    delay( delayTime );
  }

  redVal = 0;
  blueVal = 0;
  greenVal = 255;
  for ( int i = 0 ; i < 255 ; i += 1 ) {
    blueVal += 1;
    greenVal -= 1;
    analogWrite( BLUE, 255 - blueVal );
    analogWrite( GREEN, 255 - greenVal );
//    enabledPin = enableRandomPin(enabledPin);

    delay( delayTime );
  }

  redVal = 0;
  blueVal = 255;
  greenVal = 0;
  for ( int i = 0 ; i < 255 ; i += 1 ) {
    redVal += 1;
    blueVal -= 1;
    analogWrite( RED, 255 - redVal );
    analogWrite( BLUE, 255 - blueVal );
//    enabledPin = enableRandomPin(enabledPin);

    delay( delayTime );
  }
}


