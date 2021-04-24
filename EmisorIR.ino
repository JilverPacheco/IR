#define PIN 3
#define DHTPIN 7 // Indicamos el pin del arduino donde conectamos el sensor
int water_ain = A0;
int mois = A1;
int ad_value = 0;
byte bGlobalErr; //para pasar el codigo de error de vuelta de las funciones
byte DHTDAT[5];  //Array para almacenar los bytes enviados por el sensor
int t, h;
#define inicio 9000
#define pausa 4500
#define cero 560
#define uno 1690
#define Hz 38000
unsigned long mensaje = 0;
unsigned long mensaje2 = 0;
unsigned long mensaje3 = 0;
unsigned long mensaje4 = 0;
void setup()
{
    InitDHT();          // Inicializamos el pin empleado para leer el sensor
    Serial.begin(9600); //Iniciamos comunicacion serie con el pc para ver los datos leidos
    pinMode(PIN, OUTPUT);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
}

void loop()
{
    ReadDHT(); // Leemos el sensor y almacenamos el resultados en variables globales

    //Como en este sensor la humedad y la temperatura no nos sale con decimales,
    //podemos desechar los bytes 1 y 3 de la lectura del sensor
    h = DHTDAT[0];
    t = DHTDAT[2];
    Serial.print(" \n");

    Serial.print("Humedad relativa: ");
    Serial.print(h);
    Serial.print(" %\t");
    mensaje2 = h;
    Serial.print(" \n");

    escribepin2(inicio);
    delayMicroseconds(pausa);
    escribepin2(cero);
    escribemsj2();

    Serial.print(" \n");
    Serial.print(" \n");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println("*C");
    mensaje = t;
    escribepin(inicio);
    delayMicroseconds(pausa);
    escribepin(cero);
    escribemsj();

    Serial.print(" \n");
    Serial.print(" \n");
    ad_value = analogRead(water_ain);
    Serial.print(" \t");
    Serial.print("nivel de tanque: ");
    Serial.println(ad_value);
    mensaje3 = ad_value;
    escribepin3(inicio);
    delayMicroseconds(pausa);
    escribepin3(cero);
    escribemsj3();
    Serial.print(" \n");
    Serial.print(" \n");
    Serial.print(" \t");
    mois = analogRead(A1);
    Serial.print(" suelo ");
    Serial.print(mois);
    mensaje4 = mois;
    Serial.print(" \n");
    escribepin4(inicio);
    delayMicroseconds(pausa);
    escribepin4(cero);
    escribemsj4();
}

void escribepin(int microseg)
{
    tone(PIN, Hz);
    delayMicroseconds(microseg);
    noTone(PIN);
}

void escribepin2(int microseg)
{
    tone(PIN, Hz);
    delayMicroseconds(microseg);
    noTone(PIN);
}

void escribepin3(int microseg)
{
    tone(PIN, Hz);
    delayMicroseconds(microseg);
    noTone(PIN);
}

void escribepin4(int microseg)
{
    tone(PIN, Hz);
    delayMicroseconds(microseg);
    noTone(PIN);
}

void escribemsj()
{ /////////////////////// MENSAJE
    for (int nbit = 31; nbit >= 0; nbit--)
    {
        Serial.print(bitRead(mensaje, nbit));
        if (bitRead(mensaje, 0))
        {
            escribepin(uno);
        }
        else
        {
            escribepin(cero);
            delayMicroseconds(cero);
        }
        delayMicroseconds(cero);
        escribepin(cero);
    }
    delay(2000);
}

void escribemsj2()
{ /////////////////////// MENSAJE
    for (int nbit = 31; nbit >= 0; nbit--)
    {
        Serial.print(bitRead(mensaje2, nbit));
        if (bitRead(mensaje2, nbit))
        {
            escribepin2(uno);
        }
        else
        {
            escribepin2(cero);
            delayMicroseconds(cero);
        }
        delayMicroseconds(cero);
        escribepin2(cero);
    }
    delay(2000);
} /////////////////////// FIN MENSAJE
void escribemsj3()
{ /////////////////////// MENSAJE
    for (int nbit = 31; nbit >= 0; nbit--)
    {
        Serial.print(bitRead(mensaje3, nbit));
        if (bitRead(mensaje3, nbit))
        {
            escribepin3(uno);
        }
        else
        {
            escribepin3(cero);
            delayMicroseconds(cero);
        }
        delayMicroseconds(cero);
        escribepin3(cero);
    }
    delay(2000);
} /////////////////////// FIN MENSAJE

void escribemsj4()
{ /////////////////////// MENSAJE
    for (int nbit = 31; nbit >= 0; nbit--)
    {
        Serial.print(bitRead(mensaje4, nbit));
        if (bitRead(mensaje4, nbit))
        {
            escribepin4(uno);
        }
        else
        {
            escribepin4(cero);
            delayMicroseconds(cero);
        }
        delayMicroseconds(cero);
        escribepin4(cero);
    }
    delay(2000);
} /////////////////////// FIN MENSAJE
/*
  escribepin(39416);
  escribepin(inicio);
  escribepin(2210);
  escribepin(cero);
*/

void InitDHT()
{
    pinMode(DHTPIN, OUTPUT);
    digitalWrite(DHTPIN, HIGH);
}

void ReadDHT()
{
    bGlobalErr = 0;
    byte dht_in;
    byte i;
    // Enviamos el comando "start read and report" al sensor
    // Primero: ponemos a "0" el pin durante 18ms
    digitalWrite(DHTPIN, LOW);
    delay(18);
    delay(5); //TKB, frm Quine at Arduino forum
    //Segundo: ponemos a "1" el pin durante 40us,enviamos el comando de "start read" al sensor
    digitalWrite(DHTPIN, HIGH);
    delayMicroseconds(40);
    //Tercero: Cambiamos el pin de Arduino a entrada de datos
    pinMode(DHTPIN, INPUT);
    delayMicroseconds(40); //Esperamos 40 us
    dht_in = digitalRead(DHTPIN);
    //si hay un 1 en la lectura del pin, indicamos que hay error de tipo 1
    if (dht_in)
    {
        bGlobalErr = 1;
        return;
    }
    delayMicroseconds(80); //Esperamos 80us
    dht_in = digitalRead(DHTPIN);
    //si no hay un 1 en la lectura del pin, indicamos que hay error de tipo 2
    if (!dht_in)
    {
        bGlobalErr = 2;
        return;
    }
    /*Despues de 40us a nivel bajo, el pin deberia de estar durante 80us a nivel alto.
    Despues de esto comienza el envio del primer bit hasta alcanzar los 40 bits enviados.
    The routine "read_dht_dat()" expects to be called with the system already into this low.*/
    delayMicroseconds(80); //Esperamos 80us
    //Ahora comienza la recepcion de datos, son 5 bytes de datos, es decir 40 bits, almacenamos en un array de 5 bytes
    for (i = 0; i < 5; i++)
        DHTDAT[i] = read_dht_dat();
    //Cuarto: Volvemos a configurar el pin del arduino como salida
    pinMode(DHTPIN, OUTPUT);
    //Quinto:Ponemos a "1" el pin de salida
    digitalWrite(DHTPIN, HIGH);
    //Comprobamos si los datos recibidos coinciden con el checksum recibido
    byte DHTCHECKSUM = DHTDAT[0] + DHTDAT[1] + DHTDAT[2] + DHTDAT[3];
    //Si no coincide el byte recibido de checksum con la suma de los 4 primeros bytes enviamos error tipo 3
    if (DHTDAT[4] != DHTCHECKSUM)
        bGlobalErr = 3;
};

byte read_dht_dat()
{
    //Cogemos 8 de los bits recibidos y los devolvemos como un byte.
    //Si por ejemplo recibimos 00000100 , devolvemos en decimal 4
    byte i = 0;
    byte result = 0;
    for (i = 0; i < 8; i++)
    {
        //Entramos mientras dura el primer bit de start (a nivel bajo durante 50us) del byte
        //Esperamos hasta que el pin se pone a nivel alto señalizando fin del la transmision del bit de start
        while (digitalRead(DHTPIN) == LOW)
            ;
        //La linea de datos debera estar ahora a nivel alto durante 27 o 70us,
        //dependiendo si un "0" o un "1" esta siendo enviado respectivamente
        delayMicroseconds(30); //Esperamos 30 us
        if (digitalRead(DHTPIN) == HIGH)
            result |= (1 << (7 - i)); //Si despues de los 30us el pin permanece a "1" añadimos un 1 al byte, sino queda un "0"
        //Esperamos hasta que el pin se vuelve a poner a nivel bajo,
        // el cual indica la señal de start del siguiente bit de la transmision
        while (digitalRead(DHTPIN) == HIGH)
            ;
    }
    return result; //devolvemos el resultado
}
