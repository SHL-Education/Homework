#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include <GL/glut.h>

#define SLICE	360

void rect_pulse_signal(void)
{
	float t, T = 0.01;
	float amp = 100;
	float step = 0.0;
	float omega = 2 * M_PI * 100;	// frequency = 5 Hz
	float x = 0, x2 = 0, y, cx, cy;
	int cache = 0;
	int i;

	//t = step = T / 100;
	step = T / 100;
	t = -1 * T;

	//printf("step = %f\n", step);

	if(t > T)
		t = 0.0;
	
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_LINES);
	for(; ; t += step)
	{
		y = 0;

		if(t > 1 * T)
		{
			break;
			t = 0.0;
		}

		//y = amp * (sin(omega * t) / (omega * t));
		for(i = 1; i < 101; i++)
			y += 100 * ((1 - cos(i * M_PI)) / (i * M_PI) * sin(i * t));

		if(cache)
		{
			glVertex2f(cx * 6000, cy * 1);
			glVertex2f(t * 6000, y * 1);
		}

		cache = 1;
		cx = t;
		cy = y;
		//printf("t = %f, y = %f\n", t * 6000, y * 1);
	}
	glEnd();
}

void display(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	glColor3f(1, 0, 0);

	glBegin(GL_LINE_LOOP);
	glVertex3f(100.0, 0.0, 0.0);
        glVertex3f(-100.0, 0.0, 0.0);
        glEnd();

        glColor3f(0.0, 1.0, 0.0);

        glBegin(GL_LINE_LOOP);
        glVertex3f(0.0, 100.0, 0.0);
        glVertex3f(0.0, -100.0, 0.0);
        glEnd();

	rect_pulse_signal();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
        GLfloat n_range = 20.0f;

        if(h == 0)
                h = 1;

        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        if(w <= h)
                glOrtho(-n_range, n_range, -n_range * h / w, n_range * h / w, -n_range, n_range);
        else
                glOrtho(-n_range * w / h, n_range * w / h, -n_range, n_range, -n_range, n_range);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(0);
			break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(1200, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Digital Signal Processing");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}
