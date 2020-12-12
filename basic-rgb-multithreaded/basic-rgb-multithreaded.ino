#define RED 22
#define BLUE 24
#define GREEN 23

#define MS(x) chrono::milliseconds(x)

using namespace std;
using namespace rtos;

Thread led_red_thread;
Thread led_green_thread;
Thread led_blue_thread;

void setup_leds() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void led_red_function() {
  for (;;) {
    ThisThread::sleep_for(MS(512));
    for(int i = 255; i >= 0; i--) {
      analogWrite(RED, 255 - i);
      ThisThread::sleep_for(MS(1));
    }
    ThisThread::sleep_for(MS(512));
    for(int i = 05; i < 255; i++) {
      analogWrite(RED, 255 - i);
      ThisThread::sleep_for(MS(1));
    }
  }
}

void led_green_function() {
  for (;;) {
    ThisThread::sleep_for(MS(256));
    for(int i = 0; i < 255; i++) {
      analogWrite(GREEN, 255 - i);
      ThisThread::sleep_for(MS(1));
    }
    ThisThread::sleep_for(MS(512));
    for(int i = 255; i>= 0; i--) {
      analogWrite(GREEN, 255 - i);
      ThisThread::sleep_for(MS(1));
    }
    ThisThread::sleep_for(MS(256));
  }
}

void led_blue_function() {
  for(;;) {
    for(int i = 255; i >= 0; i--) {
      analogWrite(BLUE, 255 - i);
      ThisThread::sleep_for(MS(1));
    }
    ThisThread::sleep_for(MS(512));
    for(int i = 0; i < 255; i++) {
      analogWrite(BLUE, 255 - i);
      ThisThread::sleep_for(MS(1));
    }
    ThisThread::sleep_for(MS(512));
  }
}
int main() {
  setup_leds();
  led_red_thread.start(led_red_function);
  led_green_thread.start(led_green_function);
  led_blue_thread.start(led_blue_function);
}
