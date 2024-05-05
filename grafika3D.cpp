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

void floor(){
	// Bottom 
	glBegin(GL_POLYGON);
	glColor3f(0.55,0.55,0.55);
	glVertex3f(-100,-30,80);
	glVertex3f(110,-30,80);
	glVertex3f(110,-30,-90);
	glVertex3f(-100,-30,-90);
	glEnd();
	
	// Front 
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(-100,-30,80);
	glVertex3f(110,-30,80);
	glVertex3f(110,-20,80);
	glVertex3f(-100,-20,80);
	glEnd();
	
	// Top
	glBegin(GL_POLYGON);
	glColor3f(0.25, 0.55, 0.55);
	glVertex3f(-100,-20,80);
	glVertex3f(110,-20,80);
	glVertex3f(110,-20,-90);
	glVertex3f(-100,-20,-90);
	glEnd();
	
	// Back 
	glBegin(GL_POLYGON);
	glColor3f(0.2,0.2,0.2);
	glVertex3f(-100,-30,-90);
	glVertex3f(110,-30,-90);
	glVertex3f(110,-20,-90);
	glVertex3f(-100,-20,-90);
	glEnd();
	
	// Left
	glBegin(GL_POLYGON);
	glColor3f(0.2,0.2,0.2);
	glVertex3f(-100,-30,80);
	glVertex3f(-100,-30,-90);
	glVertex3f(-100,-20,-90);
	glVertex3f(-100,-20,80);
	glEnd();
	
	// Right 
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(110,-30,80);
	glVertex3f(110,-30,-90);
	glVertex3f(110,-20,-90);
	glVertex3f(110,-20,80);
	glEnd();
	
}

void wall(){
	 // Right Wall
	 //Left
    glBegin(GL_POLYGON);
    glColor3f(0.3,0.3,0.45); 
    glVertex3f(100, -20, 80);
    glVertex3f(100, 100, 80); 
    glVertex3f(100, 100, -90);
    glVertex3f(100, -20, -90);
    glEnd();
    
     //Right
    glBegin(GL_POLYGON);
    glColor3f(0.3,0.3,0.45); 
    glVertex3f(110, -20, 80);
    glVertex3f(110, 100, 80); 
    glVertex3f(110, 100, -90);
    glVertex3f(110, -20, -90);
    glEnd();
    
    //Front
	glBegin(GL_POLYGON);
	glColor3f(0.55, 0.55, 0.65);
	glVertex3f(100, -20, 80);
	glVertex3f(100, 100, 80);
	glVertex3f(110, 100, 80);
	glVertex3f(110, -20, 80);
	glEnd();
	
	//Back
	glBegin(GL_POLYGON);
	glColor3f(0.3,0.3,0.5); 
	glVertex3f(100, -20, -90);
	glVertex3f(100, 100, -90);
	glVertex3f(110, 100, -90);
	glVertex3f(110, -20, -90);
	glEnd();
	
	//Top
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.7);
	glVertex3f(100, 100, 80);
	glVertex3f(110, 100, 80);
	glVertex3f(110, 100, -90);
	glVertex3f(100, 100, -90);
	glEnd();
	
	//Bottom
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.7);
	glVertex3f(100, -20, 80);
	glVertex3f(110, -20, 80);
	glVertex3f(110, -20, -90);
	glVertex3f(100, -20, -90);
	glEnd();

    // Left Wall
    // Front
    glBegin(GL_POLYGON);
    glColor3f(0.3,0.3,0.5); 
    glVertex3f(-100,-20,-80);
	glVertex3f(100,-20,-80);
	glVertex3f(100,100,-80);
	glVertex3f(-100,100,-80);
    glEnd();
    
    // Back 
	glBegin(GL_POLYGON);
    glColor3f(0.3,0.3,0.5); 
    glVertex3f(-100,-20,-90);
	glVertex3f(100,-20,-90);
	glVertex3f(100,100,-90);
	glVertex3f(-100,100,-90);
    glEnd();
    
    // Left
	glBegin(GL_POLYGON);
	glColor3f(0.55, 0.55, 0.65);
	glVertex3f(-100,100,-80);
	glVertex3f(-100,100,-90);
	glVertex3f(-100,-20,-90);
	glVertex3f(-100,-20,-80);
	glEnd();
	
	// Right
	glBegin(GL_POLYGON);
	glColor3f(0.55, 0.55, 0.65);
	glVertex3f(100,100,-80);
	glVertex3f(100,100,-90);
	glVertex3f(100,-20,-90);
	glVertex3f(100,-20,-80);
	glEnd();
	
	// Top
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.7);
	glVertex3f(-100, 100, -80);
	glVertex3f(100, 100, -80);
	glVertex3f(100, 100, -90);
	glVertex3f(-100, 100, -90);
	glEnd();
	
	// Bottom
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.7);
	glVertex3f(-100, -20, -80);
	glVertex3f(100, -20, -80);
	glVertex3f(100, -20, -90);
	glVertex3f(-100, -20, -90);
	glEnd();
}

void wardrobe() {
  glTranslatef(-90, 0, -80);
  
  // Front 
  glBegin(GL_POLYGON);
  glColor3f(0.65, 0.35, 0.3);
  glVertex3f(0, -20, 30);
  glVertex3f(50, -20, 30);
  glVertex3f(50, 80, 30);
  glVertex3f(0, 80, 30);
  glEnd();

  // Back 
  glBegin(GL_POLYGON);
  glColor3f(0.65, 0.35, 0.3);
  glVertex3f(0, -20, 0);
  glVertex3f(50, -20, 0);
  glVertex3f(50, 80, 0);
  glVertex3f(0, 80, 0);
  glEnd();

  // Left 
  glBegin(GL_POLYGON);
  glColor3f(0.6, 0.3, 0.15);
  glVertex3f(0, -20, 0);
  glVertex3f(0, -20, 30);
  glVertex3f(0, 80, 30);
  glVertex3f(0, 80, 0);
  glEnd();

  // Top 
  glBegin(GL_POLYGON);
  glColor3f(0.6, 0.3, 0.25);
  glVertex3f(0, 80, 0);
  glVertex3f(50, 80, 0);
  glVertex3f(50, 80, 30);
  glVertex3f(0, 80, 30);
  glEnd();
  
  // Bottom 
  glBegin(GL_POLYGON);
  glColor3f(0.6, 0.3, 0.25);
  glVertex3f(0, -20, 0);
  glVertex3f(50, -20, 0);
  glVertex3f(50, -20, 30);
  glVertex3f(0, -20, 30);
  glEnd();

  // Right 
  glColor3f(0.6, 0.3, 0.15);
  glBegin(GL_POLYGON);
  glVertex3f(50, -20, 0);
  glVertex3f(50, -20, 30);
  glVertex3f(50, 80, 30);
  glVertex3f(50, 80, 0);
  glEnd();
  
}

void bed() {
    glTranslatef(-90, 0, 0);
   
    // Bedframe    
    // Front
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.15);
    glVertex3f(0, 0, 80);
    glVertex3f(80, 0, 80);
    glVertex3f(80, -20, 80);
    glVertex3f(0, -20, 80);
    glEnd();
    
    // Back
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.15);
    glVertex3f(0, 0, 15);
    glVertex3f(80, 0, 15);
    glVertex3f(80, -20, 15);
    glVertex3f(0, -20, 15);
    glEnd();
    
    // Left
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.25);
    glVertex3f(0, 0, 15);
    glVertex3f(0, 0, 80);
    glVertex3f(0, -20, 80);
    glVertex3f(0, -20, 15);
    glEnd();
    
    // Right
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.25);
    glVertex3f(80, 0, 15);
    glVertex3f(80, 0, 80);
    glVertex3f(80, -20, 80);
    glVertex3f(80, -20, 15);
    glEnd();
    
    // Top
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.35, 0.35);
    glVertex3f(0, 0, 15);
    glVertex3f(80, 0, 15);
    glVertex3f(80, 0, 80);
    glVertex3f(0, 0, 80);
    glEnd();
    
    // Bottom
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.35, 0.98);
    glVertex3f(0, -20, 15);
    glVertex3f(80, -20, 15);
    glVertex3f(80, -20, 80);
    glVertex3f(0, -20, 80);
    glEnd();
    
    //Head Board
    // Left
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.25);
    glVertex3f(-10, 35, 15);
    glVertex3f(-10, 35, 80);
    glVertex3f(-10, -20, 80);
    glVertex3f(-10, -20, 15);
    glEnd();
    
	// Right
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.4, 0.4);
    glVertex3f(0, 35, 15);
    glVertex3f(0, 35, 80);
    glVertex3f(0, -20, 80);
    glVertex3f(0, -20, 15);
    glEnd();
    
    // Top
	glBegin(GL_POLYGON);
	glColor3f(0.65, 0.35, 0.35);
	glVertex3f(-10, 35, 15);
	glVertex3f(0, 35, 15);
	glVertex3f(0, 35, 80);
	glVertex3f(-10, 35, 80);
	glEnd();
	
	// Bottom
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.35, 0.35);
	glVertex3f(-10, -20, 15);
	glVertex3f(0, -20, 15);
	glVertex3f(0, -20, 80);
	glVertex3f(-10, -20, 80);
	glEnd();
	
	// Front
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.3, 0.15);
	glVertex3f(-10, 35, 80);
	glVertex3f(0, 35, 80);
	glVertex3f(0, -20, 80);
	glVertex3f(-10, -20, 80);
	glEnd();
	
	// Back
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.3, 0.15);
	glVertex3f(-10, 35, 15);
	glVertex3f(0, 35, 15);
	glVertex3f(0, -20, 15);
	glVertex3f(-10, -20, 15);
	glEnd();
	
	// Bed    
    // Front
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.55);
    glVertex3f(0, 0, 80);
    glVertex3f(80, 0, 80);
    glVertex3f(80, 10, 80);
    glVertex3f(0, 10, 80);
    glEnd();
    
    // Back
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.55);
    glVertex3f(0, 0, 15);
    glVertex3f(80, 0, 15);
    glVertex3f(80, 10, 15);
    glVertex3f(0, 10, 15);
    glEnd();
    
    // Left
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.45);
    glVertex3f(0, 0, 15);
    glVertex3f(0, 0, 80);
    glVertex3f(0, 10, 80);
    glVertex3f(0, 10, 15);
    glEnd();
    
    // Right
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.45);
    glVertex3f(80, 0, 15);
    glVertex3f(80, 0, 80);
    glVertex3f(80, 10, 80);
    glVertex3f(80, 10, 15);
    glEnd();
    
    // Top
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.7);
    glVertex3f(0, 10, 15);
    glVertex3f(80, 10, 15);
    glVertex3f(80, 10, 80);
    glVertex3f(0, 10, 80);
    glEnd();
    
    // Bottom
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.35, 0.35);
    glVertex3f(0, 0, 15);
    glVertex3f(80, 0, 15);
    glVertex3f(80, 0, 80);
    glVertex3f(0, 0, 80);
    glEnd();
}

void desk() {
    glTranslatef(100, 0, 0); 

    //Top Desk
    // Top
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.7);
    glVertex3f(0, 25, -80);
    glVertex3f(0, 25, -45);
    glVertex3f(-90, 25, -45);
    glVertex3f(-90, 25, -80);
    glEnd();
    
    // Bottom
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.35, 0.3);
    glVertex3f(0, 20, -80);
    glVertex3f(0, 20, -45);
    glVertex3f(-90, 20, -45);
    glVertex3f(-90, 20, -80);
    glEnd();
    
    // Right
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.35, 0.2);
    glVertex3f(0, 25, -80);
    glVertex3f(0, 20, -80);
    glVertex3f(0, 20, -45);
    glVertex3f(0, 25, -45);
    glEnd();

    // Left
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.35, 0.2);
    glVertex3f(-90, 25, -80);
    glVertex3f(-90, 20, -80);
    glVertex3f(-90, 20, -45);
    glVertex3f(-90, 25, -45);
    glEnd();

    // Front
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.35, 0.3);
    glVertex3f(0, 25, -45);
    glVertex3f(-90, 25, -45);
    glVertex3f(-90, 20, -45);
    glVertex3f(0, 20, -45);
    glEnd();

	// Back
   	glBegin(GL_POLYGON);
    glColor3f(0.65, 0.35, 0.3);
    glVertex3f(0, 25, -80);
    glVertex3f(-90, 25, -80);
    glVertex3f(-90, 20, -80);
    glVertex3f(0, 20, -80);
    glEnd();

    // Table Leg (Right)
    // Top
	glBegin(GL_POLYGON);
	glColor3f(0.65, 0.35, 0.3);
	glVertex3f(0, 20, -80);
	glVertex3f(0, 20, -45);
	glVertex3f(-10, 20, -45);
	glVertex3f(-10, 20, -80);
	glEnd();
	
	// Bottom
	glBegin(GL_POLYGON);
	glColor3f(0.65, 0.35, 0.3);
	glVertex3f(0, -20, -80);
	glVertex3f(0, -20, -45);
	glVertex3f(-10, -20, -45);
	glVertex3f(-10, -20, -80);
	glEnd();

    //Right
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.35, 0.2);
    glVertex3f(0, -20, -80);
    glVertex3f(0, -20, -45);
    glVertex3f(0, 20, -45);
    glVertex3f(0, 20, -80);
    glEnd();
    
    //Left
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.15);
    glVertex3f(-10, -20, -80);
    glVertex3f(-10, -20, -45);
    glVertex3f(-10, 20, -45);
    glVertex3f(-10, 20, -80);
    glEnd();
    
    //Back
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.35, 0.3);
    glVertex3f(0, 20, -80);
    glVertex3f(-10, 20, -80);
    glVertex3f(-10, -20, -80);
    glVertex3f(0, -20, -80);
    glEnd();
    
    //Front
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.25);
    glVertex3f(0, 20, -45);
    glVertex3f(-10, 20, -45);
    glVertex3f(-10, -20, -45);
    glVertex3f(0, -20, -45);
    glEnd();
    
    // Table Leg (Left)
    // Top
	glBegin(GL_POLYGON);
	glColor3f(0.65, 0.35, 0.3);
	glVertex3f(-80, 20, -80);
	glVertex3f(-80, 20, -45);
	glVertex3f(-90, 20, -45);
	glVertex3f(-90, 20, -80);
	glEnd();
	
	// Bottom
	glBegin(GL_POLYGON);
	glColor3f(0.65, 0.35, 0.3);
	glVertex3f(-80, -20, -80);
	glVertex3f(-80, -20, -45);
	glVertex3f(-90, -20, -45);
	glVertex3f(-90, -20, -80);
	glEnd();

    //Right
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.15);
    glVertex3f(-80, -20, -80);
    glVertex3f(-80, -20, -45);
    glVertex3f(-80, 20, -45);
    glVertex3f(-80, 20, -80);
    glEnd();
    
    //Left
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.35, 0.2);
    glVertex3f(-90, -20, -80);
    glVertex3f(-90, -20, -45);
    glVertex3f(-90, 20, -45);
    glVertex3f(-90, 20, -80);
    glEnd();
    
    //Back
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.35, 0.3);
    glVertex3f(-80, 20, -80);
    glVertex3f(-90, 20, -80);
    glVertex3f(-90, -20, -80);
    glVertex3f(-80, -20, -80);
    glEnd();
    
    //Front
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.25);
    glVertex3f(-80, 20, -45);
    glVertex3f(-90, 20, -45);
    glVertex3f(-90, -20, -45);
    glVertex3f(-80, -20, -45);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
   	gluLookAt(0,0,3,0,0,0,0,1,0);
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);
	
	// Display Floor
   	glPushMatrix();
    floor();
    glPopMatrix();
    
    // Display Wall
   	glPushMatrix();
    wall();
    glPopMatrix();
    
    // Draw Wardrobe
    glPushMatrix();
    wardrobe();
    glPopMatrix();
    
    // Display Bed
    glPushMatrix();
    bed();
    glPopMatrix();
    
    // Display Desk
    glPushMatrix();
    desk();
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
