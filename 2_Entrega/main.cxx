#include <GL/freeglut>
#include <GL/gl.h>

void reshape(int width, int height)
{
  glViewport( 0.0, 0.0, width, height );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();

  gluPerspective( 60.0f, ( GLfloat ) width / ( GLfloat ) height, 1.0f, 100.0f );

  glMatrixMode( GL_MODELVIEW );

}

void init()
{
  glClearColor( 0.0, 0.0, 0.0, 0.0 );
  glEnable( GL_DEPTH_TEST );
}

int main( int argc, char* argv[] )
{
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
}
