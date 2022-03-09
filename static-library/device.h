#pragma once

#include <filesystem>
#include <string>

namespace bar
{
    enum class device_type { file, socket, };

    class file
    {
    public:

        file (std::filesystem::path path);

        int read (void * buffer, unsigned length);

        int write (void const * buffer, unsigned length);

        static inline
        device_type type () { return device_type::file; }

    };

    enum class family { ipv4, ipv6, };

    enum class protocol { tcp, udp };

    class socket
    {
    public:

        socket (family, std::string_view host, protocol, std::string_view port);

        int read (void* buffer, unsigned length);

        int write (void const* buffer, unsigned length);

        static inline
        device_type type () { return device_type::socket; }

    };
}