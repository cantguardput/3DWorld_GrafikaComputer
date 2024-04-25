#include<gl/freeglut.h> 

float xrot =0;
float yrot =0;
float xdiff =0;
float ydiff =0;
bool mouseDown = false;

void project(int width, int height){
	if (height==0) height=1;
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,width/height, 5, 450);
	glTranslatef(0, 0, -300);
	glMatrixMode(GL_MODELVIEW);
	
}
	

void init(void){
	glClearColor(0.5, 0.5, 0.5, 0.1);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	
	glMatrixMode(GL_MODELVIEW);
	glPointSize(10.0);
	glLineWidth(7.0f);	
}


void idle(){
	if (!mouseDown)	{
		xrot+=0.3;
		yrot+=0.4;
	}
	glutPostRedisplay();
}

void mouse (int button, int state, int x, int y){
	if(button==GLUT_LEFT_BUTTON && state ==GLUT_DOWN){
		mouseDown=true;
		xdiff=x - yrot;
		ydiff= -y + xrot;
	}
	else mouseDown = false;
}

void mousemotion(int x, int y)
{
	if(mouseDown){
		yrot= x - xdiff;
		xrot= y + ydiff;
		glutPostRedisplay();
	}
}

void displayFloor(){
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-100, -30, 80);
    glVertex3f(100, -30, 80);
    glVertex3f(100, -30, -80);
    glVertex3f(-100, -30, -80);
    glEnd();
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(-9, 3, 12, 3, 0, 0, 0, 1, 0);
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);
	
	//Lantai
   	glPushMatrix();
    displayFloor();
    glPopMatrix();
    
    // Dinding Kanan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6); 
    glVertex3f(100, -30, 80);
    glVertex3f(100, 100, 80); 
    glVertex3f(100, 100, -80);
    glVertex3f(100, -30, -80);
    glEnd();
    glPopMatrix();

    // Dinding Kiri
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.65, 0.65, 0.65); 
    glVertex3f(-100,-30,-80);
	glVertex3f(100,-30,-80);
	glVertex3f(100,100,-80);
	glVertex3f(-100,100,-80);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

int main (int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(250, 80);
	glutInitWindowSize(900, 600);
	glutCreateWindow("3D World Bedroom");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(mousemotion);
	glutReshapeFunc(project);
	init();
	glutMainLoop();
}
