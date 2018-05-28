#include <iostream>

#include <GL/freeglut.h>
#include <GL/gl.h>

bool paused = false;

GLfloat width;
GLfloat height;

GLdouble eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ;

GLdouble eye_1_X = 1461.0, eye_1_Y = -5000.0, eye_1_Z = 483.0;
GLdouble center_1_X = 1461, center_1_Y = 0, center_1_Z = 483;
GLdouble up_1_X = 0, up_1_Y = 0, up_1_Z = 1;

GLdouble eye_2_X = 5000, eye_2_Y = 800, eye_2_Z = 700;
GLdouble center_2_X = -224.5, center_2_Y = 800, center_2_Z = 700;
GLdouble up_2_X = 0, up_2_Y = 0, up_2_Z = 1;

GLdouble eye_3_X = -1461, eye_3_Y = -526, eye_3_Z = 5000;
GLdouble center_3_X = 1461, center_3_Y = 526, center_3_Z = 0;
GLdouble up_3_X = 0, up_3_Y = 1, up_3_Z = 0;

void init()
{
  glClearColor( 1.0, 1.0, 1.0, 0.0 );
  width = 680;
  height = 480;
  glEnable( GL_DEPTH_TEST );
}

void display()
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  glLoadIdentity();

  gluLookAt( eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ );

  glPushMatrix();
  glColor3f( 0, 1, 0 );
  glTranslatef( 26, 494, 59 );
  glScalef( 50, 50, 50 );
  glutSolidSphere( 1.0,  20.0,  20.0 );
  //glScalef( 2.541,51, 5 );
  //glutSolidCube( 1.0 );
  /*glBegin( GL_QUADS );
    glVertex3i();
    glVertex3i();
    glVertex3i();
    glVertex3i();
  glEnd();*/
  glPopMatrix();

  glPushMatrix();
  glColor3f( 0.0, 1, 0 );
  glTranslatef( 2744, 603, 17 );
  glScalef( 50, 50, 50 );
  glutSolidSphere( 1.0,  20.0,  20.0 );
  glPopMatrix();

  //ltoe
  glPushMatrix();
  glColor3f( 0.0, 0.0, 1.0 );
  glTranslatef( -475, 592, 18 );
  glScalef( 50, 50, 50 );
  glutSolidSphere( 1.0,  20.0,  20.0 );
  glPopMatrix();

  glPushMatrix();
  glColor3f( 0.0, 0.0, 1.0 );
  glTranslatef( 3383, 789, 12 );
  glScalef( 50, 50, 50 );
  glutSolidSphere( 1.0,  20.0,  20.0 );
  glPopMatrix();

  //SACR
  glPushMatrix();
  glColor3f( 1.0, 0, 0 );
  glTranslatef( -480, 526, 954 );
  glScalef( 50, 50, 50 );
  glutSolidSphere( 1.0,  20.0,  20.0 );
  glPopMatrix();

  glPushMatrix();
  glColor3f( 1.0, 0.5, 0 );
  glTranslatef( 3215, 709, 968 );
  glScalef( 50, 50, 50 );
  glutSolidSphere( 1.0,  20.0,  20.0 );
  glPopMatrix();

  glutSwapBuffers();
}

void reshape(int n_width, int n_height)
{
  glViewport( 0.0, 0.0, width, height );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();

  gluPerspective( 60.0f, ( GLfloat ) n_width / ( GLfloat ) n_height, 1.0f, 10000.0f );

  glMatrixMode( GL_MODELVIEW );

  width = n_width;
  height = n_height;
}

void keyboard( unsigned char key, int x, int y )
{
  switch(key)
  {
    case 'q': case 'Q': case 27:
      exit(0);
    break;
    case '1':
      eyeX = eye_1_X;
      eyeY = eye_1_Y;
      eyeZ = eye_1_Z;
      centerX = center_1_X;
      centerY = center_1_Y;
      centerZ = center_1_Z;
      upX = up_1_X;
      upY = up_1_Y;
      upZ = up_1_Z;
    break;
    case '2':
      eyeX = eye_2_X;
      eyeY = eye_2_Y;
      eyeZ = eye_2_Z;
      centerX = center_2_X;
      centerY = center_2_Y;
      centerZ = center_2_Z;
      upX = up_2_X;
      upY = up_2_Y;
      upZ = up_2_Z;
    break;
    case '3':
      eyeX = eye_3_X;
      eyeY = eye_3_Y;
      eyeZ = eye_3_Z;
      centerX = center_3_X;
      centerY = center_3_Y;
      centerZ = center_3_Z;
      upX = up_3_X;
      upY = up_3_Y;
      upZ = up_3_Z;
    break;
    case 'p': case 'P':
      paused = true;
    break;
  }

  glutPostRedisplay();
}

int main( int argc, char* argv[] )
{
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
  glutInitWindowPosition( 100, 100 );
  glutInitWindowSize( 640, 480 );
  glutCreateWindow( "Track Lab" );
  init();
  glutDisplayFunc( display );
  glutReshapeFunc( reshape );
  glutKeyboardFunc( keyboard );
  glutMainLoop();

  return 0;
}
