#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
    class Dialog;
}
class QTimer;
class QextSerialPort;
class QextSerialEnumerator;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    Ui::Dialog *ui;
    ~Dialog();

public slots:
    //void ReceivedData_micro(QString item);

signals:
    //void SendData_micro(QString item);
    void SendData_dialog(QString item);
    void SendData_validacion(QString item);
    void SendData_iotarjeta(QString item);
    void SendData_io(QString item);


protected:
    void changeEvent(QEvent *e);

private Q_SLOTS:
    void onPortNameChanged(const QString &name);
    void onBaudRateChanged(int idx);
    void onParityChanged(int idx);
    void onDataBitsChanged(int idx);
    void onStopBitsChanged(int idx);
    void onQueryModeChanged(int idx);
    void onTimeoutChanged(int val);
    void onOpenCloseButtonClicked();
    void onSendButtonClicked();
    void onReadyRead();
    void onPortAddedOrRemoved();


private:
   // Ui::Dialog *ui;
    QTimer *timer;
    QextSerialPort *port;
    QextSerialEnumerator *enumerator;
};

#endif // DIALOG_H
