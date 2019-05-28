#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_pushButtonAddPosition_clicked();
    void on_pushButtonCancel_clicked();
    void on_pushButtonSave_clicked();
    void on_pushButtonProductFIle_clicked();

    void on_pushButtonAddOrder_clicked();
    void on_pushButtonCancelOrder_clicked();
    void on_pushButtonSaveOrder_clicked();
    void on_pushButtonAddOrderFile_clicked();

    void on_pushButtonAddDish_clicked();
    void on_pushButtonCancelDish_clicked();
    void on_pushButtonSaveDish_clicked();
    void on_pushButtonResponceDate_clicked();
    void on_pushButtonCancelhideResponceDate_clicked();

    void on_pushButton_clicked();
    void on_pushButton_4_clicked();

    int searchProductPrice(QString& productName,QTableWidget* table);
    QString getPrice(QString& recipe, QTableWidget* table);
    QString getWord(QString& str);
    bool deleteProduct(QString name);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
