#include "View.h"
#include <wiringPi.h>

View::View(Led *led1, Led *led2, Led *led3, Led *led4, Led *led5, LCD *lcd)
{
    this->light1 = led1;
    this->light2 = led2;
    this->light3 = led3;
    this->light4 = led4;
    this->light5 = led5;
    this->lcd = lcd;
    this->lightState = LIGHT_OFF;
}

View::~View()
{

}

void View::setState(int state)
{
    lightState = state;
}

void View::lightView()
{
    switch (lightState)
    {
        case LIGHT_OFF:
            lightOff();
        break;
        case LIGHT_1:
            lightOn_1();
        break;
        case LIGHT_2:
            lightOn_2();
        break;
        case LIGHT_3:
            lightOn_3();
        break;
        case LIGHT_4:
            lightOn_4();
        break;
        case LIGHT_5:
            lightOn_5();
        break;
        case LIGNT_WARNING:
            lightWarning();
        break;
    }
}

void View::lightOn_1()
{
    char buff[30]= {0,};
    sprintf(buff, "Light 1  ");
    lcd->WriteStringXY(0, 0, buff);
    lcd->backLightOn();

    light1->On();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn_2()
{
    char buff[30];
    sprintf(buff, "Light 2  ");
    lcd->WriteStringXY(0, 0, buff);
    lcd->backLightOn();

    light1->On();
    light2->On();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn_3()
{
    char buff[30];
    sprintf(buff, "Light 3  ");
    lcd->WriteStringXY(0, 0, buff);
    lcd->backLightOn();

    light1->On();
    light2->On();
    light3->On();
    light4->Off();
    light5->Off();
}

void View::lightOn_4()
{
    char buff[30];
    sprintf(buff, "Light 4  ");
    lcd->WriteStringXY(0, 0, buff);
    lcd->backLightOn();

    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->Off();
}

void View::lightOn_5()
{
    char buff[30];
    sprintf(buff, "Light 5  ");
    lcd->WriteStringXY(0, 0, buff);
    lcd->backLightOn();

    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->On();
}

void View::lightOff()
{
    char buff[30];
    sprintf(buff, "Light Off");
    lcd->WriteStringXY(0, 0, buff);
    lcd->backLightOff();

    light1->Off();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightWarning()
{
    char buff[30];
    sprintf(buff, "WARNING");
    lcd->WriteStringXY(0, 0, buff);

    
    static unsigned int prevTime = 0;
    static unsigned int state = 0;
    if(millis() - prevTime > 500)
    {
        prevTime = millis();
        state = !state;
        if(state)
        {
            light1->On();
            light2->On();
            light3->On();
            light4->On();
            light5->On();
        }
        else
        {
            light1->Off();
            light2->Off();
            light3->Off();
            light4->Off();
            light5->Off();
        }
    }
}