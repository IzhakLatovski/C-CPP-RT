#include "car.h"

#include <iostream>

int main()
{
	bus_t bus1;
	cout<<bus1.getSeatsNumber()<<endl;
	cout<<bus1.getId()<<endl;
	bus_t bus2;
	cout<<bus2.getId()<<endl;
	private_t private1;
	cout<<private1.getId()<<endl;
	cout<<private1.getSpeed()<<endl;
	private1.accelerate();
	private1.accelerate();
	cout<<private1.getSpeed()<<endl;
	private1.reduceSpeed();
	cout<<private1.getSpeed()<<endl;
	cout<<private1.getCarName()<<endl;
	cout<<bus1.getCarName()<<endl;
	cout<<bus1.getCapacity()<<endl;
	private_t private3(1800);
	cout<<private3.getCapacity()<<endl;







	return 0;
}