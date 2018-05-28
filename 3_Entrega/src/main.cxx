#include <GL/freeglut.h>
#include <GL/gl.h>

GLfloat width;
GLfloat height;
GLfloat iteration;
bool running = true;

GLdouble eye_1_X = 5000, eye_1_Y = 5000, eye_1_Z = 5000;
GLdouble center_1_X = 0, center_1_Y = 0, center_1_Z = 0;
GLdouble up_1_X = 0, up_1_Y = 1, up_1_Z = 0;

GLdouble eye_2_X = 5000, eye_2_Y = 5000, eye_2_Z = 5000;
GLdouble center_2_X = 0, center_2_Y = 0, center_2_Z = 0;
GLdouble up_2_X = 0, up_2_Y = 1, up_2_Z = 0;

GLdouble eye_3_X = -5000, eye_3_Y = -5000, eye_3_Z = -5000;
GLdouble center_3_X = 0, center_3_Y = 0, center_3_Z = 0;
GLdouble up_3_X = 0, up_3_Y = 1, up_3_Z = 0;

void init()
{
    iteration = 0;
  glClearColor( 0.0, 0.0, 0.0, 0.0 );
  width = 680;
  height = 480;
  glEnable( GL_DEPTH_TEST );
}

void display()
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  glLoadIdentity();
  //gluLookAt( eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ );
  gluLookAt( 1461.0, 329.0, 50.0, 1461.0, 329.0, 62.0, 0, 1, 0 );
  glPushMatrix();
  glColor3f( 0.0, 0.4, 1.0 );
  //glTranslatef( 1461.0, 329.0, 62.0 );
  //glScalef( 2.641, 1, 1 );
  glutSolidCube( 1.0 );
  glPopMatrix();

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

void timer( int value ) {
    if( running ) {
        iteration += 1;
    }

    glutPostRedisplay( );
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
