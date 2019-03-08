#include <cstdlib>
#include <iostream>

#include <unistd.h>
#include <getopt.h>

#include "config.hh"
#include "socket.hh"

static void usage()
{
        std::cout << "Usage:"
                  << std::endl;
        std::cout << "  lnetd -c lnetd.conf [options]"
                  << std::endl
                  << std::endl;
        std::cout << "Options:"
                  << std::endl;
        std::cout << "  -c/--config -\tpass configuration file"
                  << std::endl;
        std::cout << "  -h/--help   -\tprint this message"
                  << std::endl;
        std::exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
        int c = 0;
        std::string_view config_path;
        Config *cnf = nullptr;

        static const struct option options[] = {
                {"config", required_argument, NULL, 'c'}
        };

        if (argc == 1)
                usage();

        while ((c = getopt_long(argc, argv, "hc:", options, NULL)) >= 0)
        {
                switch (c)
                {
                case 'c':
                        config_path = optarg;
                        break;
                default:
                        break;
                }
        }

        if (config_path.empty())
                usage();
        
        try
        {
                cnf = new Config(std::move(config_path));
        }
        catch (std::exception &e)
        {
                std::cout << e.what() << std::endl;
                delete cnf;
                std::exit(EXIT_FAILURE);
        }

        delete cnf;
	return 0;
}
