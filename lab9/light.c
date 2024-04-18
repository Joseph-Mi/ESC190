#include "c_img.h"
#include <stdio.h>
#include <stdint.h>

int main()
{

    rgb_img *image;
    char *filename = "image5.bin";
    read_in_img(&image, filename);
    //print_grad(image);
    printf("\n\n\n");

    size_t height = image->height;
    size_t width = image->width;

    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            int red = get_pixel(image, row, col, 0);
            int green = get_pixel(image, row, col, 1);
            int blue = get_pixel(image, row, col, 2);

            red *= 0.8;
            if (red >= 255){
                red = 255;
            }
            green *= 0.8;
            if (green >= 255){
                red = 255;
            }
            blue *= 0.8;
            if (blue >= 255){
                red = 255;
            }
            set_pixel(image, row, col, red, green, blue);

        }
    }

    write_img(image, "image2.bin");
    //print_grad(image);
    // destroy_image(image);

    return 0;
}