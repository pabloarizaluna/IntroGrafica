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

void drawSphere( float x, float y, float z, int radius ) {
    glColor3f( 1.0, 0.0, 1.0 );
    glPushMatrix( );

    glTranslatef( x, y, z );

    glutWireSphere( radius, 20, 20 );

    glPopMatrix( );
}

void drawConnectors( int actualIt ) {
    if( actualIt < vertices[ 0 ].size( ) ) {
        renderCylinderDirector( vertices[ 0 ][ actualIt ][ 0 ], vertices[ 0 ][ actualIt ][ 1 ], vertices[ 0 ][ actualIt ][ 2 ], vertices[ 1 ][ actualIt ][ 0 ], vertices[ 1 ][ actualIt ][ 1 ], vertices[ 1 ][ actualIt ][ 2 ], 15, 30 );
        renderCylinderDirector( vertices[ 1 ][ actualIt ][ 0 ], vertices[ 1 ][ actualIt ][ 1 ], vertices[ 1 ][ actualIt ][ 2 ], vertices[ 2 ][ actualIt ][ 0 ], vertices[ 2 ][ actualIt ][ 1 ], vertices[ 2 ][ actualIt ][ 2 ], 15, 30 );
        renderCylinderDirector( vertices[ 2 ][ actualIt ][ 0 ], vertices[ 2 ][ actualIt ][ 1 ], vertices[ 2 ][ actualIt ][ 2 ], vertices[ 3 ][ actualIt ][ 0 ], vertices[ 3 ][ actualIt ][ 1 ], vertices[ 3 ][ actualIt ][ 2 ], 15, 30 );
        renderCylinderDirector( vertices[ 3 ][ actualIt ][ 0 ], vertices[ 3 ][ actualIt ][ 1 ], vertices[ 3 ][ actualIt ][ 2 ], vertices[ 4 ][ actualIt ][ 0 ], vertices[ 4 ][ actualIt ][ 1 ], vertices[ 4 ][ actualIt ][ 2 ], 15, 30 );
        renderCylinderDirector( vertices[ 4 ][ actualIt ][ 0 ], vertices[ 4 ][ actualIt ][ 1 ], vertices[ 4 ][ actualIt ][ 2 ], vertices[ 5 ][ actualIt ][ 0 ], vertices[ 5 ][ actualIt ][ 1 ], vertices[ 5 ][ actualIt ][ 2 ], 15, 30 );
        renderCylinderDirector( vertices[ 5 ][ actualIt ][ 0 ], vertices[ 5 ][ actualIt ][ 1 ], vertices[ 5 ][ actualIt ][ 2 ], vertices[ 6 ][ actualIt ][ 0 ], vertices[ 6 ][ actualIt ][ 1 ], vertices[ 6 ][ actualIt ][ 2 ], 15, 30 );

        renderCylinderDirector( vertices[ 0 ][ actualIt ][ 0 ], vertices[ 0 ][ actualIt ][ 1 ], vertices[ 0 ][ actualIt ][ 2 ], vertices[ 7 ][ actualIt ][ 0 ], vertices[ 7 ][ actualIt ][ 1 ], vertices[ 7 ][ actualIt ][ 2 ], 15, 30 );
        renderCylinderDirector( vertices[ 7 ][ actualIt ][ 0 ], vertices[ 7 ][ actualIt ][ 1 ], vertices[ 7 ][ actualIt ][ 2 ], vertices[ 8 ][ actualIt ][ 0 ], vertices[ 8 ][ actualIt ][ 1 ], vertices[ 8 ][ actualIt ][ 2 ], 15, 30 );
        renderCylinderDirector( vertices[ 8 ][ actualIt ][ 0 ], vertices[ 8 ][ actualIt ][ 1 ], vertices[ 8 ][ actualIt ][ 2 ], vertices[ 9 ][ actualIt ][ 0 ], vertices[ 9 ][ actualIt ][ 1 ], vertices[ 9 ][ actualIt ][ 2 ], 15, 30 );
        renderCylinderDirector( vertices[ 9 ][ actualIt ][ 0 ], vertices[ 9 ][ actualIt ][ 1 ], vertices[ 9 ][ actualIt ][ 2 ], vertices[ 10 ][ actualIt ][ 0 ], vertices[ 10 ][ actualIt ][ 1 ], vertices[ 10 ][ actualIt ][ 2 ], 15, 30 );
        renderCylinderDirector( vertices[ 10 ][ actualIt ][ 0 ], vertices[ 10 ][ actualIt ][ 1 ], vertices[ 10 ][ actualIt ][ 2 ], vertices[ 11 ][ actualIt ][ 0 ], vertices[ 11 ][ actualIt ][ 1 ], vertices[ 11 ][ actualIt ][ 2 ], 15, 30 );
        renderCylinderDirector( vertices[ 11 ][ actualIt ][ 0 ], vertices[ 11 ][ actualIt ][ 1 ], vertices[ 11 ][ actualIt ][ 2 ], vertices[ 12 ][ actualIt ][ 0 ], vertices[ 12 ][ actualIt ][ 1 ], vertices[ 12 ][ actualIt ][ 2 ], 15, 30 );
    }
}

void renderCylinder(float x1, float y1, float z1, float x2,float y2, float z2,
  float radius,int subdivisions,GLUquadricObj *quadric
  )
{
  float vx = x2-x1;
  float vy = y2-y1;
  float vz = z2-z1;
  float v = sqrt( vx*vx + vy*vy + vz*vz );
  float ax;

  if (fabs(vz) < 1.0e-3) {
    ax = 57.2957795*acos( vx/v ); // rotation angle in x-y plane
    if ( vy <= 0.0 )
      ax = -ax;
  }
  else {
    ax = 57.2957795*acos( vz/v ); // rotation angle
    if ( vz <= 0.0 )
      ax = -ax;
  }

  float rx = -vy*vz;
  float ry = vx*vz;

  glPushMatrix();
  //draw the cylinder body
  glTranslatef( x1,y1,z1 );
  if (fabs(vz) < 1.0e-3) {
    glRotated(90.0, 0, 1, 0.0); // Rotate & align with x axis
    glRotated(ax, -1.0, 0.0, 0.0); // Rotate to point 2 in x-y plane
  }
  else {
    glRotated(ax, rx, ry, 0.0); // Rotate about rotation vector
  }
  gluQuadricOrientation(quadric,GLU_OUTSIDE);
  gluCylinder(quadric, radius, radius, v, subdivisions, 1);

  //draw the first cap
  gluQuadricOrientation(quadric,GLU_INSIDE);
  gluDisk( quadric, 0.0, radius, subdivisions, 1);
  glTranslatef( 0,0,v );

  //draw the second cap
  gluQuadricOrientation(quadric,GLU_OUTSIDE);
  gluDisk( quadric, 0.0, radius, subdivisions, 1);
  glPopMatrix();
}

void renderCylinderDirector(float x1, float y1, float z1, float x2,float y2,
  float z2, float radius,int subdivisions
  )
{
    glColor3f( 1.0, 0.0, 0.0 );
  GLUquadricObj *quadric=gluNewQuadric();
  gluQuadricNormals(quadric, GLU_SMOOTH);
  renderCylinder(x1,y1,z1,x2,y2,z2,radius,subdivisions,quadric);
}

void drawMarkers( int actualIt ) {
    if( actualIt < vertices[ 0 ].size( ) ) {
        for( int i = 0; i < vertices.size( ); i++ ) {
            drawSphere( vertices[ i ][ actualIt ][ 0 ], vertices[ i ][ actualIt ][ 1 ], vertices[ i ][ actualIt ][ 2 ], 20 );
        }
    }
}

void loadFile( char* filename ) {
    std::string line;
    std::ifstream file( filename );

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
            else if( vertics.size( ) != 0 ) {
                vertices.push_back( vertics );
                vertics.clear( );
            }
        }
        vertices.push_back( vertics );
        file.close( );
      }
      else {
        std::cout << "error con el archivo de entrada" << std::endl;
    }
}
