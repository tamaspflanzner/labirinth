#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "WallFactory.h"

using namespace std;

// Define a constant for the value of PI
#define GL_PI 3.1415f

GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;
GLfloat RedCubeAlpha = 0.5;
GLfloat BlueCubeAlpha = 0.5;
int RedCubeFirst = 1;
int BlendType = 0;
GLfloat WallColorComponent = 0.5f;

int MenuID;

static GLfloat lightPos[] = { 0.0f, 0.0f, 75.0f, 1.0f };
static GLfloat ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f};
static GLfloat diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f};

char textout[256];

int nrOfRounds = 5;
WallFactory *wallFactory;

void BitmapText(GLfloat x, GLfloat y, char *string)
{
  int len, i;
  glRasterPos2f(x, y);
  len = (int) strlen (string);
  for (i = 0; i < len; i++){
    glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, string[i]);
  }
}

void RenderRedCube(GLfloat alpha)
{
  glColor4f(1.0, 0.0, 0.0, alpha);
  glutSolidCube(5.0);
}

void RenderBlueCube(GLfloat alpha)
{
  glColor4f(0.0, 0.0, 1.0, alpha);
  glutSolidCube(15.0);
}

void RenderGrayWall(GLfloat gray)
{
  glPushMatrix();
  glColor4f(gray, gray, gray, 1.0);
  glTranslatef(0.0, 0.0, -20.0);
  glScalef(20.0, 20.0, 1.0);
  glutSolidCube(1.0);
  glPopMatrix();
}

void RenderText()
{
  glPushAttrib(GL_LIGHTING_BIT);
  glDisable(GL_LIGHTING);
  glColor3f(1.0, 1.0, 1.0);
  sprintf(textout, "Blue alpha: %0.1f  Red alpha: %0.1f", BlueCubeAlpha, RedCubeAlpha);
  BitmapText(-20.0, -20.0, textout);
  glPopAttrib();
}

// Called to draw scene
void RenderScene(void)
{
  // Clear the window with current clearing color
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // >> Modellezo programresz

  //RenderText();

  glPushMatrix();
  glRotatef(xRot, 1.0, 0.0, 0.0);
  glRotatef(yRot, 0.0, 1.0, 0.0);

  //glEnable(GL_CULL_FACE);

  //RenderGrayWall(WallColorComponent);

	glPushMatrix();
//  	glColor4f(0.0, 1.0, 0.0, 1.0);
  	//glTranslatef(0.0, 0.0, -20.0);
  	glScalef(0.1, 0.1, 0.1);


	for(int w=0; w<8*wallFactory->nrOfRounds; w++){
	
		for(int r=0; r<6; r++){
		  	glBegin(GL_POLYGON);

				if(r==0)
					  	glColor4f(0.0, 1.0, 0.0, 1.0);
				if(r==1)
					  	glColor4f(1.0, 0.0, 0.0, 1.0);
				if(r==2)
					  	glColor4f(0.0, 0.0, 1.0, 1.0);
				if(r==3)
					  	glColor4f(1.0, 1.0, 0.0, 1.0);
				if(r==4)
					  	glColor4f(1.0, 0.0, 1.0, 1.0);
				if(r==5)
					  	glColor4f(0.0, 1.0, 1.0, 1.0);
				
				

		  		for(int p=0; p<4; p++){
				
			    	glVertex3f(wallFactory->walls[w].rectangles[r].points[p].x, 
					wallFactory->walls[w].rectangles[r].points[p].y,
					wallFactory->walls[w].rectangles[r].points[p].z );
		  		}
		  	glEnd();
		}
	}

//	glVertex3f(1.0,1.0,1.0,1.0);

  	glPopMatrix();

  glPopMatrix();
  
  // << Modellezo programresz
  
  // Flush drawing commands
  glutSwapBuffers();
}

// This function does any needed initialization on the rendering
// context. 
void SetupRC()
{
  // Black background
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
  glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

	// Setup and enable light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);

	// Enable Material color tracking
	glEnable(GL_COLOR_MATERIAL);
	// Front material ambient and diffuse colors track glColor
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glEnable(GL_NORMALIZE);

	wallFactory = new WallFactory(nrOfRounds);
}

void SpecialKeys(int key, int x, int y)
{
  // ...
  int state;

  printf("Funkciobillentyu lenyomva, kodja %d, pozicio (%d,%d). ", key, x, y);
  state = glutGetModifiers();
  if(state & GLUT_ACTIVE_SHIFT)
    printf("SHIFT lenyomva. ");
  if(state & GLUT_ACTIVE_CTRL)
    printf("CTRL lenyomva. ");
  if(state & GLUT_ACTIVE_ALT)
    printf("ALT lenyomva. ");
  printf("\n");
  fflush(stdout);

  if(key == GLUT_KEY_UP)
    xRot-= 5.0f;
  
  if(key == GLUT_KEY_DOWN)
    xRot += 5.0f;
  
  if(key == GLUT_KEY_LEFT)
    yRot -= 5.0f;
  
  if(key == GLUT_KEY_RIGHT)
    yRot += 5.0f;
  
  if(xRot > 356.0f)
    xRot = 0.0f;
  
  if(xRot < -1.0f)
    xRot = 355.0f;
  
  if(yRot > 356.0f)
    yRot = 0.0f;
  
  if(yRot < -1.0f)
    yRot = 355.0f;


  if(key == GLUT_KEY_F1)
    BlueCubeAlpha += 0.1;

  if(key == GLUT_KEY_F2)
    BlueCubeAlpha -= 0.1;

  if(key == GLUT_KEY_F3)
    RedCubeAlpha += 0.1;

  if(key == GLUT_KEY_F4)
    RedCubeAlpha -= 0.1;

  if(RedCubeAlpha < 0.0)
    RedCubeAlpha = 0.0;
  
  if(RedCubeAlpha > 1.0)
    RedCubeAlpha = 1.0;

  if(BlueCubeAlpha < 0.0)
    BlueCubeAlpha = 0.0;
  
  if(BlueCubeAlpha > 1.0)
    BlueCubeAlpha = 1.0;

  // Refresh the Window
  glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y)
{
  // ...
  int state;

  printf("Billentyu lenyomva, kodja %c, pozicio (%d,%d). ", key, x, y);
  state = glutGetModifiers();
  if(state & GLUT_ACTIVE_SHIFT)
    printf("SHIFT lenyomva. ");
  if(state & GLUT_ACTIVE_CTRL)
    printf("CTRL lenyomva. ");
  if(state & GLUT_ACTIVE_ALT)
    printf("ALT lenyomva. ");
  printf("\n");
  fflush(stdout);

  glutPostRedisplay();
}

void Timer(int value)
{
  printf("Timer esemeny (%d)\n", value);

  glutPostRedisplay();
  glutTimerFunc(1000, Timer, value + 1);
}

void Idle()
{

  glutPostRedisplay();
}

void ChangeSizeOrtho(int w, int h)
{
  GLfloat nRange = 25.0f;
  
  // Prevent a divide by zero
  if(h == 0)
    h = 1;
  
  // Set Viewport to window dimensions
  glViewport(0, 0, w, h);
  
  // Reset projection matrix stack
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  // Establish clipping volume (left, right, bottom, top, near, far)
  if (w <= h) 
    glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
  else 
    glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);
  
  // Reset Model view matrix stack
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void ChangeSizePerspective(GLsizei w, GLsizei h)
{
  GLfloat fAspect;
  
  // Prevent a divide by zero
  if(h == 0)
    h = 1;
  
  // Set Viewport to window dimensions
  glViewport(0, 0, w, h);
  
  fAspect = (GLfloat)w/(GLfloat)h;
  
  // Reset coordinate system
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  // Produce the perspective projection
  gluPerspective(60.0f,    // fovy
		 fAspect,  // aspect
		 10.0,     // zNear
		 100.0     // zFar
		 );
  gluLookAt(0.0, 0.0, 50.0, // eye
	    0.0, 0.0, 0.0,  // center
	    0.0, 1.0, 0.0   // up
	    );
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void ProcessMenu(int value)
{
  switch(value)
    {
    case 1:
      printf("1. menupont kivalasztva.\n");
      RedCubeFirst = 1;
      break;
      
    case 2:
      printf("2. menupont kivalasztva.\n");
      RedCubeFirst = 0;
      break;
      
    case 3:
      BlendType = 0;
      break;

    case 4:
      BlendType = 1;
      break;

    case 5:
      WallColorComponent = 0.5f;
      break;

    case 6:
      WallColorComponent = 1.0f;
      break;

    case 7:
      exit(0);

    default:
      break;
    }
  
  glutPostRedisplay();
}

int main(int argc, char* argv[])
{
  // >> Inicializalas

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  //glutInitWindowSize(300, 300);
  glutCreateWindow("GLUT Alap");

  // << Inicializalas

  // >> Callback fuggvenyek

  glutReshapeFunc(ChangeSizeOrtho); // Parhuzamos vetites
  //glutReshapeFunc(ChangeSizePerspective); // Perspektiv vetites

  glutSpecialFunc(SpecialKeys);
  glutKeyboardFunc(Keyboard);
  glutDisplayFunc(RenderScene);
  //glutTimerFunc(1000, Timer, 1); // 1 mp mulva meghivodik a Timer() fuggveny
  //glutIdleFunc(Idle); // Idle(), ha nem tortenik semmi
  
  // << Callback fuggvenyek

  // >> Menu

  MenuID = glutCreateMenu(ProcessMenu);
  glutAddMenuEntry("Piros kocka eloszor", 1);
  glutAddMenuEntry("Kek kocka eloszor", 2);
  glutAddMenuEntry("Dst Blend: GL_ONE_MINUS_SRC_ALPHA", 3);
  glutAddMenuEntry("Dst Blend: GL_ONE", 4);
  glutAddMenuEntry("Szurke fal", 5);
  glutAddMenuEntry("Feher fal", 6);
  glutAddMenuEntry("Kilepes", 7);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  // << Menu

  SetupRC();
  glutMainLoop();
  
  return 0;
}
