#ifndef DISPLAY_DATOS_H
#define DISPLAY_DATOS_H

#include <header.h>

namespace Ui {
class display_datos;
}

class display_datos : public QDialog
{
    Q_OBJECT

public:
    explicit display_datos(QWidget *parent = 0);
    ~display_datos();

private slots:
    void on_pushButton_modificar_clicked();

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::display_datos *ui;

    void conectar();

    void modificar();
};

#endif // DISPLAY_DATOS_H
