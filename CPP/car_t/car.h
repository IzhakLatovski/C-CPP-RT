#ifndef CAR_H
#define CAR_H

#include <iostream>

using namespace std;

class car_t
{
	public:
		car_t& operator=(const car_t& otherCar);
		bool operator<(const car_t& otherCar);

		char* getCarName()const;
		bool getGearType()const;
		bool compareByType(const car_t& otherCar) const;
		size_t getCapacity() const;
		const size_t getId() const;
	protected:
		~car_t();
		car_t();
		car_t(const size_t capacity);
		car_t(const car_t& otherCar);

		void setName(char* name);
		void setGearType(bool type);
	private:
		static size_t idCounter;
		const size_t myId;
		size_t myCapacity;
		bool myGear; /*0 - Manual , 1 - Automatic*/
		char* myName;
};

class private_t:public car_t
{
	public:
		~private_t();
		private_t();
		private_t(const size_t capacity);
		private_t(const private_t& otherPrivate);

		size_t accelerate();
		size_t reduceSpeed();	
		size_t getSpeed();
	private:
		size_t mySpeed;
};

class bus_t:public car_t
{
	public:
		~bus_t();
		bus_t();
		bus_t(const size_t capacity);
		bus_t(const bus_t& otherBus);

		size_t getSeatsNumber();
		void setSeatsNumber(size_t value);
		size_t getLineNumber();
		void setLineNumber(size_t value);
	private:
		size_t numberOfSeats;
		size_t lineNumber;
};

#endif