
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes( byte_pointer start, size_t len ) {
    size_t i;

    for( i = 0; i < len; i++ ) {
        printf( " %.2x", start[i] );
    }
    printf( "\n" );
}

void show_int( int x ) {
    show_bytes( (byte_pointer)&x, sizeof(int) );
}

void show_float( float x ) {
    show_bytes( (byte_pointer)&x, sizeof(float) );
}

int main() {
    int i = 12345;
    show_int( i );
    show_float( 1.1 );
    
    const char *s = "abcdef";
    show_bytes( (byte_pointer)s, strlen(s) );

    printf( "%ld\n", sizeof(float) );

    printf( "%f\n", pow( 2, -4 ) + pow( 2, -5 ) +
                    pow( 2, -8 ) + pow( 2, -9 ) + pow( 2, -12 ) + pow( 2, -13 ) +
                    pow( 2, -16 ) + pow( 2, -17 ) + pow( 2, -20 ) + pow( 2, -21 ) + pow( 2, -23 )
            );

    short x = 12345;
    short mx = -x;
    show_bytes( (byte_pointer)&x, sizeof(short) );
    show_bytes( (byte_pointer)&mx, sizeof(short) );
    
    return 0;
}