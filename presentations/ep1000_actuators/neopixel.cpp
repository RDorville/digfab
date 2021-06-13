
// using Adafruit Neopixel library
#include <Adafruit_NeoPixel.h>
const int PIN = 12;		// digitalIO pin
const int NUMPIX = 8;	// num of neopix
// create a neopixel object
Adafruit_NeoPixel np = Adafruit_NeoPixel(
		NUMPIX, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600);
  np.setBrightness(128);
}

void loop()
{
  // flash all, R->G->B
  unsigned long c = np.Color(255,0,0);
  flash(c);
  c = np.Color(0,255,0);
  flash(c);
  c = np.Color(0,0,255);
  flash(c);
  // scroll random lights
  for (int i=0; i<10; ++i)
    runLights();
}

void runLights()
{
  const int DLY = 100;
  int r, g, b;
  // obtain a random color
  r = random(256); g = random(256); b = random(256);
  unsigned long c = np.Color(r,g,b);
  for (int p=0; p < NUMPIX; ++p)
  {
    np.setPixelColor(p, c);
    np.show();
    delay(DLY);
  }
}

void flash(unsigned long c)
{
  np.fill(c, 0, NUMPIX);
  np.show();
  delay(500);
  // clear
  np.clear();
  np.show();
  delay(500);
}

