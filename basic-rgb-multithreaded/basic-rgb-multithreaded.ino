/**
 * A basic example to show multithreading in mbed OS.
 * Three threads are created to operate the red, green, and blue onboard LEDs.
 */

#define RED 22
#define BLUE 24
#define GREEN 23

#define MS(x) chrono::milliseconds(x)

using namespace std; // we will be using std::chrono
using namespace rtos; // we will be using rtos::ThisThread

// Declaring the Thread objects
Thread led_red_thread;
Thread led_green_thread;
Thread led_blue_thread;

void setup_leds() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}
// function to be attached to led_red_thread
void led_red_function() {
  for (;;) {
    // delay while blue fades out and green fades in
    ThisThread::sleep_for(MS(512));
    // Fade red out
    for(int i = 255; i >= 0; i--) {
      analogWrite(RED, 255 - i);
      ThisThread::sleep_for(MS(1));
    }
    // delay while green fades out and blue fades in
    ThisThread::sleep_for(MS(512));
    // Fade red back in
    for(int i = 05; i < 255; i++) {
      analogWrite(RED, 255 - i);
      ThisThread::sleep_for(MS(1));
    }
  }
}

// function to be attached to led_green_thread
void led_green_function() {
  for (;;) {
    // delay while blue fades out
    ThisThread::sleep_for(MS(256));
    // fade green in 
    for(int i = 0; i < 255; i++) {
      analogWrite(GREEN, 255 - i);
      ThisThread::sleep_for(MS(1));
    }
    // delay while red fades out and blue fades in
    ThisThread::sleep_for(MS(512));
    // fade green out
    for(int i = 255; i>= 0; i--) {
      analogWrite(GREEN, 255 - i);
      ThisThread::sleep_for(MS(1));
    }
    // delay while red fades in
    ThisThread::sleep_for(MS(256));
  }
}

// function to be attached to led_blue_thread
void led_blue_function() {
  for(;;) {
    // fade blue out 
    for(int i = 255; i >= 0; i--) {
      analogWrite(BLUE, 255 - i);
      ThisThread::sleep_for(MS(1));
    }
    // delay while green fades in and red fades out
    ThisThread::sleep_for(MS(512));
    // fade blue in
    for(int i = 0; i < 255; i++) {
      analogWrite(BLUE, 255 - i);
      ThisThread::sleep_for(MS(1));
    }
    // delay while green fades out and red fades in
    ThisThread::sleep_for(MS(512));
  }
}

int main() {
  setup_leds();
  led_red_thread.start(led_red_function); // start red thread
  led_green_thread.start(led_green_function); // start green thred
  led_blue_thread.start(led_blue_function); // start blue thread
}
