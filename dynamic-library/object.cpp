#include "pch.h"
#include "object.h"

#include <string>

namespace foo
{
    class string_object : public foo::object
    {
        std::string m_value;        

    public:

        explicit string_object (std::string value) : m_value{value} {}

        void format (FILE * stream) override { fprintf(stream, "string: %s\n", m_value.data()); }

    };

    std::shared_ptr<object> make_string (char const* value)
    {
        return std::make_shared<string_object>(std::string{value});
    }

    class number_object : public foo::object
    {
        long double m_value;        

    public:

        explicit number_object (long double value) : m_value{value} {}

        void format (FILE * stream) override { fprintf(stream, "number: %lf\n", m_value); }

    };

    std::shared_ptr<object> make_number (long double value)
    {
        return std::make_shared<number_object>(value);
    }
}