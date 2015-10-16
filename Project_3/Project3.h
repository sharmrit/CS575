#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>


struct s
{
	float value;
	int pad[NUM];
} Array[4];

int
main( int argc, char *argv[ ] )
{
#ifndef _OPENMP
	fprintf( stderr, "OpenMP is not available\n" );
	return 1;
#endif

	omp_set_num_threads( NUMT );

	unsigned int someBigNumber = 1000000000;	// if > 4B, use "long unsigned int"

	#pragma omp parallel for
	for( int i = 0; i < 4; i++ )
	{
		for( unsigned int j = 0; j < someBigNumber; j++ )
		{
			Array[ i ].value = Array[ i ].value + 2.;
		}
	}
}