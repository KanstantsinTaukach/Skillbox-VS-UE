#pragma once

class Wheel
{
private:
	float diameter;

public:
	Wheel() : diameter(0.0f)
	{
		std::cout << "Wheel default constructor\n";
	}
	Wheel(float dim) : diameter(dim)
	{
		std::cout << "Wheel constructor with arguments\n";
	}

	std::ostream& print(std::ostream& out) const
	{
		out << diameter << " ";
		return out;
	}
};

class Engine
{
private:
	float power;

public:
	Engine() : power(0.0f)
	{
		std::cout << "Engine default constructor\n";
	}
	Engine(float inPower) : power(inPower)
	{
		std::cout << "Engine constructor with arguments\n";
	}

	std::ostream& print(std::ostream& out) const
	{
		out << power << " ";
		return out;
	}

	float getPower() const { return power; };

	bool operator>(const float val) const
	{
		return power > val;
	}
};

class Vehicle
{
public:
	Vehicle()
	{
		std::cout << "Vehicle default constructor\n";
	}
	virtual ~Vehicle() = default;

	virtual std::ostream& print(std::ostream& out) const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Vehicle& v)
	{
		return v.print(out);
	}
};

class WaterVehicle : public Vehicle
{
protected:
	float draft;

public:
	WaterVehicle() : draft(0.0f) 
	{ 
		std::cout << "WaterVehicle default constructor\n";
	}
	WaterVehicle(float inDraft) : draft(inDraft) 
	{
		std::cout << "WaterVehicle constructor with arguments\n";
	}

	std::ostream& print(std::ostream& out) const override
	{
		out << "WaterVehicle Draft: " << draft << "\n";
		return out;
	}
};

class RoadVehicle : public Vehicle
{
protected:
	float groundClearance;

public:
	RoadVehicle() : groundClearance(0.0f)
	{
		std::cout << "RoadVehicle default constructor\n";
	}
	RoadVehicle(float inGroundClearance) : groundClearance(inGroundClearance)
	{
		std::cout << "RoadVehicle constructor with arguments\n";
	}

	std::ostream& print(std::ostream& out) const override
	{
		out << "RoadVehicle Ground clearance: " << groundClearance << "\n";
		return out;
	}
};

class Bicycle : public RoadVehicle
{
protected:
	Wheel wheel1;
	Wheel wheel2;

public:
	Bicycle() : wheel1(0.0f), wheel2(0.0f), RoadVehicle(0.0f)
	{
		std::cout << "Bicycle default constructor\n";
	}
	Bicycle(Wheel InWheel1, Wheel InWheel2, float vehicle) : wheel1(InWheel1), wheel2(InWheel2), RoadVehicle(vehicle)
	{
		std::cout << "Bicycle constructor with arguments\n";
	}

	std::ostream& print(std::ostream& out) const override
	{
		out << "Bicycle Wheels: ";
		wheel1.print(out);
		wheel2.print(out);
		out << " Ground clearance: " << groundClearance << "\n";
		return out;
	}
};

class Car : public RoadVehicle
{
protected:
	Wheel wheel1;
	Wheel wheel2;
	Wheel wheel3;
	Wheel wheel4;
	Engine engine;

public:
	Car() : engine(0.0f), wheel1(0.0f), wheel2(0.0f), wheel3(0.0f), wheel4(0.0f), RoadVehicle(0.0f)
	{
		std::cout << "Car default constructor\n";
	}
	Car(Engine power, Wheel InWheel1, Wheel InWheel2, Wheel InWheel3, Wheel InWheel4, float vehicle) : engine(power), wheel1(InWheel1), wheel2(InWheel2), wheel3(InWheel3), wheel4(InWheel4), RoadVehicle(vehicle)
	{
		std::cout << "Car constructor with arguments\n";
	}

	std::ostream& print(std::ostream& out) const override
	{
		out << "Car Engine: ";
		engine.print(out);
		out << " Wheels: ";
		wheel1.print(out);
		wheel2.print(out);
		wheel3.print(out);
		wheel4.print(out);
		out << "Ground clearance: " << groundClearance << "\n";
		return out;
	}

	float getPower() const { return engine.getPower(); };
};