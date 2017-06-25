#define DISTANCE 1

int StepCounter = 0;
int Stepping = false;

void setup() 
  {
  pinMode(8, OUTPUT);  // to cntrl direction
  pinMode(9, OUTPUT);  // to step one step 
  
  digitalWrite(8, LOW);     // no-step
  digitalWrite(9, LOW);     //  direction

  pinMode(2, INPUT);  // physical button step-up
  pinMode(4, INPUT);  // GUI button step-up
  
  
  pinMode(3, INPUT);  // physical button step-down
  pinMode(5, INPUT);   // GUI button step-down
}

void loop() 
  {
  if ((digitalRead(3) == LOW || digitalRead(4) == LOW) && Stepping == false)
    {
     digitalWrite(8, LOW);
      Stepping = true;
    }
  
  if ((digitalRead(2) == LOW || digitalRead(5) == LOW) && Stepping == false)
    {
    digitalWrite(8, HIGH);
    Stepping = true;
    }

  if (Stepping == true)
    {
    digitalWrite(9, HIGH);
    delay(1);
    digitalWrite(9, LOW);
    delay(1);
    StepCounter = StepCounter + 1;
    if (StepCounter == DISTANCE)
       {
        StepCounter = 0;
        Stepping = false;
        }
    }
  }

