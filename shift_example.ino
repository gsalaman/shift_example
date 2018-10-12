#define DATA_PIN  A0
#define CLK_PIN   A1

void write_bit(int bit)
{
  digitalWrite(DATA_PIN, bit);
  digitalWrite(CLK_PIN, HIGH);
  digitalWrite(CLK_PIN, LOW);
}

void setup() 
{
  Serial.begin(9600);

  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLK_PIN, OUTPUT);

  // Make sure both lines are low
  digitalWrite(DATA_PIN, LOW);
  digitalWrite(CLK_PIN, LOW);
  
  // shift in 0,0 to clear flops
  write_bit(0);
  write_bit(0);

}

void loop() 
{

  static int cnt=0;

  // count in binary from 0 to 3, shifting in that number to our two outputs.  
  // We're gonna do this once every 2 seconds, but the shifts are gonna happen at 250 ms intervals so we can see them.
  switch (cnt)
  {
    case 0:
      write_bit(0);
      delay(250);
      write_bit(0);
    break;

    case 1:
      write_bit(0);
      delay(250);
      write_bit(1);
    break;

    case 2:
      write_bit(1);
      delay(250);
      write_bit(0);
    break;

    case 3:
      write_bit(1);
      delay(250);
      write_bit(1);
    break;
  }

  cnt++;
  if (cnt > 3) cnt = 0;

  delay(1750);

}
