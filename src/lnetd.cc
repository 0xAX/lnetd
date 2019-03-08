#include <cstdlib>
#include <iostream>

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
        if (argc == 1)
                usage();

	return 0;
}
