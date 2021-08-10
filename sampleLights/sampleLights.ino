
int Green_In = 12;
int Red_In = 7;
int Yellow_In = 13;

//array to contain light outputs
int Light_Pins[] = { Green_In, Red_In, Yellow_In };


void setup() {
  
  // put your setup code here, to run once:
  pinMode(Green_In, OUTPUT);
  pinMode(Red_In, OUTPUT);
  pinMode(Yellow_In, OUTPUT);
}

void loop() {

//turn off all lights
 digitalWrite(Green_In, LOW);
 digitalWrite(Red_In, LOW);
 digitalWrite(Yellow_In, LOW);

 delay(100);

 int Number_Of_Options = sizeof(Light_Pins) / sizeof(Light_Pins[0]);
 
// choose which light to turn on
    int Old_Rand_Num = random(0, Number_Of_Options);

//turn on the first light
    digitalWrite(Light_Pins[Old_Rand_Num], HIGH);

//choose new light to turn on
    int new_Rand = random(0, Number_Of_Options);

    //change the newly selected pin if necassary
    while (Old_Rand_Num == new_Rand) {

        // choose a different light
        new_Rand = random(0, Number_Of_Options);
    }

//turn off the previous light
  digitalWrite(Light_Pins[Old_Rand_Num], LOW);

  delay(100);
  
//turn on the next light
  digitalWrite(Light_Pins[new_Rand], HIGH);

  delay(100);

}
