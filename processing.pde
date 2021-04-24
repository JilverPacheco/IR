import processing.serial.*;
Serial myPort;  // Create object from Serial class
String val= "";
int numero;
void setup() {
  size(1080, 750);
  myPort = new Serial(this, "COM5", 9600);
  myPort.bufferUntil('\n');
}

void draw() {
 background(0); 
 fill(255);// fill white color to text
 PFont f = createFont("Georgia", 70);
 textFont(f);
 textSize(32);
 text("Temp(°C)         Humidity(%)",10,64);
 fill(225,0,0);
 textSize(32);
   System.out.println(numero);
 text(numero, 15,115);
}
void serialEvent(Serial myPort) // whenever serial event happens it runs
{
  val = myPort.readStringUntil('\n'); //gathering data from port in a variable val
  numero= Integer.valueOf(val); 
}
