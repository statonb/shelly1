#ifndef _HAVER_C_H_
#define _HAVER_C_H_

#include <stdlib.h>
#include <math.h>
#include <stdint.h>

typedef enum    {   HAVERSINE_METHOD_1
                    ,HAVERSINE_METHOD_2
                    , POLAR_COORDINATE_FLAT_EARTH
                    , SPHERICAL_EARTH_PROJECTION_TO_PLANE
                }   HaversineMethod;

double computeDistance    (   double lat1
                            , double lon1
                            , double lat2
                            , double lon2
                            , HaversineMethod h
                        );

double initialBearing(double latDeg1, double lonDeg1, double latDeg2, double lonDeg2);

void whereIsThere(   double currentLat
                    ,double currentLon
                    ,double distance
                    ,double heading
                    ,double *pFinalLat
                    ,double *pFinalLon
    );

#endif

