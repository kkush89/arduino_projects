
//establish temperature input pin and baseline temperature

const int Sensor_Pin = A0;
float Background_Temp = 0; //to be calibrated

//LED digital pins
const int Yellow_LED = 4;
const int Green_LED = 3;
const int Red_LED = 2;

//constants for voltage conversion
const float Max_Voltage = 5.0;
const float Number_Of_Possible_Values = 1024;


//function to turn on LEDs to match temperature
void Led_Control (float temp, int pins[], int total_number);
void Turn_On_Off(int pins[], int number_of_pins, int state []);
const int On = 1;
const int Off = 0;
  

void setup() {

  //open serial port
  Serial.begin(9600);

  //set digital pins 2,3,4 to control LEDS; off at the start
  for (int i = Red_LED; i <= Yellow_LED; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }

  //set baseline temperature from first 10 readings
  int number_of_readings = 100;
  float sum_of_readings = 0;
  for(int i = 1; i <= number_of_readings; i++){
    sum_of_readings = sum_of_readings + analogRead(Sensor_Pin);
  }

  //average for background

  float Average_Voltage = ((sum_of_readings/number_of_readings)/Number_Of_Possible_Values) * Max_Voltage;
  Background_Temp = (Average_Voltage - 0.5) * 100;

}

void loop() {

  
  int Sensor_Input = analogRead(Sensor_Pin);
  
  //put value on serial monitor
  Serial.print("Sensor Value: ");
  Serial.print(Sensor_Input);

  //convert the sensor value to voltage ; val/1024 * 5
  float Sensor_Voltage = (Sensor_Input/Number_Of_Possible_Values) * Max_Voltage ;

  //Put the voltage on the serial monitor
  Serial.print(" , Volts: ");
  Serial.print(Sensor_Voltage);

  //get corresponding temperature and print
  float temperature = (Sensor_Voltage - 0.5 ) * 100;
  Serial.print(" , degrees C: ");
  Serial.println(temperature);

  //pins to turn on/off
  int total_number = 3;
  int pins [total_number] = {Red_LED, Green_LED, Yellow_LED};

  Led_Control (temperature, pins, total_number);

  delay(1);
}

void Led_Control (float temp, int pins[], int total_number){

  int LED_State [total_number] = {Off, Off, Off};
  int number_of_pins_off;
  
  //turn all off for low temperature
  if (temp < (Background_Temp + 2)){
      number_of_pins_off = 3;
  }
  //turn one LED for slightly higher temperature
  else if(temp >= (Background_Temp + 2) && temp < (Background_Temp + 4)){
    number_of_pins_off = 2;
  }
  else if(temp >= (Background_Temp + 4) && temp < (Background_Temp + 6)){
    number_of_pins_off = 1;
  }
  else if (temp > Background_Temp + 6){
    number_of_pins_off = 0;
  }

  Serial.print("How many should be off: ");
  Serial.println(number_of_pins_off);

  //call function to turn off the LEDS
  //all on
  if(number_of_pins_off == 0){
    for(int i = 0; i <= total_number; i++){
      LED_State[i] = On;
      Turn_On_Off (pins, total_number, LED_State);
    }
  }
  //all off
  else if (number_of_pins_off == 3){
     Turn_On_Off (pins, total_number, LED_State);
  }
  else{
    //turn off what needs to be off
    for(int i = 0; i < number_of_pins_off; i++){
      LED_State[i] = Off;
    }

    //turn on the rest
    for(int i = (total_number - 1); i >= number_of_pins_off; i--){
      LED_State[i] = On;
    }

    Turn_On_Off (pins, total_number, LED_State);
  }

  
}

void Turn_On_Off(int pins[], int number_of_pins, int state []){


  for (int i = 0; i <= number_of_pins; i++){
    if( state[i] == On){
       //turn on the corresponding LED
       digitalWrite(pins[i], HIGH);
    }
    else if(state[i] == Off){
      //turn off the corresponding LED
      digitalWrite(pins[i], LOW);
    }
  }
}
