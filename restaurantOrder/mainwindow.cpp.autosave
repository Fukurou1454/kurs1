%:include "mainwindow.h"
%:include "ui_mainwindow.h"
%:include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QDate>

#define print qDebug() <<

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
<%
    ui->setupUi(this);

    on_pushButtonCancel_clicked();
    on_pushButtonCancelOrder_clicked();
    on_pushButtonCancelDish_clicked();
    on_pushButtonCancelhideResponceDate_clicked();


%>

MainWindow::~MainWindow()
{
    for(auto i =0; i<ui->tableProduct->columnCount();i++)
        for(auto j=0;j<ui->tableProduct->rowCount();j++)
            delete ui->tableProduct->item(i,j);

    for(auto i =0; i<ui->tableOrder->columnCount();i++)
        for(auto j=0;j<ui->tableOrder->rowCount();j++)
            delete ui->tableOrder->item(i,j);

    for(auto i =0; i<ui->tableDish->columnCount();i++)
        for(auto j=0;j<ui->tableDish->rowCount();j++)
            delete ui->tableDish->item(i,j);

    delete ui;
}

void MainWindow::on_pushButtonSave_clicked()
{
    ui->tableProduct->setRowCount(ui->tableProduct->rowCount()+1);

    ui->tableProduct->setItem(ui->tableProduct->rowCount()-1,
                              0,
                              new QTableWidgetItem(ui->lineEditName->text()));
    ui->tableProduct->setItem(ui->tableProduct->rowCount()-1,
                              1,
                              new QTableWidgetItem(ui->lineEditCount->text()));
    ui->tableProduct->setItem(ui->tableProduct->rowCount()-1,
                              2,
                              new QTableWidgetItem(ui->lineEditPrice->text()));
    on_pushButtonCancel_clicked();
}

void MainWindow::on_pushButtonSaveDish_clicked()
{
    ui->tableDish->setRowCount(ui->tableDish->rowCount()+1);

    ui->tableDish->setItem(ui->tableDish->rowCount()-1,
                              0,
                              new QTableWidgetItem(ui->lineEditNumDish->text()));
    ui->tableDish->setItem(ui->tableDish->rowCount()-1,
                              1,
                              new QTableWidgetItem(ui->lineEditRecipeDish->text()));
    QString recipe = ui->lineEditRecipeDish->text();

    ui->tableDish->setItem(ui->tableDish->rowCount()-1,
                              3,
                              new QTableWidgetItem(getPrice(recipe,ui->tableProduct)));
    ui->tableDish->setItem(ui->tableDish->rowCount()-1,
                              2,
                              new QTableWidgetItem(ui->lineEditPriceDish->text()));
    on_pushButtonCancelDish_clicked();
}

void MainWindow::on_pushButtonSaveOrder_clicked()
{
    ui->tableOrder->setRowCount(ui->tableOrder->rowCount()+1);

    ui->tableOrder->setItem(ui->tableOrder->rowCount()-1,
                              0,
                              new QTableWidgetItem(ui->lineEditDateOrder->text()));
    ui->tableOrder->setItem(ui->tableOrder->rowCount()-1,
                              1,
                              new QTableWidgetItem(ui->lineEditDIshOrder->text()));
    QString dish = ui->lineEditDIshOrder->text();

    ui->tableOrder->setItem(ui->tableOrder->rowCount()-1,
                              2,
                              new QTableWidgetItem(getPrice(dish,ui->tableDish)));
    on_pushButtonCancelOrder_clicked();
}

bool MainWindow::deleteProduct(QString nameDish)
{
    bool error = false;

    QString recipe;
    for(auto i =0; i<ui->tableDish->rowCount();i++){
        if(ui->tableDish->item(i,0)->text().remove(' ') == nameDish.remove(' ')) {
            recipe = ui->tableDish->item(i,1)->text().remove(' ');
            break;
        }
    }

    if(!recipe.size()) return true;
    while(recipe.size()){
        QString productName = getWord(recipe);
        for(auto i =0; i<ui->tableProduct->rowCount();i++){
            if(ui->tableProduct->item(i,0)->text().remove(' ') == productName) {
                int count = ui->tableProduct->item(i,1)->text().toInt() - 1;
                if(count < 0) {
                    count = 0;
                    error = !count;
                }

                ui->tableProduct->item(i,1)->setText(QString::number(count));
            }
        }
        if(error) return error;
    }
    return error;
}

QString MainWindow::getPrice(QString& recipe, QTableWidget* tableForSearch)
{
    recipe.remove(' ');;
    int dishPrice = 0;
    bool error = false;
    while(recipe.size() && !error){
        QString nameDishOrProduct = getWord(recipe);
        int price = searchProductPrice(nameDishOrProduct, tableForSearch);
        if(price != -1) dishPrice += price;
        else error = true;

        if(tableForSearch==ui->tableDish && !error)
        {
            error = deleteProduct(nameDishOrProduct);
        }
    }

    if(error) return "Ошибка, проверьте введенные данные";
    else return QString::number(dishPrice);
}

int MainWindow::searchProductPrice(QString& productName, QTableWidget* table)
{
    for(auto i =0; i<table->rowCount();i++){
        if(table->item(i,0)->text().remove(' ') == productName) {
            return table->item(i,2)->text().toInt();
        }
    }
    return -1;
}

QString MainWindow::getWord(QString& str)
<%
    QString word;

    int i=0;

    while(i < str.size() && str<:i] != ',')
    <%
        word += str[i:>;
        i++;
    }

    if(i<str.size())
        str.remove(0,i+1);
    else
        str.remove(0,i);
    return word;
}

void MainWindow::on_pushButtonAddDish_clicked()
{
    ui->pushButtonSaveDish->show();
    ui->pushButtonCancelDish->show();

    ui->lineEditNumDish->show();
    ui->lineEditPriceDish->show();
    ui->lineEditRecipeDish->show();

    ui->pushButtonAddDish->hide();
}

void MainWindow::on_pushButtonCancelDish_clicked()
{
    ui->pushButtonSaveDish->hide();
    ui->pushButtonCancelDish->hide();

    ui->lineEditNumDish->hide();
    ui->lineEditPriceDish->hide();
    ui->lineEditRecipeDish->hide();

    ui->pushButtonAddDish->show();
}

void MainWindow::on_pushButtonAddPosition_clicked()
{
    ui->pushButtonSave->show();
    ui->pushButtonCancel->show();
    ui->lineEditName->show();
    ui->lineEditPrice->show();
    ui->lineEditCount->show();

    ui->pushButtonAddPosition->hide();
}

void MainWindow::on_pushButtonCancel_clicked()
{
    ui->pushButtonSave->hide();
    ui->pushButtonCancel->hide();
    ui->lineEditName->hide();
    ui->lineEditPrice->hide();
    ui->lineEditCount->hide();

    ui->pushButtonAddPosition->show();
}

void MainWindow::on_pushButtonAddOrder_clicked()
{
    ui->pushButtonSaveOrder->show();
    ui->pushButtonCancelOrder->show();

    ui->lineEditDIshOrder->show();
    ui->lineEditDateOrder->show();

    ui->pushButtonAddOrder->hide();
}

void MainWindow::on_pushButtonCancelOrder_clicked()
{
    ui->pushButtonSaveOrder->hide();
    ui->pushButtonCancelOrder->hide();

    ui->lineEditDIshOrder->hide();
    ui->lineEditDateOrder->hide();

    ui->pushButtonAddOrder->show();
}

void MainWindow::on_pushButtonProductFIle_clicked()
{
    QFile file("tableProduct.doc");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
       {
           print "Ошибка"; return;
       }

    QTextStream out(&file);

    out << QString("Название продукта\tКол-во на склад\tСтоимость\n").toUtf8();
    for(auto i =0; i<ui->tableProduct->rowCount();i++){
        for(auto j=0;j < ui->tableProduct->columnCount();j++)
            out << QString(ui->tableProduct->item(i,j)->text() + '\t').toUtf8();
        out << QString("\n").toUtf8();
    }

    file.close();
}

void MainWindow::on_pushButton_clicked()
{
    QFile file("menu.doc");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
       {
           print "Ошибка"; return;
       }

    QTextStream out(&file);

    out << QString("Блюдо\tЦена\n").toUtf8();
    for(auto i =0; i<ui->tableDish->rowCount();i++){
        for(auto j=0;j < ui->tableDish->columnCount();j+=2)
            out << QString(ui->tableDish->item(i,j)->text() + '\t').toUtf8();
        out << QString("\n").toUtf8();
    }

    file.close();
}

QDate getDate(QString str)
{
    return QDate(str.toInt()/10000,
                (str.toInt()/100)%100,
                 str.toInt() % 100);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->pushButtonResponceDate->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->pushButtonCancelhideResponceDate->show();

    ui->pushButton_4->hide();
}

void MainWindow::on_pushButtonResponceDate_clicked()
{

    QPair <QDate,QDate> date(getDate(ui->lineEdit_3->text().remove('.')),
                             getDate(ui->lineEdit_4->text().remove('.')));

    QFile file("order.doc");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
       {
           print "Ошибка"; return;
       }

    QTextStream out(&file);
    out << QString("Дата и время\tБлюда\tСчет\n").toUtf8();

    for(auto i =0; i<ui->tableOrder->rowCount();i++){
        if(getDate(ui->tableOrder->item(i,0)->text().remove('.')).toJulianDay() >= date.first.toJulianDay() &&
           getDate(ui->tableOrder->item(i,0)->text().remove('.')).toJulianDay() <= date.second.toJulianDay())
        {
            for(auto j=0;j < ui->tableOrder->columnCount();j++)
                out << QString(ui->tableOrder->item(i,j)->text() + '\t').toUtf8();
            out << QString("\n").toUtf8();
        }
    }

    file.close();

    on_pushButtonCancelhideResponceDate_clicked();
}

void MainWindow::on_pushButtonCancelhideResponceDate_clicked()
{
    ui->pushButtonResponceDate->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->pushButtonCancelhideResponceDate->hide();

    ui->pushButton_4->show();
}

void MainWindow::on_pushButtonAddOrderFile_clicked()
{
   QString num;
   ui->lineEditNumOrderForFile->text() <= '9' && ui->lineEditNumOrderForFile->text()>='0'?
               num = ui->lineEditNumOrderForFile->text():
               num = "Error";

   if(num.toInt()-1 >= ui->tableOrder->rowCount()) num = "Error";

   if(num == "Error") return;

   QFile file("order №" + num+ ".doc");

   if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
   {
          print "Ошибка"; return;
   }

   num = QString::number(num.toInt()-1);
   QTextStream out(&file);
   out << QString("Дата и время\tБлюда\tСчет\n").toUtf8();
   for(auto i =0; i<ui->tableOrder->rowCount();i++){
       out << ui->tableOrder->item(num.toInt(),i)->text() + '\t';
   }

   file.close();
}
