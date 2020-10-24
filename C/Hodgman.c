#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
#include<float.h>
#define SIZE 10
int x_min, x_max, y_min, y_max, x[SIZE], y[SIZE], xc[SIZE], yc[SIZE], i, vertices;

int clip_left(int limit)
{
	int j=0; float m;
	for(i=0; i<limit; i++)
	{
		if(x[(i+1)%limit]-x[i])
		{
			m = (y[(i+1)%limit]-y[i]) * (1.0 / (x[(i+1)%limit]-x[i]));
		}
		else
		{
			m = FLT_MAX;
		}
		if(x[i]>=x_min && x[(i+1)%limit]>=x_min)			//IN-->IN, storing second vertex
		{
			xc[j] = x[(i+1)%limit];
			yc[j] = y[(i+1)%limit];
			j++;
			continue;
		}
		if(x[i]<x_min && x[(i+1)%limit]<x_min)
		{
			continue;										//OUT-->OUT, not storing any vertex
		}
		if(x[i]>=x_min && x[(i+1)%limit]<x_min)				//IN-->OUT, Storing intersection point only 
		{
			xc[j] = x_min;
			yc[j] = y[i] + m * (x_min-x[i]);
			j++;
			continue;
		}
		if(x[i]<x_min && x[(i+1)%limit]>=x_min)				//OUT-->IN, storing interection point and second vertex 
		{
			xc[j] = x_min;
			yc[j] = y[i] + m * (x_min-x[i]); 
			xc[j+1] = x[(i+1)%limit];
			yc[j+1] = y[(i+1)%limit]; 
			j+=2;
		}
	}
	for(i=0; i<j; i++)
	{
		x[i] = xc[i];
		y[i] = yc[i];
		xc[i] = yc[i] = 0;
	}
	if(j<limit)
		for(; i<limit; i++)
			x[i] = y[i] =0;
	return j;
}

int clip_right(int limit)
{
	int j=0; float m;
	for(i=0; i<limit; i++)
	{
		if(x[(i+1)%limit]-x[i])
		{
			m = (y[(i+1)%limit]-y[i]) * (1.0 / (x[(i+1)%limit]-x[i]));
		}
		else
		{
			m = FLT_MAX;
		}
		if(x[i]<=x_max && x[(i+1)%limit]<=x_max)			//IN-->IN, storing second vertex
		{
			xc[j] = x[(i+1)%limit];
			yc[j] = y[(i+1)%limit];
			j++;
			continue;
		}
		if(x[i]>x_max && x[(i+1)%limit]>x_max)
		{
			continue;										//OUT-->OUT, not storing any vertex
		}
		if(x[i]<=x_max && x[(i+1)%limit]>x_max)				//IN-->OUT, Storing intersection point only 
		{		
			xc[j] = x_max;
			yc[j] = y[i] + m * (x_max - x[i]);
			j++;
			continue;
		}
		if(x[i]>x_max && x[(i+1)%limit]<=x_max)				//OUT-->IN, storing interection point and second vertex 
		{
			xc[j] = x_max;
			yc[j] = y[i] + m * (x_max - x[i]);
			xc[j+1] = x[(i+1)%limit];
			yc[j+1] = y[(i+1)%limit]; 
			j+=2;
		}
	}
	for(i=0; i<j; i++)
	{
		x[i] = xc[i];
		y[i] = yc[i];
		xc[i] = yc[i] = 0;
	}
	if(j<limit)
		for(; i<limit; i++)
			x[i] = y[i] = 0;
	return j;
}

int clip_bottom(int limit)
{
	int j=0; float m;
	for(i=0; i<limit; i++)
	{
		if(x[(i+1)%limit]-x[i])
		{
			m = (y[(i+1)%limit]-y[i]) * (1.0 / (x[(i+1)%limit]-x[i]));
		}
		else
		{
			m = FLT_MAX;
		}
		if(y[i]>=y_min && y[(i+1)%limit]>=y_min)			//IN-->IN, storing second vertex
		{
			xc[j] = x[(i+1)%limit];
			yc[j] = y[(i+1)%limit];
			j++;
			continue;
		}
		if(y[i]<y_min && y[(i+1)%limit]<y_min)
		{
			continue;										//OUT-->OUT, not storing any vertex
		}
		if(y[i]>=y_min && y[(i+1)%limit]<y_min)				//IN-->OUT, Storing intersection point only 
		{
			xc[j] = x[i] + (y_min - y[i]) / m;
			yc[j] = y_min;
			j++;
			continue;
		}
		if(y[i]<y_min && y[(i+1)%limit]>=y_min)				//OUT-->IN, storing interection point and second vertex 
		{
			xc[j] = x[i] + (y_min - y[i]) / m;
			yc[j] = y_min;
			xc[j+1] = x[(i+1)%limit];
			yc[j+1] = y[(i+1)%limit]; 
			j+=2;
		}
	}

	for(i=0; i<j; i++)
	{
		x[i] = xc[i];
		y[i] = yc[i];
		xc[i] = yc[i] = 0;
	}
	if(j<limit)
		for(; i<limit; i++)
			x[i] = y[i] = 0;
	return j;
}

int clip_top(int limit)
{
	int j=0; float m;
	for(i=0; i<limit; i++)
	{
		if(x[(i+1)%limit]-x[i])
		{
			m = (y[(i+1)%limit]-y[i]) * (1.0 / (x[(i+1)%limit]-x[i]));
		}
		else
		{
			m = FLT_MAX;
		}
		if(y[i]<=y_max && y[(i+1)%limit]<=y_max)			//IN-->IN, storing second vertex
		{
			xc[j] = x[(i+1)%limit];
			yc[j] = y[(i+1)%limit];
			j++;
			continue;
		}
		if(y[i]>y_max && y[(i+1)%limit]>y_max)
		{
			continue;										//OUT-->OUT, not storing any vertex
		}
		if(y[i]<=y_max && y[(i+1)%limit]>y_max)				//IN-->OUT, Storing intersection point only 
		{
			xc[j] = x[i] + ((y_max - y[i]) / m);
			yc[j] = y_max;
			j++;
			continue;
		}
		if(y[i]>y_max && y[(i+1)%limit]<=y_max)				//OUT-->IN, storing interection point and second vertex 
		{
			xc[j] = x[i] + ((y_max - y[i]) / m);
			yc[j] = y_max;
			xc[j+1] = x[(i+1)%limit];
			yc[j+1] = y[(i+1)%limit]; 
			j+=2;
		}
	}
	for(i=0; i<j; i++)
	{
		x[i] = xc[i];
		y[i] = yc[i];
		xc[i] = yc[i] = 0;
	}
	if(j<limit)
		for(; i<limit; i++)
			x[i] = y[i] = 0;
	return j;
}

void hodgman()
{
	int result_l = clip_left(vertices);
	int result_t = clip_top(result_l);
	int result_r = clip_right(result_t);
	int result_b = clip_bottom(result_r);

	glLineWidth(9.0);							//drawing the window	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.980, 0.337, 0.321);
	glVertex2f(x_min, y_min);
	glVertex2f(x_max, y_min);
	glVertex2f(x_max, y_max);
	glVertex2f(x_min, y_max);
	glEnd();	

    glBegin(GL_POLYGON);                        //drawing the polygon
	glColor3f(0.427, 0.984, 0.176);
	for(i=0; i<result_b; i++)
    {
        glVertex2f(x[i],y[i]);
    }
	glEnd();	
    glFlush();
}

void key(int key, int x, int y)
{
	if(key == GLUT_KEY_RIGHT)
	{
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		hodgman();
	}
}

void init()
{
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
}

void display() 
{
	glLineWidth(9.0);							//drawing the window	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.427, 0.984, 0.176);
	glVertex2f(x_min, y_min);
	glVertex2f(x_max, y_min);
	glVertex2f(x_max, y_max);
	glVertex2f(x_min, y_max);
	glEnd();	

    glBegin(GL_POLYGON);                        //drawing the polygon
	glColor3f(0.141, 0.670, 0.976);
	for(i=0; i<vertices; i++)
    {
        glVertex2f(x[i],y[i]);
    }
	glEnd();	
    glFlush();
}

int main(int argc,char** argv) 
{ 
	glutInit(&argc,argv);
	printf("Enter the value of x_min: ");
	scanf("%d",&x_min); 
	printf("Enter the value of x_max: ");
	scanf("%d",&x_max); 
	printf("Enter the value of y_min: ");
	scanf("%d",&y_min); 
	printf("Enter the value of y_max: ");
	scanf("%d",&y_max); 
    printf("Enter the number of vertices of polygon: ");
    scanf("%d",&vertices);
    printf("Enter the coordinates in cyclic order\n");
    for(i=0; i<vertices; i++)
    {
        printf("Vertex %d: ",i+1);
        scanf("%d%d",&x[i],&y[i]);
    }
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500,300);
	glutInitWindowSize(500,500);
	glutCreateWindow("Sutherland–Hodgman Polygon Clipping Algorithm");
	init();	
	glutDisplayFunc(display);
 	glutSpecialFunc(key);
	glutMainLoop();
	return 0; 
}