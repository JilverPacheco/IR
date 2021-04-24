#define PIN 11

int pausas[32], pausas2[32], pausas3[32], pausas4[32], cuentamsj, cuentamsj2, cuentamsj3, cuentamsj4;
unsigned long mensaje, mensaje2, mensaje3, mensaje4;
char datos[3];

void setup()
{
    Serial.begin(9600);
    pinMode(PIN, INPUT);
}

void loop()
{
    pausas[0] = pulseIn(PIN, HIGH);
    if (pausas[0] > 0)
    {
        for (cuentamsj = 31; cuentamsj >= 0; cuentamsj--)
        {
            pausas[cuentamsj] = pulseIn(PIN, HIGH);
        }
        for (cuentamsj = 31; cuentamsj >= 0; cuentamsj--)
        {
            if (pausas[cuentamsj] > 500 && pausas[cuentamsj] < 700)
            {
                bitSet(mensaje, cuentamsj);
            }
            else
            {
                bitClear(mensaje, cuentamsj);
            }
        }

        //  Serial.print("Mensaje original: 0x48B76C93 Traducido: 0x"); // HEX(0x48B76C93) // TEXT(H·l") // BIN(01001000 10110111 01101100 10010011)
        // if ((mensaje - 1 - cuentamsj) == mensaje);{

        //
    }

    pausas2[0] = pulseIn(PIN, HIGH);
    if (pausas2[0] > 0)
    {
        for (cuentamsj2 = 31; cuentamsj2 >= 0; cuentamsj2--)
        {
            pausas2[cuentamsj2] = pulseIn(PIN, HIGH);
        }
        for (cuentamsj2 = 31; cuentamsj2 >= 0; cuentamsj2--)
        {
            if (pausas2[cuentamsj2] > 500 && pausas2[cuentamsj2] < 700)
            {
                bitSet(mensaje2, cuentamsj2);
            }
            else
            {
                bitClear(mensaje2, cuentamsj2);
            }
        }

        //  Serial.print("Mensaje original: 0x48B76C93 Traducido: 0x"); // HEX(0x48B76C93) // TEXT(H·l") // BIN(01001000 10110111 01101100 10010011)
        // if ((mensaje - 1 - cuentamsj) == mensaje);{

        //
    }

    pausas3[0] = pulseIn(PIN, HIGH);
    if (pausas3[0] > 0)
    {
        for (cuentamsj3 = 31; cuentamsj3 >= 0; cuentamsj3--)
        {
            pausas3[cuentamsj3] = pulseIn(PIN, HIGH);
        }
        for (cuentamsj3 = 31; cuentamsj3 >= 0; cuentamsj3--)
        {
            if (pausas3[cuentamsj3] > 500 && pausas3[cuentamsj3] < 700)
            {
                bitSet(mensaje3, cuentamsj3);
            }
            else
            {
                bitClear(mensaje3, cuentamsj3);
            }
        }

        //  Serial.print("Mensaje original: 0x48B76C93 Traducido: 0x"); // HEX(0x48B76C93) // TEXT(H·l") // BIN(01001000 10110111 01101100 10010011)
        // if ((mensaje - 1 - cuentamsj) == mensaje);{

        //
    }

    pausas4[0] = pulseIn(PIN, HIGH);
    if (pausas4[0] > 0)
    {
        for (cuentamsj4 = 31; cuentamsj4 >= 0; cuentamsj4--)
        {
            pausas4[cuentamsj4] = pulseIn(PIN, HIGH);
        }
        for (cuentamsj4 = 31; cuentamsj4 >= 0; cuentamsj4--)
        {
            if (pausas4[cuentamsj4] > 500 && pausas4[cuentamsj4] < 700)
            {
                bitSet(mensaje4, cuentamsj4);
            }
            else
            {
                bitClear(mensaje4, cuentamsj4);
            }
        }

        //  Serial.print("Mensaje original: 0x48B76C93 Traducido: 0x"); // HEX(0x48B76C93) // TEXT(H·l") // BIN(01001000 10110111 01101100 10010011)
        // if ((mensaje - 1 - cuentamsj) == mensaje);{

        //
    }

    Serial.print(mensaje);
    Serial.print(";");

    Serial.print(mensaje2);
    Serial.print(";");

    Serial.print(mensaje3);
    Serial.print(";");
    Serial.println(mensaje4);
