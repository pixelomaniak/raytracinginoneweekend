#pragma once

#define drand48() std::rand() / static_cast<float>(RAND_MAX)
#define MAXFLOAT 3.402823466e+38F // https://msdn.microsoft.com/en-us/library/6bs3y5ya.aspx
#define M_PI 3.1415926535897932384626433832795