#pragma once

#if defined(DYNAMIC_LIBRARY_EXPORT)
# define DYNAMIC_LIBRARY_API __declspec(dllexport)
#else
# define DYNAMIC_LIBRARY_API __declspec(dllimport)
#endif