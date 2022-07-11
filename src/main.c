#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdio.h>
#include <stdlib.h>
#include "psnr.h"

void fatal(const char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(-1);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fatal("need two input images to compare");
    }

    int width_orig, height_orig, nrChannels_orig;
    unsigned char* original = stbi_load(argv[1], &width_orig, &height_orig, &nrChannels_orig, 0);
    
    int width_deriv, height_deriv, nrChannels_deriv;
    unsigned char* derivative = stbi_load(argv[2], &width_deriv, &height_deriv, &nrChannels_deriv, 0);

    if (width_orig != width_deriv || height_orig != height_deriv || nrChannels_orig != nrChannels_deriv) {
        fatal("image dimensions/channels must match");
    }

    double res = psnr(original, derivative, width_orig, height_orig, nrChannels_orig);
    printf("PSNR = %f\n", res);
    
    stbi_image_free(original);
    stbi_image_free(derivative);
    
    return 0;
}
