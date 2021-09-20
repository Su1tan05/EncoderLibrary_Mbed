#include "mbed.h"
#include <string>

Serial pc(USBTX, USBRX); // tx, rx

PwmOut EnA(D6);
DigitalOut In1(D7);
DigitalOut In2(D8);
InterruptIn EncoderChanel1(D10);
int encValue = 0;

void PrintSomethingToComPort()
{
    encValue++;
    //pc.printf("encVaule: %d", encValue);
}
int main()
{
    EnA.write(0.3);
    while (true) {
        In1.write(1);
        In2.write(0);
        EncoderChanel1.rise(&PrintSomethingToComPort);
        pc.printf("EncValue: %d \r\n", encValue);
        pc.printf("value: %d \r\n", EncoderChanel1.read());
        wait(1);
    }
}