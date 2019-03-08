#include "config.hh"

Config::Config(const std::string_view&& path)
{
        this->conf = path;

        if (!fs::exists(this->conf))
                throw fs::filesystem_error("during reading of configuration file",
                                           std::error_code(ENOENT, std::system_category()));
}

Config::~Config()
{}
