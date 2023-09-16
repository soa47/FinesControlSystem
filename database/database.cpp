#include "stdafx.hpp"

std::string Database::CreateRequest( const std::string& url, const std::string& headers )
{
	char buffer[ 256 ]{  };
	DWORD bytesRead{ NULL };

	try
	{
		this->m_handle = InternetOpenA( NULL, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL );
		if ( this->m_handle == nullptr )
			throw "InternetOpenA";

		this->m_handle = InternetConnectA( this->m_handle, this->m_serverName.data( ), INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, NULL, NULL );
		if ( this->m_handle == nullptr )
			throw "InternetConnectA";

		this->m_handle = HttpOpenRequestA( this->m_handle, "GET", url.c_str( ), NULL, NULL, NULL, INTERNET_FLAG_NO_CACHE_WRITE | INTERNET_FLAG_RELOAD, NULL );
		if ( this->m_handle == nullptr )
			throw "HttpOpenRequestA";

		if ( !HttpSendRequestA( this->m_handle, headers.c_str( ), static_cast<DWORD>( headers.size( ) ), NULL, NULL ) )
			throw "HttpSendRequestA";

		if ( !InternetReadFile( this->m_handle, buffer, sizeof( buffer ), &bytesRead ) )
			throw "InternetReadFile";

		InternetCloseHandle( this->m_handle );
		std::cout << "Успешно!" << std::endl;

	} catch ( std::string& exeption )
	{
		std::cout << exeption;
	}

	this->m_hostingResponse.append( buffer, bytesRead );
	Sleep( 1500 );
	return this->m_hostingResponse;
}