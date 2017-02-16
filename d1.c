#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "const.h"
#include "haver_c.h"


int main(int argc, char *argv[])
{
    double d;
	double hdg;
    double lat1 = -20.316657;
    double lon1 = 118.616327;
    double lat2 = -20.316881;
    double lon2 = 118.6162601;

    if (argc > 1)
    {
        lat1 = strtod(argv[1], NULL);
        lon1 = strtod(argv[2], NULL);
        lat2 = strtod(argv[3], NULL);
        lon2 = strtod(argv[4], NULL);
    }
    
    d = computeDistance(lat1, lon1, lat2, lon2, SPHERICAL_EARTH_PROJECTION_TO_PLANE) * METERS_TO_FEET;
	hdg = initialBearing(lat1, lon1, lat2, lon2);

    printf("Point1 %lf|%lf\nPoint2 %lf|%lf\nDistance %lf\nDirection %lf\n"
        ,lat1
        ,lon1
        ,lat2
        ,lon2
        ,d
		,hdg
        );
    return 0;
}
    
