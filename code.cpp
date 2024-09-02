#define ir1 4
#define ir2 6
#define ir3 7
int x1,x2,x3;
int pos;

#define right_en 5
#define r1 11 
#define r2 10
#define left_en 3
#define l1 8 
#define l2 9

int flag1, flag2, flag3;

int arr[3] = {0,0,0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ir3,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  x1 = digitalRead(ir1);
  x2 = digitalRead(ir2);
  x3 = digitalRead(ir3);

  if(x1 == 1)
  {
    // left
    pos = 0;
    analogWrite(right_en, 70);
    analogWrite(left_en, 70);
    digitalWrite(r2, LOW);
    digitalWrite(r1, HIGH);
    digitalWrite(l2, LOW);
    digitalWrite(l1, HIGH);
    flag1 = 1;
    flag2 = 0;
    flag3 = 0;
  }
  else if(x2 == 1)
  {
    // straight
    pos = 3500;
    analogWrite(right_en, 70);
    analogWrite(left_en, 70);
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    flag1 = 0;
    flag2 = 1;
    flag3 = 0;
  }
  else if(x3 == 1)
  {
    // right
    pos = 7000;
    analogWrite(right_en, 70);
    analogWrite(left_en, 70);
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(l1, LOW);
    digitalWrite(l2, HIGH);
    flag1 = 0;
    flag2 = 0;
    flag3 = 1;
  }
  else if (x1 == 0 &&  x2==0 && x3 == 0) {

    arr[0] = x1;
    arr[1] = x2;
    arr[2] = x3;
  // analogWrite(right_en, 0);
  // analogWrite(left_en, 0);

  if(flag3 == 1)
  {
    // left
    analogWrite(right_en, 100);
    analogWrite(left_en, 100);
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(l1, LOW);
    digitalWrite(l2, HIGH);
    
    
  }
  if(flag1 == 1)
  {
    // right
    analogWrite(right_en, 100);
    analogWrite(left_en, 100);
    digitalWrite(r2, LOW);
    digitalWrite(r1, HIGH);
    digitalWrite(l2, LOW);
    digitalWrite(l1, HIGH);
    
  }

  }

  Serial.print("ir1: ");
  Serial.print(x1);
  Serial.print(" ir2: ");
  Serial.print(x2);
  Serial.print(" ir3: ");
  Serial.print(x3);
  Serial.print(" pos: ");
  Serial.print(pos);
  Serial.print("flag1: ");
  Serial.print(flag1);
  Serial.print(" flag2: ");
  Serial.print(flag2);
  Serial.print(" flag3: ");
  Serial.println(flag3);



}
