#ifndef __TEMPHUMIDSERVICE_H__
#define __TEMPHUMIDSERVICE_H__

#include "DHT_Data.h"
#include "TempHumidView.h"

class TempHumidService
{
private:
    TempHumidView *tempHumiView;

public:
    TempHumidService(TempHumidView *tempHumiView);
    virtual ~TempHumidService();
    void updateEvent(DHT_Data dhtData);
};

#endif /* __TEMPHUMIDSERVICE_H__ */