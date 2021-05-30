import processing.serial.*;
Serial myPort;
PImage termo;PImage logo;PImage tanque;PImage humedad;PImage tierra;
String val= "";
int[] nums;
int dato1,dato2,dato3,dato4,altura;
void setup() {
  size(1000,700);
 // background(255);
  termo = loadImage("termometro.png");
  logo = loadImage("logo_udi_.png");
  tanque = loadImage("tanque.png");
  humedad = loadImage("humedad.png");
  tierra = loadImage("tierra.png");
  myPort = new Serial(this, "COM5", 9600);
  myPort.bufferUntil('\n');

}
 void serialEvent(Serial myPort)// whenever serial event happens it runs
{
  val = myPort.readStringUntil('\n'); //gathering data from port in a variable val
  val = val.substring(0, val.length() - 2);
  int[] nums = int(split(val, ';'));
   dato1 = (nums[0]);
  dato2 =(nums[1]);
    dato3 =(nums[2]);
    dato4 =(nums[3]);
 
}
void draw() {
  background(185);
  strokeWeight(5);
  fill(255,255,255);
  rect(25, 100, 440, 265);
  strokeWeight(5);
  fill(255, 255, 255);
  rect(525, 100, 440, 265);
  strokeWeight(5);
  fill(255, 255, 255);
  rect(25, 400, 440, 265);
  strokeWeight(5);
  fill(255, 255, 255);
  rect(525, 400, 440, 265);
  image(logo, 558, 0);
  image(termo,200, 140);
  image(tanque,150, 430);
  image(humedad,600, 150);
  image(tierra,580, 450);
  textSize(14);
  fill(0, 102, 153);
  text("Supervisor de variables industriales aplicando comunicación inalámbrica", 10, 16);
  textSize(14);
  fill(0, 102, 153);
  text("enfocado a un invernadero industrial ", 120, 32);
  textSize(14);
  fill(0, 102, 153);
  text("Daniel Yamith Angarita Arenas", 120, 48);
  textSize(14);
  fill(0, 102, 153);
  text("Daniel Emilio Blanco Gómez", 120, 64);
  textSize(14);
  fill(0, 102, 153);
  text("Jilver Pacheco Rivera", 120, 82);
  textSize(14);
  fill(0, 102, 153);
  text("Docentes: Ing. Javier Suárez León, Ing. Oscar Fernando Becerra Angarita", 220, 695);
  textSize(14);
  fill(0, 102, 153);
  text("Temperatura (°C)", 180, 125);
  text("Nivel de agua (%)", 180, 425);
  text("Humedad (%)", 700, 125);
  text("Humedad de la tierra (%)", 650, 425);
  textSize(32);
  text("°C",400,250);
  text(dato1, 356, 250);
  text("%",900,250);
  text(dato2, 856, 250);
  text("%",420,550);
  text(dato3, 356, 550);
  text("%",900,550);
  text(dato4, 834, 550);
  
  //noStroke();
  
  drawTemp(dato1);
  drawHum(dato2);
  drawLevel(dato3);
  drawTierra(dato4);

}
void drawTemp(int dato1){
  // la temperatura va de -40º a 50º centigrados
  int altura = (int) map(dato1, 0, 100, 0, -170);
  if (dato1 < 100){
  stroke(255, 0, 0);
  fill(255, 0, 0);
  rect(218, 312, 25, altura);
}
}
void drawHum(int dato2){
  int altura = (int) map(dato2, 0, 100, 0, -145);
  if (dato2 < 100){
  stroke(0, 0, 0);
  fill(120, 68, 197);
  rect(675, 300, 73, altura);
  if (dato2 <= 25){
  textSize(16);
 text("Seco",650,350); 
}
  if (dato2>50&& dato2<= 80){
  textSize(16);
 text("humedad promedio",650,350); 
}
if (dato2>80){
  textSize(16);
 text("Exceso de humedad",650,350); 
}
}

}
void drawLevel(int dato3){
  // la temperatura va de -40º a 50º centigrados
  int altura = (int) map(dato3, 0, 100, 0, -175);
  if (dato3 < 100){
  stroke(46, 136, 254);
  fill(46, 136, 254);
  rect(195, 626, 114, altura);
}
if (dato3 == 0){
  textSize(16);
 text("No hay agua",150,650); 
}
if (dato3 > 0 && dato3 <= 25){
  textSize(16);
 text("Nivel bajo de agua",150,650); 
}
if (dato3 > 25 && dato3 <= 50){
  textSize(16);
 text("Nivel medio de agua",150,650); 
}
if (dato3 > 50 && dato3 < 100){
  textSize(16);
 text("Nivel Alto de agua",150,650); 
}
if (dato3 == 100){
  textSize(16);
 text("Tanque lleno",150,650); 
}
}
void drawTierra(int dato4){
  // la temperatura va de -40º a 50º centigrados
  int altura = (int) map(dato4, 0, 100, 0, -120);
  if (dato4 < 100){
  stroke(0, 0, 0);
  fill(133, 110, 99);
  rect(718, 575, 63, altura);
}
if (dato4 <= 5){
  textSize(16);
 text("Sensor no esta en tierra",600,600); 
}
if (dato4 > 5 && dato4<= 20){
  textSize(16);
 text("tierra Seca",600,600); 
}
if (dato4 > 20 && dato4<= 50){
  textSize(16);
 text("tierra humeda",600,600); 
}
if (dato4 > 50 && dato4<= 100){
  textSize(16);
 text("tierra con exceso de agua",600,600); 
}
}
