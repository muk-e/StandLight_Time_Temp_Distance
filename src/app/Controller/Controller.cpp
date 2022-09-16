#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clockServ, TempHumidService *tempHumiService)
{
    this->service = serv;
    this->clockService = clockServ;
    this->tempHumidService = tempHumiService;
    this->lightState = LIGHT_OFF;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    if (strBtn == "modeButton")
    {
        service->updateState("modeButton");
    }
    if (strBtn == "powerButton")
    {
        service->updateState("powerButton");
    }
    if (strBtn == "clockUpdate")
    {
        clockService->updateEvent();
    }
    if(strBtn == "warningTemp")
    {
        service->updateState("warningTemp");
    }

    if(strBtn == "normalTemp")
    {
        service->updateState("normalTemp");
    }
}

void Controller::updateTempHumid(DHT_Data dhtData)
{
    tempHumidService->updateEvent(dhtData);
}