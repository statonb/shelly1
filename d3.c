#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "const.h"
#include "haver_c.h"

int main(int argc, char *argv[])
{
    double lat1 = 40.705498;
    double lon1 = -74.013357;
    double d = 500.0;
	double hdg;
    double lat2;
    double lon2;
	int i;

    if (argc > 1)
    {
        lat1 = strtod(argv[1], NULL);
        lon1 = strtod(argv[2], NULL);
        d = strtod(argv[3], NULL);
    }

	printf("Center: %lf,%lf\nRadius: %lf\n", lat1, lon1, d);
	printf("Point,Lat,Lon\n");
	for(i=0; i<360; i++)
	{
	    whereIsThere(lat1, lon1, d, (double)i, &lat2, &lon2);
		printf("%3d,%lf,%lf\n", i, lat2, lon2);
	}

    return 0;
}
    
