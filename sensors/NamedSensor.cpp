/*
 * NamedSensor.cpp
 *
 *  Created on: 12. 11. 2013.
 *      Author: Dean
 */

#include "NamedSensor.h"

NamedSensor::NamedSensor(const unsigned char numSensors, const char* const* names,
		unsigned long int frequency) {
	this->numSensors = numSensors;
	this->sensorNames = names;
	this->sensorValues = new SensorReading[numSensors];
	this->sensorStates = new SensorState[numSensors];
	this->frequency = frequency;
	this->lastReadTime = millis() - 1000;
	for (unsigned char i = 0; i < numSensors; ++i) {
		this->sensorStates[i] = NOT_READ;
	}
}

NamedSensor::~NamedSensor() {
	// TODO Auto-generated destructor stub
}

bool NamedSensor::hasCooledOff() {
	unsigned long int now = millis();
	if((now - this->lastReadTime) >= this->frequency) {
		lastReadTime = now;
		return true;
	}
	return false;
}

float NamedSensor::valueF(int valueId) {
	if(hasCooledOff()) {
		readSensors();
	}
	return sensorValues[valueId].floatReading;
}

int NamedSensor::valueI(int valueId) {
	if(hasCooledOff()) {
		readSensors();
	}
	return sensorValues[valueId].integerReading;
}

SensorState NamedSensor::getState(int valueId) {
	return sensorStates[valueId];
}

SensorValueType NamedSensor::getValueType(int valueId) {
	return FLOAT_VALUE;
}