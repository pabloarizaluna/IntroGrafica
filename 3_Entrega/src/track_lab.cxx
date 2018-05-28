#include "track_lab.h"

std::vector< std::vector< std::vector< GLfloat > > > vertices;

void draw_room(
  GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth
  )
{

  glPushMatrix();
  glColor3fv( white );

  glTranslatef( x, y, z );
  glScalef( width, height, depth );
  glutSolidCube( 1.0 );
  glPopMatrix();

  glPushMatrix();
  glColor3f( 0.0, 0.0, 0.0 );

  glTranslatef( x, y, z );
  glScalef( width - width * 0.01 , height - height * 0.01, depth - depth * 0.01 );
  glutWireCube( 1.0 );
  glPopMatrix();

  glPushMatrix();
  glColor3fv( blue );

  glTranslatef( x - width * 0.25, y - height * 0.5, z );
  glScalef( width * 0.2, 100.0, depth * 0.75 );
  glutSolidCube( 1.0 );
  glPopMatrix();

  //left
  draw_walls(
    x - width * 0.5, y, z - height * 0.25, 800.0, height, depth * 0.25
  );

  draw_walls(
    x - width * 0.5, y, z + height * 0.25, 800.0, height, depth * 0.25
  );

  //rigth
  draw_walls(
    x + width * 0.5, y, z + height * 0.25, 800.0, height, depth * 0.25
  );

  draw_walls(
    x + width * 0.5, y, z - height * 0.25, 800.0, height, depth * 0.25
  );

  draw_door(
    x - width * 0.20, y - height * 0.35, z + depth * 0.5, width * 0.2, height,
    depth * 0.05
    );
  draw_window(
    x + width * 0.20, y, z + depth * 0.5, width * 0.5, height * 0.4, depth * 0.05
    );

  //back
  draw_walls(
    x, y, z - depth * 0.5, width * 0.25, height, 800.0
  );

  draw_walls(
    x + width * 0.3, y, z - depth * 0.5, width * 0.25, height, 800.0
  );

  draw_walls(
    x - width * 0.3, y, z - depth * 0.5, width * 0.25, height, 800.0
  );

  glPushMatrix();
  glColor3fv( white );

  glTranslatef( x, y + height * 0.55, z );
  glScalef( width * 0.1, height * 0.09, depth * 0.1 );
  glRotatef( 90.0, 1, 0, 0 );

  GLUquadricObj *focus = gluNewQuadric();
  gluQuadricDrawStyle( focus, GLU_FILL );
  gluCylinder( focus, 1.0, 1.0, 1.0, 5, 5 );
  glPopMatrix();

  glPushMatrix();
  glColor3f( 0.0, 0.0, 0.0 );

  glTranslatef( x, y + height * 0.55, z );
  glScalef( width * 0.112, height * 0.091, depth * 0.112 );
  glRotatef( 90.0, 1, 0, 0 );

  gluQuadricDrawStyle( focus, GLU_FILL );
  gluCylinder( focus, 1.0, 1.0, 1.0, 5, 5 );
  glPopMatrix();
}

void draw_walls(
  GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth
  )
{
  glPushMatrix();
  glColor3fv( blue );

  glTranslatef( x, y, z );
  glScalef( width, height, depth );
  glutSolidCube( 1.0 );
  glPopMatrix();
}

void draw_door(
  GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth
  )
{
  glPushMatrix();
  glColor3f( 0.0, 0.0, 0.0 );

  glTranslatef( x, y, z );
  glScalef( width, height, depth );
  glutSolidCube( 1.0 );
  glPopMatrix();

}

void draw_window(
  GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth
  )
{
  glPushMatrix();
  glColor3fv( white_blue );

  glTranslatef( x, y, z );
  glScalef( width, height, depth );
  glutSolidCube( 1.0 );
  glPopMatrix();
}

void drawLimb( float x, float y, float z, float angle, char axis, int base, int height ) {
    glColor3f( 1.0f, 0.0f, 0.0f );
    glPushMatrix( );

    glTranslatef( x, y, z );

    if( axis == 'x' ) {
        glRotatef( angle, 1.0f, 0.0f, 0.0f );
    }
    else if( axis == 'y' ) {
        glRotatef( angle, 0.0f, 1.0f, 0.0f );
    }
    else if( axis == 'z' ) {
        glRotatef( angle, 0.0f, 0.0f, 1.0f );
    }

    glRotatef( 90.0, 0.0, 1.0, 0.0 );


    glutWireCone( base, height/3, 20, 20 );

    glRotatef( 180.0, 0.0f, 1.0f, 0.0f );

    glutWireCone( base, 2*(height/3), 20, 20 );

    glPopMatrix( );
}

void drawSphere( float x, float y, float z, int radius ) {
    glColor3f( 1.0, 1.0, 0.0 );
    glPushMatrix( );

    glTranslatef( x, y, z );

    glutWireSphere( radius, 10, 10 );

    glPopMatrix( );
}

void draw_subject( float x, float y, float z ) {
    drawLimb( 0.0 + x, 500.0 + y, 0.0 + z, 90.0, 'z', 250, 750 );
    drawSphere( 0.0 + x, 0.0 + y, 0.0 + z, 50 );

    drawLimb( -288.0 + x, -167.0 + y, 0.0 + z, 30.0, 'z', 100, 1000 );
    drawSphere( -866.0 + x, -500.0 + y, 0.0 + z, 50 );
    drawLimb( -866.0 + x, -750.0 + y, 0.0 + z, 90.0, 'z', 100, 750 );
    drawSphere( -866.0 + x, -1250.0 + y, 0.0 + z, 50 );

    drawLimb( 288.0 + x, -167.0 + y, 0.0 + z, 150.0, 'z', 100, 1000 );
    drawSphere( 866.0 + x, -500.0 + y, 0.0 + z, 50 );
    drawLimb( 866.0 + x, -750.0 + y, 0.0 + z, 90.0, 'z', 100, 750 );
    drawSphere( 866 + x, -1250.0 + y, 0.0 + z, 50 );

    drawLimb( 0.0 + x, -500.0 + y, 0.0 + z, 90.0, 'z', 300, 1500 );
    drawSphere( 0.0 + x, -1500.0 + y, 0.0 + z, 50 );

    drawLimb( -239.0 + x, -1842.0 + y, 0.0 + z, 55.0, 'z', 175, 1250 );
    drawSphere( -717.0 + x, -2524.0 + y, 0.0 + z, 50 );
    drawLimb( -717.0 + x, -2857.0 + y, 0.0 + z, 90.0, 'z', 125, 1000 );
    drawSphere( -717.0 + x, -3524.0 + y, 0.0 + z, 50 );
    drawLimb( -717.0 + x, -3524.0 + y, -133.0 + z, 270.0, 'y', 75, 400 );

    drawLimb( 239.0 + x, -1842.0 + y, 0.0, 125.0 + z, 'z', 175, 1250 );
    drawSphere( 717.0 + x, -2524.0 + y, 0.0 + z, 50 );
    drawLimb( 717.0 + x, -2857.0 + y, 0.0 + z, 90.0, 'z', 125, 1000 );
    drawSphere( 717.0 + x, -3524.0 + y, 0.0 + z, 50 );
    drawLimb( 717.0 + x, -3524.0 + y, -133.0 + z, 270.0, 'y', 75, 400 );
}

void drawMarkers( int actualIt ) {
    if( actualIt < vertices.size( ) ) {
        for( int i = 0; i < vertices.size( ); i++ ) {
            drawSphere( vertices[ i ][ actualIt ][ 0 ], vertices[ i ][ actualIt ][ 1 ], vertices[ i ][ actualIt ][ 2 ], 50 );
        }
    }
}

void loadFile( ) {
    std::string line;
    std::ifstream file( "../markers.in" );

    if( file.is_open( ) ) {
        std::vector< std::vector < GLfloat > > vertics;
        while( getline( file, line ) ) {
            if( line != "SACR" && line != "LASI" && line != "LTHI" && line != "LKNE" && line != "LTIB" && line != "LANK" && line != "LTOE" && line != "RASI" && line != "RTHI" && line != "RKNE" && line != "RTIB" && line != "RANK" && line != "RTOE" ) {
                std::stringstream ss( line );
                std::string item;
                float vert1, vert2, vert3;
                std::vector< GLfloat > verts;

                getline( ss, item, ' ' );
                vert1 = std::stof( item );
                getline( ss, item, ' ' );
                vert2 = std::stof( item );
                getline( ss, item, ' ' );
                vert3 = std::stof( item );

                verts.push_back( vert1 );
                verts.push_back( vert2 );
                verts.push_back( vert3 );

                vertics.push_back( verts );
            }
            else if( vertics.size( ) == 0 ) {
                vertices.push_back( vertics );
                vertics.clear( );
            }
        }
        file.close( );
      }
      else {
        std::cout << "error con el archivo markers.in" << std::endl;
    }
}
