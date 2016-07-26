#pragma once
#include <iostream>
#include <windows.h>
#include <Ole2.h>
#include <stdio.h>
#include <math.h>
#include <NuiApi.h>
#include "BodyPoint.h"
#include "KinectOneAdapater.h"
#define PI 3.14159265

using namespace std;


/**
  * @brief This class manage the joints of the body like a points and connect with the adapters 
  */
class FullBody
{

public:
	/**
	* @brief constructor of the class
	*/
	FullBody();

	/**
	* @brief constructor of the class that initialize the connection with the sensor  
	*/
	FullBody(int sensor);

	/**
	* @brief destructor of the class
	*/
	~FullBody();

	/**
	* @brief return the position of the joint 
	* @param joint specified to return the position
	*/
	BodyPointPosition returnPosition(BodyParts joint);

	/**
	* @brief function to execute the function update of the sensor 
	*/
	void dataKinect();


private:	

	// Collection of the body points 
	BodyPoint* bodyPointsCollection[21];
	
	/**
	* @brief translate the bumber of the joint 
	*/
	BodyParts translateNumber(int number);

	//Adapter of the sensor kinect V 1.0
	KinectOneAdapter* sensorOneKinect;

};

