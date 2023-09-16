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
		std::cout << "[1] ���������� ����������� ������" << std::endl;
		std::cout << "[2] �������������� ������ ������������" << std::endl;
		std::cout << "����: ";

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
				std::cout << "���������� ������ ��� � ������!" << std::endl;
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
				std::cout << "���������� ������ ��� � ������!" << std::endl;
				break;
		}
	}

	void MenuHeader( )
	{
		system( "cls" );
		std::cout << "\t� � � � � �   � � � � �" << std::endl;
		std::cout << "�������� �������� ����� ����������������\n" << std::endl;
	}

public:

	void Initilaize( )
	{
		this->MenuHeader( );

		std::cout << "[1] �������� ����� � ���� ������" << std::endl;
		std::cout << "[2] ������� ����� �� ���� ������\n" << std::endl;

		std::cout << "����: ";

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
