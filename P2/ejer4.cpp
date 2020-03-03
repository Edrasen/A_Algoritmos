//E. Alain Ramos Mesas
//Calculate minimum distance between 2 different points dorm a points array

#include<iostream>
#include<math.h>
#include <fstream>

using namespace std;

//create struct point wich can hold x and y coordinates
typedef struct point{
    double px; //x coordinate
    double py; //y coordinate
    point(double x, double y){ //constructor, it's not necessary
        px = x;
        py = y;
    }
}point;

//calculate the distance between two points
double calculateD(point p1, point p2){
    double d;
    double dpx = p2.px - p1.px; //distance between x1 & x2
    double dpy = p2.py - p1.py; //distance between y1 & y2
    d = sqrt(pow(dpx, 2) + pow(dpy, 2));    //distance between two points
    return d;
}

//geting all distances between all given points
void getDistances(point *p, int n){
    int p1, p2; //auxiliar variables to save minimum distance points
    int i, j; //iterators
    double d;
    double mind = 1000; //generic minimum value
    for(i = 0; i < n; i++){
        for (j = i + 1; j < n; j++)
        {
            d = calculateD(p[i], p[j]);
            printf("Distancia entre P[%d] y P[%d]: %0.3lf \n", i+1, j+1, d);
            if (d < mind) //it validates if distance between points is the smallest one
            {
                mind = d;
                p1 = i;
                p2 = j;
            }
        }
    }
    printf("\nLa distancia mas corta es entre P[%d] y P[%d]", p1+1, p2+1);
}

//creating an array from points
point* create(int n){
    point* p; //points vector
    p = (point* )calloc(n, (sizeof(point)));
    return p;
}

//filling our vector
point* fill(point *p, int n){
    char delim; //auxiliar to read comma from input.txt file
    int i;
    ifstream inData; //filestream 
    inData.open("input.txt"); //open input file
    for (i=0; i<20; i++) { //it allows save x & y data from coordinates
        inData >> p[i].px 
            >> delim
            >> p[i].py;
    }
    inData.close(); //closing input file
    return p;
}

//it just let us see all points from the vector
void showArr(point *p, int n){
    for(int k = 0; k < n; k++){
        printf("\nP[%d]: (%0.3lf , %0.3lf)", k + 1, p[k].px, p[k].py);
    }
}

int main(){
    int n;
    point *p;
    printf("Numero de puntos que contiene el archivo: ");
    scanf("%d", &n);
    p = create(n);
    p = fill(p, n);
    showArr(p, n);
    printf("\n\n");
    getDistances(p, n);
    return 0;
}