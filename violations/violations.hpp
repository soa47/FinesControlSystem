#pragma once
#ifndef VIOLATIONS_HPP
#define VIOLATIONS_HPP

#include "stdafx.hpp"

class Violation : Database
{
protected:
	int m_violationReason{ };
public:
	struct ViolationParams
	{
		// Speed violation params
		unsigned int m_carSpeed{ };
		unsigned int m_flowSpeed{ };

		// Seat belt violations params
		unsigned int m_passangersCount{ };

		// General vars
		char m_carNumber[ 11 ]{ };
		unsigned int m_fineAmmount{ };
	};

	// Sending info to database
	void SendViolationParams( unsigned int requestReason, ViolationParams* params );

	// Adding a violation to the database
	virtual void AddViolation( ) { };

	// Removing a violation to the database
	void RemoveViolation( unsigned int requestReason );
};

class SpeedViolation : Violation
{
public:
	void AddViolation( ) override;
};

class SeatbeltViolation : Violation
{
public:
	void AddViolation( ) override;
};

#endif // !VIOLATIONS_HPP
