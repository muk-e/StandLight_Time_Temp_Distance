#ifndef __TEMPHUMIDVIEW_H__
#define __TEMPHUMIDVIEW_H__

#include "LCD.h"

class TempHumidView
{
private:
    LCD *lcd;

public:
    TempHumidView(LCD *lcd);
    virtual ~TempHumidView();
    void setTempHumidData(float temp, float humid);
};

#endif /* __TEMPHUMIDVIEW_H__ */