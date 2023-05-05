/*Code to control an LED via bluetooth through a phone app.
Project  by MukeshArvindh. Code by MukeshArvindh.*/

/*If you are going to copy and  paste the code, then do not forget 
to delete the void setup() and void loop()  function from the 
sketch you are using before doing so,as the functions already
exist  in this sketch. Copy-pasting the comments will not
cause any changes in the outcome  or code.*/

/*Note:This code has been compiled and checked multiple times,  and has 
proven to be accurate. The product also works as intended.*/

//Bluetooth  uses serial communication. So, we use many serial functions 
//in this sketch.  
const int LED = 5;
/*Declaring that there is an LED on pin 5 of the arduino  board. We use 
const as we will not change this. You don't have to name it LED.  You 
can even put your name instead.*/
char switchstate;
/*declaring that  there is a variable called switchstate, which will 
hold a character value. This  is due to programming of the app, which
will send  a text value to arduino. If  we use 'int' instead of 
'char' the code will not work properly.*/
void setup()  {//Here the code only runs once.
Serial.begin(9600);
/*To start serial communication  at a rate of 9600 bits per second. This  
is the default rate anyways.*/
pinMode(LED,  OUTPUT);
//Declaring that the LED is an output.
}
void loop() {//This code  repeats. This is our main code.
while(Serial.available()>0){ 
 //code to be  executed only when Serial.available()>0
 /*Serial.available>0 is to check if  there is any reading from the 
 HC-05 Bluetooth module.*/ 
switchstate = Serial.read();
/*The  character we had declared earlier is now being assigned a value-
the value of  whatever Serial.read() is.*/
//Serial.read() is to read the value coming from  app.
Serial.print(switchstate);
//This will print the value onto the Serial  monitor.
Serial.print("\
");
//This moves to the next line after every  new line printed.
delay(15);
/*Gives a break of 15 milliseconds. Delay is  for human eye, and for
speed of some computers, as some will crash at high speeds.*/
if(switchstate  == '1'){//Checking if the value from app is '1'
 digitalWrite(5, HIGH);
 //If  it is, write the component on pin 5(LED) high. 
}
else if(switchstate == '0'){//Else,  if the vaue from app is '0',
 digitalWrite(5, LOW);//Write the component on pin  5(LED) low.
}
}
}
