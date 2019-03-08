#pragma once

#include <filesystem>

namespace fs = std::filesystem;

#ifndef ENOENT
constexpr int ENOENT 2;
#endif

class Config {
public:
	Config() = delete;
	~Config();
        Config(const Config&) = delete;
	Config& operator=(const Config&) = delete;

        Config(const std::string_view&& path);

private:
	enum class ClientProto {
		Udp,
		Unknown
	};

        fs::path conf;
};
