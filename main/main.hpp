#pragma once
#ifndef MAIN_HPP
#define MAIN_HPP

#include "stdafx.hpp"

class ConsoleInterface
{
	Violation* m_violation{ nullptr };
	SpeedViolation* m_spViolation{ nullptr };
	SeatbeltViolation* m_sbViolation{ nullptr };

private:

	void FineHandler( bool isRemoveFine )
	{
		std::cout << "[1] Превышение скоростного режима" << std::endl;
		std::cout << "[2] Непристегнутый ремень безопасности" << std::endl;
		std::cout << "Ввод: ";

		int input{ };
		std::cin >> input;

		switch ( input )
		{
			case 1:

				if ( !isRemoveFine )
					m_spViolation->AddViolation( );
				else
					m_violation->RemoveViolation( 2 );

				break;

			case 2:

				if ( !isRemoveFine )
					m_sbViolation->AddViolation( );
				else
					m_violation->RemoveViolation( 3 );

				break;

			default:
				std::cout << "Указанного пункта нет в списке!" << std::endl;
				break;
		}
	}

	void InputHandler( )
	{
		int input{ };
		std::cin >> input;

		switch ( input )
		{
			case 1:
				this->MenuHeader( );
				this->FineHandler( false );
				break;

			case 2:
				this->MenuHeader( );
				this->FineHandler( true );
				break;

			default:
				std::cout << "Указанного пункта нет в списке!" << std::endl;
				break;
		}
	}

	void MenuHeader( )
	{
		system( "cls" );
		std::cout << "\tШ Т Р А Ф Ы   Г И Б Д Д" << std::endl;
		std::cout << "Выберите желаемый пункт функциональности\n" << std::endl;
	}

public:

	void Initilaize( )
	{
		this->MenuHeader( );

		std::cout << "[1] Добавить штраф в базу данных" << std::endl;
		std::cout << "[2] Удалить штраф из базы данных\n" << std::endl;

		std::cout << "Ввод: ";

		this->InputHandler( );
	}

	ConsoleInterface( )
	{
		m_violation = new Violation;
		m_spViolation = new SpeedViolation;
		m_sbViolation = new SeatbeltViolation;

		system( "chcp 1251" );
	}

	~ConsoleInterface( )
	{
		delete m_violation;
		delete m_spViolation;
		delete m_sbViolation;
	}
};

#endif // !MAIN_HPP
