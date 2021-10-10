#pragma once

#ifdef DELVE_API
#define DELVE __declspec(dllexport)
#else
#define DELVE __declspec(dllimport)
#endif
