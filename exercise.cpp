#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "bmp_handler.h"

using namespace std;

const int R = 2, G = 1, B = 0;

void test_background(int i) {
        cout << "\e[48;5;" << i << "m";
        cout << ' ';
        cout << "\e[0m";
}

int main()
{
    // change charset for windows
#ifdef _WIN32
    system("chcp 65001");
#endif

    // read in bmp file with filename "redleaf.bmp"
    char filename[] = "002.bmp";
    BMP bmp(filename);

    cout << "successly input image : " << filename << endl;

    // get image height and width
    int height = bmp.height(), width = bmp.width();

    cout << "height = " << height << endl;
    cout << "width = " << width << endl;

    // read pixels : (r, g, b) stored in bmp.bitmap
    // for pixel on i-th row and j-th column
    // - red = bmp.bitmap[i][j][R]
    // - green = bmp.bitmap[i][j][G]
    // - blue = bmp.bitmap[i][j][B]

    // print (r, g, b) value for each pixel
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int c = 16 + (bmp.bitmap[i][j][R] / 42) * 36 + (bmp.bitmap[i][j][G] / 42) * 6 + (bmp.bitmap[i][j][B] / 42);
            if(c >= 16 && c <= 231){
                test_background(c);
            }else{
                int t = bmp.bitmap[i][j][R] + bmp.bitmap[i][j][G] + bmp.bitmap[i][j][B];
                t /= 3;
                t /= 11;
                test_background(t + 232);
            }
        }
        cout << endl;
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int t = bmp.bitmap[i][j][R] + bmp.bitmap[i][j][G] + bmp.bitmap[i][j][B];
                t /= 3;
                t /= 11;
                test_background(t + 232);
        }
        cout << endl;
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int f = 4 * (16 + (bmp.bitmap[i][j][R] / 42) * 36 + (bmp.bitmap[i][j][G] / 42) * 6 + (bmp.bitmap[i][j][B] / 42));
            if(i > 0)f -= 16 + (bmp.bitmap[i - 1][j][R] / 42) * 36 + (bmp.bitmap[i - 1][j][G] / 42) * 6 + (bmp.bitmap[i - 1][j][B] / 42);
            if(j > 0)f -= 16 + (bmp.bitmap[i][j - 1][R] / 42) * 36 + (bmp.bitmap[i][j - 1][G] / 42) * 6 + (bmp.bitmap[i][j - 1][B] / 42);
            if(i < height - 1)f -= 16 + (bmp.bitmap[i + 1][j][R] / 42) * 36 + (bmp.bitmap[i + 1][j][G] / 42) * 6 + (bmp.bitmap[i + 1][j][B] / 42);
            if(j < width - 1)f -= 16 + (bmp.bitmap[i][j + 1][R] / 42) * 36 + (bmp.bitmap[i][j + 1][G] / 42) * 6 + (bmp.bitmap[i][j + 1][B] / 42);
            f /= 4;
            if(f > 40 || f < -40)cout << ".";
            else cout << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            int c = 16 + (bmp.bitmap[j][i][R] / 42) * 36 + (bmp.bitmap[j][i][G] / 42) * 6 + (bmp.bitmap[j][i][B] / 42);
            if(c >= 16 && c <= 231){
                test_background(c);
            }else{
                int t = bmp.bitmap[j][i][R] + bmp.bitmap[j][i][G] + bmp.bitmap[j][i][B];
                t /= 3;
                t /= 11;
                test_background(t + 232);
            }
        }
        cout << endl;
    }
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            int t = bmp.bitmap[j][i][R] + bmp.bitmap[j][i][G] + bmp.bitmap[j][i][B];
                t /= 3;
                t /= 11;
                test_background(t + 232);
        }
        cout << endl;
    }
    //cout << "(" << bmp.bitmap[i][j][R] + bmp.bitmap[i][j][G] + bmp.bitmap[i][j][B] << ")";
    // for each red pixel (r,g,b) = (255,0,0), print "#"
    // otherwise print " "

    return 0;
}
