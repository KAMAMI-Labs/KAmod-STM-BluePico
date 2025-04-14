//Board: STM32 MCU Based Boards / Generic STM32F0 series
//Board part number: Generic F030F4Px
//Upload metod: STM32 Cube Programmer (Serial)

#define LED_PIN   PA4

int message_period = 0;
int port_pwm = 0;
int port_pwm_dir = 0;

//--------------------------------------
void setup() {
  //Serial.begin(115200);
  //Serial.println("KAmod BluePico STM32F030, Hello :)");
  pinMode(LED_PIN, OUTPUT);
}

//--------------------------------------
void loop() {
  analogWrite(LED_PIN, (255 - port_pwm));
  if (port_pwm_dir == 0){
    port_pwm += 20;
    if (port_pwm >= 150){
      port_pwm = 150;
      port_pwm_dir = 1;
    }
  } else {
    port_pwm -= 20;
    if (port_pwm <= 0){
      port_pwm = 0;
      port_pwm_dir = 0;
    }
  }

  delay(100); 
}
