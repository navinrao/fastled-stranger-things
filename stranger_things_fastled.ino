
// Import Statements
// Read more here: https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries
#define FASTLED_ESP8266_NODEMCU_PIN_ORDER
#include <FastLED.h>

#define NUM_LEDS 50
#define DATA_PIN 4
char text = 'run';
CRGB leds[NUM_LEDS];
/* 
  delay(1000): This is a 1 second delay
  ASCII value of 'a' is 97 and 'z' is 122
*/

void setup() {
  // Entry Point
  Serial.begin(115200);
  pinMode(16, OUTPUT);
  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS); 
  // FASTLED.setMaxPowerInVoltsAndMilliamps(5, 500);
}

void loop() {
  // Mandatory loop that will continue to run indefinitely while powered on
  delay(1000); // delay for interruption
  Serial.println("Hello World"); 
  digitalWrite(16, HIGH);
  delay(500);
  digitalWrite(16, LOW);

  int displayedWord = random(0, 4);
  switch (displayedWord)
  {
  case 0:
    message("run");
    break;
  case 1:
    message("help");
    break;
  case 2:
    message("hello");
    break;
  case 3:
    chaseForward();
    flashAll();
    break;
  }
}
void message(char *text) {
  size_t length = strlen(text);
  for (int i = 0; i < length; i++)
  {
    int index = lookupChar(text[i]);
    if (index >= 0)
    {
      leds[index] = CRGB(CRGB::White);
      FastLED.show();
      delay(2000);
      FastLED.clear();
      FastLED.show();
      delay(250);
    }
    else
    {
      // Space, punctuation, etc.
      delay(1500);
    }
  }

  delay(1000);
  flashAll();
}

void flashAll() {
  Serial.println("In flashAll");
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Red;
    FastLED.show();
  }
  delay(1000);
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
    FastLED.show();
  }
  delay(1000);
}
void chaseForward(){
  for(int dot = NUM_LEDS; dot >=0 ; dot--) { 
    leds[dot] = CRGB::Blue;
    FastLED.show();
    leds[dot] = CRGB::Black;
    delay(50);
  }
}

int lookupChar(char c)
{
  switch (c)
  {
  case 'a':
    return 0;
    break;
  case 'b':
    return 2;
    break;
  case 'c':
    return 4;
    break;
  case 'd':
    return 6;
    break;
  case 'e':
    return 8;
    break;
  case 'f':
    return 10;
    break;
  case 'g':
    return 12;
    break;
  case 'h':
    return 14;
    break;
  case 'i':
    return 15;
    break;
  case 'j':
    return 17;
    break;
  case 'k':
    return 19;
    break;
  case 'l':
    return 21;
    break;
  case 'm':
    return 22;
    break;
  case 'n':
    return 49;
    break;
  case 'o':
    return 47;
    break;
  case 'p':
    return 45;
    break;
  case 'q':
    return 43;
    break;
  case 'r':
    return 42;
    break;
  case 's':
    return 40;
    break;
  case 't':
    return 38;
    break;
  case 'u':
    return 36;
    break;
  case 'v':
    return 34;
    break;
  case 'w':
    return 32;
    break;
  case 'x':
    return 30;
    break;
  case 'y':
    return 28;
    break;
  case 'z':
    return 27;
    break;
  default:
    return -1;
    break;
  }
}


  // for (int i = 0; i < text.length(); i++) {
  //   // subtract ASCII code of 'a' by code of letter to get position in leds[]. Set that led and show
  //   //text[i]


  // }

