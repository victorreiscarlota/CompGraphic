#include <stdio.h>

#define WIDTH 200
#define HEIGHT 200

typedef struct {
    int x, y;
} Point;

void drawLine(unsigned char image[HEIGHT][WIDTH][3], Point p1, Point p2, unsigned char color[3]) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int steps = dx > dy ? dx : dy;
    
    float xIncrement = dx / (float) steps;
    float yIncrement = dy / (float) steps;
    
    float x = p1.x;
    float y = p1.y;
    
    for (int i = 0; i <= steps; i++) {
        int px = (int)x;
        int py = (int)y;
        
        if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT) {
            image[py][px][0] = color[0]; 
            image[py][px][1] = color[1]; 
            image[py][px][2] = color[2]; 
        }
        
        x += xIncrement;
        y += yIncrement;
    }
}

void savePPM(const char *filename, unsigned char image[HEIGHT][WIDTH][3]) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, 1, WIDTH * HEIGHT * 3, file);
    fclose(file);
}

int main() {
    unsigned char image[HEIGHT][WIDTH][3] = {{{255, 255, 255}}}; 

    
    unsigned char black[3] = {0, 0, 0}; 
    unsigned char red[3] = {255, 0, 0}; 

    
    Point p1 = {100, 10};
    Point p2 = {200, 60};
    Point p3 = {100, 150};
    Point p4 = {10, 180};
    Point p5 = {100, 180};
    Point p6 = {190, 180};


    drawLine(image, p1, p2, black);
    drawLine(image, p2, p6, black);
    drawLine(image, p3, p1, black);
    drawLine(image, p3, p4, black);
    drawLine(image, p4, p5, black);
    drawLine(image, p5, p6, black);

    savePPM("output.ppm", image);

    printf("Imagem gerada: output.ppm\n");

    return 0;
}
