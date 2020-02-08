char val;
int enA = 3;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;
int cepet = 100;
int normal = 100;
int lambat = 100;

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop()
{
  if ( Serial.available() > 0 )
  {
    val = Serial.read();
    Serial.println(val);
    if ( val == 'U' )
    {
      maju();
    }
    else if ( val == 'F' )
    {
      maju();
    }
    else if ( val == 'D' )
    {
      mundur();
    }
    else if ( val == 'B' )
    {
      mundur();
    }
    else if ( val == 'L' )
    {
      kiri();
    }
    else if ( val == 'R' )
    {
      kanan();
    }
    else if ( val == 'C' )
    {
      berenti();
    }
    else if ( val == 'S' )
    {
      berenti();
    }
  }
}

void maju()
{
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, normal);   // set speed to 200 out of possible range 0~255

  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, normal);  // set speed to 200 out of possible range 0~255
}

void mundur()
{
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, normal);   // set speed to 200 out of possible range 0~255

  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, normal );  // set speed to 200 out of possible range 0~255
}

void kanan()
{
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in3, LOW);
  analogWrite(enA, cepet);   // set speed to 200 out of possible range 0~255

  // turn on motor B
  digitalWrite(in2, HIGH);
  digitalWrite(in4, HIGH);
  analogWrite(enB, cepet);  // set speed to 200 out of possible range 0~255
}

void kiri()
{
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in3, HIGH);
  analogWrite(enA, cepet);   // set speed to 200 out of possible range 0~255

  // turn on motor B
  digitalWrite(in2, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, cepet);  // set speed to 200 out of possible range 0~255
}



void berenti()
{
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
