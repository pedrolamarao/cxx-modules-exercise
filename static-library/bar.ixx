module;

#include "pch.h"
#include "device.h"

export module bar;

export namespace bar 
{
    export using ::bar::family;
    export using ::bar::file;
    export using ::bar::protocol;
    export using ::bar::socket;
};