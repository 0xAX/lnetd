#pragma once

#include <filesystem>

class Config {
public:
	Config() = delete;
	~Config();

private:
	enum class ClientProto {
		Udp,
		Unknown
	};

	std::filesystem::path conf;
};
