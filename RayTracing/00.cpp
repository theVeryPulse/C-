#include <iostream>

int main()
{

    // Image

    int image_width  = 256;
    int image_height = 256;

    // Render

    std::cout << "P3\n" 
              << image_width << ' ' << image_height << "\n"
              << "255\n";

    for (int row = 0; row < image_height; row++)
    {
        std::clog << row << "/" << image_height - 1 << '\n' << std::flush;
        for (int col = 0; col < image_width; col++)
        {
            // /*
            double r = 0.0;
            double g = double(col) / (image_width - 1);
            double b = double(row) / (image_height - 1);

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
            // */
            // std::cout << "0 0 0\n";
        }
    }
    std::clog << "Done\n";
}
