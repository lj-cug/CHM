#pragma once

#include "logger.hpp"
#include "triangulation.hpp"
#include "module_base.hpp"
#include "TPSpline.hpp"
#include <cstdlib>
#include <string>

#include <cmath>
#include <armadillo>
#define _USE_MATH_DEFINES
#include <cmath>

class lwinddata : public face_info
{
public:
    double curvature;
};
/**
* \addtogroup modules
* @{
* \class Wind
* \brief Calculates Wind
*
* Calculates wind in a terrible way
*
* Depends:
* - Wind from met file "u" [m/s]
* - Direction from met file 'ud' [degrees]
*
* Provides:
* - Wind "u" [m/s]
* - Wind direction 'ud' [degrees]
*/
class Liston_wind : public module_base
{
public:
    Liston_wind();
    ~Liston_wind();
    virtual void run(mesh domain, boost::shared_ptr<global> global_param);
    virtual void init(mesh domain);

};

/**
@}
*/