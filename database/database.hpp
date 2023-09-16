#pragma once
#ifndef REQUESTS_HPP
#define REQUESTS_HPP

class Database
{
private:

	HANDLE m_handle{ nullptr };
	std::string_view m_serverName{ "soamane47.beget.tech" };
	std::string m_hostingResponse { "" };

public:

	// Sending a GET request to the server
	std::string CreateRequest( const std::string& url, const std::string& headers = "Content-Type: text/html\r\nUser-Agent: license" );
};

#endif // !REQUESTS_HPP
