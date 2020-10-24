#include<stdio.h>
#include<GL/glut.h>
#include<GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#define SIZE 10
int a0, b0, x[SIZE], y[SIZE], i, vertices;
float new_colour[3], old_colour[3];

void init()
{
	glClearColor(0.6, 0.980, 0.937, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
}

void display() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    old_colour[0] = 0;
    old_colour[1] = 0;
    old_colour[2] = 0;
	glLineWidth(9.0);							                       //drawing the rectangle	
	glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
        for(i=0; i<vertices; i++)
        {
            glVertex2f(x[i],y[i]);
        }
	glEnd();	
    glFlush();
}

void floodfill_four(int x, int y) 								//using 4-connected approach to fill the polygon
{
    float current[3];  
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, current); 
    
    if((current[0]==old_colour[0]) && (current[1]==old_colour[1]) && (current[2]==old_colour[2]))  
    {
        glBegin(GL_POINTS);                            		            //drawing point
            glColor3f(new_colour[0], new_colour[1], new_colour[2]);
            glVertex2f(x,y);	
        glEnd();  
        floodfill_four(x+1, y);  
        floodfill_four(x-1, y);  
        floodfill_four(x, y+1);  
        floodfill_four(x, y-1);  
    }
    glFlush();
}

void floodfill_eight(int x, int y) 							//using 8-connected approach to fill the polygon
{
    float current[3];  
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, current); 
    
    if((current[0]==old_colour[0]) && (current[1]==old_colour[1]) && (current[2]==old_colour[2]))  
    {
        glBegin(GL_POINTS);                            		            //drawing point
            glColor3f(new_colour[0], new_colour[1], new_colour[2]);
            glVertex2f(x,y);	
        glEnd();  
        floodfill_eight(x+1, y); 
        floodfill_eight(x-1, y);  
        floodfill_eight(x, y+1);  
        floodfill_eight(x, y-1);  
        floodfill_eight(x+1, y+1);  
        floodfill_eight(x-1, y+1);  
        floodfill_eight(x+1, y-1);  
        floodfill_eight(x-1, y-1);  
    }
    glFlush();
}

void key(int key, int x, int y)						//key function
{
	if(key == GLUT_KEY_LEFT)						//pressing the left key calls flood fill for 4-connected approach
	{
        int a = a0;
        int b = 500-b0;
        floodfill_four(a,b);
	}
    if(key == GLUT_KEY_RIGHT)							//pressing the right key calls flood fill for 8-connected approach
	{
        floodfill_eight(a0, (500-b0));
	}
}

int main(int argc,char** argv) 
{ 
	glutInit(&argc,argv);
    printf("Enter the number of vertices of polygon: ");
    scanf("%d",&vertices);
    printf("Enter the coordinates in cyclic order\n");
    for(i=0; i<vertices; i++)
    {
        printf("Vertex %d: ",i+1);
        scanf("%d%d",&x[i],&y[i]);
    }
    printf("Enter coordinates of the seed point: ");
	scanf("%d%d",&a0,&b0); 
    printf("Enter RGB value of colour to be filled: ");					//entering the RGB value of colour to be filled in the polygon
    for(i=0; i<3; i++)
    {
        scanf("%f",&new_colour[i]);
    }
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500,300);
	glutInitWindowSize(500,500);
	glutCreateWindow("Flood Fill Algorithm");
	init();	
	glutDisplayFunc(display);
 	glutSpecialFunc(key);
	glutMainLoop();
	return 0; 
}
