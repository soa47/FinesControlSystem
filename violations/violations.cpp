#include "stdafx.hpp"

void Violation::SendViolationParams( unsigned int requestReason, ViolationParams* params )
{
	std::string request{ };

	switch ( requestReason )
	{
		case 0:

			request =
			{
				"index.php"
				+ std::string( "?RequestReason=" ) + std::to_string( requestReason )
				+ std::string( "&CarNumber=" ) + std::string( params->m_carNumber )
				+ std::string( "&CarSpeed=" ) + std::to_string( params->m_carSpeed )
				+ std::string( "&FlowSpeed=" ) + std::to_string( params->m_flowSpeed )
				+ std::string( "&FineAmmount=" ) + std::to_string( params->m_fineAmmount )
			};

			break;

		case 1:

			request =
			{
				"index.php"
				+ std::string( "?RequestReason=" ) + std::to_string( requestReason )
				+ std::string( "&CarNumber=" ) + std::string( params->m_carNumber )
				+ std::string( "&FineAmmount=" ) + std::to_string( params->m_fineAmmount )
			};

			break;

		case 2:

			request =
			{
				"index.php"
				+ std::string( "?RequestReason=" ) + std::to_string( requestReason )
				+ std::string( "&CarNumber=" ) + std::string( params->m_carNumber )
			};

			break;

		case 3:

			request =
			{
				"index.php"
				+ std::string( "?RequestReason=" ) + std::to_string( requestReason )
				+ std::string( "&CarNumber=" ) + std::string( params->m_carNumber )
			};
			break;

		default:
			break;
	}


	this->CreateRequest( request );
}

void Violation::RemoveViolation( unsigned int requestReason )
{
	ViolationParams params{ };
	memset( &params, 0, sizeof( params ) );

	std::cout << "Введите номер автомобиля: ";
	std::cin >> params.m_carNumber;

	this->SendViolationParams( requestReason, &params );
}

void SpeedViolation::AddViolation( )
{
	ViolationParams params{ };
	memset( &params, 0, sizeof( params ) );

	std::cout << "Введите номер автомобиля ( Формат: X???XX??? ): ";
	std::cin >> params.m_carNumber;

	std::cout << "Введие фактическую скорость машины: ";
	std::cin >> params.m_carSpeed;
	if ( params.m_carSpeed > 450 || params.m_carSpeed <= 0 )
	{
		std::cout << "Некорректная скорость автомобиля!" << std::endl;
		Sleep( 1500 );
		return;
	}

	std::cout << "Введие разрешенную скорость на участке дороги: ";
	std::cin >> params.m_flowSpeed;

	if ( params.m_flowSpeed < 20 || params.m_flowSpeed > 110 )
	{
		std::cout << "Некорректная допустима скорость на участке дороги!" << std::endl;
		Sleep( 1500 );
		return;
	}

	unsigned int speedDifference{ params.m_carSpeed - params.m_flowSpeed };

	if ( speedDifference > 20 && speedDifference < 40 )
	{
		params.m_fineAmmount = 500;
	} else if ( speedDifference > 40 && speedDifference < 60 )
	{
		params.m_fineAmmount = 1500;
	} else if ( speedDifference > 60 )
	{
		params.m_fineAmmount = 5000;
	}

	this->m_violationReason = 0;
	this->SendViolationParams( this->m_violationReason, &params );
}

void SeatbeltViolation::AddViolation( )
{
	ViolationParams params{ };
	memset( &params, 0, sizeof( params ) );

	std::cout << "Введите номер автомобиля: ";
	std::cin >> params.m_carNumber;

	std::cout << "Введите количество непристегнутых лиц: ";
	std::cin >> params.m_passangersCount;

	for ( unsigned int i{ 0 }; i < params.m_passangersCount; i++ )
	{
		params.m_fineAmmount += 1000;
	}

	this->m_violationReason = 1;
	this->SendViolationParams( this->m_violationReason, &params );
}