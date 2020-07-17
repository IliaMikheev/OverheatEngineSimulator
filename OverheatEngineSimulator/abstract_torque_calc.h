#pragma once
class AbstractTorqueCalc
{
public:
	virtual ~AbstractTorqueCalc() = default;
	virtual float fromAngularVelocity(float angularVelocity) = 0;
};

