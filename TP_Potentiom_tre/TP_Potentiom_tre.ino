/////////////////////////////
//SOLUTION I pour CodeCast.//
/////////////////////////////
const int analogInputPotentiometre = 14;

int valeur = 0;

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(analogInputPotentiometre, INPUT);
}

void loop() 
{
  valeur = analogRead(analogInputPotentiometre);
  //Potentiomètre à 0.
  if(valeur == 0) 
  {
    //Toutes les LEDs s'éteignent.
    for(int i=0; i<12; i++)
    {
      digitalWrite(i, LOW);
    }
  }

  //Potentiomètre au tiers, soit 341.
  else if(valeur < 1023/3) 
  {
    //Le premier FOR allume les LEDs.
    for(int i=0; i<4; i++)
    {
      digitalWrite(i, HIGH);
    }
    //Ce FOR éteint les LEDs.
    for(int i=4; i<12; i++)
    {
      digitalWrite(i, LOW);
    }
  }

  //Potentiomètre au deux tiers, soit 682.
  else if(valeur < 2*(1023/3)) 
  {
    for(int i=0; i<8; i++)
    {
      digitalWrite(i, HIGH);
    }
    for(int i=8; i<12; i++)
    {
      digitalWrite(i, LOW);
    }
  }
  
  //Potentiomètre au maximum de sa valeur, soit 1023.
  else
  {
    //Toutes les LEDs s'allument.
    for(int i=0; i<12; i++)
    {
      digitalWrite(i, HIGH);
    }
  }
}

////////////////////////////
//SOLUTION II, factorisée.//
////////////////////////////
//Déclaration des variables.
const int analogInputPotentiometre = 14;

int valeur = 0; //Valeur du potentiomètre.
int ledsOnLedsOff = LOW; //Variable utilisée pour commandeLeds.

void setup() {
  //Déclaration des LEDs vertes
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  //LEDs oranges.
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  //LEDs rouges.
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  //Potentiomètre.
  pinMode(analogInputPotentiometre, INPUT);
}

void loop() 
{
  valeur = analogRead(analogInputPotentiometre); //Lecture de l'entrée analogie (potentiomètre).
  
  //Potentiomètre à 0.
  if(valeur == 0) 
  {
    commandeLeds(0, 12, LOW);
  }
  
  //Potentiomètre au tiers, soit 341.
  else if(valeur < 1023/3) 
  {
    commandeLeds(0, 4, HIGH);
    commandeLeds(4, 12, LOW);
  }
  
  //Potentiomètre au deux tiers, soit 682.
  else if(valeur < 2*(1023/3)) 
  {
    commandeLeds(0, 8, HIGH);
    commandeLeds(8, 12, LOW);
  }
  
  //Potentiomètre au maximum de sa valeur, soit 1023.
  else
  {
    commandeLeds(0, 12, HIGH);
  }
}

void commandesLed(int startLedsOn, int stopLedsOn, int onOff) //Le premier paramètre indique à quelle broche commencé la boucle, le second ou s'arrêter.
{
  ledsOnLedsOff = onOFF; //Et cette variable indique si la LED s'allume ou s'éteint.
  for(int i=startLedsOn; i<stopLedsOn; i++)
    {
      digitalWrite(i, ledsOnLedsOff);
    }
}
