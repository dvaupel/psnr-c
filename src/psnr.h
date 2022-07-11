#ifndef PSNR_H
#define PSNR_H

#include <math.h>

static unsigned int inline sqr(unsigned int v) {
    return v*v;
}

double mse(const unsigned char* ref, const unsigned char* cpy, unsigned int rows, unsigned int cols, unsigned int chans) {
    unsigned int se = 0;    // sum of squared errors
    
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < chans*cols; j++) {
             se += sqr(abs(ref[i*cols*chans + j] - cpy[i*cols*chans + j]));
        }
    }

    return (double)se / (rows * cols * chans);
}

double psnr(unsigned char* ref, unsigned char* cpy, unsigned int rows, unsigned int cols, unsigned int chans) {
    double mse_ = mse(ref, cpy, rows, cols, chans);
    if (mse_ == 0) {
        return INFINITY;
    } 
    return 10 * log10(255*255 / mse_);
}

#endif
