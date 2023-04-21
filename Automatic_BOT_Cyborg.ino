
//Output pins of motor are initialised.
int enA=3;
int enB=6;
int Ain1=2;
int Ain2=4;
int Bin3=5;
int Bin4=7;

//Input pins of IR Sensors are initialised.
// int LF=A0;
int LN=A1;
int CUL=A2;
int CDL=A3;
int CUR=A4;
int CDR=A5;
int RN=A6;
// int RF=A7;

int timetrack=20;
int key1=0;
int key2=0;

//Initialising few constants and important variables
int Aspeed=0;
int Bspeed=0;
int infi=0;
void setup() 
{
  Serial.begin(9600);
  // stating all my output pins as output.
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(Ain1,OUTPUT);
  pinMode(Ain2,OUTPUT);
  pinMode(Bin3,OUTPUT);
  pinMode(Bin4,OUTPUT);

  //stating all my input pins as input.
  
  pinMode(LN,INPUT);
  pinMode(CUL,INPUT);
  pinMode(CDL,INPUT);
  pinMode(CUR,INPUT);
  pinMode(CDR,INPUT);
  pinMode(RN,INPUT);
  // pinMode(RF,INPUT);

  //Initialising the motors to remain off at zero speed.
  analogWrite(enA,Aspeed);
  analogWrite(enB,Bspeed);
  digitalWrite(Ain1,LOW);
  digitalWrite(Ain2,LOW);
  digitalWrite(Bin3,LOW);
  digitalWrite(Bin4,LOW);

}

//Code to perform various movement in the bot

void Forward()
{
  //Assuming A motor is on left side and B motor is on right side
  // A motor control
  // timetrack=timetrack+5;
  // if(timetrack==100)
  // {
  //   timetrack=20;
  // }  
  Aspeed=50;
  //  B motor control
  Bspeed=60;

  analogWrite(enA,Aspeed);
  analogWrite(enB,Bspeed);
  digitalWrite(Ain1,LOW);
  digitalWrite(Ain2,HIGH);
  digitalWrite(Bin3,HIGH);
  digitalWrite(Bin4,LOW);

}
void SlowForward()
{
  //Assuming A motor is on left side and B motor is on right side
  // A motor control
  Aspeed=40;
  //  B motor control
  Bspeed=55;

  analogWrite(enA,Aspeed);
  analogWrite(enB,Bspeed);
  digitalWrite(Ain1,LOW);
  digitalWrite(Ain2,HIGH);
  digitalWrite(Bin3,HIGH);
  digitalWrite(Bin4,LOW);
}
// void Reverse()
// {
  
//   //Assuming A motor is on left side and B motor is on right side
//   // A motor control
//   Aspeed=50;
//   //  B motor control
//   Bspeed=50;

//   analogWrite(enA,Aspeed);
//   analogWrite(enB,Bspeed);
//   digitalWrite(Ain1,LOW);
//   digitalWrite(Ain2,HIGH);
//   digitalWrite(Bin3,HIGH);
//   digitalWrite(Bin4,LOW);
// }
void Smallleft()
{
  //Assuming A motor is on left side and B motor is on right side
  // A motor control
  Aspeed=47;
  //  B motor control
  Bspeed=63;

  analogWrite(enA,Aspeed);
  analogWrite(enB,Bspeed);
  digitalWrite(Ain1,LOW);
  digitalWrite(Ain2,HIGH);
  digitalWrite(Bin3,HIGH);
  digitalWrite(Bin4,LOW);
}
void Smallright()
{
  //Assuming A motor is on left side and B motor is on right side
  // A motor control
  Aspeed=60;
  //  B motor control
  Bspeed=47;

  analogWrite(enA,Aspeed);
  analogWrite(enB,Bspeed);
  digitalWrite(Ain1,LOW);
  digitalWrite(Ain2,HIGH);
  digitalWrite(Bin3,HIGH);
  digitalWrite(Bin4,LOW);
}
void Sharpleft()
{
//Assuming A motor is on left side and B motor is on right side
  // A motor control
  Aspeed=50;
  //  B motor control
  Bspeed=100;

  analogWrite(enA,Aspeed);
  analogWrite(enB,Bspeed);
  digitalWrite(Ain1,HIGH);
  digitalWrite(Ain2,LOW);
  digitalWrite(Bin3,HIGH);
  digitalWrite(Bin4,LOW);  
}
void Sharpright()
{
  //Assuming A motor is on left side and B motor is on right side
  // A motor control
  Aspeed=100;
  //  B motor control
  Bspeed=50;

  analogWrite(enA,Aspeed);
  analogWrite(enB,Bspeed);
  digitalWrite(Ain1,HIGH);
  digitalWrite(Ain2,LOW);
  digitalWrite(Bin3,HIGH);
  digitalWrite(Bin4,LOW);
}

//Code for Bot to follow in case it is in whiteline follower mode.

void whiteline_follow(int LN_val,int CUL_val,int CDL_val,int CUR_val,int CDR_val,int RN_val)
{
  if(key1==0)
  {
  //Code for traversing slight turns and correcting small unnecessary rotation of bot
  if(CUL_val==1 || RN_val==0)
  {
    
    Smallright();
       
  }
  else if(CUR_val==1 || LN_val==0)
  {
    
    Smallleft();
    
  }
  
  else
  {
    //Basic forward motion  
    SlowForward();
  }
  }
  else if(key1>0)
  {
    //Code for traversing slight turns and correcting small unnecessary rotation of bot

  if(LN_val==0 && RN_val==0) 
  {
    
    Smallright();
    
  } 
  else if(CUL_val==1 || RN_val==0)
  {
    
      if(LN_val==0 || CUR_val==0)
      {
        key2=1;
      }
    Smallright();
       
  }
  else if(CUR_val==1 || LN_val==0)
  {
    
    Smallleft();
    
  }
  
  else
  {
    //Basic forward motion  
    SlowForward();
  }
  }
}

//Code for Bot to follow in case it is in blackline follower mode.

void blackline_follow(int LN_val,int CUL_val,int CDL_val,int CUR_val,int CDR_val,int RN_val)
{
  //Code for traversing slight turns and correcting small unnecessary rotation of bot
  if(CUL_val==0 || RN_val==1)
  {
    
    Smallright();
   
  }
  else if(CUR_val==0 || CUL_val==1)
  {
  
    Smallleft();
    
  }

  
  else
  {
    //Basic forward motion  
    SlowForward();    
  }
}

//Code for Bot to follow in case it is in edge follower mode.

void edge_follow(int LN_val,int CUL_val,int CDL_val,int CUR_val,int CDR_val,int RN_val)
{
  // To decide the orientation of black and white in edge follower case
  if(CDL_val==1 && CDR_val==0)
  {
    if(LN_val==0 && CUL_val==0)
    {
      
      Smallleft(); 
          
    }
  else if(RN_val==1 && CUR_val==1)
    {
      
      Smallright(); 
              
    }

  
    else
    {
      //Basic forward motion  
      SlowForward();    
    }
  }
  else if(CDL_val==0 && CDR_val==1)
  {
    if(LN_val==1 && CUL_val==1)
    {
      
      Smallleft(); 
       
           
    }
  else if (RN_val==0 && CUR_val==0)
    {
      
      Smallright(); 
             
    }
  }
else
    {
      //Basic forward motion  
      SlowForward();    
    }  
}


void loop() 
{
  
  //taking input from all ground sensors.
  
  
  int LN_val = analogRead(LN);  
  int CUL_val = analogRead(CUL);
  int CDL_val = analogRead(CDL);
  int CUR_val = analogRead(CUR);
  int CDR_val = analogRead(CDR);
  int RN_val = analogRead(RN);

  //converting analog input into digital as we know that we are obtaining from only two colors(Black and White).
  //Hence, we have assigned black and white --> 1 and 0 respectively.
  //This helps us to process the inputs in a more convenient way.
  
  if(LN_val>500)
  {
    LN_val=1;    
  }
  else if(LN_val<=500)
  {
    LN_val=0;
  }

  if(CUL_val>500)
  {
    CUL_val=1;    
  }
  else if(CUL_val<=500)
  {
    CUL_val=0;
  }

  if(CDL_val>500)
  {
    CDL_val=1 ;   
  }
  else if(CDL_val<=500)
  {
    CDL_val=0;
  }

  if(CUR_val>500)
  {
    CUR_val=1 ;   
  }
  else if(CUR_val<=500)
  {
    CUR_val=0;
  }

  if(CDR_val>500)
  {
    CDR_val=1 ;   
  }
  else if(CDR_val<=500)
  {
    CDR_val=0;
  }

  if(RN_val>500)
  {
    RN_val=1 ;   
  }
  else if(RN_val<=500)
  {
    RN_val=0;
  }
  

// Now we have all inputs in the form of 0s and 1s.
//We will proceed to process these obtained inputs and deduce the current state of the bot. 

//If all the four central inputs are white, 
//Or if just the two central down inputs are white,
//Then Bot is in White line follower state.
// Or if just the two central down inputs are white
  if((CUL_val==CDL_val && CDL_val==CDR_val && CUR_val==CDR_val && CDR_val==0) || (CDL_val==CDR_val && CDR_val==0))
  {
    whiteline_follow(LN_val,CUL_val,CDL_val,CUR_val,CDR_val,RN_val);
  }

//If all the four central inputs are black, 
//Or if just the two central down inputs are black,
//Then Bot is in Black line follower state.

  else if((CUL_val==CDL_val && CDL_val==CDR_val && CUR_val==CDR_val && CDR_val==1) || (CDL_val==CDR_val && CDR_val==1))
  {
    blackline_follow(LN_val,CUL_val,CDL_val,CUR_val,CDR_val,RN_val);
    key1=1;
  }

//If two inputs on either side are same and other two have different value,
//Or if just the two central down inputs are different,
//Then Bot is in Edge Follower state

  else if((CUL_val==CDL_val && CUR_val==CDR_val && CDR_val!=CDL_val) || (CDL_val!=CDR_val))
  {
    edge_follow(LN_val,CUL_val,CDL_val,CUR_val,CDR_val,RN_val);
  }
}
  
