#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "const.h"
#include "haver_c.h"

int main(int argc, char *argv[])
{
    double lat1 = -20.316657;
    double lon1 = 118.616327;
    double d = 84.862736;
	double hdg = 195.646498;
    double lat2; // = -20.316881;
    double lon2; // = 118.6162601;

    if (argc > 1)
    {
        lat1 = strtod(argv[1], NULL);
        lon1 = strtod(argv[2], NULL);
        d = strtod(argv[3], NULL);
        hdg = strtod(argv[4], NULL);
    }
    
    whereIsThere(lat1, lon1, d, hdg, &lat2, &lon2);

    printf("Point1 %lf|%lf\nDistance %lf\nHeading %lf\nPoint2 %lf|%lf\n"
        ,lat1
        ,lon1
        ,d
		,hdg
        ,lat2
        ,lon2
        );
    return 0;
}
    
