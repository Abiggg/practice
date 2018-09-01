/*
a.高层不依赖于细节，二者都应依赖于抽象；
b.抽象不应依赖于细节，细节依赖于抽象
*/

#include <iostream>

using namespace std;

class TSensor
{
public:
  TSensor(int x);
  int readTemp();
private:
  int Temp;
};

int TSensor::readTemp()
{
  cout<<"current Temp is : "<<Temp<<endl;
  return Temp;
}

TSensor::TSensor(int x)
{
  Temp = x;
}

class Heater
{
public:
  void heater();
  void cool();
};

void Heater::heater()
{
  cout<<"heating"<<endl;
}

void Heater::cool()
{
  cout<<"cooling"<<endl;
}

void Regulate(TSensor T, Heater h, int maxTemp, int minTemp)
{
    int curretTemp = T.readTemp();
    
    if(curretTemp > maxTemp)
    {
      h.cool();
    }
    else if(curretTemp < minTemp)
    {
      h.heater();
    }
    else
    {
      cout<<"OK"<<endl;
    }
}

main()
{
  int currentTemp0 = 40;
  int currentTemp1 = 130;
  int currentTemp2 = 80;
  int maxTemp = 125;
  int minTemp = 60;

  Heater ht;
  TSensor ts1(currentTemp0);
  TSensor ts2(currentTemp1);
  TSensor ts3(currentTemp2);

  Regulate(ts1, ht, maxTemp, minTemp);
  Regulate(ts2, ht, maxTemp, minTemp);
  Regulate(ts3, ht, maxTemp, minTemp);
}
