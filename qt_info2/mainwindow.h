#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <header.h>
#include <nuevo_usuario.h>


namespace Ui {
class confirmar_eliminar;
}

class confirmar_eliminar : public QDialog
{
    Q_OBJECT

public:
    explicit confirmar_eliminar(QWidget *parent = 0);
    ~confirmar_eliminar();

signals:
    void Recargar_lista(void);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::confirmar_eliminar *ui;
    void conectar ();
};

namespace Ui {
class eliminar_usuario;
}

class eliminar_usuario : public QDialog
{
    Q_OBJECT

public:
    explicit eliminar_usuario(QWidget *parent = 0);
    ~eliminar_usuario();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::eliminar_usuario *ui;
};

namespace Ui {
class nuevo_usuario;
}

class nuevo_usuario : public QDialog
{
    Q_OBJECT

signals:
    void SendData_pcmicro(QString item);
    void SendData(QString item,QString zona);
    void Recargar_lista();

public:
    explicit nuevo_usuario(QDialog *parent = 0);
    ~nuevo_usuario();

public slots:
    void ReceivedData_dialog(QString item);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_abrirButton_clicked();

private:
    Ui::nuevo_usuario *ui;
};

//class Dialog;

class QListWidget;
class QListWidgetItem;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void SendData_pcmicro(QString item);
    void itemDoubleClicked(QListWidgetItem *item);
    void SendData(QString item,QString zona);
    void Reload();
    void RELOAD();

public slots:
    void ReceivedData(QString item,QString zona);
    void Recargar_list();
    void Reload_io(QString item);
    void Tarjeta_io(QString item);
    //void ReceivedData_validacion(QString item);

private slots:
    void on_pushButton_nuevo_clicked();

    void on_pushButton_eliminar_clicked();

    void on_pushButton_reload_clicked();

    void on_listWidget_dentro_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_fuera_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    nuevo_usuario nuevoUsuario;
    eliminar_usuario eliminarUsuario;
    Dialog rfid;
    void conectar ();

};

#endif // MAINWINDOW_H
