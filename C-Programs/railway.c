#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include	<math.h>
#include	<time.h>
//#include	<windows.h>
//#define	M_PI	3.14

int	c=0,d=500,g=380,h=970,i=540,j=970,k=380,l=965,m=540,n=970;
GLfloat	x=0.0;
int	z=0,a;
int	train1,basic;

//matrix
	void	sky()
	{
	
																		glBegin(GL_POLYGON);
																		glColor3f(0,1,1);
																	glVertex2f(0,730);
																	glVertex2f(999,730);
																	glVertex2f(999,999);
																	glVertex2f(0,999);
																	glEnd();
		
		}
		
		void	sleep(unsigned	int	mseconds)
		{
						clock_t	goal	=	mseconds	+	clock();
						while	(goal	>	clock());
		}
		
		
		void	TRAINS(int	x1,int	y1,int	a,int	b)
		{															int	i=0;
		
																	glBegin(GL_QUADS);
																	glColor3f(0,0.0,1.0);																		//ENGINE
																		glVertex2f(x1,y1);																														//lengh	of	engine=60;height	of	engine=30;
	
																glColor3f(0,0.0,1.0);
																	glVertex2f(x1+60,y1);
																	glColor3f(1.0,0.0,0.0);
																	glVertex2f(x1+60,y1-30);
																	glColor3f(0,0.0,0.0);
																	glVertex2f(x1,y1-30);
																	glEnd();
		
																	while(i<3)
																	{							glBegin(GL_QUADS);																						//BOGIES
																									glColor3f(1.0,0.0,0.0);														//For	right	train	a=795,b=510
																									glVertex2f(a,b);
																									glColor3f(1.0,0.0,0.0);
																									glVertex2f(a+60,b);
																									glColor3f(1.0,0.0,0.0);
																									glVertex2f(a+60,b-20);
																									glColor3f(1.0,0.0,0.0);
																									glVertex2f(a,b-20);
																									glEnd();
																										a+=65;
																										i++;
																	}
		
		}
		
		
		void	TRACKS()
		{
		
																	sky();																	/**	Track	**/
																	glBegin(GL_LINES);
																	glColor3f(0.0,0.0,0.0);
																	glVertex2f(0,500);
																	glVertex2f(1000,500);
																	glVertex2f(0,499);
																	glVertex2f(1000,499);
																	glVertex2f(0,485);
																	glVertex2f(1000,485);
																	glVertex2f(0,486);
																	glVertex2f(1000,486);
																	while(c!=1000)
																	{
																									glVertex2f(c,d);
																									glVertex2f(c,d-15);
																									c+=10;
																	}
																	glEnd();
		}
		
		
		
		void	myinit()
		{							glClearColor(0.0,0.5,0.0,0.0);								//background	color
										gluOrtho2D(0,999,0,999);
										glPointSize(2.0);
									glLineWidth(2.0);
	
									basic	=	glGenLists(1);
																	glNewList(basic,	GL_COMPILE);
																	TRACKS();
									glEndList();
	
									train1	=	glGenLists(1);
																	glNewList(train1,	GL_COMPILE);
																	TRAINS(730,520,795,510);
									glEndList();
	}
	
	
	void	draw(void)
	{
	
									glClear(GL_COLOR_BUFFER_BIT);
									glPushMatrix();
	
									glPushMatrix();
																	glCallList(basic);
									glPopMatrix();
	
									glPushMatrix();
																	glTranslatef(x,0.0,0.0);
																	glCallList(train1);
																	glFlush();
									glPopMatrix();
	if(z<198)
	{							a+=5;
									x=x-5.0;
									sleep(10000);
									z++;
	}
	
	glPopMatrix();
	glutPostRedisplay();
	glFlush();
	
	}
	
	
	void	main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);					

glutInitWindowSize(1200,700);
glutCreateWindow("Running	Trains");
glutDisplayFunc(draw);
									myinit();
					glutMainLoop	();
}
