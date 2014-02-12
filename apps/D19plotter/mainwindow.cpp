#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <QFileDialog>
#include <QThread>

QImage Mat2QImage(int* src, int rows, int cols,double max=10.0)
{
        double scale = 255/max;
        QImage dest(cols, rows, QImage::Format_RGB32);
        for (int y = 0; y < rows; ++y) {
            const int* srcrow = src+y;
                QRgb *destrow = reinterpret_cast<QRgb*>(dest.scanLine(y));
                for (int x = 0; x < cols; ++x) {
                        unsigned int color = (*(srcrow+x*rows)) * scale;
                        if (color>255)
                            color=255;
                        destrow[x] = qRgb(255,255-color,255-color);
                }
        }
        return dest;
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),scene(new QGraphicsScene)
{
    ui->setupUi(this);
    scene->setParent(ui->_dview);
    ui->_dview->setScene(scene);
    ui->_dview->setRenderHint( QPainter::Antialiasing );
    ui->_dview->setDragMode(ui->_dview->ScrollHandDrag);
    ui->progressBar->setVisible(false);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_action_Open_triggered()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::ExistingFile);
    QString fileName;
    fileName= dialog.getOpenFileName(this);
    dialog.close();
    QThread thread;
    thread.start();
    ui->progressBar->setVisible(true);
    ui->progressBar->setTextVisible(true);

    _data.fromFile(fileName.toStdString(),ui->progressBar);
    thread.quit();
    ui->progressBar->setVisible(false);
    ui->horizontalScrollBar->setRange(0,_data._frames.size()-1);
    ui->dial->setRange(1,100);

    int pos=ui->horizontalScrollBar->value();
    QImage image=QImage(Mat2QImage(&((_data._frames[0])[0]),256,640,10));
    ui->dial->setValue(10);
    QPixmap pix=QPixmap::fromImage(image);
    pix=pix.scaled(ui->_dview->width(),ui->_dview->height(),Qt::IgnoreAspectRatio);
    scene->clear();
    scene->addPixmap(pix);
    ui->_dview->setScene(scene);

}



void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
    double max=ui->dial->value();
    QImage image=QImage(Mat2QImage(&((_data._frames[value])[0]),256,640,max));
    QPixmap pix=QPixmap::fromImage(image);
    pix=pix.scaled(ui->_dview->width(),ui->_dview->height(),Qt::IgnoreAspectRatio);
    scene->clear();
    scene->addPixmap(pix);
    ui->_dview->setScene(scene);
}

void MainWindow::on_dial_valueChanged(int value)
{
    int pos=ui->horizontalScrollBar->value();
    QImage image=QImage(Mat2QImage(&((_data._frames[pos])[0]),256,640,value));
    QPixmap pix=QPixmap::fromImage(image);
    pix=pix.scaled(ui->_dview->width(),ui->_dview->height(),Qt::IgnoreAspectRatio);
    scene->clear();
    scene->addPixmap(pix);
    ui->_dview->setScene(scene);
    ui->horizontalScrollBar->setMouseTracking(true);
}
