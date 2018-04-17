#include "track_lab.h"

GLfloat width;
GLfloat height;

GLdouble eyeX = 5000, eyeY = 5000, eyeZ = 5000;
GLdouble centerX = 0, centerY = 0, centerZ = 0;
GLdouble upX = 0, upY = 1, upZ = 0;

void init()
{
  glClearColor( 0.0, 0.0, 0.0, 0.0 );
  width = 680;
  height = 480;
  glEnable( GL_DEPTH_TEST );
}

void display()
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  glLoadIdentity();
  gluLookAt( eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ );
  draw_room( 0 , 0, 0, 20000.0, 15000.0, 15000.0 );
  draw_subject( -4000, -3900, 0 );

  glutSwapBuffers();
}

void reshape(int n_width, int n_height)
{
  glViewport( 0.0, 0.0, width, height );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();

  gluPerspective( 45.0f, ( GLfloat ) n_width / ( GLfloat ) n_height, 1.0f, 20000000000000.0f );

  glMatrixMode( GL_MODELVIEW );

  width = n_width;
  height = n_height;
}

void timer( int value )
{
  float theta = 2 * 3.1415926 / float(360);
	float tangetial_factor = tanf(theta);//calculate the tangential factor

	float radial_factor = cosf(theta);//calculate the radial factor

  float teyeX = -eyeZ;
  float teyeZ = eyeX;

  eyeX += teyeX * tangetial_factor;
  eyeZ += teyeZ * tangetial_factor;

  eyeX *= radial_factor;
  eyeZ *= radial_factor;

  glutPostRedisplay();
  glutTimerFunc( 1000.0 / 60.0, timer, 0 );
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
  glutTimerFunc( 1000.0 / 60.0, timer, 0 );
  glutMainLoop();

  return 0;
}
