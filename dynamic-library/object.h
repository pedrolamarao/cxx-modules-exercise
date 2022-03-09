#pragma once

#include <cstdio>
#include <memory>

#include "linkage.h"

namespace foo
{
    class object
    {
    public:

        virtual ~object () = default;

        virtual void format (FILE * stream) = 0;
        
    };

    class null_object : public object
    {
    public:

        inline
        void format (FILE * stream) override { fprintf(stream, "null\n"); }

    };

    DYNAMIC_LIBRARY_API inline
    std::shared_ptr<object> make_null () { return std::make_shared<null_object>(); }

    DYNAMIC_LIBRARY_API
    std::shared_ptr<object> make_string (char const *);

    DYNAMIC_LIBRARY_API
    std::shared_ptr<object> make_number (long double);
}