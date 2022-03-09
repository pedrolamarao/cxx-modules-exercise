// static library
#include <device.h>

// dynamic library
#include <object.h>

namespace
{
    class application_object : public foo::object
    {
    public:

        void format (FILE * stream) override { fprintf(stream, "application: %p\n", this); }

    };
}

int main (int argc, char* argv[])
{
    auto file = std::make_shared<bar::file>(std::filesystem::path{"/bar"});
    fprintf(stdout, "file: %d\n", file->type());

    auto socket = std::make_shared<bar::socket>(bar::family::ipv6, "example.com", bar::protocol::tcp, "http");
    fprintf(stdout, "socket: %d\n", socket->type());

    foo::make_null()->format(stdout);

    foo::make_string("string")->format(stdout);

    foo::make_number(1)->format(stdout);

    std::make_shared<application_object>()->format(stdout);

    return 0;
}
