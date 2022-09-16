#include "Listener.h"
#include <wiringPi.h>

Listener::Listener(Button *modeButton, Button *powerButton, 
Controller *control, ClockCheck *clock, DHT11 *dht11)
{
    this->modeButton = modeButton;
    this->powerButton = powerButton;
    this->controller = control;
    this->clockCheck = clock;
    this->dht11 = dht11;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if (modeButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }

    if (powerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("powerButton");
    }

    if (clockCheck->isUpdate())
    {
        controller->updateEvent("clockUpdate");
    }

   static unsigned int prevTime = 0;
    if(millis() - prevTime > 2000)
    {
        prevTime = millis();
        DHT_Data dhtData = this->dht11->readData();
        if(!dhtData.error)
        {
            if(dhtData.Temp>=27)
            {
                controller->updateEvent("warningTemp");
                controller->updateTempHumid(dhtData);
            }
            else
            {
                controller->updateEvent("normalTemp");
                controller->updateTempHumid(dhtData);
            }
        }
    }
}