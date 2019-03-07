#pragma once

#include <sys/types.h>
#include <sys/socket.h>

enum class Proto
{
	UnixDomain = AF_UNIX,
	Tcp        = AF_INET,
	Tcp6       = AF_INET6,
	Udp        = AF_INET,
	Udp6       = AF_INET6,
	Unknown
};

class Socket {
public:
	Socket() = delete;
	Socket(const Socket &socket) = delete;
	Socket& operator=(const Socket&) = delete;

	Socket(Proto protocol);	
	~Socket();
private:
};
