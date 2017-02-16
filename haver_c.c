#include "haver_c.h"
#include "const.h"

double computeDistance    (   double lat1
                            , double lon1
                            , double lat2
                            , double lon2
                            , HaversineMethod h
                        )
{
    double a, b, c;
    double theta1, theta2;
    double dx, dy, dz;
    double dlat, dlon;
    double radius = RADIUS_OF_EARTH_METERS;
    double result;

    switch (h)
    {
        case SPHERICAL_EARTH_PROJECTION_TO_PLANE:
            lon1 -= lon2;
            lon1 *= TO_RAD, lat1 *= TO_RAD, lat2 *= TO_RAD;
            a = cos((lat1 + lat2)/2.0)*lon1;
            lat1 -= lat2;
            result = sqrt((lat1 * lat1) + (a * a)) * radius;
            break;
        
        case POLAR_COORDINATE_FLAT_EARTH:
            lon1 -= lon2;
            lon1 *= TO_RAD, lat1 *= TO_RAD, lat2 *= TO_RAD;
            theta1 = (PI / 2.0) - lat1;
            theta2 = (PI / 2.0) - lat2;

            result = sqrt((theta1 * theta1) + (theta2 * theta2) - (2.0 * theta1 * theta2 * cos(lon1))) * radius;
            break;
        
        case HAVERSINE_METHOD_1:
        	lon1 -= lon2;
        	lon1 *= TO_RAD, lat1 *= TO_RAD, lat2 *= TO_RAD;

        	dz = sin(lat1) - sin(lat2);
        	dx = cos(lon1) * cos(lat1) - cos(lat2);
        	dy = sin(lon1) * cos(lat1);
        	result = asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * radius;
            break;
            
        default:
        	lon1 *= TO_RAD, lon2 *= TO_RAD, lat1 *= TO_RAD, lat2 *= TO_RAD;
            dlon = lon2 - lon1;
            dlat = lat2 - lat1;
            a = sin(dlat/2);
            b = sin(dlon/2);
            a *= a;
            b *= b;
            a += cos(lat1) * cos(lat2) * b;
            c = 2 * atan2( sqrt(a), sqrt(1-a) );
            result = c * radius;
            break;
    }
    return result;
}

double initialBearing(double latDeg1, double lonDeg1, double latDeg2, double lonDeg2)
{
    double deltaLon = (lonDeg2 - lonDeg1) * TO_RAD;
    double lat1 = latDeg1 * TO_RAD;
    double lat2 = latDeg2 * TO_RAD;
    
    double y = sin(deltaLon) * cos(lat2);
    double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(deltaLon);
    double result = atan2(y, x) / TO_RAD;

    if (result < 0) result += 360.0;
    
    return result;    
}

void whereIsThere(   double currentLat
                    ,double currentLon
                    ,double distance
                    ,double heading
                    ,double *pFinalLat
                    ,double *pFinalLon
    )
{
    double eastDisplacement;
    double northDisplacement;
    distance *= FEET_TO_METERS;

    eastDisplacement = distance * sin(heading * TO_RAD);
    northDisplacement = distance * cos(heading * TO_RAD);

    eastDisplacement /= cos(currentLat * TO_RAD);
    eastDisplacement /=  (METERS_PER_DEGREE);
    northDisplacement /= (METERS_PER_DEGREE);

    *pFinalLon = currentLon + eastDisplacement;
    *pFinalLat = currentLat + northDisplacement;
}

