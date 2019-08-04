#define R1 0 
#define R2 1
#define R3 2
#define R4 3
#define Y1 4
#define Y2 5
#define Y3 6
#define Y4 7
#define G1 8
#define G2 9 
#define G3 10 
#define G4 11

bool R1_ON = false, R2_ON = false, R3_ON = false, R4_ON = false;
bool Y1_ON = false, Y2_ON = false, Y3_ON = false, Y4_ON = false;
bool G1_ON = false, G2_ON = false, G3_ON = false, G4_ON = false;
void setup() {
  pinMode(R1, OUTPUT);pinMode(R2, OUTPUT);pinMode(R3, OUTPUT);pinMode(R4, OUTPUT);
  pinMode(Y1, OUTPUT);pinMode(Y2, OUTPUT);pinMode(Y3, OUTPUT);pinMode(Y4, OUTPUT);
  pinMode(G1, OUTPUT);pinMode(G2, OUTPUT);pinMode(G3, OUTPUT);pinMode(G4, OUTPUT);
  }

void loop() {
 /* if(R1_ON == false && R2_ON == true && R3_ON == true && R4_ON == true) {R1 = true; R2_ON = false; R3_ON = false; R4_ON = false;}
  if(R1_ON == true && R2_ON == false && R3_ON == true && R4_ON == true) {R1 = false; R2_ON = true; R3_ON = false; R4_ON = false;}
  if(R1_ON == true && R2_ON == true && R3_ON == false && R4_ON == true) {R1 = false; R2_ON = false; R3_ON = true; R4_ON = false;}
  if(R1_ON == true && R2_ON == true && R3_ON == true && R4_ON == false) {R1 = false; R2_ON = false; R3_ON = false; R4_ON = true;}*/
  digitalWrite(R1, HIGH); digitalWrite(R2, LOW); digitalWrite(R3, LOW); digitalWrite(R4, LOW); 
    delay(5000); digitalWrite(R1, LOW); 
  digitalWrite(Y1, HIGH); digitalWrite(Y2, LOW); digitalWrite(Y3, LOW); digitalWrite(Y4, LOW); 
    delay(5000); digitalWrite(Y1, LOW); 
  digitalWrite(G1, HIGH); digitalWrite(G2, LOW); digitalWrite(G3, LOW); digitalWrite(G4, LOW); 
    delay(5000);
}
