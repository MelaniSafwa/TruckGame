#include<windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include "Imageloader.h"
#define rad (3.1416/180)
#define EN_SIZE 20

#define checkImageWidth 512
#define checkImageHeight 512

GLuint _textureId1;
GLuint _textureId2;
GLuint _textureId3;
const double PI = 3.141592653589793;
int i,j,radius1,jumlah_titik,x_tengah,y_tengah;

using namespace std;

typedef unsigned short ushort;
typedef unsigned long ulong;
typedef unsigned char uchar;


using namespace std;

float skor = 10;
float zoom=3;
int tola[5000][5000];
float tX=0,tY=0,tZ=0,rX=0,rY=0,rZ=4;
float tZ1=-20,tZ2=-40,tZ3=-60,tZ4=-80,tZ5=-100,tZ6=-120;
float tolZ1=-20,tolZ2=-40,tolZ3=-60,tolZ4=-80,tolZ5=-100,tolZ6=-120;
float rotX=0,rotY=0,rotZ=0;
float cosX=0,cosY=1,cosZ=0;
float angle=0;
float xEye=0.0f,yEye=5.0f,zEye=30.0f;
float cenX=0,cenY=0,cenZ=0,roll=0;
float radius=0;
float theta=0,slope=0;
float speed = 0.5;
float angleBackFrac = 0.2;
bool saheedMinarVisible = false;
float r[] = {0.1,0.4,0.0,0.9,0.2,0.5,0.0,0.7,0.5,0.0};
float g[] = {0.2,0.0,0.4,0.5,0.2,0.0,0.3,0.9,0.0,0.2};
float b[] = {0.4,0.5,0.0,0.7,0.9,0.0,0.1,0.2,0.5,0.0};
int TIME=0;
bool START = false;

// posisi untuk Musuh()
float cubePosX[4] = {2,-3, 4, -1};

bool rot = false;

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 1000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Spion(){
	// kanan
	glPushMatrix();
		glColor3f(0.3, 0.3, 0.3);
		glTranslatef(1.3, 4, 2.5);
		glScalef(0.05, 0.05, 0.6);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.3, 0.3, 0.3);
		glRotated(15, 0, -1, 0);
		glTranslatef(1.95, 4, 2.5);
		glScalef(0.05, 0.8, 0.5);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.4, 0.77, 0.89); // lightblue
		glRotated(15, 0, -1, 0);
		glTranslatef(1.92, 4, 2.5);
		glScalef(0.03, 0.6, 0.3);
		glutSolidCube(1);
	glPopMatrix();

	// kiri
	glPushMatrix();
		glColor3f(0.3, 0.3, 0.3);
		glTranslatef(1.3, 4, -2.5);
		glScalef(0.05, 0.05, 0.6);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.3, 0.3, 0.3);
		glRotated(15, 0, 1, 0);
		glTranslatef(1.95, 4, -2.5);
		glScalef(0.05, 0.8, 0.5);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.4, 0.77, 0.89); // lightblue
		glRotated(15, 0, 1, 0);
		glTranslatef(1.92, 4, -2.5);
		glScalef(0.03, 0.6, 0.3);
		glutSolidCube(1);
	glPopMatrix();

}
	
void Pagar1(){
	// samping kiri
	glPushMatrix();
		glColor3f(0,0.21,0); // ijo gelap
		glTranslatef(-3.5, 4.5, 2.35);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-5.5, 4.5, 2.35);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-7.5, 4.5, 2.35);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-9.5, 4.5, 2.35);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	// samping kanan
	glPushMatrix();
		glTranslatef(-3.5, 4.5, -2.35);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-5.5, 4.5, -2.35);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-7.5, 4.5, -2.35);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-9.5, 4.5, -2.35);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	// depan box
	glPushMatrix();
		glTranslatef(-2.15, 4.5, -1);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.15, 4.5, 1);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	// belakang
	glPushMatrix();
		glTranslatef(-10.85, 4.5, -1);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-10.85, 4.5, 1);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	/* BAGIAN HORISONTAL */
	// samping kanan
	glPushMatrix();
		glTranslatef(-6.5, 3.3, 2.35);
		glScalef(8.9, 0.2, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-6.5, 4.7, 2.35);
		glScalef(8.9, 0.2, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	// samping kiri
	glPushMatrix();
		glTranslatef(-6.5, 3.3, -2.35);
		glScalef(8.9, 0.2, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-6.5, 4.7, -2.35);
		glScalef(8.9, 0.2, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	// depan
	glPushMatrix();
		glTranslatef(-2.15, 3.3, 0);
		glScalef(0.2, 0.2, 4.9);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.15, 4.7, 0);
		glScalef(0.2, 0.2, 4.9);
		glutSolidCube(1);
	glPopMatrix();

	// belakang
	glPushMatrix();
		glTranslatef(-10.85, 3.3, 0);
		glScalef(0.2, 0.2, 4.9);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-10.85, 4.7, 0);
		glScalef(0.2, 0.2, 4.9);
		glutSolidCube(1);
	glPopMatrix();
}

void Pagar(){
	// box 1
	glPushMatrix();
		glColor3f(0,0.2,0); // ijo gelap
		glTranslatef(-2.35, 4.5, 2.15);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0,0.2,0); // ijo gelap
		glTranslatef(-10.65, 4.5, 2.15);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0,0.2,0); // ijo gelap
		glTranslatef(-10.65, 4.5, -2.15);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0,0.2,0); // ijo gelap
		glTranslatef(-2.35, 4.5, -2.15);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();

	// horisontal
	glPushMatrix();
		glTranslatef(-6.5, 7, 2.2);
		glScalef(8.5, 0.1, 0.1);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.3, 7, 0);
		glScalef(0.1, 0.1, 4.5);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-6.5, 7, -2.2);
		glScalef(8.5, 0.1, 0.1);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-10.7, 7, 0);
		glScalef(0.1, 0.1, 4.5);
		glutSolidCube(1);
	glPopMatrix();

	// bagian tengah pagar
	glPushMatrix();
		glTranslatef(-6.5, 6.5, 2.2);
		glScalef(8.5, 0.1, 0.1);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.3, 6.5, 0);
		glScalef(0.1, 0.1, 4.5);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-6.5, 6.5, -2.2);
		glScalef(8.5, 0.1, 0.1);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-10.7, 6.5, 0);
		glScalef(0.1, 0.1, 4.5);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		Pagar1();
	glPopMatrix();
}

void Dekor(){
	// dekor depan (blok garis)
	float cou = 0.17;
	float hei = 2.45;

	glPushMatrix();
		glColor3f(0.3, 0.3, 0.3); // dark gray
		glTranslatef(1.85, hei, 0);
		glScalef(0.3, 0.25, 2.2);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.5, 0.5, 0.5); // light gray
		glTranslatef(1.85, hei-cou, 0);
		glScalef(0.3, 0.1, 2.2);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.3, 0.3, 0.3); // dark gray
		glTranslatef(1.85, hei-cou*2, 0);
		glScalef(0.3, 0.25, 2.4);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.5, 0.5, 0.5); // light gray
		glTranslatef(1.85, hei-cou*3, 0);
		glScalef(0.3, 0.1, 2.4);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.3, 0.3, 0.3); // dark gray
		glTranslatef(1.85, hei-cou*4, 0);
		glScalef(0.3, 0.25, 2.6);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.5, 0.5, 0.5); // light gray
		glTranslatef(1.85, hei-cou*5, 0);
		glScalef(0.3, 0.1, 2.6);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.3, 0.3, 0.3); // dark gray
		glTranslatef(1.85, hei-cou*6, 0);
		glScalef(0.3, 0.25, 2.8);
		glutSolidCube(1);
	glPopMatrix();
}

void Roda(){
	glPushMatrix();
		for(int j=0; j<=360; j=j+5) {
			glColor3f(0.2,0.2,0.2);
			glPushMatrix();
				glTranslatef(1,0,-0.5);
				glRotated(90,1,0,0);
				glRotated(j,0,1,0);
				glTranslatef(0,3,0.8);
				glBegin(GL_QUADS);
				glVertex3f(0,0,0);
				glVertex3f(0.1,0,0);
				glVertex3f(0.1,0.6,0);
				glVertex3f(0,0.6,0);
				glEnd();
			glPopMatrix();
		}
	glPopMatrix();

	// lingkaran depan
	glPushMatrix();
		glTranslatef(0,0,3.1);
		glColor3f(0.2,0.2,0.2);
		glBegin(GL_TRIANGLE_FAN);
		radius=80;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0; i<=360; i++) {
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
		glEnd();
	glPopMatrix();

	// lingkaran belakang
	glPushMatrix();
		glTranslatef(0,0,2.5);
		glRotated(180,1,0,0);
		glColor3f(0.2,0.2,0.2);
		glBegin(GL_TRIANGLE_FAN);
		radius=80;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0; i<=360; i++) {
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
		glEnd();
	glPopMatrix();
}

void Pagar3(){
	// samping kiri
	glPushMatrix();
		glColor3f(0.08,0.18,0.26);
		glTranslatef(-3.5, 4.5, 2.35);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-5.5, 4.5, 2.35);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-7.5, 4.5, 2.35);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-9.5, 4.5, 2.35);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	// samping kanan
	glPushMatrix();
 
		glTranslatef(-3.5, 4.5, -2.35);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
 
		glTranslatef(-5.5, 4.5, -2.35);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
 
		glTranslatef(-7.5, 4.5, -2.35);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
 
		glTranslatef(-9.5, 4.5, -2.35);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	// depan box
	glPushMatrix();
 
		glTranslatef(-2.15, 4.5, -1);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
 
		glTranslatef(-2.15, 4.5, 1);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	// belakang
	glPushMatrix();
 
		glTranslatef(-10.85, 4.5, -1);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
 
		glTranslatef(-10.85, 4.5, 1);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	/* BAGIAN HORISONTAL */
	// samping kanan
	glPushMatrix();
 
		glTranslatef(-6.5, 3.3, 2.35);
		glScalef(8.9, 0.2, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
 
		glTranslatef(-6.5, 4.7, 2.35);
		glScalef(8.9, 0.2, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	// samping kiri
	glPushMatrix();
 
		glTranslatef(-6.5, 3.3, -2.35);
		glScalef(8.9, 0.2, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
 
		glTranslatef(-6.5, 4.7, -2.35);
		glScalef(8.9, 0.2, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	// depan
	glPushMatrix();
 
		glTranslatef(-2.15, 3.3, 0);
		glScalef(0.2, 0.2, 4.9);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
 
		glTranslatef(-2.15, 4.7, 0);
		glScalef(0.2, 0.2, 4.9);
		glutSolidCube(1);
	glPopMatrix();
	
	// belakang
	glPushMatrix();
 
		glTranslatef(-10.85, 3.3, 0);
		glScalef(0.2, 0.2, 4.9);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
 
		glTranslatef(-10.85, 4.7, 0);
		glScalef(0.2, 0.2, 4.9);
		glutSolidCube(1);
	glPopMatrix();
}

void Pagar4(){
	// box 1
	glPushMatrix();
		glColor3f(0.08,0.18,0.26);
		glTranslatef(-2.35, 4.5, 2.15);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
  // ijo gelap
		glTranslatef(-10.65, 4.5, 2.15);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
 // ijo gelap
		glTranslatef(-10.65, 4.5, -2.15);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
  // ijo gelap
		glTranslatef(-2.35, 4.5, -2.15);
		glScalef(0.2, 5, 0.2);
		glutSolidCube(1);
	glPopMatrix();
	
	// horisontal
	glPushMatrix();
		glTranslatef(-6.5, 7, 2.2);
		glScalef(8.5, 0.1, 0.1);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-2.3, 7, 0);
		glScalef(0.1, 0.1, 4.5);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-6.5, 7, -2.2);
		glScalef(8.5, 0.1, 0.1);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-10.7, 7, 0);
		glScalef(0.1, 0.1, 4.5);
		glutSolidCube(1);
	glPopMatrix();
	
	// bagian tengah pagar
	glPushMatrix();
		glTranslatef(-6.5, 6.5, 2.2);
		glScalef(8.5, 0.1, 0.1);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-2.3, 6.5, 0);
		glScalef(0.1, 0.1, 4.5);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-6.5, 6.5, -2.2);
		glScalef(8.5, 0.1, 0.1);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-10.7, 6.5, 0);
		glScalef(0.1, 0.1, 4.5);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		Pagar3();
	glPopMatrix();
}

// Membuat Truck Utama
void truck(){
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;
	glScaled(0.12,0.12,0.12);
	
 	glPushMatrix();
		//depan
		glPushMatrix();
			glTranslatef(0.23,2,0);
			glColor3f(0.08,0.18,0.26);
			glScalef(3.5, 2, 4.5);
			glutSolidCube(1);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(1.39,3.8,0);
			glRotated(30, 0, 0, 1);
			glScalef(0.2, 2, 4.5);
			glutSolidCube(1);
		glPopMatrix();
		
		//atas
		glPushMatrix();
			glTranslatef(-0.27,3.83,0);
			glScalef(2.5, 1.8, 4.5);
			glutSolidCube(1);
		glPopMatrix();
		
		// gandeng 1
		glPushMatrix();
			glColor3f(0.90,0.60,0.00);
			glTranslatef(-6.5,1.5,0);
			glScalef(10, 1, 4.5);
			glutSolidCube(1);
		glPopMatrix();
		
		// box 1
		glPushMatrix();
			glColor3f(1.00,0.67,0.00);
			glTranslatef(-6.5,4,0);
			glScalef(8.5, 4, 4.5);
			glutSolidCube(1);
		glPopMatrix();
		
		// penyambung
		glPushMatrix();
			glColor3f(0.5, 1, 0.0); // lime
			glTranslatef(-12.3,1.5,0);
			glScalef(2, 0.2, 0.6);
			glutSolidCube(1);
		glPopMatrix();
		
		// gandeng 2
		glPushMatrix();
			glColor3f(0.90,0.60,0.00);
			glTranslatef(-17.8,1.5,0);
			glScalef(10, 1, 4.5);
			glutSolidCube(1);
		glPopMatrix();
		
		// box 2
		glPushMatrix();
			glColor3f(1.00,0.67,0.00);
			glTranslatef(-17.8, 4, 0);
			glScalef(8.5, 4, 4.5);
			glutSolidCube(1);
		glPopMatrix();
		
		//hiasan samping box
		glPushMatrix();
			glColor3f(0.19,0.23,0.37); 
			glTranslatef(-17.8, 4, 0);
			glScalef(8, 3.5, 4.7);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.19,0.23,0.37); 
			glTranslatef(-6.5, 4, 0);
			glScalef(8, 3.5, 4.7);
			glutSolidCube(1);
		glPopMatrix();
		
		glPushMatrix();
			glColor3f(0.19,0.23,0.37); 
			glTranslatef(-6.5, 4.7, 0);
			glScalef(7, 3.2, 4);
			glutSolidCube(1);
		glPopMatrix();
		
		glPushMatrix();
			glColor3f(0.19,0.23,0.37); 
			glTranslatef(-17.8, 4.7, 0);
			glScalef(7, 3.2, 4);
			glutSolidCube(1);
		glPopMatrix();
		
		glPushMatrix();
			glColor3f(0.90,0.60,0.00);
			glTranslatef(-17.8, 4.8, 0);
			glScalef(4, 3.2, 2);
			glutSolidCube(1);
		glPopMatrix();
		
		glPushMatrix();
			glColor3f(0.90,0.60,0.00);
			glTranslatef(-6.5, 4.8, 0);
			glScalef(4, 3.2, 2);
			glutSolidCube(1);
		glPopMatrix();
		
		glPushMatrix();
			glColor3f(0, 0, 0);
			glTranslatef(-17.8, 4.82, 0);
			glScalef(1, 3.2, 0.2);
			glutSolidCube(1);
		glPopMatrix();
		
		glPushMatrix();
			glColor3f(0, 0, 0);
			glTranslatef(-6.5, 4.82, 0);
			glScalef(1, 3.2, 0.2);
			glutSolidCube(1);
		glPopMatrix();
				
		//tulisan
		glPushMatrix();
			glColor3f(1.00,0.67,0.00);
			glTranslatef(-21.67, 4.0, -1.3);
			glScalef(1.1, 3.1, 0.5);
			glutSolidCube(1);
		glPopMatrix();
		
		glPushMatrix();
			glColor3f(1.00,0.67,0.00);
			glTranslatef(-21.669, 5.25, -0.5);
			glScalef(1.1, 0.5, 1);
			glutSolidCube(1);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-21.67, 4.0, 0.02);
			glScalef(1.1, 3.1, 0.5);
			glutSolidCube(1);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-21.669, 2.7, -0.5);
			glScalef(1.1, 0.5, 1);
			glutSolidCube(1);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-21.67, 4.0, 1.3);
			glScalef(1.1, 3.1, 0.5);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.19,0.23,0.37);  
			glTranslatef(-21.668, 4.0, 0.0);
			glScalef(1.1, 3.5, 4.0);
			glutSolidCube(1);
		glPopMatrix();
		
		//samping
		glPushMatrix();
			glColor3f(1.00,0.67,0.00);
			glTranslatef(-17.8, 4, 0);
			glRotatef(25,0,0,1);
			glScalef(5, 0.5, 4.71);
			glutSolidCube(1);
		glPopMatrix();
		
		glPushMatrix();
			glColor3f(1.00,0.67,0.00);
			glTranslatef(-6.5, 4, 0);
			glRotatef(335,0,0,1);
			glScalef(5, 0.5, 4.71);
			glutSolidCube(1);
		glPopMatrix();
		
		//pagar
		glPushMatrix();
			Pagar4();
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-11.3, 0, 0);
			Pagar4();
		glPopMatrix();
		
		// roda depan
		glPushMatrix();
			glTranslatef(-1, 0.8, -0.8);
			Roda();
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-1, 0.8, -4.8);
			Roda();
		glPopMatrix();
		
		// tengah
		glPushMatrix();
			glTranslatef(-10, 0.8, -0.8);
			Roda();
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-10, 0.8, -4.8);
			Roda();
		glPopMatrix();
		
		// belakang 1
		glPushMatrix();
			glTranslatef(-16, 0.8, -0.8);
			Roda();
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-16, 0.8, -4.8);
			Roda();
		glPopMatrix();
		
		// belakang 2
		glPushMatrix();
			glTranslatef(-22, 0.8, -0.8);
			Roda();
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-22, 0.8, -4.8);
			Roda();
		glPopMatrix();
		
		// kaca depan
		float k = 1.85;
		float l = 3.25;
		float m = 2;
		
		glColor3f(0.4, 0.77, 0.89); // lightblue
		glBegin(GL_QUADS);
			glVertex3f(k-0.69, l+1.2, m);
			glVertex3f(k-0.69, l+1.2, m-4);
			glVertex3f(k, l, m-4);
			glVertex3f(k, l, m);
		glEnd();
		
		// kaca samping kanan
		float a1 = 0.92;
		float b = 3;
		float c = 2.26;
		glBegin(GL_QUADS);
			glVertex3f(a1-2.1, b, c);
			glVertex3f(a1-2.1, b+1.4, c);
			glVertex3f(a1, b+1.4, c);
			glVertex3f(a1, b, c);
		glEnd();
		glBegin(GL_TRIANGLES);
			glVertex3f(a1, b, c);
			glVertex3f(a1, b+1.4, c);
			glVertex3f(a1+0.85, b, c);
		glEnd();
		
		// kaca samping kiri
		float xn = 4.52;
		glBegin(GL_QUADS);
			glVertex3f(a1-2.1, b, c-xn);
			glVertex3f(a1-2.1, b+1.4, c-xn);
			glVertex3f(a1, b+1.4, c-xn);
			glVertex3f(a1, b, c-xn);
		glEnd();
		glBegin(GL_TRIANGLES);
			glVertex3f(a1, b, c-xn);
			glVertex3f(a1, b+1.4, c-xn);
			glVertex3f(a1+0.85, b, c-xn);
		glEnd();
		
		// rating kiri
		glPushMatrix();
			glColor3f(0.96, 0.745, 0); // kuning
			glTranslatef(1.88, 2.3, -2.02);
			glScalef(0.25, 0.6, 0.5);
			glutSolidCube(1);
		glPopMatrix();
		
		// rating kanan
		glPushMatrix();
			glTranslatef(1.88, 2.3, 2.02);
			glScalef(0.25, 0.6, 0.5);
			glutSolidCube(1);
		glPopMatrix();
		
		// lampu kiri
		glPushMatrix();
			glColor3f(1, 1, 1); // kuning
			glTranslatef(1.88, 2.3, -1.5);
			glScalef(0.25, 0.6, 0.5);
			glutSolidCube(1);
		glPopMatrix();
		
		// lampu kanan
		glPushMatrix();
			glColor3f(1, 1, 1); // kuning
			glTranslatef(1.88, 2.3, 1.5);
			glScalef(0.25, 0.6, 0.5);
			glutSolidCube(1);
		glPopMatrix();
		
		Dekor();
		
		// bagian belakang
		// rem kanan
		glPushMatrix();
			glColor3f(0.54, 0, 0);
			glTranslatef(-22.8, 1.5, 1.5);
			glScalef(0.1, 0.5, 0.5);
			glutSolidCube(1);
		glPopMatrix();
		
		// rating kanan
		glPushMatrix();
			glColor3f(0.96, 0.745, 0); // kuning
			glTranslatef(-22.8, 1.5, 2);
			glScalef(0.1, 0.5, 0.5);
			glutSolidCube(1);
		glPopMatrix();
		
		// rem kiri
		glPushMatrix();
			glColor3f(0.54, 0, 0);
			glTranslatef(-22.8, 1.5, -1.5);
			glScalef(0.1, 0.5, 0.5);
			glutSolidCube(1);
		glPopMatrix();
		
		// rating kiri
		glPushMatrix();
			glColor3f(0.96, 0.745, 0); // kuning
			glTranslatef(-22.8, 1.5, -2);
			glScalef(0.1, 0.5, 0.5);
			glutSolidCube(1);
		glPopMatrix();
		
		Spion();
	glPopMatrix();

}

// Membuat Truck Musuh
void reverseTruck(){
	glRotated(270, 0, 1, 0);
	const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;
	glScaled(0.12,0.12,0.12);
	
 	glPushMatrix();
		//depan
		glPushMatrix();
			glTranslatef(0.23,2,0);
			glColor3f(0.216, 0.835, 0.361);
			glScalef(3.5, 2, 4.5);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.39,3.8,0);
			glRotated(30, 0, 0, 1);
			glScalef(0.2, 2, 4.5);
			glutSolidCube(1);
		glPopMatrix();

		//atas
		glPushMatrix();
			glTranslatef(-0.27,3.83,0);
			glScalef(2.5, 1.8, 4.5);
			glutSolidCube(1);
		glPopMatrix();

		// gandeng 1
		glPushMatrix();
			glColor3f(0.6, 0.3, 0.2);
			glTranslatef(-6.5,1.5,0);
			glScalef(10, 1, 4.5);
			glutSolidCube(1);
		glPopMatrix();

		// box 1
		glPushMatrix();
			glColor3f(0,0.2,0);
			glTranslatef(-6.5,4,0);
			glScalef(8.5, 4, 4.5);
			glutSolidCube(1);
		glPopMatrix();

		// penyambung
		glPushMatrix();
			glColor3f(0.5, 1, 0.0); // lime
			glTranslatef(-12.3,1.5,0);
			glScalef(2, 0.2, 0.6);
			glutSolidCube(1);
		glPopMatrix();

		// gandeng 2
		glPushMatrix();
			glColor3f(0.6, 0.3, 0.2);
			glTranslatef(-17.8,1.5,0);
			glScalef(10, 1, 4.5);
			glutSolidCube(1);
		glPopMatrix();

		// box 2
		glPushMatrix();
			glColor3f(0,0.2,0);
			glTranslatef(-17.8, 4, 0);
			glScalef(8.5, 4, 4.5);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			Pagar();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-11.3, 0, 0);
			Pagar();
		glPopMatrix();

		// roda depan
		glPushMatrix();
			glTranslatef(-1, 0.8, -0.8);
			Roda();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-1, 0.8, -4.8);
			Roda();
		glPopMatrix();

		// tengah
		glPushMatrix();
			glTranslatef(-10, 0.8, -0.8);
			Roda();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-10, 0.8, -4.8);
			Roda();
		glPopMatrix();

		// belakang 1
		glPushMatrix();
			glTranslatef(-16, 0.8, -0.8);
			Roda();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-16, 0.8, -4.8);
			Roda();
		glPopMatrix();

		// belakang 2
		glPushMatrix();
			glTranslatef(-22, 0.8, -0.8);
			Roda();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-22, 0.8, -4.8);
			Roda();
		glPopMatrix();

		// kaca depan
		float k = 1.85;
		float l = 3.25;
		float m = 2;

		glColor3f(0.4, 0.77, 0.89); // lightblue
		glBegin(GL_QUADS);
			glVertex3f(k-0.69, l+1.2, m);
			glVertex3f(k-0.69, l+1.2, m-4);
			glVertex3f(k, l, m-4);
			glVertex3f(k, l, m);
		glEnd();

		// kaca samping kanan
		float a1 = 0.92;
		float b = 3;
		float c = 2.26;
		glBegin(GL_QUADS);
			glVertex3f(a1-2.1, b, c);
			glVertex3f(a1-2.1, b+1.4, c);
			glVertex3f(a1, b+1.4, c);
			glVertex3f(a1, b, c);
		glEnd();
		glBegin(GL_TRIANGLES);
			glVertex3f(a1, b, c);
			glVertex3f(a1, b+1.4, c);
			glVertex3f(a1+0.85, b, c);
		glEnd();

		// kaca samping kiri
		float xn = 4.52;
		glBegin(GL_QUADS);
			glVertex3f(a1-2.1, b, c-xn);
			glVertex3f(a1-2.1, b+1.4, c-xn);
			glVertex3f(a1, b+1.4, c-xn);
			glVertex3f(a1, b, c-xn);
		glEnd();
		glBegin(GL_TRIANGLES);
			glVertex3f(a1, b, c-xn);
			glVertex3f(a1, b+1.4, c-xn);
			glVertex3f(a1+0.85, b, c-xn);
		glEnd();

		// rating kiri
		glPushMatrix();
			glColor3f(0.96, 0.745, 0); // kuning
			glTranslatef(1.88, 2.3, -2.02);
			glScalef(0.25, 0.6, 0.5);
			glutSolidCube(1);
		glPopMatrix();

		// rating kanan
		glPushMatrix();
			glTranslatef(1.88, 2.3, 2.02);
			glScalef(0.25, 0.6, 0.5);
			glutSolidCube(1);
		glPopMatrix();

		// lampu kiri
		glPushMatrix();
			glColor3f(1, 1, 1); // kuning
			glTranslatef(1.88, 2.3, -1.5);
			glScalef(0.25, 0.6, 0.5);
			glutSolidCube(1);
		glPopMatrix();

		// lampu kanan
		glPushMatrix();
			glColor3f(1, 1, 1); // kuning
			glTranslatef(1.88, 2.3, 1.5);
			glScalef(0.25, 0.6, 0.5);
			glutSolidCube(1);
		glPopMatrix();

		Dekor();

		// bagian belakang
		// rem kanan
		glPushMatrix();
			glColor3f(0.54, 0, 0);
			glTranslatef(-22.8, 1.5, 1.5);
			glScalef(0.1, 0.5, 0.5);
			glutSolidCube(1);
		glPopMatrix();

		// rating kanan
		glPushMatrix();
			glColor3f(0.96, 0.745, 0); // kuning
			glTranslatef(-22.8, 1.5, 2);
			glScalef(0.1, 0.5, 0.5);
			glutSolidCube(1);
		glPopMatrix();

		// rem kiri
		glPushMatrix();
			glColor3f(0.54, 0, 0);
			glTranslatef(-22.8, 1.5, -1.5);
			glScalef(0.1, 0.5, 0.5);
			glutSolidCube(1);
		glPopMatrix();

		// rating kiri
		glPushMatrix();
			glColor3f(0.96, 0.745, 0); // kuning
			glTranslatef(-22.8, 1.5, -2);
			glScalef(0.1, 0.5, 0.5);
			glutSolidCube(1);
		glPopMatrix();

		Spion();
	glPopMatrix();
}

// Program Untuk menjalankan truck musuh
void Musuh(int x, float *z){

	glPushMatrix();
        // Truck Musuh
        glTranslated(cubePosX[x],0.5,*z);
		reverseTruck();

        glTranslated(2.5, 0.45, 0);
    glPopMatrix();
    if (cubePosX[x]+tX > -0.5 && cubePosX[x]+tX<0.5){ // Jika truk menabrak
        if (*z>0 && *z<1){
            skor = 10;
            START=false;
        }
    }
    *z += speed;
    if (*z>20){
        *z = -110;
    }
}

// Untuk Load Texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 
	0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}

// Untuk merender gambar
void initRendering() { 
	Image* image1 = loadBMP("rumput.bmp");
	Image* image2 = loadBMP("pasirkb.bmp");
	Image* image3 = loadBMP("kayu.bmp");
	_textureId1 = loadTexture(image1);
	_textureId2 = loadTexture(image2);
	_textureId3 = loadTexture(image3);
}

// Jalan
void road(){
	glPushMatrix();
	    glColor3d(1.0,1.0,1.0);
		glTranslated(0, 0.199, 0);
		glPushMatrix();	
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, _textureId1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // GL_LINEAR
		 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
	
			glBegin(GL_QUADS);
				glNormal3f(0.0, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-100, 0, -10);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-100, 0, 10);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-6, 0, 10);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-6, 0, -10);
			glEnd();
			glDisable(GL_TEXTURE_2D);
	    glPopMatrix();
	
		glPushMatrix();	
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, _textureId2);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // GL_LINEAR GL_NEAREST
		 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 
		
			glBegin(GL_QUADS);
				glNormal3f(0.0, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-6, 0, -10);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-6, 0, 10);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(6, 0, 10);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(6, 0, -10);
			glEnd();
			glDisable(GL_TEXTURE_2D);
	    glPopMatrix();
	
		glPushMatrix();	
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, _textureId1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // GL_LINEAR
		 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
	
			glBegin(GL_QUADS);
				glNormal3f(0.0, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(100, 0, 10);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(100, 0, -10);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(6, 0, -10);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(6, 0, 10);
			glEnd();
			glDisable(GL_TEXTURE_2D);
	    glPopMatrix();
    glPopMatrix();
}

// Pohon sebelah kanan
void rightTree(){
	glPushMatrix();
		glColor3f(0.7, 0.5, 0.2);
		glTranslated(5,0,10);
		glScalef(0.03,0.03,0.03);
		
		//Batang
		glPushMatrix();
			glScalef(2, 40, 2);
			glTranslatef(0,0.7,1);
			glutSolidSphere(1.0, 20, 16);
		glPopMatrix();
		
		//Daun
		glColor3f(0.2, 0.5, 0.2);
		glPushMatrix();
			glScalef(2, 2, 2);
			glTranslatef(0,20,1);
			glRotatef(270, 1, 0, 0);
			glutSolidCone(10, 30, 20, 1);
		glPopMatrix();
		glPushMatrix();
			glScalef(2, 2, 2);
			glTranslatef(0,30,1);
			glRotatef(270, 1, 0, 0);
			glutSolidCone(10, 30, 20, 1);
		glPopMatrix();
		glPushMatrix();
			glScalef(2, 2, 2);
			glTranslatef(0,40,1);
			glRotatef(270, 1, 0, 0);
			glutSolidCone(10, 30, 20, 1);
		glPopMatrix();
	glPopMatrix();
}

// Pohon sebelah kiri
void leftTree(){
	glPushMatrix();
		glColor3f(0.7, 0.5, 0.2);
		glTranslated(-11,0,0);
		glScalef(0.03,0.03,0.03);
		
		//Batang
		glPushMatrix();
			glScalef(2, 40, 2);
			glTranslatef(0,0.7,1);
			glutSolidSphere(1.0, 20, 16);
		glPopMatrix();
		
		//Daun
		glColor3f(0.2, 0.5, 0.2);
		glPushMatrix();
			glScalef(2, 2, 2);
			glTranslatef(0,20,1);
			glRotatef(270, 1, 0, 0);
			glutSolidCone(10, 30, 20, 1);
		glPopMatrix();
		glPushMatrix();
			glScalef(2, 2, 2);
			glTranslatef(0,30,1);
			glRotatef(270, 1, 0, 0);
			glutSolidCone(10, 30, 20, 1);
		glPopMatrix();
		glPushMatrix();
			glScalef(2, 2, 2);
			glTranslatef(0,40,1);
			glRotatef(270, 1, 0, 0);
			glutSolidCone(10, 30, 20, 1);
		glPopMatrix();
	glPopMatrix();
}

// Rumah sebelah kanan
void rightHouse(){
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureId3);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // GL_LINEAR
	 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
		glBegin(GL_QUADS);
			glColor3f(1.0, 1.0, 1.0);
			glTexCoord2f(0.0f, 0.5f);
			glVertex3f(5, 0, -3);
			glTexCoord2f(0.5f, 0.5f);
			glVertex3f(5, 0, 3);
			glTexCoord2f(0.5f, 0.0f);
			glVertex3f(5, 2, 3);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(5, 2, -3);
		glEnd();
		
		// pintu
		glBegin(GL_QUADS);
			glColor3f(1.0, 1.0, 1.0);
			glVertex3f(4.99, 0, -1);
			glVertex3f(4.99, 0, 1);
			glVertex3f(4.99, 1.5, 1);
			glVertex3f(4.99, 1.5, -1);
		glEnd();
		
		glBegin(GL_QUADS);
			glNormal3f(0.0, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.5f);
			glVertex3f(5, 0, 3);
			glTexCoord2f(0.5f, 0.5f);
			glVertex3f(8, 0, 3);
			glTexCoord2f(0.5f, 0.0f);
			glVertex3f(8, 2, 3);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(5, 2, 3);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		// depan
		glPushMatrix();
			glColor3f(0.1553, 0.103, 0.0507);
			glBegin(GL_TRIANGLES);
				glVertex3f(6.5, 4, 0);
				glVertex3f(4.7, 2, 3.3);
				glVertex3f(8.3, 2, 3.3);
			glEnd();
			
			//kiri
			glBegin(GL_TRIANGLES);
				glVertex3f(6.5, 4, 0);
				glVertex3f(4.7, 2, -3.3);
				glVertex3f(4.7, 2, 3.3);
			glEnd();
		glPopMatrix();
		
		// gagang pintu
		glBegin(GL_QUADS);
			glColor3f(0.0, 0.0, 0.0);
			glVertex3f(4.98, 0.7, -0.8);
			glVertex3f(4.98, 0.7, -0.5);
			glVertex3f(4.98, 0.75, -0.5);
			glVertex3f(4.98, 0.75, -0.8);
		glEnd();
	glPopMatrix();
}

// Rumah sebelah kiri
void leftHouse(){
	glPushMatrix();
		glTranslated(-19,0,10);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureId3);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // GL_LINEAR
	 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
		
		glBegin(GL_QUADS);
			glColor3f(1.0, 1.0, 1.0);
			glNormal3f(0.0, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.5f);
			glVertex3f(5, 0, 3);
			glTexCoord2f(0.5f, 0.5f);
			glVertex3f(8, 0, 3);
			glTexCoord2f(0.5f, 0.0f);
			glVertex3f(8, 2, 3);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(5, 2, 3);
		glEnd();
		
		// pintu
		glBegin(GL_QUADS);
			glColor3f(1.0, 1.0, 1.0);
			glVertex3f(8.01, 0, -1);
			glVertex3f(8.01, 1.5, -1);
			glVertex3f(8.01, 1.5, 1);
			glVertex3f(8.01, 0, 1);
		glEnd();
		
		glBegin(GL_QUADS);
			glColor3f(1.0, 1.0, 1.0);
			glTexCoord2f(0.0f, 0.5f);
			glVertex3f(8, 0, 3);
			glTexCoord2f(0.5f, 0.5f);
			glVertex3f(8, 0, -3);
			glTexCoord2f(0.5f, 0.0f);
			glVertex3f(8, 2, -3);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(8, 2, 3);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		// depan
		glColor3f(0.1553, 0.103, 0.0507);
		glBegin(GL_TRIANGLES);
			glVertex3f(6.5, 4, 0);
			glVertex3f(4.7, 2, 3.3);
			glVertex3f(8.3, 2, 3.3);
		glEnd();
		
		//kiri
		glBegin(GL_TRIANGLES);
			glVertex3f(6.5, 4, 0);
			glVertex3f(8.3, 2, 3.3);
			glVertex3f(8.3, 2, -3.3);
		glEnd();
		
		glBegin(GL_QUADS);
			glColor3f(0.0, 0.0, 0.0);
			glVertex3f(8.02, 0.7, -0.8);
			glVertex3f(8.02, 0.75, -0.8);
			glVertex3f(8.02, 0.75, -0.5);
			glVertex3f(8.02, 0.7, -0.5);
		glEnd();
	glPopMatrix();
}

// Latar perbagian
void environment(){
    // Jalan road
    road();
	
	// Pohon kanan
	glTranslated(3,0,0);
	rightTree();
	
	// rumah kanan
	rightHouse();

	// Pohon kiri
	leftTree();
	
	// rumah kiri
	leftHouse();
}

// Menyatukan semua objek
void draw(){
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;

    TIME = t;
	skor -= 0.001;
	if(skor <= 0){
		START = false;
	}

    ///truck
    glPushMatrix();
        glTranslated(0,1,0);
        glRotated(90,0,1,0);
        glScaled(0.6,0.6,0.6);
        truck();
    glPopMatrix();
    
	
    //Environment
    if(tX>=5.2)tX=5.2;
    if(tX<=-5.2)tX=-5.2;
    if(tY>0.1)tY= 0.1;
    if(tY<-15)tY= -15;

	// Memanggil Truck Musuh
    glPushMatrix();
        glTranslated(tX,tY,tZ);
        environment();
    glPopMatrix();
    
    glPushMatrix();
        glTranslated(tX,0,0);
        Musuh(1, &tolZ1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ1);
        environment();
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ2);
        environment();
    glPopMatrix();
    glPushMatrix();
        glTranslated(tX,0,0);
        Musuh(3, &tolZ2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ3);
        environment();
    glPopMatrix();
    glPushMatrix();
        glTranslated(tX,0,0);
        Musuh(1, &tolZ3);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ4);
        environment();
    glPopMatrix();
    glPushMatrix();
        glTranslated(tX,0,0);
        Musuh(0, &tolZ4);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ5);
        environment();
	glPopMatrix();
	glPushMatrix();
	    glTranslated(tX,0,0);
	    Musuh(1, &tolZ5);
	glPopMatrix();
	
	glPushMatrix();
	    glTranslated(tX,tY,tZ6);
	    environment();
	glPopMatrix();
	glPushMatrix();
	    glTranslated(tX,0,0);
	    Musuh(2, &tolZ6);
	glPopMatrix();
	
	tZ+=speed;
  	tZ1+=speed;
  	tZ2+=speed;
  	tZ3+=speed;
  	tZ4+=speed;
  	tZ5+=speed;
  	tZ6+=speed;

    if(tZ>=20)
		tZ=-120;
    if(tZ1>=20)
		tZ1=-120;
    if(tZ2>=20)
		tZ2=-120;
    if(tZ3>=20)
		tZ3=-120;
    if(tZ4>=20)
		tZ4=-120;
    if(tZ5>=20)
		tZ5=-120;
    if(tZ6>=20)
		tZ6=-120;
}

void drawBitmapText(char *str,float x,float y,float z)
{
	char *c;
	glRasterPos3f(x,y+8,z);

	for (c=str; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
	}
}

void drawStrokeText(char* str,int x,int y,int z)
{
	char *c;
	glPushMatrix();
		glTranslatef(x-1, y+8,z);
		glScalef(0.004f,0.004f,z);
	
		for (c=str; *c != '\0'; c++)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
		}
	glPopMatrix();
}

void drawStrokeText2(char* str,int x,int y,int z)
{
	  char *c;
	  glPushMatrix();
	  glTranslatef(x-0.5, y+8,z);
	  glScalef(0.0065f,0.0065f,z);

	  for (c=str; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();
}

void drawStrokeText3(char* str,int x,int y,int z)
{
	char *c;
	glPushMatrix();
		glTranslatef(x, y+8,z);
		glScalef(0.002f,0.002f,z);

	  	for (c=str; *c != '\0'; c++)
	  	{
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  	}
	glPopMatrix();
}

void drawStrokeChar(char c,float x,float y,float z)
{
	glPushMatrix();
    	glTranslatef(x, y+8,z);
    	glScalef(0.002f,0.002f,z);
        glutStrokeCharacter(GLUT_STROKE_ROMAN , c);
	glPopMatrix();
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*80.0;
    double aa=a;

    if(!rot){
        a=0;
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(	0.0, 4.5, 9.0,
                0, 4, 0,
                0, 1.0f, 0.0f);

    if(START){    	
		glPushMatrix();
            glTranslated(0,0,-1);
            glScaled(zoom,zoom,zoom);
            glRotated(a,0,1,0);
            glRotated(10,1,0,0);
			draw();
        glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 9, -2);
			glRotated(60, 1, 0, 0);
			glColor3f(1,0.5,0);
			glScalef(25, 0.001, 1.5);
			glutSolidCube(1);
		glPopMatrix();
		
		drawStrokeText3("LEFT: A, RIGHT: D, MAIN MENU: M",-8,0.9,0);
        
        // menampilkan jarak
        char skor2[100];
        int skor3 = sprintf(skor2, "JARAK:  %f", skor);
        drawStrokeText3(skor2, 3, 0, 0);
    }
    else{
        glPushMatrix();
            glTranslated(0,3,0);
            glRotated(aa,0,1,0);
            glScaled(2,2,2);
            truck();
        glPopMatrix();

        drawStrokeText("Press G to Start",-1,-2,0);
        drawStrokeText2("TRUCK GAME",-2,-1,0);
    }
    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    float frac = 0.4; // geser truk
    float rotFrac = 1;
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
        case 'a':
            tX+=frac;
            break;
        case 'd':
            tX-=frac;
            break;
        case 'g':
            START=true;
            break;
        case 'm':
            START=false;
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.1f, 0.1f, 0.1f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);
	glutInitWindowSize(1366,720);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

    glutCreateWindow("TUBES TRUCK");
	initRendering();
 	PlaySound(TEXT("Training.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
	
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0.8,0.8,1.0,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}

