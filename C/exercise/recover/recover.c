#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // Open arquive
    FILE *recover_image = fopen(argv[1], "r");

    // Assing an array to fouth byte
    unsigned char fourth_header_byte[] = {0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7,
                                        0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef};

    // Assing an array to save blocks
    unsigned char buffer[512];

    // Declare new_image
    char *filename = malloc(4);
    FILE *new_image = fopen(filename, "w");

    // Assing number to new_image's
    int n = 0;

    // Main
    while (fread(buffer, sizeof(buffer), 1, recover_image))
    {
        // Find a header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            for (int i = 0; i < 16; i++)
            {
                if (buffer[3] == fourth_header_byte[i])
                {
                    // Check if has a new_image and close it
                    if (new_image != NULL) fclose(new_image);

                    // Assing name to new_image
                    n++;
                    sprintf(filename, "%03i.jpg", n);
                    new_image = fopen(filename, "w");
                    if (new_image == NULL)
                    {
                        fclose(recover_image);
                        //printf("Could not create %s.\n", *new_image);
                        return 3;
                    }

                    // print the first block into the new_image
                    fwrite(buffer, sizeof(buffer), 1, new_image);

                    //break;
                }
            }
        }
        // If has not header and exist a new_image, copy a block
        else if (new_image != NULL)
        {
            // print the block in the new_image
            fwrite(buffer, sizeof(buffer), 1, new_image);
        }
    }
    free(filename);
}