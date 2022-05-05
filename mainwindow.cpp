#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


    QStringList listItems1 = QStringList() << "bsfsa" << "aasd"<<"8as" << "lasd" <<"0"<< "dalkd" << "eeoo"<<"1232"<<"114";
    QStringList listItems2 = QStringList() << "asfsaasdv" << "baasdvsd" <<"129"<< "dasavdsd" << "lasavdlkd" << "eesaoepo"<<"541123"<<"73";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->listWidget1->addItems(listItems1);
    ui->listWidget2->addItems(listItems2);
    //this->setLayout(gridLayout);
    ui->listWidget2->setFocusPolicy(Qt::NoFocus);
    ui->listWidget1->setFocusPolicy(Qt::NoFocus);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton2_1_clicked()
{
     static Qt::SortOrder ascOrder = Qt::AscendingOrder;
     ui->listWidget1->sortItems(ascOrder);
}


void MainWindow::on_pushButton2_2_clicked()
{
    static Qt::SortOrder descOrder = Qt::DescendingOrder;
    ui->listWidget2->sortItems(descOrder);
}


void MainWindow::on_pushButton1_1_clicked()
{
    if(ui->listWidget1->count()==0)
    {
        QMessageBox::information(this,tr("Ошибка"),tr("Список пуст"));
        return;
    }
    QListWidgetItem *item = ui->listWidget1->item(ui->listWidget1->currentRow());
    if (!item) {
     QMessageBox::information(this,tr("Ошибка"),tr("Не выбран элемент в списке"));
     return;
    }


    ui->listWidget1->takeItem (ui->listWidget1->currentRow());
    ui->listWidget2->addItem(item);
    ui->listWidget1->setCurrentRow(-1);
    ui->listWidget1->setSelectionMode(QAbstractItemView::ExtendedSelection);

}


void MainWindow::on_pushButton1_2_clicked()
{
    if(ui->listWidget2->count()==0)
    {
        QMessageBox::information(this,tr("Ошибка"),tr("Список пуст"));
        return;
    }

    QListWidgetItem *item = ui->listWidget2->item(ui->listWidget2->currentRow());
    if (!item) {
     QMessageBox::information(this,tr("Ошибка"),tr("Не выбран элемент в списке"));
     return;
    }


    ui->listWidget2->takeItem (ui->listWidget2->currentRow());
    ui->listWidget1->addItem(item);
    ui->listWidget2->setCurrentRow(-1);
    ui->listWidget2->setSelectionMode(QAbstractItemView::ExtendedSelection);
}

