module;

#include "pch.h"
#include "object.h"

export module foo;

export namespace foo
{
    using ::foo::object;
    using ::foo::make_null;
    using ::foo::make_string;
    using ::foo::make_number;
}