#include "window.h"
#include <QKeyEvent>
#include <QDebug>


#define ROVIMG_WIDTH 230
#define ROVIMG_HEIGHT 374

// Constructor
Window::Window(QRect screen, QWidget *parent) : QWidget(parent)
{
    //this->setGeometry(0, 0, screen.width(), screen.height());   // -50
    this->setGeometry(0, 0, 1920, 1080);

    // set black background
    QPalette pal = palette();

  	// Set backgroud color
  	pal.setColor(QPalette::Background, QColor(14,14,14,255));
    this->setAutoFillBackground(true);
    this->setPalette(pal);


  	// Show Rover Image at the center of the window
    QLabel *pixlabel = new QLabel(this);
    QPixmap pixrover(":/Images/rover_up-230x374.png");
  	pixlabel->setPixmap(pixrover.scaled(ROVIMG_WIDTH, ROVIMG_HEIGHT, Qt::KeepAspectRatio));
  	pixlabel->setGeometry( (this->width() - ROVIMG_WIDTH) /2, (this->height() - ROVIMG_HEIGHT) /2, ROVIMG_WIDTH, ROVIMG_HEIGHT );


  	// Show Team D.I.A.N.A. logo at bottom-right
  	QLabel *pixlogo = new QLabel(this);
    QPixmap pixmaplogo(":/Images/diana-logo-193x90.png");
  	pixlogo->setPixmap(pixmaplogo.scaled(193, 90, Qt::KeepAspectRatio));
  	pixlogo->setGeometry( this->width() - 238, this->height() - 120, 193, 90 );

    connected = false;

    /*
    // Custom elements
    start_button = new StartButton(this);
    start_button->setGeometry(this->width()/ 2 - 100, this->height() - 100, 200, 100);

    rover = new RoverShow(this);
    rover->setGeometry(300, 0, this->width() - 600, this->height() - 100);

  	batterydisplay = new BatteryDisplay(this);
  	batterydisplay->setGeometry(BAT_DISPLAY_POSX, (this->height() - BAT_DISPLAY_HEIGHT) / 2, BAT_DISPLAY_WIDTH + 2, BAT_DISPLAY_HEIGHT + 2);

  	statusdisplay = new StatusDisplay(this);
  	statusdisplay->setGeometry(STATUS_DISPLAY_POSX, (this->height() - STATUS_DISPLAY_HEIGHT) / 2, STATUS_DISPLAY_WIDTH + 2, STATUS_DISPLAY_HEIGHT + 2);
  */

  	//key_press_event = new KeyPress(this);
  	//key_press_event->show();

}

/*
void Window::keyPressEvent (QKeyEvent *k) {
  	switch ( tolower(k->ascii()) ) {
  	        case 'r':                               // reload
  	            qDebug("Pressed R");
  	            update();
  	            break;
  	        case 'q':                               // quit
  	            QApplication::exit();
  	            break;
  	    }
}
*/
