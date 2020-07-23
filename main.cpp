#include<windows.h>
#include<gl/glut.h>
#include<math.h>

const double PI = 3.141592653589793;
int titik;
void init(void);
void tampil(void);
void keyboard(unsigned char,int,int);
void mouse(int button, int state, int x, int y);
void ukuran(int,int);
void mousemotion(int x, int y);
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown =false;
int is_depth;
GLUquadricObj *qobj;
#define deltat .001

void init(void)
{
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(6.0);
    //MENGATUR ARRAY TITIK
    glEnableClientState(GL_VERTEX_ARRAY);

    //mengatur array WARNA
    glEnableClientState(GL_COLOR_ARRAY);
    glShadeModel(GL_SMOOTH);
}

void ukuran(int lebar, int tinggi)
{
    glViewport(0,0,lebar,tinggi);
    if(tinggi==0) tinggi=1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50,lebar/tinggi,5,500);
    glTranslatef(0,0,-200);
    glMatrixMode(GL_MODELVIEW);
}

void lingkaran(int nilai_radius, int total, int koordinatX, int koordinatY, int sumbuZ)
{
     glBegin(GL_POLYGON);
     for (titik=0; titik<=360; titik++)
     {
        float angle=titik*(2*PI/total);
        float nilai_x=koordinatX+nilai_radius*cos(angle);
        float nilai_y=koordinatY+nilai_radius*sin(angle);
        glVertex3f(nilai_x, nilai_y,sumbuZ);
     }
     glEnd();
}

void lingkaran2(int nilai_radius, int total, int koordinatX, int koordinatY, int sumbuZ)
{
     glLineWidth(4.0);
     glBegin(GL_LINE_LOOP);
     for (titik=0; titik<=100; titik++)
     {
        float angle=titik*(2*PI/total);
        float nilai_x=koordinatX+nilai_radius*cos(angle);
        float nilai_y=koordinatY+nilai_radius*sin(angle);
        glVertex3f(nilai_x, nilai_y,sumbuZ);
     }
     glEnd();
}

void tiang()
{
    glVertex3f(30,30,30);
    qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluCylinder(qobj, 1, 1, 50, 20, 30);
}

void lampu (void)
{
    //lampu kiri depan
    //depan
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(-53,7.9,28);
    glVertex3f(-45,7.9,30);
    glVertex3f(-45,24.9,29);
    glVertex3f(-53,24.9,27);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(-54,7.9,30);
    glVertex3f(-46,7.9,32);
    glVertex3f(-46,24.9,31);
    glVertex3f(-54,24.9,29);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(-45,7.9,30);
    glVertex3f(-46,7.9,32);
    glVertex3f(-46,24.9,31);
    glVertex3f(-45,24.9,29);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(-54,7.9,30);
    glVertex3f(-53,7.9,28);
    glVertex3f(-53,24.9,27);
    glVertex3f(-54,24.9,29);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(-54,24.9,29);
    glVertex3f(-53,24.9,27);
    glVertex3f(-45,24.9,29);
    glVertex3f(-46,24.9,31);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(-54,7.9,30);
    glVertex3f(-53,7.9,28);
    glVertex3f(-45,7.9,30);
    glVertex3f(-46,7.9,32);
    glEnd();

    //lampu kanan depan
    //depam
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(53,7.9,28);
    glVertex3f(45,7.9,30);
    glVertex3f(45,24.9,29);
    glVertex3f(53,24.9,27);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(54,7.9,30);
    glVertex3f(46,7.9,32);
    glVertex3f(46,24.9,31);
    glVertex3f(54,24.9,29);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(45,7.9,30);
    glVertex3f(46,7.9,32);
    glVertex3f(46,24.9,31);
    glVertex3f(45,24.9,29);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(54,7.9,30);
    glVertex3f(53,7.9,28);
    glVertex3f(53,24.9,27);
    glVertex3f(54,24.9,29);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(54,24.9,29);
    glVertex3f(53,24.9,27);
    glVertex3f(45,24.9,29);
    glVertex3f(46,24.9,31);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(54,7.9,30);
    glVertex3f(53,7.9,28);
    glVertex3f(45,7.9,30);
    glVertex3f(46,7.9,32);
    glEnd();

    //lampu kiri belakang
    //depam
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(-53,7.9,-58);
    glVertex3f(-45,7.9,-60);
    glVertex3f(-45,24.9,-59);
    glVertex3f(-53,24.9,-57);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(-54,7.9,-60);
    glVertex3f(-46,7.9,-62);
    glVertex3f(-46,24.9,-61);
    glVertex3f(-54,24.9,-59);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(-45,7.9,-60);
    glVertex3f(-46,7.9,-62);
    glVertex3f(-46,24.9,-61);
    glVertex3f(-45,24.9,-59);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(-54,7.9,-60);
    glVertex3f(-53,7.9,-58);
    glVertex3f(-53,24.9,-57);
    glVertex3f(-54,24.9,-59);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(-54,24.9,-59);
    glVertex3f(-53,24.9,-57);
    glVertex3f(-45,24.9,-59);
    glVertex3f(-46,24.9,-61);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(-54,7.9,-60);
    glVertex3f(-53,7.9,-58);
    glVertex3f(-45,7.9,-60);
    glVertex3f(-46,7.9,-62);
    glEnd();

    //lampu kanan belakang
    //depam
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(53,7.9,-58);
    glVertex3f(45,7.9,-60);
    glVertex3f(45,24.9,-59);
    glVertex3f(53,24.9,-57);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(54,7.9,-60);
    glVertex3f(46,7.9,-62);
    glVertex3f(46,24.9,-61);
    glVertex3f(54,24.9,-59);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(45,7.9,-60);
    glVertex3f(46,7.9,-62);
    glVertex3f(46,24.9,-61);
    glVertex3f(45,24.9,-59);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(54,7.9,-60);
    glVertex3f(53,7.9,-58);
    glVertex3f(53,24.9,-57);
    glVertex3f(54,24.9,-59);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(54,24.9,-59);
    glVertex3f(53,24.9,-57);
    glVertex3f(45,24.9,-59);
    glVertex3f(46,24.9,-61);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(54,7.9,-60);
    glVertex3f(53,7.9,-58);
    glVertex3f(45,7.9,-60);
    glVertex3f(46,7.9,-62);
    glEnd();
}

void lapangan(void)
{
    //LAPANGAN
    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    glVertex3f(-50,-39.8,12.5);
    glVertex3f(-50,-39.8,-45.5);
    glVertex3f(50,-39.8,-45.5);
    glVertex3f(50,-39.8,12.5);
    glEnd();
    //Garis Lapangan
    //Kanan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(40,-38,10.5);
    glVertex3f(40,-38,-37.5);
    glVertex3f(42,-38,-37.5);
    glVertex3f(42,-38,10.5);
    glEnd();
    //Depan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-38.7,10.5);
    glVertex3f(-40,-38.7,8.5);
    glVertex3f(40,-38.7,8.5);
    glVertex3f(40,-38.7,10.5);
    glEnd();
    //Kiri
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-38.7,10.5);
    glVertex3f(-40,-38.7,-37.5);
    glVertex3f(-42,-38.7,-37.5);
    glVertex3f(-42,-38.7,10.5);
    glEnd();
    //Belakang
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-38.7,-37.5);
    glVertex3f(-40,-38.7,-35.5);
    glVertex3f(40,-38.7,-35.5);
    glVertex3f(40,-38.7,-37.5);
    glEnd();
    //Tengah
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0,-38.7,10.5);
    glVertex3f(0,-38.7,-37.5);
    glVertex3f(2,-38.7,-37.5);
    glVertex3f(2,-38.7,10.5);
    glEnd();
    //Tengah 2
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0,-37.7,-11);
    glVertex3f(0,-37.7,-3);
    glVertex3f(2,-37.7,-3);
    glVertex3f(2,-37.7,-11);
    glEnd();
    //Tengah 3
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0,-37.7,-21);
    glVertex3f(0,-37.7,-11);
    glVertex3f(2,-37.7,-11);
    glVertex3f(2,-37.7,-21);
    glEnd();
    //Area Pinalti
    //Kiri 2
    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    glVertex3f(-40,-36.8,2.5);
    glVertex3f(-40,-36.8,-30.5);
    glVertex3f(-25,-36.8,-30.5);
    glVertex3f(-25,-36.8,2.5);
    glEnd();
    //Kotak Besar Kiri
    //Kanan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-25,-36.7,0.5);
    glVertex3f(-25,-36.7,-27.5);
    glVertex3f(-27,-36.7,-27.5);
    glVertex3f(-27,-36.7,0.5);
    glEnd();
    //Belakang
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-36.7,-27.5);
    glVertex3f(-40,-36.7,-25.5);
    glVertex3f(-27,-36.7,-25.5);
    glVertex3f(-27,-36.7,-27.5);
    glEnd();
    //Depan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-36.7,0.5);
    glVertex3f(-40,-36.7,-1.5);
    glVertex3f(-27,-36.7,-1.5);
    glVertex3f(-27,-36.7,0.5);
    glEnd();
    //Kotak Kecil Kiri
    //Kanan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-33,-36.7,-5.5);
    glVertex3f(-33,-36.7,-20.5);
    glVertex3f(-35,-36.7,-20.5);
    glVertex3f(-35,-36.7,-5.5);
    glEnd();
    //Belakang
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-36.7,-20.5);
    glVertex3f(-40,-36.7,-18.5);
    glVertex3f(-35,-36.7,-18.5);
    glVertex3f(-35,-36.7,-20.5);
    glEnd();
    //Depan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-36.7,-5.5);
    glVertex3f(-40,-36.7,-7.5);
    glVertex3f(-35,-36.7,-7.5);
    glVertex3f(-35,-36.7,-5.5);
    glEnd();
    //Area Pinalti
    //Kanan 2
    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    glVertex3f(40,-36.8,4.5);
    glVertex3f(40,-36.8,-30.5);
    glVertex3f(25,-36.8,-30.5);
    glVertex3f(25,-36.8,4.5);
    glEnd();
    //Kotak Besar Kanan
    //Kiri
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(25,-36.7,0.5);
    glVertex3f(25,-36.7,-27.5);
    glVertex3f(27,-36.7,-27.5);
    glVertex3f(27,-36.7,0.5);
    glEnd();
    //Belakang
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(40,-36.7,-27.5);
    glVertex3f(40,-36.7,-25.5);
    glVertex3f(27,-36.7,-25.5);
    glVertex3f(27,-36.7,-27.5);
    glEnd();
    //Depan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(40,-36.7,0.5);
    glVertex3f(40,-36.7,-1.5);
    glVertex3f(27,-36.7,-1.5);
    glVertex3f(27,-36.7,0.5);
    glEnd();
    //Kotak Kecil Kanan
    //Kiri
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(33,-36.7,-5.5);
    glVertex3f(33,-36.7,-20.5);
    glVertex3f(35,-36.7,-20.5);
    glVertex3f(35,-36.7,-5.5);
    glEnd();
    //Belakang
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(40,-36.7,-20.5);
    glVertex3f(40,-36.7,-18.5);
    glVertex3f(35,-36.7,-18.5);
    glVertex3f(35,-36.7,-20.5);
    glEnd();
    //Depan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(40,-36.7,-5.5);
    glVertex3f(40,-36.7,-7.5);
    glVertex3f(35,-36.7,-7.5);
    glVertex3f(35,-36.7,-5.5);
    glEnd();
    //Lingkaran Tengah
    glColor3f(1,1,1);
    glPushMatrix();
    glRotatef(90,45, 0, 0);
    lingkaran(10,50,1.5,-13.5,39.4);
    //Lingkaran Kecil Pinalti Kiri
    lingkaran(2,10,-30,-13.5,36.9);
    //Lingkaran Setengah Kiri
    lingkaran(8,40,-25,-13.5,38.9);
    //Lingkaran Setengah Kiri 2
    glColor3f(0,1,0);
    lingkaran(6,30,-25,-13.5,37.9);
    //Lingkaran Kecil Pinalti Kanan
    glColor3f(1,1,1);
    lingkaran(2,10,30,-13.5,36.9);
    //Lingkaran Setengah Kiri
    lingkaran(8,40,25,-13.5,38.9);
    //Lingkaran Setengah Kiri 2
    glColor3f(0,1,0);
    lingkaran(6,30,25,-13.5,37.9);
    //Lingkaran Tengah 2
    glColor3f(0,1,0);
    lingkaran(8,40,1.5,-13.5,38.9);
    //Lingkaran Tengah 3
    glColor3f(1,1,1);
    lingkaran(2,10,1.5,-13.5,37.9);
    //Lingkaran Corner Kiri Belakang
    glColor3f(1,1,1);
    lingkaran(3,15,-39,-34.5,38.9);
    //Lingkaran Corner Kiri Belakang 2
    glColor3f(0,1,0);
    lingkaran(2,10,-39,-34.5,37.9);
    //Lingkaran Corner Kanan Belakang
    glColor3f(1,1,1);
    lingkaran(3,15,39,-34.5,38.9);
    //Lingkaran Corner Kanan Belakang 2
    glColor3f(0,1,0);
    lingkaran(2,10,39,-34.5,37.9);
    //Lingkaran Corner Kiri Depan
    glColor3f(1,1,1);
    lingkaran(3,15,-39,7.5,38.9);
    //Lingkaran Corner Kiri Depan 2
    glColor3f(0,1,0);
    lingkaran(2,10,-39,7.5,37.9);
    //Lingkaran Corner Kanan Depan
    glColor3f(1,1,1);
    lingkaran(3,15,39,7.5,38.9);
    //Lingkaran Corner Kanan Depan 2
    glColor3f(0,1,0);
    lingkaran(2,10,39,7.5,37.9);


    glPopMatrix();
}

void bendera_corner_kiri_belakang()
{
    //TIANG
    //Belakang
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(-42,-36.7,-37.5);
    glVertex3f(-40,-36.7,-37.5);
    glVertex3f(-40,-26.7,-37.5);
    glVertex3f(-42,-26.7,-37.5);
    glEnd();
    //Depan
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(-42,-36.7,-35.5);
    glVertex3f(-40,-36.7,-35.5);
    glVertex3f(-40,-26.7,-35.5);
    glVertex3f(-42,-26.7,-35.5);
    glEnd();
    //Kiri
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(-42,-36.7,-35.5);
    glVertex3f(-42,-36.7,-37.5);
    glVertex3f(-42,-26.7,-37.5);
    glVertex3f(-42,-26.7,-35.5);
    glEnd();
    //Bawah
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(-42,-36.6,-35.5);
    glVertex3f(-42,-36.6,-37.5);
    glVertex3f(-40,-36.6,-37.5);
    glVertex3f(-40,-36.6,-35.5);
    glEnd();
    //Kanan
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(-40,-36.7,-35.5);
    glVertex3f(-40,-36.7,-37.5);
    glVertex3f(-40,-26.7,-37.5);
    glVertex3f(-40,-26.7,-35.5);
    glEnd();
    //Atas
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(-42,-26.7,-35.5);
    glVertex3f(-42,-26.7,-37.5);
    glVertex3f(-40,-26.7,-37.5);
    glVertex3f(-40,-26.7,-35.5);
    glEnd();

    //BENDERA
    //Belakang Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(-38,-30.7,-37.5);
    glVertex3f(-36,-30.7,-37.5);
    glVertex3f(-36,-28.7,-37.5);
    glVertex3f(-38,-28.7,-37.5);
    glEnd();
    //Belakang Kuning 2
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(-40,-28.7,-37.5);
    glVertex3f(-38,-28.7,-37.5);
    glVertex3f(-38,-26.7,-37.5);
    glVertex3f(-40,-26.7,-37.5);
    glEnd();
    //Belakang Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(-40,-30.7,-37.5);
    glVertex3f(-38,-30.7,-37.5);
    glVertex3f(-38,-28.7,-37.5);
    glVertex3f(-40,-28.7,-37.5);
    glEnd();
    //Belakang Orange 2
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(-38,-28.7,-37.5);
    glVertex3f(-36,-28.7,-37.5);
    glVertex3f(-36,-26.7,-37.5);
    glVertex3f(-38,-26.7,-37.5);
    glEnd();
    //Bawah Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(-40,-30.7,-35.5);
    glVertex3f(-40,-30.7,-37.5);
    glVertex3f(-38,-30.7,-37.5);
    glVertex3f(-38,-30.7,-35.5);
    glEnd();
    //Bawah Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(-38,-30.7,-35.5);
    glVertex3f(-38,-30.7,-37.5);
    glVertex3f(-36,-30.7,-37.5);
    glVertex3f(-36,-30.7,-35.5);
    glEnd();
    //Atas Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(-40,-26.7,-35.5);
    glVertex3f(-40,-26.7,-37.5);
    glVertex3f(-38,-26.7,-37.5);
    glVertex3f(-38,-26.7,-35.5);
    glEnd();
    //Atas Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(-38,-26.7,-35.5);
    glVertex3f(-38,-26.7,-37.5);
    glVertex3f(-36,-26.7,-37.5);
    glVertex3f(-36,-26.7,-35.5);
    glEnd();
    //DEPAN
    //Depan Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(-38,-30.7,-35.5);
    glVertex3f(-36,-30.7,-35.5);
    glVertex3f(-36,-28.7,-35.5);
    glVertex3f(-38,-28.7,-35.5);
    glEnd();
    //Depan Kuning 2
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(-40,-28.7,-35.5);
    glVertex3f(-38,-28.7,-35.5);
    glVertex3f(-38,-26.7,-35.5);
    glVertex3f(-40,-26.7,-35.5);
    glEnd();
    //Depan Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(-40,-30.7,-35.5);
    glVertex3f(-38,-30.7,-35.5);
    glVertex3f(-38,-28.7,-35.5);
    glVertex3f(-40,-28.7,-35.5);
    glEnd();
    //Depan Orange 2
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(-38,-28.7,-35.5);
    glVertex3f(-36,-28.7,-35.5);
    glVertex3f(-36,-26.7,-35.5);
    glVertex3f(-38,-26.7,-35.5);
    glEnd();
    //Kanan Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(-38,-28.7,-37.5);
    glVertex3f(-36,-28.7,-35.5);
    glVertex3f(-36,-26.7,-35.5);
    glVertex3f(-38,-26.7,-37.5);
    glEnd();
    //Kanan Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(-40,-30.7,-37.5);
    glVertex3f(-38,-30.7,-35.5);
    glVertex3f(-38,-28.7,-35.5);
    glVertex3f(-40,-28.7,-37.5);
    glEnd();
}

void bendera_corner_kanan_belakang()
{
    //TIANG
    //Belakang
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(42,-36.7,-37.5);
    glVertex3f(40,-36.7,-37.5);
    glVertex3f(40,-26.7,-37.5);
    glVertex3f(42,-26.7,-37.5);
    glEnd();
    //Depan
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(42,-36.7,-35.5);
    glVertex3f(40,-36.7,-35.5);
    glVertex3f(40,-26.7,-35.5);
    glVertex3f(42,-26.7,-35.5);
    glEnd();
    //Kanan
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(42,-36.7,-35.5);
    glVertex3f(42,-36.7,-37.5);
    glVertex3f(42,-26.7,-37.5);
    glVertex3f(42,-26.7,-35.5);
    glEnd();
    //Bawah
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(42,-36.6,-35.5);
    glVertex3f(42,-36.6,-37.5);
    glVertex3f(40,-36.6,-37.5);
    glVertex3f(40,-36.6,-35.5);
    glEnd();
    //Kiri
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(40,-36.7,-35.5);
    glVertex3f(40,-36.7,-37.5);
    glVertex3f(40,-26.7,-37.5);
    glVertex3f(40,-26.7,-35.5);
    glEnd();
    //Atas
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(42,-26.7,-35.5);
    glVertex3f(42,-26.7,-37.5);
    glVertex3f(40,-26.7,-37.5);
    glVertex3f(40,-26.7,-35.5);
    glEnd();

    //BENDERA
    //Belakang Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(38,-30.7,-37.5);
    glVertex3f(36,-30.7,-37.5);
    glVertex3f(36,-28.7,-37.5);
    glVertex3f(38,-28.7,-37.5);
    glEnd();
    //Belakang Kuning 2
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(40,-28.7,-37.5);
    glVertex3f(38,-28.7,-37.5);
    glVertex3f(38,-26.7,-37.5);
    glVertex3f(40,-26.7,-37.5);
    glEnd();
    //Belakang Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(40,-30.7,-37.5);
    glVertex3f(38,-30.7,-37.5);
    glVertex3f(38,-28.7,-37.5);
    glVertex3f(40,-28.7,-37.5);
    glEnd();
    //Belakang Orange 2
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(38,-28.7,-37.5);
    glVertex3f(36,-28.7,-37.5);
    glVertex3f(36,-26.7,-37.5);
    glVertex3f(38,-26.7,-37.5);
    glEnd();
    //Bawah Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(40,-30.7,-35.5);
    glVertex3f(40,-30.7,-37.5);
    glVertex3f(38,-30.7,-37.5);
    glVertex3f(38,-30.7,-35.5);
    glEnd();
    //Bawah Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(38,-30.7,-35.5);
    glVertex3f(38,-30.7,-37.5);
    glVertex3f(36,-30.7,-37.5);
    glVertex3f(36,-30.7,-35.5);
    glEnd();
    //Atas Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(40,-26.7,-35.5);
    glVertex3f(40,-26.7,-37.5);
    glVertex3f(38,-26.7,-37.5);
    glVertex3f(38,-26.7,-35.5);
    glEnd();
    //Atas Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(38,-26.7,-35.5);
    glVertex3f(38,-26.7,-37.5);
    glVertex3f(36,-26.7,-37.5);
    glVertex3f(36,-26.7,-35.5);
    glEnd();
    //DEPAN
    //Depan Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(38,-30.7,-35.5);
    glVertex3f(36,-30.7,-35.5);
    glVertex3f(36,-28.7,-35.5);
    glVertex3f(38,-28.7,-35.5);
    glEnd();
    //Depan Kuning 2
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(40,-28.7,-35.5);
    glVertex3f(38,-28.7,-35.5);
    glVertex3f(38,-26.7,-35.5);
    glVertex3f(40,-26.7,-35.5);
    glEnd();
    //Depan Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(40,-30.7,-35.5);
    glVertex3f(38,-30.7,-35.5);
    glVertex3f(38,-28.7,-35.5);
    glVertex3f(40,-28.7,-35.5);
    glEnd();
    //Depan Orange 2
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(38,-28.7,-35.5);
    glVertex3f(36,-28.7,-35.5);
    glVertex3f(36,-26.7,-35.5);
    glVertex3f(38,-26.7,-35.5);
    glEnd();
    //Kanan Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(38,-28.7,-37.5);
    glVertex3f(36,-28.7,-35.5);
    glVertex3f(36,-26.7,-35.5);
    glVertex3f(38,-26.7,-37.5);
    glEnd();
    //Kanan Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(40,-30.7,-37.5);
    glVertex3f(38,-30.7,-35.5);
    glVertex3f(38,-28.7,-35.5);
    glVertex3f(40,-28.7,-37.5);
    glEnd();
}

void bendera_corner_kiri_depan()
{
    //TIANG
    //Belakang
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(-42,-36.7,10.5);
    glVertex3f(-40,-36.7,10.5);
    glVertex3f(-40,-26.7,10.5);
    glVertex3f(-42,-26.7,10.5);
    glEnd();
    //Depan
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(-42,-36.7,8.5);
    glVertex3f(-40,-36.7,8.5);
    glVertex3f(-40,-26.7,8.5);
    glVertex3f(-42,-26.7,8.5);
    glEnd();
    //Kiri
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(-42,-36.7,8.5);
    glVertex3f(-42,-36.7,10.5);
    glVertex3f(-42,-26.7,10.5);
    glVertex3f(-42,-26.7,8.5);
    glEnd();
    //Bawah
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(-42,-36.6,8.5);
    glVertex3f(-42,-36.6,10.5);
    glVertex3f(-40,-36.6,10.5);
    glVertex3f(-40,-36.6,8.5);
    glEnd();
    //Kanan
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(-40,-36.7,8.5);
    glVertex3f(-40,-36.7,10.5);
    glVertex3f(-40,-26.7,10.5);
    glVertex3f(-40,-26.7,8.5);
    glEnd();
    //Atas
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(-42,-26.7,8.5);
    glVertex3f(-42,-26.7,10.5);
    glVertex3f(-40,-26.7,10.5);
    glVertex3f(-40,-26.7,8.5);
    glEnd();

    //BENDERA
    //Belakang Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(-38,-30.7,10.5);
    glVertex3f(-36,-30.7,10.5);
    glVertex3f(-36,-28.7,10.5);
    glVertex3f(-38,-28.7,10.5);
    glEnd();
    //Belakang Kuning 2
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(-40,-28.7,10.5);
    glVertex3f(-38,-28.7,10.5);
    glVertex3f(-38,-26.7,10.5);
    glVertex3f(-40,-26.7,10.5);
    glEnd();
    //Belakang Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(-40,-30.7,10.5);
    glVertex3f(-38,-30.7,10.5);
    glVertex3f(-38,-28.7,10.5);
    glVertex3f(-40,-28.7,10.5);
    glEnd();
    //Belakang Orange 2
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(-38,-28.7,10.5);
    glVertex3f(-36,-26.7,10.5);
    glVertex3f(-36,-26.7,10.5);
    glVertex3f(-38,-26.7,10.5);
    glEnd();
    //Bawah Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(-40,-30.7,8.5);
    glVertex3f(-40,-30.7,10.5);
    glVertex3f(-38,-30.7,10.5);
    glVertex3f(-38,-30.7,8.5);
    glEnd();
    //Bawah Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(-38,-30.7,8.5);
    glVertex3f(-38,-30.7,10.5);
    glVertex3f(-36,-30.7,10.5);
    glVertex3f(-36,-30.7,8.5);
    glEnd();
    //Atas Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(-40,-26.7,8.5);
    glVertex3f(-40,-26.7,10.5);
    glVertex3f(-38,-26.7,10.5);
    glVertex3f(-38,-26.7,8.5);
    glEnd();
    //Atas Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(-38,-26.7,8.5);
    glVertex3f(-38,-26.7,10.5);
    glVertex3f(-36,-26.7,10.5);
    glVertex3f(-36,-26.7,8.5);
    glEnd();
    //DEPAN
    //Depan Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(-38,-30.7,8.5);
    glVertex3f(-36,-30.7,8.5);
    glVertex3f(-36,-28.7,8.5);
    glVertex3f(-38,-28.7,8.5);
    glEnd();
    //Depan Kuning 2
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(-40,-28.7,8.5);
    glVertex3f(-38,-28.7,8.5);
    glVertex3f(-38,-26.7,8.5);
    glVertex3f(-40,-26.7,8.5);
    glEnd();
    //Depan Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(-40,-30.7,8.5);
    glVertex3f(-38,-30.7,8.5);
    glVertex3f(-38,-28.7,8.5);
    glVertex3f(-40,-28.7,8.5);
    glEnd();
    //Depan Orange 2
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(-38,-28.7,8.5);
    glVertex3f(-36,-28.7,8.5);
    glVertex3f(-36,-26.7,8.5);
    glVertex3f(-38,-26.7,8.5);
    glEnd();
    //Kanan Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(-38,-28.7,10.5);
    glVertex3f(-36,-28.7,8.5);
    glVertex3f(-36,-26.7,8.5);
    glVertex3f(-38,-26.7,10.5);
    glEnd();
    //Kanan Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(-40,-30.7,10.5);
    glVertex3f(-38,-30.7,8.5);
    glVertex3f(-38,-28.7,8.5);
    glVertex3f(-40,-28.7,10.5);
    glEnd();
}

void bendera_corner_kanan_depan()
{
    //TIANG
    //Belakang
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(42,-36.7,10.5);
    glVertex3f(40,-36.7,10.5);
    glVertex3f(40,-26.7,10.5);
    glVertex3f(42,-26.7,10.5);
    glEnd();
    //Depan
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(42,-36.7,8.5);
    glVertex3f(40,-36.7,8.5);
    glVertex3f(40,-26.7,8.5);
    glVertex3f(42,-26.7,8.5);
    glEnd();
    //Kanan
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(42,-36.7,8.5);
    glVertex3f(42,-36.7,10.5);
    glVertex3f(42,-26.7,10.5);
    glVertex3f(42,-26.7,8.5);
    glEnd();
    //Bawah
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(42,-36.6,8.5);
    glVertex3f(42,-36.6,10.5);
    glVertex3f(40,-36.6,10.5);
    glVertex3f(40,-36.6,8.5);
    glEnd();
    //Kiri
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(40,-36.7,8.5);
    glVertex3f(40,-36.7,10.5);
    glVertex3f(40,-26.7,10.5);
    glVertex3f(40,-26.7,8.5);
    glEnd();
    //Atas
    glBegin(GL_POLYGON);
    glColor3ub(255, 94, 0);
    glVertex3f(42,-26.7,8.5);
    glVertex3f(42,-26.7,10.5);
    glVertex3f(40,-26.7,10.5);
    glVertex3f(40,-26.7,8.5);
    glEnd();

    //BENDERA
    //Belakang Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(38,-30.7,10.5);
    glVertex3f(36,-30.7,10.5);
    glVertex3f(36,-28.7,10.5);
    glVertex3f(38,-28.7,10.5);
    glEnd();
    //Belakang Kuning 2
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(40,-28.7,10.5);
    glVertex3f(38,-28.7,10.5);
    glVertex3f(38,-26.7,10.5);
    glVertex3f(40,-26.7,10.5);
    glEnd();
    //Belakang Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(40,-30.7,10.5);
    glVertex3f(38,-30.7,10.5);
    glVertex3f(38,-28.7,10.5);
    glVertex3f(40,-28.7,10.5);
    glEnd();
    //Belakang Orange 2
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(38,-28.7,10.5);
    glVertex3f(36,-26.7,10.5);
    glVertex3f(36,-26.7,10.5);
    glVertex3f(38,-26.7,10.5);
    glEnd();
    //Bawah Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(40,-30.7,8.5);
    glVertex3f(40,-30.7,10.5);
    glVertex3f(38,-30.7,10.5);
    glVertex3f(38,-30.7,8.5);
    glEnd();
    //Bawah Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(38,-30.7,8.5);
    glVertex3f(38,-30.7,10.5);
    glVertex3f(36,-30.7,10.5);
    glVertex3f(36,-30.7,8.5);
    glEnd();
    //Atas Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(40,-26.7,8.5);
    glVertex3f(40,-26.7,10.5);
    glVertex3f(38,-26.7,10.5);
    glVertex3f(38,-26.7,8.5);
    glEnd();
    //Atas Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(38,-26.7,8.5);
    glVertex3f(38,-26.7,10.5);
    glVertex3f(36,-26.7,10.5);
    glVertex3f(36,-26.7,8.5);
    glEnd();
    //DEPAN
    //Depan Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(38,-30.7,8.5);
    glVertex3f(36,-30.7,8.5);
    glVertex3f(36,-28.7,8.5);
    glVertex3f(38,-28.7,8.5);
    glEnd();
    //Depan Kuning 2
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(40,-28.7,8.5);
    glVertex3f(38,-28.7,8.5);
    glVertex3f(38,-26.7,8.5);
    glVertex3f(40,-26.7,8.5);
    glEnd();
    //Depan Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(40,-30.7,8.5);
    glVertex3f(38,-30.7,8.5);
    glVertex3f(38,-28.7,8.5);
    glVertex3f(40,-28.7,8.5);
    glEnd();
    //Depan Orange 2
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(38,-28.7,8.5);
    glVertex3f(36,-28.7,8.5);
    glVertex3f(36,-26.7,8.5);
    glVertex3f(38,-26.7,8.5);
    glEnd();
    //Kanan Orange
    glBegin(GL_POLYGON);
    glColor3ub(255, 154, 38);
    glVertex3f(38,-28.7,10.5);
    glVertex3f(36,-28.7,8.5);
    glVertex3f(36,-26.7,8.5);
    glVertex3f(38,-26.7,10.5);
    glEnd();
    //Kanan Kuning
    glBegin(GL_POLYGON);
    glColor3ub(196, 255, 79);
    glVertex3f(40,-30.7,10.5);
    glVertex3f(38,-30.7,8.5);
    glVertex3f(38,-28.7,8.5);
    glVertex3f(40,-28.7,10.5);
    glEnd();
}

void gerbang (void)
{
    //depam kiri
    glBegin(GL_QUADS);
    glColor3f(0.73,0.73,0.55);
    glVertex3f(-35,-39.9,40);
    glVertex3f(-25,-39.9,40);
    glVertex3f(-25,-9.9,40);
    glVertex3f(-35,-9.9,40);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.73,0.73,0.55);
    glVertex3f(-35,-39.9,30);
    glVertex3f(-25,-39.9,30);
    glVertex3f(-25,-9.9,30);
    glVertex3f(-35,-9.9,30);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.73,0.73,0.55);
    glVertex3f(-25,-39.9,30);
    glVertex3f(-25,-9.9,30);
    glVertex3f(-25,-9.9,40);
    glVertex3f(-25,-39.9,40);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.73,0.73,0.55);
    glVertex3f(-35,-39.9,30);
    glVertex3f(-35,-9.9,30);
    glVertex3f(-35,-9.9,40);
    glVertex3f(-35,-39.9,40);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.73,0.73,0.55);
    glVertex3f(-35,-9.9,40);
    glVertex3f(-25,-9.9,40);
    glVertex3f(-25,-9.9,30);
    glVertex3f(-35,-9.9,30);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0.73,0.73,0.55);
    glVertex3f(-35,-39.9,40);
    glVertex3f(-25,-39.9,40);
    glVertex3f(-25,-39.9,30);
    glVertex3f(-35,-39.9,30);
    glEnd();

    //depam kanan
    glBegin(GL_QUADS);
    glColor3f(0.73,0.73,0.55);
    glVertex3f(35,-39.9,40);
    glVertex3f(25,-39.9,40);
    glVertex3f(25,-9.9,40);
    glVertex3f(35,-9.9,40);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.73,0.73,0.55);
    glVertex3f(35,-39.9,30);
    glVertex3f(25,-39.9,30);
    glVertex3f(25,-9.9,30);
    glVertex3f(35,-9.9,30);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.73,0.73,0.55);
    glVertex3f(25,-39.9,30);
    glVertex3f(25,-9.9,30);
    glVertex3f(25,-9.9,40);
    glVertex3f(25,-39.9,40);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.73,0.73,0.55);
    glVertex3f(35,-39.9,30);
    glVertex3f(35,-9.9,30);
    glVertex3f(35,-9.9,40);
    glVertex3f(35,-39.9,40);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.73,0.73,0.55);
    glVertex3f(35,-9.9,40);
    glVertex3f(25,-9.9,40);
    glVertex3f(25,-9.9,30);
    glVertex3f(35,-9.9,30);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0.73,0.73,0.55);
    glVertex3f(35,-39.9,40);
    glVertex3f(25,-39.9,40);
    glVertex3f(25,-39.9,30);
    glVertex3f(35,-39.9,30);
    glEnd();

    //depam tengah
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.85);
    glVertex3f(-7.5,-39.9,39);
    glVertex3f(7.5,-39.9,39);
    glVertex3f(7.5,-15.9,39);
    glVertex3f(-7.5,-15.9,39);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-7.5,-39.9,31);
    glVertex3f(7.5,-39.9,31);
    glVertex3f(7.5,-15.9,31);
    glVertex3f(-7.5,-15.9,31);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(7.5,-39.9,31);
    glVertex3f(7.5,-15.9,31);
    glVertex3f(7.5,-15.9,39);
    glVertex3f(7.5,-39.9,30);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-7.5,-39.9,31);
    glVertex3f(-7.5,-15.9,31);
    glVertex3f(-7.5,-15.9,39);
    glVertex3f(-7.5,-39.9,39);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-7.5,-15.9,39);
    glVertex3f(7.5,-15.9,39);
    glVertex3f(7.5,-15.9,31);
    glVertex3f(-7.5,-15.9,31);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-7.5,-39.9,39);
    glVertex3f(7.5,-39.9,39);
    glVertex3f(7.5,-39.9,31);
    glVertex3f(-7.5,-39.9,31);
    glEnd();

    //coklat depan
    glBegin(GL_POLYGON);
    glColor3f(0.25,0,0);
    glVertex3f(-25,-39.9,40);
    glVertex3f(-25,-19.9,40);
    glVertex3f(25,-19.9,40);
    glVertex3f(25,-39.9,40);
    glEnd();

    //putih depan
    glBegin(GL_POLYGON);
    glColor3f(0.84,0.84,0.84);
    glVertex3f(-25,-39.9,38.9);
    glVertex3f(-25,-17.9,38.9);
    glVertex3f(-7.5,-17.9,38.9);
    glVertex3f(-7.5,-39.9,38.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84,0.84,0.84);
    glVertex3f(25,-39.9,38.9);
    glVertex3f(25,-17.9,38.9);
    glVertex3f(7.5,-17.9,38.9);
    glVertex3f(7.5,-39.9,38.9);
    glEnd();

    //putih blkg
    glBegin(GL_POLYGON);
    glColor3f(0.84,0.84,0.84);
    glVertex3f(-25,-39.9,37.9);
    glVertex3f(-25,-17.9,37.9);
    glVertex3f(-7.5,-17.9,33.9);
    glVertex3f(-7.5,-39.9,33.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84,0.84,0.84);
    glVertex3f(25,-39.9,37.9);
    glVertex3f(25,-17.9,37.9);
    glVertex3f(7.5,-17.9,33.9);
    glVertex3f(7.5,-39.9,33.9);
    glEnd();

    //putih atas
    glBegin(GL_POLYGON);
    glColor3f(0.84,0.84,0.84);
    glVertex3f(-25,-17.9,38.9);
    glVertex3f(-25,-17.9,37.9);
    glVertex3f(-7.5,-17.9,33.9);
    glVertex3f(-7.5,-17.9,38.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84,0.84,0.84);
    glVertex3f(25,-17.9,38.9);
    glVertex3f(25,-17.9,37.9);
    glVertex3f(7.5,-17.9,33.9);
    glVertex3f(7.5,-17.9,38.9);
    glEnd();

    lingkaran2(8,100,0,-30,41);

    glPopMatrix();
}

void logo(void)
{
    float a1x=-7, a1y=-26, z=41, b1x=7, b1y=-26, a2x=-8, a2y=-30, b2x=8, b2y=-30, a3x=-7, a3y=-34, b3x=7, b3y=-34,
    a4x=0, a4y=-22, b4x=0.1, b4y=-38, Ma1b1, Ma2b2, Ma3b3, Ma4b4, Ca1b1, Ca2b2, Ca3b3, Ca4b4, pa, pb, pc, pd, pe,pf;

    glBegin(GL_LINES);
    glColor3f(0.84,0.84,0.84);
    glVertex3f(a1x,a1y,z);
    glVertex3f(b1x,b1y,z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.84,0.84,0.84);
    glVertex3f(a2x,a2y,z);
    glVertex3f(b2x,b2y,z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.84,0.84,0.84);
    glVertex3f(a3x,a3y,z);
    glVertex3f(b3x,b3y,z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.84,0.84,0.84);
    glVertex3f(a4x,a4y,z);
    glVertex3f(b4x,b4y,z);
    glEnd();

    //rumus perpotongan
    Ma1b1=(b1y-a1y)/(b1x-a1x);
    Ma2b2=(b2y-a2y)/(b2x-a2x);
    Ma3b3=(b3y-a3y)/(b3x-a3x);
    Ma4b4=(b4y-a4y)/(b4x-a4x);
    Ca1b1=a1y-(a1x*Ma1b1);
    Ca2b2=a2y-(a2x*Ma2b2);
    Ca3b3=a3y-(a3x*Ma3b3);
    Ca4b4=a4y-(a4x*Ma4b4);

    //titik potong
    pa=(Ca1b1-Ca4b4)/(Ma4b4-Ma1b1);
    pb=(Ma4b4*pa)+Ca4b4;
    pc=(Ca2b2-Ca4b4)/(Ma4b4-Ma2b2);
    pd=(Ma4b4*pc)+Ca4b4;
    pe=(Ca3b3-Ca4b4)/(Ma4b4-Ma3b3);
    pf=(Ma4b4*pe)+Ca4b4;

    //hasil
    glBegin(GL_POINTS);
    glColor3f(0.84,0.84,0.84);
    glVertex3f(pa,pb,z);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0.84,0.84,0.84);
    glVertex3f(pc,pd,z);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0.84,0.84,0.84);
    glVertex3f(pe,pf,z);
    glEnd();
}

void gawang()
{
        //GAWANG
    //KIRI
    //BELAKANG
    //Belakang Miring
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-36.7,-20.5);
    glVertex3f(-38,-36.7,-20.5);
    glVertex3f(-35,-26.7,-20.5);
    glVertex3f(-35,-24.7,-20.5);
    glEnd();
    //Depan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-36.7,-18.5);
    glVertex3f(-38,-36.7,-18.5);
    glVertex3f(-35,-26.7,-18.5);
    glVertex3f(-35,-24.7,-18.5);
    glEnd();
    //Kiri
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-36.7,-20.5);
    glVertex3f(-40,-36.7,-18.5);
    glVertex3f(-35,-24.7,-18.5);
    glVertex3f(-35,-24.7,-20.5);
    glEnd();
    //Bawah
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-38,-36.7,-20.5);
    glVertex3f(-38,-36.7,-18.5);
    glVertex3f(-35,-26.7,-18.5);
    glVertex3f(-35,-26.7,-20.5);
    glEnd();
    //Belakang Tegak - Kiri
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-35,-36.7,-20.5);
    glVertex3f(-35,-36.7,-18.5);
    glVertex3f(-35,-24.7,-18.5);
    glVertex3f(-35,-24.7,-20.5);
    glEnd();
    //Belakang Tegak - Belakang
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-35,-36.7,-20.5);
    glVertex3f(-33,-36.7,-20.5);
    glVertex3f(-33,-24.7,-20.5);
    glVertex3f(-35,-24.7,-20.5);
    glEnd();
    //Belakang Tegak - Kanan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-33,-36.7,-20.5);
    glVertex3f(-33,-36.7,-18.5);
    glVertex3f(-33,-24.7,-18.5);
    glVertex3f(-33,-24.7,-20.5);
    glEnd();
    //Belakang Tegak - Depan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-35,-36.7,-18.5);
    glVertex3f(-33,-36.7,-18.5);
    glVertex3f(-33,-24.7,-18.5);
    glVertex3f(-35,-24.7,-18.5);
    glEnd();
    //Belakang Tegak - Atas
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-35,-24.7,-20.5);
    glVertex3f(-35,-24.7,-18.5);
    glVertex3f(-33,-24.7,-18.5);
    glVertex3f(-33,-24.7,-20.5);
    glEnd();
    //DEPAN
    //Depan Miring
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-36.7,-5.5);
    glVertex3f(-38,-36.7,-5.5);
    glVertex3f(-35,-26.7,-5.5);
    glVertex3f(-35,-24.7,-5.5);
    glEnd();
    //Depan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-36.7,-7.5);
    glVertex3f(-38,-36.7,-7.5);
    glVertex3f(-35,-26.7,-7.5);
    glVertex3f(-35,-24.7,-7.5);
    glEnd();
    //Kiri
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-36.7,-5.5);
    glVertex3f(-40,-36.7,-7.5);
    glVertex3f(-35,-24.7,-7.5);
    glVertex3f(-35,-24.7,-5.5);
    glEnd();
    //Bawah
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-38,-36.7,-5.5);
    glVertex3f(-38,-36.7,-7.5);
    glVertex3f(-35,-26.7,-7.5);
    glVertex3f(-35,-26.7,-5.5);
    glEnd();
    //Depan Tegak - Kiri
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-35,-36.7,-5.5);
    glVertex3f(-35,-36.7,-7.5);
    glVertex3f(-35,-24.7,-7.5);
    glVertex3f(-35,-24.7,-5.5);
    glEnd();
    //Depan Tegak - Belakang
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-35,-36.7,-7.5);
    glVertex3f(-33,-36.7,-7.5);
    glVertex3f(-33,-24.7,-7.5);
    glVertex3f(-35,-24.7,-7.5);
    glEnd();
    //Depan Tegak - Kanan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-33,-36.7,-5.5);
    glVertex3f(-33,-36.7,-7.5);
    glVertex3f(-33,-24.7,-7.5);
    glVertex3f(-33,-24.7,-5.5);
    glEnd();
    //Depan Tegak - Depan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-35,-36.7,-5.5);
    glVertex3f(-33,-36.7,-5.5);
    glVertex3f(-33,-24.7,-5.5);
    glVertex3f(-35,-24.7,-5.5);
    glEnd();
    //Depan Tegak - Atas
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-35,-24.7,-5.5);
    glVertex3f(-35,-24.7,-7.5);
    glVertex3f(-33,-24.7,-7.5);
    glVertex3f(-33,-24.7,-5.5);
    glEnd();
    //ATAS
    //Atas
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-35,-24.7,-7.5);
    glVertex3f(-35,-24.7,-18.5);
    glVertex3f(-33,-24.7,-18.5);
    glVertex3f(-33,-24.7,-7.5);
    glEnd();
    //Kiri
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-35,-26.7,-7.5);
    glVertex3f(-35,-26.7,-18.5);
    glVertex3f(-35,-24.7,-18.5);
    glVertex3f(-35,-24.7,-7.5);
    glEnd();
    //Bawah
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-35,-26.7,-7.5);
    glVertex3f(-35,-26.7,-18.5);
    glVertex3f(-33,-26.7,-18.5);
    glVertex3f(-33,-26.7,-7.5);
    glEnd();
    //Kanan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-33,-26.7,-7.5);
    glVertex3f(-33,-26.7,-18.5);
    glVertex3f(-33,-24.7,-18.5);
    glVertex3f(-33,-24.7,-7.5);
    glEnd();
    //JARING GAWANG KIRI
    //Vertikal
    //1
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-39.4,-35.7,-7.5);
    glVertex3f(-39.4,-35.7,-18.5);
    glVertex3f(-39.1,-34.7,-18.5);
    glVertex3f(-39.1,-34.7,-7.5);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-38.4,-33.7,-7.5);
    glVertex3f(-38.4,-33.7,-18.5);
    glVertex3f(-38.1,-32.7,-18.5);
    glVertex3f(-38.1,-32.7,-7.5);
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-37.4,-31.7,-7.5);
    glVertex3f(-37.4,-31.7,-18.5);
    glVertex3f(-37.1,-30.7,-18.5);
    glVertex3f(-37.1,-30.7,-7.5);
    glEnd();
    //4
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-36.4,-29.7,-7.5);
    glVertex3f(-36.4,-29.7,-18.5);
    glVertex3f(-36.1,-28.7,-18.5);
    glVertex3f(-36.1,-28.7,-7.5);
    glEnd();
    //5
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-35.4,-27.7,-7.5);
    glVertex3f(-35.4,-27.7,-18.5);
    glVertex3f(-35.1,-26.7,-18.5);
    glVertex3f(-35.1,-26.7,-7.5);
    glEnd();
    //Horizontal
    //1
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-36.7,-17.5);
    glVertex3f(-40,-36.7,-16.5);
    glVertex3f(-35,-24.7,-16.5);
    glVertex3f(-35,-24.7,-17.5);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-36.7,-15.5);
    glVertex3f(-40,-36.7,-14.5);
    glVertex3f(-35,-24.7,-14.5);
    glVertex3f(-35,-24.7,-15.5);
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-36.7,-13.5);
    glVertex3f(-40,-36.7,-12.5);
    glVertex3f(-35,-24.7,-12.5);
    glVertex3f(-35,-24.7,-13.5);
    glEnd();
    //4
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-36.7,-11.5);
    glVertex3f(-40,-36.7,-10.5);
    glVertex3f(-35,-24.7,-10.5);
    glVertex3f(-35,-24.7,-11.5);
    glEnd();
    //5
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,-36.7,-9.5);
    glVertex3f(-40,-36.7,-8.5);
    glVertex3f(-35,-24.7,-8.5);
    glVertex3f(-35,-24.7,-9.5);
    glEnd();

    //KANAN
    //BELAKANG
    //Belakang Miring
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(40,-36.7,-20.5);
    glVertex3f(38,-36.7,-20.5);
    glVertex3f(35,-26.7,-20.5);
    glVertex3f(35,-24.7,-20.5);
    glEnd();
    //Depan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(40,-36.7,-18.5);
    glVertex3f(38,-36.7,-18.5);
    glVertex3f(35,-26.7,-18.5);
    glVertex3f(35,-24.7,-18.5);
    glEnd();
    //Kiri
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(40,-36.7,-20.5);
    glVertex3f(40,-36.7,-18.5);
    glVertex3f(35,-24.7,-18.5);
    glVertex3f(35,-24.7,-20.5);
    glEnd();
    //Bawah
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(38,-36.7,-20.5);
    glVertex3f(38,-36.7,-18.5);
    glVertex3f(35,-26.7,-18.5);
    glVertex3f(35,-26.7,-20.5);
    glEnd();
    //Belakang Tegak - Kiri
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(35,-36.7,-20.5);
    glVertex3f(35,-36.7,-18.5);
    glVertex3f(35,-24.7,-18.5);
    glVertex3f(35,-24.7,-20.5);
    glEnd();
    //Belakang Tegak - Belakang
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(35,-36.7,-20.5);
    glVertex3f(33,-36.7,-20.5);
    glVertex3f(33,-24.7,-20.5);
    glVertex3f(35,-24.7,-20.5);
    glEnd();
    //Belakang Tegak - Kanan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(33,-36.7,-20.5);
    glVertex3f(33,-36.7,-18.5);
    glVertex3f(33,-24.7,-18.5);
    glVertex3f(33,-24.7,-20.5);
    glEnd();
    //Belakang Tegak - Depan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(35,-36.7,-18.5);
    glVertex3f(33,-36.7,-18.5);
    glVertex3f(33,-24.7,-18.5);
    glVertex3f(35,-24.7,-18.5);
    glEnd();
    //Belakang Tegak - Atas
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(35,-24.7,-20.5);
    glVertex3f(35,-24.7,-18.5);
    glVertex3f(33,-24.7,-18.5);
    glVertex3f(33,-24.7,-20.5);
    glEnd();
    //DEPAN
    //Depan Miring
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(40,-36.7,-5.5);
    glVertex3f(38,-36.7,-5.5);
    glVertex3f(35,-26.7,-5.5);
    glVertex3f(35,-24.7,-5.5);
    glEnd();
    //Depan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(40,-36.7,-7.5);
    glVertex3f(38,-36.7,-7.5);
    glVertex3f(35,-26.7,-7.5);
    glVertex3f(35,-24.7,-7.5);
    glEnd();
    //Kiri
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(40,-36.7,-5.5);
    glVertex3f(40,-36.7,-7.5);
    glVertex3f(35,-24.7,-7.5);
    glVertex3f(35,-24.7,-5.5);
    glEnd();
    //Bawah
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(38,-36.7,-5.5);
    glVertex3f(38,-36.7,-7.5);
    glVertex3f(35,-26.7,-7.5);
    glVertex3f(35,-26.7,-5.5);
    glEnd();
    //Depan Tegak - Kiri
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(35,-36.7,-5.5);
    glVertex3f(35,-36.7,-7.5);
    glVertex3f(35,-24.7,-7.5);
    glVertex3f(35,-24.7,-5.5);
    glEnd();
    //Depan Tegak - Belakang
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(35,-36.7,-7.5);
    glVertex3f(33,-36.7,-7.5);
    glVertex3f(33,-24.7,-7.5);
    glVertex3f(35,-24.7,-7.5);
    glEnd();
    //Depan Tegak - Kanan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(33,-36.7,-5.5);
    glVertex3f(33,-36.7,-7.5);
    glVertex3f(33,-24.7,-7.5);
    glVertex3f(33,-24.7,-5.5);
    glEnd();
    //Depan Tegak - Depan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(35,-36.7,-5.5);
    glVertex3f(33,-36.7,-5.5);
    glVertex3f(33,-24.7,-5.5);
    glVertex3f(35,-24.7,-5.5);
    glEnd();
    //Depan Tegak - Atas
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(35,-24.7,-5.5);
    glVertex3f(35,-24.7,-7.5);
    glVertex3f(33,-24.7,-7.5);
    glVertex3f(33,-24.7,-5.5);
    glEnd();
    //ATAS
    //Atas
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(35,-24.7,-7.5);
    glVertex3f(35,-24.7,-18.5);
    glVertex3f(33,-24.7,-18.5);
    glVertex3f(33,-24.7,-7.5);
    glEnd();
    //Kiri
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(35,-26.7,-7.5);
    glVertex3f(35,-26.7,-18.5);
    glVertex3f(35,-24.7,-18.5);
    glVertex3f(35,-24.7,-7.5);
    glEnd();
    //Bawah
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(35,-26.7,-7.5);
    glVertex3f(35,-26.7,-18.5);
    glVertex3f(33,-26.7,-18.5);
    glVertex3f(33,-26.7,-7.5);
    glEnd();
    //Kanan
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(33,-26.7,-7.5);
    glVertex3f(33,-26.7,-18.5);
    glVertex3f(33,-24.7,-18.5);
    glVertex3f(33,-24.7,-7.5);
    glEnd();
    //JARING GAWANG KIRI
    //Vertikal
    //1
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(39.4,-35.7,-7.5);
    glVertex3f(39.4,-35.7,-18.5);
    glVertex3f(39.1,-34.7,-18.5);
    glVertex3f(39.1,-34.7,-7.5);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(38.4,-33.7,-7.5);
    glVertex3f(38.4,-33.7,-18.5);
    glVertex3f(38.1,-32.7,-18.5);
    glVertex3f(38.1,-32.7,-7.5);
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(37.4,-31.7,-7.5);
    glVertex3f(37.4,-31.7,-18.5);
    glVertex3f(37.1,-30.7,-18.5);
    glVertex3f(37.1,-30.7,-7.5);
    glEnd();
    //4
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(36.4,-29.7,-7.5);
    glVertex3f(36.4,-29.7,-18.5);
    glVertex3f(36.1,-28.7,-18.5);
    glVertex3f(36.1,-28.7,-7.5);
    glEnd();
    //5
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(35.4,-27.7,-7.5);
    glVertex3f(35.4,-27.7,-18.5);
    glVertex3f(35.1,-26.7,-18.5);
    glVertex3f(35.1,-26.7,-7.5);
    glEnd();
    //Horizontal
    //1
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(40,-36.7,-17.5);
    glVertex3f(40,-36.7,-16.5);
    glVertex3f(35,-24.7,-16.5);
    glVertex3f(35,-24.7,-17.5);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(40,-36.7,-15.5);
    glVertex3f(40,-36.7,-14.5);
    glVertex3f(35,-24.7,-14.5);
    glVertex3f(35,-24.7,-15.5);
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(40,-36.7,-13.5);
    glVertex3f(40,-36.7,-12.5);
    glVertex3f(35,-24.7,-12.5);
    glVertex3f(35,-24.7,-13.5);
    glEnd();
    //4
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(40,-36.7,-11.5);
    glVertex3f(40,-36.7,-10.5);
    glVertex3f(35,-24.7,-10.5);
    glVertex3f(35,-24.7,-11.5);
    glEnd();
    //5
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(40,-36.7,-9.5);
    glVertex3f(40,-36.7,-8.5);
    glVertex3f(35,-24.7,-8.5);
    glVertex3f(35,-24.7,-9.5);
    glEnd();
}

void stadium(void)
{
    //kiri
    //1
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(-42,-10.0,30.0);
    glVertex3f(-42,-40.0,30.0);
    glVertex3f(-58,-40.0,25.0);
    glVertex3f(-58,-10.0,25.0);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(-58,-10.0,25.0);
    glVertex3f(-58,-40.0,25.0);
    glVertex3f(-64,-40.0,16.0);
    glVertex3f(-64,-10.0,16.0);
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(-64,-10.0,16.0);
    glVertex3f(-64,-40.0,16.0);
    glVertex3f(-68,-40.0,7.0);
    glVertex3f(-68,-10.0,7.0);
    glEnd();
    //4
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(-68,-10.0,7.0);
    glVertex3f(-68,-40.0,7.0);
    glVertex3f(-70,-40.0,-2.0);
    glVertex3f(-70,-10.0,-2.0);
    glEnd();
    //5
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(-70,-10.0,-2.0);
    glVertex3f(-70,-40.0,-2.0);
    glVertex3f(-71,-40.0,-11.0);
    glVertex3f(-71,-10.0,-11.0);
    glEnd();
    //6
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(-71,-10.0,-11.0);
    glVertex3f(-71,-40.0,-11.0);
    glVertex3f(-71,-40.0,-20.0);
    glVertex3f(-71,-10.0,-20.0);
    glEnd();
    //7
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(-71,-10.0,-20.0);
    glVertex3f(-71,-40.0,-20.0);
    glVertex3f(-70,-40.0,-29.0);
    glVertex3f(-70,-10.0,-29.0);
    glEnd();
    //8
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(-70,-10.0,-29.0);
    glVertex3f(-70,-40.0,-29.0);
    glVertex3f(-68,-40.0,-38.0);
    glVertex3f(-68,-10.0,-38.0);
    glEnd();
    //9
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(-68,-10.0,-38.0);
    glVertex3f(-68,-40.0,-38.0);
    glVertex3f(-64,-40.0,-47.0);
    glVertex3f(-64,-10.0,-47.0);
    glEnd();
    //10
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(-64,-10.0,-47.0);
    glVertex3f(-64,-40.0,-47.0);
    glVertex3f(-58,-40.0,-56.0);
    glVertex3f(-58,-10.0,-56.0);
    glEnd();
    //11
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(-58,-10.0,-56.0);
    glVertex3f(-58,-40.0,-56.0);
    glVertex3f(-42,-40.0,-61.0);
    glVertex3f(-42,-10.0,-61.0);
    glEnd();
    //atap
    //1
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(-42,-10.0,30.0);
    glVertex3f(-32,-10.0,10.0);
    glVertex3f(-48,-10.0,5.0);
    glVertex3f(-58,-10.0,25.0);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(-58,-10.0,25.0);
    glVertex3f(-48,-10.0,5.0);
    glVertex3f(-54,-10.0,-4.0);
    glVertex3f(-64,-10.0,16.0);
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(-64,-10.0,16.0);
    glVertex3f(-54,-10.0,-4.0);
    glVertex3f(-58,-10.0,-13.0);
    glVertex3f(-68,-10.0,7.0);
    glEnd();
    //4
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(-68,-10.0,7.0);
    glVertex3f(-58,-10.0,13.0);
    glVertex3f(-60,-10.0,-18.0);
    glVertex3f(-70,-10.0,-2.0);
    glEnd();
    //5
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(-70,-10.0,-2.0);
    glVertex3f(-50,-10.0,22.0);
    glVertex3f(-61,-10.0,-31.0);
    glVertex3f(-71,-10.0,-11.0);
    glEnd();
    //6
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(-71,-10.0,-11.0);
    glVertex3f(-61,-10.0,-31.0);
    glVertex3f(-61,-10.0,0.0);
    glVertex3f(-71,-10.0,-20.0);
    glEnd();
    //7
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(-71,-10.0,-20.0);
    glVertex3f(-61,-10.0,0.0);
    glVertex3f(-60,-10.0,-9.0);
    glVertex3f(-70,-10.0,-29.0);
    glEnd();
    //8
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(-70,-10.0,-29.0);
    glVertex3f(-60,-10.0,-9.0);
    glVertex3f(-58,-10.0,-18.0);
    glVertex3f(-68,-10.0,-38.0);
    glEnd();
    //9
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(-68,-10.0,-38.0);
    glVertex3f(-58,-10.0,-18.0);
    glVertex3f(-54,-10.0,-27.0);
    glVertex3f(-64,-10.0,-47.0);
    glEnd();
    //10
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(-64,-10.0,-47.0);
    glVertex3f(-54,-10.0,-27.0);
    glVertex3f(-48,-10.0,-36.0);
    glVertex3f(-58,-10.0,-56.0);
    glEnd();
    //11
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(-58,-10.0,-56.0);
    glVertex3f(-48,-10.0,-36.0);
    glVertex3f(-32,-10.0,-41.0);
    glVertex3f(-42,-10.0,-61.0);
    glEnd();
    //atas
    //1
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(42,-10.0,30.0);
    glVertex3f(32,-10.0,10.0);
    glVertex3f(48,-10.0,5.0);
    glVertex3f(58,-10.0,25.0);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(58,-10.0,25.0);
    glVertex3f(48,-10.0,5.0);
    glVertex3f(54,-10.0,-4.0);
    glVertex3f(64,-10.0,16.0);
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(64,-10.0,16.0);
    glVertex3f(54,-10.0,-4.0);
    glVertex3f(58,-10.0,-13.0);
    glVertex3f(68,-10.0,7.0);
    glEnd();
    //4
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(68,-10.0,7.0);
    glVertex3f(58,-10.0,13.0);
    glVertex3f(60,-10.0,-18.0);
    glVertex3f(70,-10.0,-2.0);
    glEnd();
    //5
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(70,-10.0,-2.0);
    glVertex3f(50,-10.0,22.0);
    glVertex3f(61,-10.0,-31.0);
    glVertex3f(71,-10.0,-11.0);
    glEnd();
    //6
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(71,-10.0,-11.0);
    glVertex3f(61,-10.0,-31.0);
    glVertex3f(61,-10.0,0.0);
    glVertex3f(71,-10.0,-20.0);
    glEnd();
    //7
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(71,-10.0,-20.0);
    glVertex3f(61,-10.0,0.0);
    glVertex3f(60,-10.0,-9.0);
    glVertex3f(70,-10.0,-29.0);
    glEnd();
    //8
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(70,-10.0,-29.0);
    glVertex3f(60,-10.0,-9.0);
    glVertex3f(58,-10.0,-18.0);
    glVertex3f(68,-10.0,-38.0);
    glEnd();
    //9
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(68,-10.0,-38.0);
    glVertex3f(58,-10.0,-18.0);
    glVertex3f(54,-10.0,-27.0);
    glVertex3f(64,-10.0,-47.0);
    glEnd();
    //10
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(64,-10.0,-47.0);
    glVertex3f(54,-10.0,-27.0);
    glVertex3f(48,-10.0,-36.0);
    glVertex3f(58,-10.0,-56.0);
    glEnd();
    //11
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(58,-10.0,-56.0);
    glVertex3f(48,-10.0,-36.0);
    glVertex3f(32,-10.0,-41.0);
    glVertex3f(42,-10.0,-61.0);
    glEnd();


    //tengah
    //1
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(42,-10.0,30.0);
    glVertex3f(42,-40.0,30.0);
    glVertex3f(-42,-40.0,30.0);
    glVertex3f(-42,-10.0,30.0);
    glEnd();
    //garis motif tengah
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(42,-13.0,-61.5);
    glVertex3f(42,-16.0,-61.5);
    glVertex3f(-42,-16.0,-61.5);
    glVertex3f(-42,-13.0,-61.5);
    glEnd();
    //
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(42,-10.0,-61.5);
    glVertex3f(42,-40.0,-61.5);
    glVertex3f(39,-40.0,-61.5);
    glVertex3f(39,-10.0,-61.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(42,-10.0,30.5);
    glVertex3f(42,-40.0,30.5);
    glVertex3f(39,-40.0,30.5);
    glVertex3f(39,-10.0,30.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(29,-10.0,-61.5);
    glVertex3f(29,-40.0,-61.5);
    glVertex3f(26,-40.0,-61.5);
    glVertex3f(26,-10.0,-61.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(16,-10.0,-61.5);
    glVertex3f(16,-40.0,-61.5);
    glVertex3f(19,-40.0,-61.5);
    glVertex3f(19,-10.0,-61.5);
    glEnd();
    // pintu masuk
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,1);
    glVertex3f(17,-26.0,-61.2);
    glVertex3f(17,-40.0,-61.2);
    glVertex3f(-3,-40.0,-61.2);
    glVertex3f(-3,-26.0,-61.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,1);
    glVertex3f(40,-26.0,-61.2);
    glVertex3f(40,-40.0,-61.2);
    glVertex3f(27,-40.0,-61.2);
    glVertex3f(27,-26.0,-61.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,1);
    glVertex3f(-40,-26.0,-61.2);
    glVertex3f(-40,-40.0,-61.2);
    glVertex3f(-24,-40.0,-61.2);
    glVertex3f(-24,-26.0,-61.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(9,-10.0,-61.5);
    glVertex3f(9,-40.0,-61.5);
    glVertex3f(6,-40.0,-61.5);
    glVertex3f(6,-10.0,-61.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-1,-10.0,-61.5);
    glVertex3f(-1,-40.0,-61.5);
    glVertex3f(-4,-40.0,-61.5);
    glVertex3f(-4,-10.0,-61.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-10,-10.0,-61.5);
    glVertex3f(-10,-40.0,-61.5);
    glVertex3f(-13,-40.0,-61.5);
    glVertex3f(-13,-10.0,-61.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-23,-10.0,-61.5);
    glVertex3f(-23,-40.0,-61.5);
    glVertex3f(-26,-40.0,-61.5);
    glVertex3f(-26,-10.0,-61.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-39,-10.0,-61.5);
    glVertex3f(-39,-40.0,-61.5);
    glVertex3f(-42,-40.0,-61.5);
    glVertex3f(-42,-10.0,-61.5);
    glEnd();
    //
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-39,-10.0,30.5);
    glVertex3f(-39,-40.0,30.5);
    glVertex3f(-42,-40.0,30.5);
    glVertex3f(-42,-10.0,30.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(42,-13.0,30.5);
    glVertex3f(42,-16.0,30.5);
    glVertex3f(-42,-16.0,30.5);
    glVertex3f(-42,-13.0,30.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(42,-25.0,-61.5);
    glVertex3f(42,-28.0,-61.5);
    glVertex3f(-42,-28.0,-61.5);
    glVertex3f(-42,-25.0,-61.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(42,-25.0,30.5);
    glVertex3f(42,-28.0,30.5);
    glVertex3f(-42,-28.0,30.5);
    glVertex3f(-42,-25.0,30.5);
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(42,-10.0,30.0);
    glVertex3f(42,-10.0,10.0);
    glVertex3f(-42,-10.0,10.0);
    glVertex3f(-42,-10.0,30.0);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(42,-10.0,-61.0);
    glVertex3f(42,-40.0,-61.0);
    glVertex3f(-42,-40.0,-61.0);
    glVertex3f(-42,-10.0,-61.0);
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.54,0.49,0.43 );
    glVertex3f(42,-10.0,-61.0);
    glVertex3f(42,-10.0,-41.0);
    glVertex3f(-42,-10.0,-41.0);
    glVertex3f(-42,-10.0,-61.0);
    glEnd();

    //kanan
    //1
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(42,-10.0,30.0);
    glVertex3f(42,-40.0,30.0);
    glVertex3f(58,-40.0,25.0);
    glVertex3f(58,-10.0,25.0);
    glEnd();
    //motif
    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(42,-13.0,30.5);
    glVertex3f(42,-16.0,30.5);
    glVertex3f(58,-16.0,25.5);
    glVertex3f(58,-13.0,25.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(42,-25.0,30.5);
    glVertex3f(42,-28.0,30.5);
    glVertex3f(58,-28.0,25.5);
    glVertex3f(58,-25.0,25.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(55,-10.0,26.5);
    glVertex3f(55,-40.0,26.5);
    glVertex3f(58,-40.0,25.5);
    glVertex3f(58,-10.0,25.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-55,-10.0,26.5);
    glVertex3f(-55,-40.0,26.5);
    glVertex3f(-58,-40.0,25.5);
    glVertex3f(-58,-10.0,25.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-42,-13.0,30.5);
    glVertex3f(-42,-16.0,30.5);
    glVertex3f(-58,-16.0,25.5);
    glVertex3f(-58,-13.0,25.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-42,-25.0,30.5);
    glVertex3f(-42,-28.0,30.5);
    glVertex3f(-58,-28.0,25.5);
    glVertex3f(-58,-25.0,25.5);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(58,-10.0,25.0);
    glVertex3f(58,-40.0,25.0);
    glVertex3f(64,-40.0,16.0);
    glVertex3f(64,-10.0,16.0);
    glEnd();
    //motif
    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(58,-13.0,25.5);
    glVertex3f(58,-16.0,25.5);
    glVertex3f(64,-16.0,16.5);
    glVertex3f(64,-13.0,16.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(58,-25.0,25.5);
    glVertex3f(58,-28.0,25.5);
    glVertex3f(64,-28.0,16.5);
    glVertex3f(64,-25.0,16.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-58,-13.0,25.5);
    glVertex3f(-58,-16.0,25.5);
    glVertex3f(-64,-16.0,16.5);
    glVertex3f(-64,-13.0,16.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-58,-25.0,25.5);
    glVertex3f(-58,-28.0,25.5);
    glVertex3f(-64,-28.0,16.5);
    glVertex3f(-64,-25.0,16.5);
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(64,-10.0,16.0);
    glVertex3f(64,-40.0,16.0);
    glVertex3f(68,-40.0,7.0);
    glVertex3f(68,-10.0,7.0);
    glEnd();
    //motif
    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(64,-13.0,16.5);
    glVertex3f(64,-16.0,16.5);
    glVertex3f(68,-16.0,7.5);
    glVertex3f(68,-13.0,7.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(64,-25.0,16.5);
    glVertex3f(64,-28.0,16.5);
    glVertex3f(68,-28.0,7.5);
    glVertex3f(68,-25.0,7.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(64,-10.0,16.5);
    glVertex3f(64,-40.0,16.5);
    glVertex3f(66,-40.0,12.0);
    glVertex3f(66,-10.0,12.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-64,-10.0,16.5);
    glVertex3f(-64,-40.0,16.5);
    glVertex3f(-66,-40.0,12.0);
    glVertex3f(-66,-10.0,12.0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-64,-13.0,16.5);
    glVertex3f(-64,-16.0,16.5);
    glVertex3f(-68,-16.0,7.5);
    glVertex3f(-68,-13.0,7.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-64,-25.0,16.5);
    glVertex3f(-64,-28.0,16.5);
    glVertex3f(-68,-28.0,7.5);
    glVertex3f(-68,-25.0,7.5);
    glEnd();
    //4
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(68,-10.0,7.0);
    glVertex3f(68,-40.0,7.0);
    glVertex3f(70,-40.0,-2.0);
    glVertex3f(70,-10.0,-2.0);
    glEnd();
    //motif
    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(68,-13.0,7.5);
    glVertex3f(68,-16.0,7.5);
    glVertex3f(70.5,-16.0,-2.5);
    glVertex3f(70.5,-13.0,-2.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(68,-25.0,7.5);
    glVertex3f(68,-28.0,7.5);
    glVertex3f(70.5,-28.0,-2.5);
    glVertex3f(70.5,-25.0,-2.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-68,-13.0,7.5);
    glVertex3f(-68,-16.0,7.5);
    glVertex3f(-70.5,-16.0,-2.5);
    glVertex3f(-70.5,-13.0,-2.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-68,-25.0,7.5);
    glVertex3f(-68,-28.0,7.5);
    glVertex3f(-70.5,-28.0,-2.5);
    glVertex3f(-70.5,-25.0,-2.5);
    glEnd();
    //5
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(70,-10.0,-2.0);
    glVertex3f(70,-40.0,-2.0);
    glVertex3f(71,-40.0,-11.0);
    glVertex3f(71,-10.0,-11.0);
    glEnd();
    //motif
    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(70.5,-13.0,-2.5);
    glVertex3f(70.5,-16.0,-2.5);
    glVertex3f(71.5,-16.0,-11.5);
    glVertex3f(71.5,-13.0,-11.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(70.5,-25.0,-2.5);
    glVertex3f(70.5,-28.0,-2.5);
    glVertex3f(71.5,-28.0,-11.5);
    glVertex3f(71.5,-25.0,-11.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(70.5,-10.0,-2.5);
    glVertex3f(70.5,-40.0,-2.5);
    glVertex3f(70.5,-40.0,-5.5);
    glVertex3f(70.5,-10.0,-5.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-70.5,-10.0,-2.5);
    glVertex3f(-70.5,-40.0,-2.5);
    glVertex3f(-70.5,-40.0,-5.5);
    glVertex3f(-70.5,-10.0,-5.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-70.5,-13.0,-2.5);
    glVertex3f(-70.5,-16.0,-2.5);
    glVertex3f(-71.5,-16.0,-11.5);
    glVertex3f(-71.5,-13.0,-11.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-70.5,-25.0,-2.5);
    glVertex3f(-70.5,-28.0,-2.5);
    glVertex3f(-71.5,-28.0,-11.5);
    glVertex3f(-71.5,-25.0,-11.5);
    glEnd();
    //6
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(71,-10.0,-11.0);
    glVertex3f(71,-40.0,-11.0);
    glVertex3f(71,-40.0,-20.0);
    glVertex3f(71,-10.0,-20.0);
    glEnd();
    //motif
    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(71.5,-13.0,-11.5);
    glVertex3f(71.5,-16.0,-11.5);
    glVertex3f(71,-16.0,-20.5);
    glVertex3f(71,-13.0,-20.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(71.5,-25.0,-11.5);
    glVertex3f(71.5,-28.0,-11.5);
    glVertex3f(71,-28.0,-20.5);
    glVertex3f(71,-25.0,-20.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-71.5,-13.0,-11.5);
    glVertex3f(-71.5,-16.0,-11.5);
    glVertex3f(-71,-16.0,-20.5);
    glVertex3f(-71,-13.0,-20.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-71.5,-25.0,-11.5);
    glVertex3f(-71.5,-28.0,-11.5);
    glVertex3f(-71,-28.0,-20.5);
    glVertex3f(-71,-25.0,-20.5);
    glEnd();
    //7
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(71,-10.0,-20.0);
    glVertex3f(71,-40.0,-20.0);
    glVertex3f(70,-40.0,-29.0);
    glVertex3f(70,-10.0,-29.0);
    glEnd();
    //motif
    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(71,-13.0,-20.5);
    glVertex3f(71,-16.0,-20.5);
    glVertex3f(70,-16.0,-29.5);
    glVertex3f(70,-13.0,-29.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(71,-25.0,-20.5);
    glVertex3f(71,-28.0,-20.5);
    glVertex3f(70,-28.0,-29.5);
    glVertex3f(70,-25.0,-29.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(71,-10.0,-20.5);
    glVertex3f(71,-40.0,-20.5);
    glVertex3f(70.5,-40.0,-25.5);
    glVertex3f(70.5,-10.0,-25.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-71,-10.0,-20.5);
    glVertex3f(-71,-40.0,-20.5);
    glVertex3f(-70.5,-40.0,-25.5);
    glVertex3f(-70.5,-10.0,-25.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-71,-13.0,-20.5);
    glVertex3f(-71,-16.0,-20.5);
    glVertex3f(-70,-16.0,-29.5);
    glVertex3f(-70,-13.0,-29.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-71,-25.0,-20.5);
    glVertex3f(-71,-28.0,-20.5);
    glVertex3f(-70,-28.0,-29.5);
    glVertex3f(-70,-25.0,-29.5);
    glEnd();
    //8
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(70,-10.0,-29.0);
    glVertex3f(70,-40.0,-29.0);
    glVertex3f(68,-40.0,-38.0);
    glVertex3f(68,-10.0,-38.0);
    glEnd();
    //motif
    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(70,-13.0,-29.5);
    glVertex3f(70,-16.0,-29.5);
    glVertex3f(68,-16.0,-38.5);
    glVertex3f(68,-13.0,-38.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(70,-25.0,-29.5);
    glVertex3f(70,-28.0,-29.5);
    glVertex3f(68,-28.0,-38.5);
    glVertex3f(68,-25.0,-38.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-70,-13.0,-29.5);
    glVertex3f(-70,-16.0,-29.5);
    glVertex3f(-68,-16.0,-38.5);
    glVertex3f(-68,-13.0,-38.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-70,-25.0,-29.5);
    glVertex3f(-70,-28.0,-29.5);
    glVertex3f(-68,-28.0,-38.5);
    glVertex3f(-68,-25.0,-38.5);
    glEnd();
    //9
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(68,-10.0,-38.0);
    glVertex3f(68,-40.0,-38.0);
    glVertex3f(64,-40.0,-47.0);
    glVertex3f(64,-10.0,-47.0);
    glEnd();
    //motif
    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(68,-13.0,-38.5);
    glVertex3f(68,-16.0,-38.5);
    glVertex3f(64,-16.0,-47.5);
    glVertex3f(64,-13.0,-47.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(68,-25.0,-38.5);
    glVertex3f(68,-28.0,-38.5);
    glVertex3f(64,-28.0,-47.5);
    glVertex3f(64,-25.0,-47.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(68,-10.0,-38.5);
    glVertex3f(68,-40.0,-38.5);
    glVertex3f(67,-40.0,-41.5);
    glVertex3f(67,-10.0,-41.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-68,-10.0,-38.5);
    glVertex3f(-68,-40.0,-38.5);
    glVertex3f(-67,-40.0,-41.5);
    glVertex3f(-67,-10.0,-41.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-68,-13.0,-38.5);
    glVertex3f(-68,-16.0,-38.5);
    glVertex3f(-64,-16.0,-47.5);
    glVertex3f(-64,-13.0,-47.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-68,-25.0,-38.5);
    glVertex3f(-68,-28.0,-38.5);
    glVertex3f(-64,-28.0,-47.5);
    glVertex3f(-64,-25.0,-47.5);
    glEnd();
    //10
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(64,-10.0,-47.0);
    glVertex3f(64,-40.0,-47.0);
    glVertex3f(58,-40.0,-56.0);
    glVertex3f(58,-10.0,-56.0);
    glEnd();
    //motif
    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(64,-13.0,-47.5);
    glVertex3f(64,-16.0,-47.5);
    glVertex3f(58,-16.0,-56.5);
    glVertex3f(58,-13.0,-56.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(64,-25.0,-47.5);
    glVertex3f(64,-28.0,-47.5);
    glVertex3f(58,-28.0,-56.5);
    glVertex3f(58,-25.0,-56.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-64,-13.0,-47.5);
    glVertex3f(-64,-16.0,-47.5);
    glVertex3f(-58,-16.0,-56.5);
    glVertex3f(-58,-13.0,-56.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-64,-25.0,-47.5);
    glVertex3f(-64,-28.0,-47.5);
    glVertex3f(-58,-28.0,-56.5);
    glVertex3f(-58,-25.0,-56.5);
    glEnd();
    //11
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.74,0.67 );
    glVertex3f(58,-10.0,-56.0);
    glVertex3f(58,-40.0,-56.0);
    glVertex3f(42,-40.0,-61.0);
    glVertex3f(42,-10.0,-61.0);
    glEnd();
    //motif
    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(58,-13.0,-56.5);
    glVertex3f(58,-16.0,-56.5);
    glVertex3f(42,-16.0,-61.5);
    glVertex3f(42,-13.0,-61.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(58,-25.0,-56.5);
    glVertex3f(58,-28.0,-56.5);
    glVertex3f(42,-28.0,-61.5);
    glVertex3f(42,-25.0,-61.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(58,-10.0,-56.5);
    glVertex3f(58,-40.0,-56.5);
    glVertex3f(56,-40.0,-57);
    glVertex3f(56,-10.0,-57);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-58,-10.0,-56.5);
    glVertex3f(-58,-40.0,-56.5);
    glVertex3f(-56,-40.0,-57);
    glVertex3f(-56,-10.0,-57);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-58,-13.0,-56.5);
    glVertex3f(-58,-16.0,-56.5);
    glVertex3f(-42,-16.0,-61.5);
    glVertex3f(-42,-13.0,-61.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1 );
    glVertex3f(-58,-25.0,-56.5);
    glVertex3f(-58,-28.0,-56.5);
    glVertex3f(-42,-28.0,-61.5);
    glVertex3f(-42,-25.0,-61.5);
    glEnd();


    //bonus bawah rumput
    //atas
    //1
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(-42,-39,30.0);
    glVertex3f(-32,-39,10.0);
    glVertex3f(-48,-39,5.0);
    glVertex3f(-58,-39,25.0);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(-58,-39,25.0);
    glVertex3f(-48,-39,5.0);
    glVertex3f(-54,-39,-4.0);
    glVertex3f(-64,-39,16.0);
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(-64,-39,16.0);
    glVertex3f(-54,-39,-4.0);
    glVertex3f(-58,-39,-13.0);
    glVertex3f(-68,-39,7.0);
    glEnd();
    //4
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(-68,-39,7.0);
    glVertex3f(-58,-39,13.0);
    glVertex3f(-60,-39,-18.0);
    glVertex3f(-70,-39,-2.0);
    glEnd();
    //5
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(-70,-39,-2.0);
    glVertex3f(-50,-39,22.0);
    glVertex3f(-61,-39,-31.0);
    glVertex3f(-71,-39,-11.0);
    glEnd();
    //6
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(-71,-39,-11.0);
    glVertex3f(-61,-39,-31.0);
    glVertex3f(-61,-39,0.0);
    glVertex3f(-71,-39,-20.0);
    glEnd();
    //7
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(-71,-39,-20.0);
    glVertex3f(-61,-39,0.0);
    glVertex3f(-60,-39,-9.0);
    glVertex3f(-70,-39,-29.0);
    glEnd();
    //8
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(-70,-39,-29.0);
    glVertex3f(-60,-39,-9.0);
    glVertex3f(-58,-39,-18.0);
    glVertex3f(-68,-39,-38.0);
    glEnd();
    //9
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(-68,-39,-38.0);
    glVertex3f(-58,-39,-18.0);
    glVertex3f(-54,-39,-27.0);
    glVertex3f(-64,-39,-47.0);
    glEnd();
    //10
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(-64,-39,-47.0);
    glVertex3f(-54,-39,-27.0);
    glVertex3f(-48,-39,-36.0);
    glVertex3f(-58,-39,-56.0);
    glEnd();
    //11
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(-58,-39,-56.0);
    glVertex3f(-48,-39,-36.0);
    glVertex3f(-32,-39,-41.0);
    glVertex3f(-42,-39,-61.0);
    glEnd();
    //atas
    //1
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(42,-39,30.0);
    glVertex3f(32,-39,10.0);
    glVertex3f(48,-39,5.0);
    glVertex3f(58,-39,25.0);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(58,-39,25.0);
    glVertex3f(48,-39,5.0);
    glVertex3f(54,-39,-4.0);
    glVertex3f(64,-39,16.0);
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(64,-39,16.0);
    glVertex3f(54,-39,-4.0);
    glVertex3f(58,-39,-13.0);
    glVertex3f(68,-39,7.0);
    glEnd();
    //4
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(68,-39,7.0);
    glVertex3f(58,-39,13.0);
    glVertex3f(60,-39,-18.0);
    glVertex3f(70,-39,-2.0);
    glEnd();
    //5
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(70,-39,-2.0);
    glVertex3f(50,-39,22.0);
    glVertex3f(61,-39,-31.0);
    glVertex3f(71,-39,-11.0);
    glEnd();
    //6
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(71,-39,-11.0);
    glVertex3f(61,-39,-31.0);
    glVertex3f(61,-39,0.0);
    glVertex3f(71,-39,-20.0);
    glEnd();
    //7
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(71,-39,-20.0);
    glVertex3f(61,-39,0.0);
    glVertex3f(60,-39,-9.0);
    glVertex3f(70,-39,-29.0);
    glEnd();
    //8
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(70,-39,-29.0);
    glVertex3f(60,-39,-9.0);
    glVertex3f(58,-39,-18.0);
    glVertex3f(68,-39,-38.0);
    glEnd();
    //9
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(68,-39,-38.0);
    glVertex3f(58,-39,-18.0);
    glVertex3f(54,-39,-27.0);
    glVertex3f(64,-39,-47.0);
    glEnd();
    //10
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(64,-39,-47.0);
    glVertex3f(54,-39,-27.0);
    glVertex3f(48,-39,-36.0);
    glVertex3f(58,-39,-56.0);
    glEnd();
    //11
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(58,-39,-56.0);
    glVertex3f(48,-39,-36.0);
    glVertex3f(32,-39,-41.0);
    glVertex3f(42,-39,-61.0);
    glEnd();
    //tengah
    //atas
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(42,-39,30.0);
    glVertex3f(42,-39,10.0);
    glVertex3f(-42,-39,10.0);
    glVertex3f(-42,-39,30.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(-60,-39,20.0);
    glVertex3f(-60,-39,-50.0);
    glVertex3f(-42,-39,-50.0);
    glVertex3f(-42,-39,20.0);
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(42,-39,-61.0);
    glVertex3f(42,-39,-41.0);
    glVertex3f(-42,-39,-41.0);
    glVertex3f(-42,-39,-61.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,1,0 );
    glVertex3f(60,-39,20.0);
    glVertex3f(60,-39,-50.0);
    glVertex3f(42,-39,-50.0);
    glVertex3f(42,-39,20.0);
    glEnd();

    //bangku atas penonton
    //1
    //tengah
    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5 );
    glVertex3f(42,-10,30.0);
    glVertex3f(42,-25,20.0);
    glVertex3f(-42,-25,20.0);
    glVertex3f(-42,-10,30.0);
    glEnd();

    //bangku atas belakang
    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(42,-10,30.0);
    glVertex3f(42,-23,20.0);
    glVertex3f(15,-23,20.0);
    glVertex3f(15,-10,30.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(12,-10,30.0);
    glVertex3f(12,-23,20.0);
    glVertex3f(-15,-23,20.0);
    glVertex3f(-15,-10,30.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(-17,-10,30.0);
    glVertex3f(-17,-23,20.0);
    glVertex3f(-42,-23,20.0);
    glVertex3f(-42,-10,30.0);
    glEnd();

    //bangku atas depan
    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(42,-10,-61.0);
    glVertex3f(42,-23,-52.3);
    glVertex3f(15,-23,-52.3);
    glVertex3f(15,-10,-61.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(12,-10,-61.0);
    glVertex3f(12,-23,-52.3);
    glVertex3f(-15,-23,-52.3);
    glVertex3f(-15,-10,-61.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(-17,-10,-61.0);
    glVertex3f(-17,-23,-52.3);
    glVertex3f(-42,-23,-52.3);
    glVertex3f(-42,-10,-61.0);
    glEnd();

    //bangku bawah depan
    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(42,-27,-47.0);
    glVertex3f(42,-33,-42.3);
    glVertex3f(15,-33,-42.3);
    glVertex3f(15,-27,-47.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(12,-27,-47.0);
    glVertex3f(12,-33,-42.3);
    glVertex3f(-15,-33,-42.3);
    glVertex3f(-15,-27,-47.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(-17,-27,-47.0);
    glVertex3f(-17,-33,-42.3);
    glVertex3f(-42,-33,-42.3);
    glVertex3f(-42,-27,-47.0);
    glEnd();

    //bangku bawah belakang
    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(42,-35,15.0);
    glVertex3f(42,-29,18.3);
    glVertex3f(15,-29,18.3);
    glVertex3f(15,-35,15.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(12,-35,15.0);
    glVertex3f(12,-29,18.3);
    glVertex3f(-15,-29,18.3);
    glVertex3f(-15,-35,15.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(-17,-35,15.0);
    glVertex3f(-17,-29,18.3);
    glVertex3f(-42,-29,18.3);
    glVertex3f(-42,-35,15.0);
    glEnd();
    //
    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5 );
    glVertex3f(42,-36,15.0);
    glVertex3f(42,-27,20.0);
    glVertex3f(-42,-27,20.0);
    glVertex3f(-42,-36,15.0);
    glEnd();
    //
    glBegin(GL_POLYGON);
    glColor3f(1.5,1,0.5 );
    glVertex3f(42,-27,20.0);
    glVertex3f(42,-25,20.0);
    glVertex3f(-42,-25,20.0);
    glVertex3f(-42,-27,20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.5,1,0.5 );
    glVertex3f(42,-27,20.0);
    glVertex3f(42,-25,20.0);
    glVertex3f(54,-25,15.0);
    glVertex3f(54,-27,15.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.5,1,0.5 );
    glVertex3f(42,-27,-51.0);
    glVertex3f(42,-25,-51.0);
    glVertex3f(54,-25,-41.0);
    glVertex3f(54,-27,-41.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.5,1,0.5 );
    glVertex3f(-42,-27,-51.0);
    glVertex3f(-42,-25,-51.0);
    glVertex3f(-54,-25,-41.0);
    glVertex3f(-54,-27,-41.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.5,1,0.5 );
    glVertex3f(-42,-27,20.0);
    glVertex3f(-42,-25,20.0);
    glVertex3f(-54,-25,15.0);
    glVertex3f(-54,-27,15.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.5,1,0.5 );
    glVertex3f(42,-27,-51.0);
    glVertex3f(42,-25,-51.0);
    glVertex3f(-42,-25,-51.0);
    glVertex3f(-42,-27,-51.0);
    glEnd();
    //
    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5 );
    glVertex3f(42,-10,-61.0);
    glVertex3f(42,-25,-51.0);
    glVertex3f(-42,-25,-51.0);
    glVertex3f(-42,-10,-61.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5 );
    glVertex3f(42,-36,-42.0);
    glVertex3f(42,-27,-51.0);
    glVertex3f(-42,-27,-51.0);
    glVertex3f(-42,-36,-42.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5 );
    glVertex3f(-45,-36,-41.0);
    glVertex3f(-54,-27,-41.0);
    glVertex3f(-42,-27,-51.0);
    glVertex3f(-42,-36,-42.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5 );
    glVertex3f(45,-36,-41.0);
    glVertex3f(54,-27,-41.0);
    glVertex3f(42,-27,-51.0);
    glVertex3f(42,-36,-42.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5 );
    glVertex3f(-54,-36,15.0);
    glVertex3f(-54,-27,15.0);
    glVertex3f(-42,-27,20.0);
    glVertex3f(-42,-36,15.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5 );
    glVertex3f(54,-36,15.0);
    glVertex3f(54,-27,15.0);
    glVertex3f(42,-27,20.0);
    glVertex3f(42,-36,15.0);
    glEnd();


    //sudut kanan
    glBegin(GL_TRIANGLES);
    glColor3f(0.5,1,0.5 );
    glVertex3f(42,-10,30.0);//bawah
    glVertex3f(42,-25,20.0);
    glVertex3f(61,-10,20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5 );
    glVertex3f(54,-25,15.0);
    glVertex3f(64,-10,15.0);
    glVertex3f(61,-10,20.0);
    glVertex3f(42,-25,20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5 );
    glVertex3f(-54,-25,15.0);
    glVertex3f(-64,-10,15.0);
    glVertex3f(-61,-10,20.0);
    glVertex3f(-42,-25,20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5 );
    glVertex3f(64,-10,-41.0);
    glVertex3f(54,-25,-41.0);
    glVertex3f(42,-25,-51.0);
    glVertex3f(61,-10,-51.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5 );
    glVertex3f(-64,-10,-41.0);
    glVertex3f(-54,-25,-41.0);
    glVertex3f(-42,-25,-51.0);
    glVertex3f(-61,-10,-51.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.5,1,0.5 );
    glVertex3f(-42,-10,30.0);//atas
    glVertex3f(-42,-25,20.0);
    glVertex3f(-61,-10,20);
    glEnd();
    //tengah kanan
    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5 );
    glVertex3f(54,-25,15.0);//atas
    glVertex3f(64,-10,15.0);
    glVertex3f(64,-10,-41.0);//bawah
    glVertex3f(54,-25,-41.0);
    glEnd();
    // bangku kanan
    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(62,-11,12.0);//atas
    glVertex3f(54,-22,12.0);
    glVertex3f(54,-22,0.0);//bawah
    glVertex3f(62,-11,0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(62,-11,-2.0);//atas
    glVertex3f(54,-22,-2.0);
    glVertex3f(54,-22,-14.0);//bawah
    glVertex3f(62,-11,-14.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(62,-11,-16.0);//atas
    glVertex3f(54,-22,-16.0);
    glVertex3f(54,-22,-28.0);//bawah
    glVertex3f(62,-11,-28.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(62,-11,-30.0);//atas
    glVertex3f(54,-22,-30.0);
    glVertex3f(54,-22,-40.0);//bawah
    glVertex3f(62,-11,-40.0);
    glEnd();
    //bangku kiri
    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(-62,-11,12.0);//atas
    glVertex3f(-54,-22,12.0);
    glVertex3f(-54,-22,0.0);//bawah
    glVertex3f(-62,-11,0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(-62,-11,-2.0);//atas
    glVertex3f(-54,-22,-2.0);
    glVertex3f(-54,-22,-14.0);//bawah
    glVertex3f(-62,-11,-14.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(-62,-11,-16.0);//atas
    glVertex3f(-54,-22,-16.0);
    glVertex3f(-54,-22,-28.0);//bawah
    glVertex3f(-62,-11,-28.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(-62,-11,-30.0);//atas
    glVertex3f(-54,-22,-30.0);
    glVertex3f(-54,-22,-40.0);//bawah
    glVertex3f(-62,-11,-40.0);
    glEnd();

    //bangku kanan bawah
    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(51,-28,12.0);//atas
    glVertex3f(46,-35,12.0);
    glVertex3f(46,-35,0.0);//bawah
    glVertex3f(51,-28,0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(51,-28,-2.0);//atas
    glVertex3f(46,-35,-2.0);
    glVertex3f(46,-35,-14.0);//bawah
    glVertex3f(51,-28,-14.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(51,-28,-16.0);//atas
    glVertex3f(46,-35,-16.0);
    glVertex3f(46,-35,-28.0);//bawah
    glVertex3f(51,-28,-28.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(51,-28,-30.0);//atas
    glVertex3f(46,-35,-30.0);
    glVertex3f(46,-35,-40.0);//bawah
    glVertex3f(51,-28,-40.0);
    glEnd();

    //bangku kiri bawah
    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(-51,-28,12.0);//atas
    glVertex3f(-46,-35,12.0);
    glVertex3f(-46,-35,0.0);//bawah
    glVertex3f(-51,-28,0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(-51,-28,-2.0);//atas
    glVertex3f(-46,-35,-2.0);
    glVertex3f(-46,-35,-14.0);//bawah
    glVertex3f(-51,-28,-14.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(-51,-28,-16.0);//atas
    glVertex3f(-46,-35,-16.0);
    glVertex3f(-46,-35,-28.0);//bawah
    glVertex3f(-51,-28,-28.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4,0.5 );
    glVertex3f(-51,-28,-30.0);//atas
    glVertex3f(-46,-35,-30.0);
    glVertex3f(-46,-35,-40.0);//bawah
    glVertex3f(-51,-28,-40.0);
    glEnd();
    //
    glBegin(GL_POLYGON);
    glColor3f(1.5,1.5,0.5 );
    glVertex3f(54,-25,15.0);//atas
    glVertex3f(54,-27,15.0);
    glVertex3f(54,-27,-41.0);//bawah
    glVertex3f(54,-25,-41.0);
    glEnd();

    //tengah kiri
    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5 );
    glVertex3f(-54,-25,15.0);//atas
    glVertex3f(-64,-10,15.0);
    glVertex3f(-64,-10,-41.0);//bawah
    glVertex3f(-54,-25,-41.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5 );
    glVertex3f(-45,-36,15.0);//atas
    glVertex3f(-54,-27,15.0);
    glVertex3f(-54,-27,-41.0);//bawah
    glVertex3f(-45,-36,-41.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5,1,0.5 );
    glVertex3f(45,-36,15.0);//atas
    glVertex3f(54,-27,15.0);
    glVertex3f(54,-27,-41.0);//bawah
    glVertex3f(45,-36,-41.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.5,1.5,0.5 );
    glVertex3f(-54,-25,15.0);//atas
    glVertex3f(-54,-27,15.0);
    glVertex3f(-54,-27,-41.0);//bawah
    glVertex3f(-54,-25,-41.0);
    glEnd();
    //sudut kiri
    glBegin(GL_TRIANGLES);
    glColor3f(0.5,1,0.5 );
    glVertex3f(42,-10,-61.0);//bawah
    glVertex3f(42,-25,-51.0);
    glVertex3f(61,-10,-51);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.5,1,0.5 );
    glVertex3f(-42,-10,-61.0);//atas
    glVertex3f(-42,-25,-51.0);
    glVertex3f(-61,-10,-51);
    glEnd();

    //atap tv kanan
    glBegin(GL_TRIANGLES);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(54,-10,-23);
    glVertex3f(54,-3,-23);
    glVertex3f(71,-10,-23);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(54,-10,-5);
    glVertex3f(54,-3,-5);
    glVertex3f(71,-10,-5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(54,-3,-5.0);
    glVertex3f(71,-10,-5.0);
    glVertex3f(71,-10,-23.0);
    glVertex3f(54,-3,-23.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(54,-3,-5.0);
    glVertex3f(54,-10,-5.0);
    glVertex3f(54,-10,-23.0);
    glVertex3f(54,-3,-23.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0 );
    glVertex3f(53.5,-4,-6.0);
    glVertex3f(53.5,-9,-6.0);
    glVertex3f(53.5,-9,-22.0);
    glVertex3f(53.5,-4,-22.0);
    glEnd();

    //atap tv kiri
    glBegin(GL_TRIANGLES);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(-54,-10,-23);
    glVertex3f(-54,-3,-23);
    glVertex3f(-71,-10,-23);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(-54,-10,-5);
    glVertex3f(-54,-3,-5);
    glVertex3f(-71,-10,-5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(-54,-3,-5.0);
    glVertex3f(-71,-10,-5.0);
    glVertex3f(-71,-10,-23.0);
    glVertex3f(-54,-3,-23.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.43,0.43,0.43);
    glVertex3f(-54,-3,-5.0);
    glVertex3f(-54,-10,-5.0);
    glVertex3f(-54,-10,-23.0);
    glVertex3f(-54,-3,-23.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f(-53.5,-4,-6.0);
    glVertex3f(-53.5,-9,-6.0);
    glVertex3f(-53.5,-9,-22.0);
    glVertex3f(-53.5,-4,-22.0);
    glEnd();

    //garis paling bawah
    //tengah kanan
    glBegin(GL_POLYGON);
    glColor3f(1.5,1,0.5 );
    glVertex3f(45,-39,15.0);//atas
    glVertex3f(45,-36,15.0);
    glVertex3f(45,-36,-42.0);//bawah
    glVertex3f(45,-39,-42.0);
    glEnd();
    //tengah kiri
    glBegin(GL_POLYGON);
    glColor3f(1.5,1,0.5 );
    glVertex3f(-45,-39,15.0);//atas
    glVertex3f(-45,-36,15.0);
    glVertex3f(-45,-36,-42.0);//bawah
    glVertex3f(-45,-39,-42.0);
    glEnd();
    //tengah belakang
    glBegin(GL_POLYGON);
    glColor3f(1.5,1,0.5 );
    glVertex3f(45,-39,15.0);//atas
    glVertex3f(45,-36,15.0);
    glVertex3f(-45,-36,15.0);//bawah
    glVertex3f(-45,-39,15.0);
    glEnd();
    //tengah depan
    glBegin(GL_POLYGON);
    glColor3f(1.5,1,0.5 );
    glVertex3f(45,-39,-42.0);//atas
    glVertex3f(45,-36,-42.0);
    glVertex3f(-45,-36,-42.0);//bawah
    glVertex3f(-45,-39,-42.0);
    glEnd();

    //pembatas lapangan
    //tengah depan
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.5,1.2 );
    glVertex3f(44,-39,-37.0);//atas
    glVertex3f(44,-36,-37.0);
    glVertex3f(-44,-36,-37.0);//bawah
    glVertex3f(-44,-39,-37.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7,0.5,1.2 );
    glVertex3f(44,-39,-39.0);//atas
    glVertex3f(44,-36,-39.0);
    glVertex3f(-44,-36,-39.0);//bawah
    glVertex3f(-44,-39,-39.0);
    glEnd();

    glBegin(GL_POLYGON);
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.5,1.2 );
    glVertex3f(44,-36,-39.0);//kiri
    glVertex3f(44,-36,-37.0);
    glVertex3f(-44,-36,-37.0);//kanan
    glVertex3f(-44,-36,-39.0);
    glEnd();
    //tengah belakang
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.5,1.2 );
    glVertex3f(44,-39,10.0);//atas
    glVertex3f(44,-36,10.0);
    glVertex3f(-44,-36,10.0);//bawah
    glVertex3f(-44,-39,10.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7,0.5,1.2 );
    glVertex3f(44,-39,12.0);//atas
    glVertex3f(44,-36,12.0);
    glVertex3f(-44,-36,12.0);//bawah
    glVertex3f(-44,-39,12.0);
    glEnd();

    glBegin(GL_POLYGON);
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.5,1.2 );
    glVertex3f(44,-36,12.0);//kiri
    glVertex3f(44,-36,10.0);
    glVertex3f(-44,-36,10.0);//kanan
    glVertex3f(-44,-36,12.0);
    glEnd();
    //tengah kanan
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.5,1.2 );
    glVertex3f(42,-39,10.0);//atas
    glVertex3f(42,-39,-37.0);
    glVertex3f(42,-36,-37.0);//bawah
    glVertex3f(42,-36,10.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7,0.5,1.2 );
    glVertex3f(44,-39,10.0);//atas
    glVertex3f(44,-39,-37.0);
    glVertex3f(44,-36,-37.0);//bawah
    glVertex3f(44,-36,10.0);
    glEnd();

    glBegin(GL_POLYGON);
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.5,1.2 );
    glVertex3f(42,-36,10.0);//kanan
    glVertex3f(42,-36,-37.0);
    glVertex3f(44,-36,-37.0);//kiri
    glVertex3f(44,-36,10.0);
    glEnd();

    //tengah kiri
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.5,1.2 );
    glVertex3f(-42,-39,10.0);//atas
    glVertex3f(-42,-39,-37.0);
    glVertex3f(-42,-36,-37.0);//bawah
    glVertex3f(-42,-36,10.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7,0.5,1.2 );
    glVertex3f(-44,-39,10.0);//atas
    glVertex3f(-44,-39,-37.0);
    glVertex3f(-44,-36,-37.0);//bawah
    glVertex3f(-44,-36,10.0);
    glEnd();

    glBegin(GL_POLYGON);
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.5,1.2 );
    glVertex3f(-42,-36,10.0);//kiri
    glVertex3f(-42,-36,-37.0);
    glVertex3f(-44,-36,-37.0);//kanan
    glVertex3f(-44,-36,10.0);
    glEnd();

    // tali tali kawat tengah ke kanan

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(0,-10,29);
    glVertex3f(0,-5,27);
    glVertex3f(0,-6,27);
    glVertex3f(0,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(3,-10,29);
    glVertex3f(3,-5,27);
    glVertex3f(3,-6,27);
    glVertex3f(3,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(6,-10,29);
    glVertex3f(6,-5,27);
    glVertex3f(6,-6,27);
    glVertex3f(6,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(9,-10,29);
    glVertex3f(9,-5,27);
    glVertex3f(9,-6,27);
    glVertex3f(9,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(12,-10,29);
    glVertex3f(12,-5,27);
    glVertex3f(12,-6,27);
    glVertex3f(12,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(15,-10,29);
    glVertex3f(15,-5,27);
    glVertex3f(15,-6,27);
    glVertex3f(15,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(18,-10,29);
    glVertex3f(18,-5,27);
    glVertex3f(18,-6,27);
    glVertex3f(18,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(21,-10,29);
    glVertex3f(21,-5,27);
    glVertex3f(21,-6,27);
    glVertex3f(21,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(24,-10,29);
    glVertex3f(24,-5,27);
    glVertex3f(24,-6,27);
    glVertex3f(24,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(27,-10,29);
    glVertex3f(27,-5,27);
    glVertex3f(27,-6,27);
    glVertex3f(27,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(30,-10,29);
    glVertex3f(30,-5,27);
    glVertex3f(30,-6,27);
    glVertex3f(30,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(33,-10,29);
    glVertex3f(33,-5,27);
    glVertex3f(33,-6,27);
    glVertex3f(33,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(36,-10,29);
    glVertex3f(36,-5,27);
    glVertex3f(36,-6,27);
    glVertex3f(36,-8,15);

    // kiri

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-3,-10,29);
    glVertex3f(-3,-5,27);
    glVertex3f(-3,-6,27);
    glVertex3f(-3,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-6,-10,29);
    glVertex3f(-6,-5,27);
    glVertex3f(-6,-6,27);
    glVertex3f(-6,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-9,-10,29);
    glVertex3f(-9,-5,27);
    glVertex3f(-9,-6,27);
    glVertex3f(-9,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-12,-10,29);
    glVertex3f(-12,-5,27);
    glVertex3f(-12,-6,27);
    glVertex3f(-12,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-15,-10,29);
    glVertex3f(-15,-5,27);
    glVertex3f(-15,-6,27);
    glVertex3f(-15,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-18,-10,29);
    glVertex3f(-18,-5,27);
    glVertex3f(-18,-6,27);
    glVertex3f(-18,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-21,-10,29);
    glVertex3f(-21,-5,27);
    glVertex3f(-21,-6,27);
    glVertex3f(-21,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-24,-10,29);
    glVertex3f(-24,-5,27);
    glVertex3f(-24,-6,27);
    glVertex3f(-24,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-27,-10,29);
    glVertex3f(-27,-5,27);
    glVertex3f(-27,-6,27);
    glVertex3f(-27,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-30,-10,29);
    glVertex3f(-30,-5,27);
    glVertex3f(-30,-6,27);
    glVertex3f(-30,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-33,-10,29);
    glVertex3f(-33,-5,27);
    glVertex3f(-33,-6,27);
    glVertex3f(-33,-8,15);

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-36,-10,29);
    glVertex3f(-36,-5,27);
    glVertex3f(-36,-6,27);
    glVertex3f(-36,-8,15);
}

void bola()
{
    glColor3ub(255, 255, 255);
    glutWireSphere(2,100,100);
}

void bulan()
{
    glColor3ub(255, 240, 161);
    glutWireSphere(10,100,100);
}

void atap(void)
{
    float awal [8][3] = {{-60,0,-50},{-50,60,0},{0,-50,50},{60,0,-50},{0,-60,0},{0,0,-50},{-60,0,50},{-50,50,50}};
    float akhir [8][3] = {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    float intermediate [8][2];
    float warna [8][3] = {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};

    static float tween = 0.0 - deltat; //supaya point pertama tepat

    //perulangan untuk menampung nilai tween terbaru

    if(tween<1)
    {
        tween += deltat;
    }

    for(int vtx = 0; vtx<8; vtx++)
    {
        intermediate[vtx][0] = (1.0 - tween)* awal[vtx][0]+ tween*akhir[vtx][0];
        intermediate[vtx][1] = (1.0 - tween)* awal[vtx][1]+ tween*akhir[vtx][1];
    }

    //setting pointer array untuk titik dan warna
    glVertexPointer(3, GL_FLOAT, 0, intermediate);
    glColorPointer(3, GL_FLOAT, 0, warna);

    //perulangan dibuat besar supaya lambat
    for(int i = 0; i<10000000; i++);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_POLYGON,0,8);
    glTranslatef(0,0,-10);
    glutPostRedisplay();
    glLoadIdentity();
}

void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluLookAt(0,0,3,0,0,0,0,1,0);
    glRotatef(xrot,1,0,0);
    glRotatef(yrot,0,1,0);

    if(is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

    //depam
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-60,-50,50);
    glVertex3f(-60,-40,50);
    glVertex3f(60,-40,50);
    glVertex3f(60,-50,50);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-60,-50,-70);
    glVertex3f(-60,-40,-70);
    glVertex3f(60,-40,-70);
    glVertex3f(60,-50,-70);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(60,-40,50);
    glVertex3f(60,-50,50);
    glVertex3f(60,-50,-70);
    glVertex3f(60,-40,-70);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-60,-40,50);
    glVertex3f(-60,-50,50);
    glVertex3f(-60,-50,-70);
    glVertex3f(-60,-40,-70);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-60,-40,50);
    glVertex3f(60,-40,50);
    glVertex3f(60,-40,-70);
    glVertex3f(-60,-40,-70);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-60,-50,50);
    glVertex3f(60,-50,50);
    glVertex3f(60,-50,-70);
    glVertex3f(-60,-50,-70);
    glEnd();

    gawang();

    //tiang lampu
    glPushMatrix();
    glColor3f(0,0.5,0.75);
    glTranslatef(-50.0, 10.0, 30.0);
    glRotatef(90, 45, 0, 0);
    tiang();
    glTranslatef(100,0,0);
    tiang();
    glTranslatef(0,-90,0);
    tiang();
    glTranslatef(-100,0,0);
    tiang();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-50,80,-30);
    bulan();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,-33,-13);
    bola();
    glPopMatrix();

    stadium();
    lampu();
    logo();
    lapangan();
    bendera_corner_kiri_belakang();
    bendera_corner_kanan_belakang();
    bendera_corner_kiri_depan();
    bendera_corner_kanan_depan();
    gerbang();


    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mousedown=true;
        xdiff=x-yrot;
        ydiff=-y+xrot;
	}
	else
	{
        mousedown = false;
	}
}

void mousemotion(int x, int y)
{
    if (mousedown)
    {
		yrot=x-xdiff;
		xrot=y+ydiff;

        glLoadIdentity();
        glPushMatrix();
		glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        //Bergerak Ke Arah Kiri
        case 'g':
        case 'G':
            glTranslatef(-3.0,0.0,0.0);
            break;
        //Bergerak Ke Arah Kanan
        case 'h':
        case 'H':
            glTranslatef(3.0,0.0,0.0);
            break;
        //Bergerak Ke Arah Atas
        case 't':
        case 'T':
            glTranslatef(0.0,3.0,0.0);
            break;
        //Bergerak Ke Arah Bawah
        case 'y':
        case 'Y':
            glTranslatef(0.0,-3.0,0.0);
            break;
        //Bergerak Rotasi Arah dari Atas ke Bawah
        case 'q':
        case 'Q':
            glRotatef(2.0,1.0,0.0,0.0);
            break;
        //Bergerak Rotasi Arah dari Bawah ke Atas
        case 'w':
        case 'W':
            glRotatef(-2.0,1.0,0.0,0.0);
            break;
        //Bergerak Rotasi Arah dari Kanan ke Kiri (Vertikal)
        case 's':
        case 'S':
            glRotatef(2.0,0.0,0.0,1.0);
            break;
        //Bergerak Rotasi Arah dari Kiri ke Kanan (Vertikal)
        case 'a':
        case 'A':
            glRotatef(-2.0,0.0,0.0,1.0);
            break;
        //Bergerak Rotasi Arah dari Kanan ke Kiri (Horizontal)
        case 'x':
        case 'X':
            glRotatef(-2.0,0.0,1.0,0.0);
            break;
        //Bergerak Rotasi Arah dari Kiri ke Kanan (Horizontal)
        case 'z':
        case 'Z':
            glRotatef(2.0,0.0,1.0,0.0);
            break;
        //Membuat Efek Zoom In (Memperbesar Tampilan)
        case 'b':
        case 'B':
            glTranslatef(0.0,0.0,3.0);
            break;
        //Membuat Efek Zoom Out (Memperkecil Tampilan)
        case 'n':
        case 'N':
            glTranslatef(0.0,0.0,-3.0);
            break;
    }
    glPushMatrix();
    tampil();
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(250,100);
    glutCreateWindow("TR GRAFKOM L");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mousemotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
