#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Point {
    float x;
    float y;
};

struct Circle {
    struct Point center;
    float radius;
};

int ispointIN(struct Point p, struct Circle c) {
    float distance = sqrt(pow(p.x - c.center.x, 2) + pow(p.y - c.center.y, 2));
    
    return distance <= c.radius;
}

int countINcircle(struct Point points[], int num_points, struct Circle circle) {
    int count = 0;
    for (int i = 0; i < num_points; i += 1) {
        if (ispointIN(points[i], circle)) {
            count += 1;
        }
    }
    return count;
}

int main() {
    
    system("chcp 65001");

    struct Circle circle1 = {{0.0, 0.0}, 5.0};
    
    struct Point points[] = {
        {1.0, 2.7},
        {42.0, 4.0},
        {5.0, -2.0},
        {-1.0, -2.0},
        {10.3, 14.0}
    };
    int num_points = sizeof(points) / sizeof(points[0]);
    
    int pointsinside = countINcircle(points, num_points, circle1);
    
    printf("Кількість точок, що знаходяться всередині кола: %d\n", pointsinside);
    
    return 0;
}