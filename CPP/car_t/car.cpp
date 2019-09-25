#include "car.h"
#include <iostream>
#include <string>

using namespace std;

size_t car_t::idCounter=1;

car_t::~car_t()
{

}

car_t::car_t():myId(idCounter++)
{
	myCapacity=1600;
}

car_t::car_t(const size_t capacity):myId(idCounter++)
{
	myCapacity=capacity;
}

car_t::car_t(const car_t& otherCar):myId(idCounter++)
{
	myCapacity=otherCar.getCapacity();
}

char* car_t::getCarName()const
{
	return myName;
}

bool car_t::getGearType()const
{
	return myGear;
}

void car_t::setGearType(bool type)
{
	myGear=type;
}

void car_t::setName(char* name)
{
	myName=name;
}

size_t car_t::getCapacity() const
{
	return myCapacity;
}

bool car_t::compareByType(const car_t& otherCar) const
{
	if(myName==otherCar.getCarName())
	{
		return 1;
	}
	return 0;
}

const size_t car_t::getId() const
{
	return myId;
}

/*
car_t& car_t::operator=(const car_t& otherCar)
{
	if(this!=&otherCar)
	{
		myCapacity=otherCar.getCapacity();
		myGear=otherCar.getGearType();
	}
	return *this;
}*/

bool car_t::operator<(const car_t& otherCar)
{
	return (myCapacity<otherCar.getCapacity() ? 1 : 0);
}

/*******************************************************************************************/

private_t::~private_t()
{

}

private_t::private_t()
{
	setGearType(1);
	setName("Private");
	mySpeed=0;
}

private_t::private_t(const size_t capacity)
{
	setGearType(1);
	setName("Private");
	mySpeed=0;
}

private_t::private_t(const private_t& otherPrivate)
{
	setGearType(1);
	setName("Private");
	mySpeed=0;
}

size_t private_t::accelerate()
{
	mySpeed+=10;
}

size_t private_t::reduceSpeed()
{
	if(mySpeed<=0)
	{
		cout<<"Can't drive with speed <0"<<endl;
	}
	else
	{
		mySpeed-=10;
	}
}

size_t private_t::getSpeed()
{
	return mySpeed;
}

/*******************************************************************************************/

bus_t::~bus_t()
{

}

bus_t::bus_t()
{
	setGearType(0);
	setName("Bus");
	numberOfSeats=50;
	lineNumber=12;
}

bus_t::bus_t(const size_t capacity)
{
	setGearType(0);
	setName("Bus");
	numberOfSeats=50;
	lineNumber=12;
}

bus_t::bus_t(const bus_t& otherBus)
{
	setGearType(0);
	setName("Bus");
	numberOfSeats=50;
	lineNumber=12;
}

size_t bus_t::getSeatsNumber()
{
	return numberOfSeats;
}

void bus_t::setSeatsNumber(size_t value)
{
	numberOfSeats=value;
}

size_t bus_t::getLineNumber()
{
	return lineNumber;
}

void bus_t::setLineNumber(size_t value)
{
	lineNumber=value;
}