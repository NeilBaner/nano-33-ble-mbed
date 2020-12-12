using namespace std;
using namespace rtos;

#define MS(x) chrono::milliseconds(x)

int main() {
  pinMode(13, OUTPUT);
  for(;;) {
    digitalWrite(13, HIGH);
    ThisThread::sleep_for(MS(500));
    digitalWrite(13, LOW);
    ThisThread::sleep_for(MS(500));
  }
}
