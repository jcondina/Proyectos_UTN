#include "display_datos.h"
#include "mainwindow.h"
#include "ui_display_datos.h"

// Variable global con id a mostrar datos
extern QString id_mostrar;

/*! Constructor */
display_datos::display_datos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::display_datos)
{
    ui->setupUi(this);

    qDebug()<<id_mostrar;

    conectar();
}

/*! Destructor */
display_datos::~display_datos()
{
    delete ui;
}

/*! \fn void display_datos::on_pushButton_modificar_clicked()
 *  \brief Al presionar el boton "Modificar" se habilita la edicion de los campos, excepto el de la tarjeta
 */
void display_datos::on_pushButton_modificar_clicked()
{
    ui->lineEdit_nombre->setReadOnly(false);
    ui->lineEdit_apellido->setReadOnly(false);
    ui->lineEdit_dni->setReadOnly(false);
}

/*! \fn void display_datos::on_buttonBox_accepted()
 *  \brief Al presionar el boton "Ok" se cierra la ventana
 */
void display_datos::on_buttonBox_accepted()
{
   modificar();
   display_datos::close();
}

/*! \fn void display_datos::on_buttonBox_rejected()
 * \brief Al presionar el bonton "Cancel" cerramos la ventana sin efectuar cambios
 */
void display_datos::on_buttonBox_rejected()
{
    this->close();
}

/*! \fn void display_datos::conectar()
 *  \brief Funcion usada para conectarse con la base de datos y hacer una consulta a la misma segun
 *         el numero de la tarjeta. Luego se completan los campos de la ventana con los datos obtenidos
 */
void display_datos::conectar()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName($HOSTNAME);
    db.setDatabaseName($DATABASENAME);
    db.setUserName($USERNAME);
    db.setPassword($PASSWORD);
    bool ok = db.open();

    if(ok)
    {
        QString numero_tarjeta, apellido, nombre, dni, zona, path;

        QSqlQuery query;
        QString info_query = "SELECT * FROM persona WHERE numero_tarjeta = ";
        info_query.append(id_mostrar);
        qDebug()<< info_query;

        query.exec(info_query);

        while (query.next()) {
           numero_tarjeta = query.value(0).toString();
           nombre = query.value(1).toString();
           apellido = query.value(2).toString();
           dni = query.value(3).toString();
           zona = query.value(4).toString();
           path = query.value(5).toString();
        }

        ui->lineEdit_nombre->setText(nombre);
        ui->lineEdit_apellido->setText(apellido);
        ui->lineEdit_dni->setText(dni);
        ui->lineEdit_id->setText(numero_tarjeta);
        QPixmap pix(path);
        ui->label_pix->setPixmap(pix);

        db.close();
    }
    else
    {
        qDebug()<<"Fallo conexion BDD";
    }
}

/*! \fn void display_datos::conectar()
 *  \brief Funcion usada para conectarse con la base de datos y hacer una consulta a la misma segun
 *         el numero de la tarjeta. Luego se completan los campos de la ventana con los datos obtenidos
 */
void display_datos::modificar()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName($HOSTNAME);
    db.setDatabaseName($DATABASENAME);
    db.setUserName($USERNAME);
    db.setPassword($PASSWORD);
    bool ok = db.open();

    if(ok)
    {
        QSqlQuery query;

        QString info_query = "UPDATE persona SET nombre = ";
        info_query.append("'"+ui->lineEdit_nombre->text()+"'");
        info_query.append(" WHERE numero_tarjeta = ");
        info_query.append(id_mostrar);
        query.exec(info_query);

        info_query = "UPDATE persona SET apellido = ";
        info_query.append("'"+ui->lineEdit_apellido->text()+"'");
        info_query.append(" WHERE numero_tarjeta = ");
        info_query.append(id_mostrar);
        query.exec(info_query);

        info_query = "UPDATE persona SET dni = ";
        info_query.append("'"+ui->lineEdit_dni->text()+"'");
        info_query.append(" WHERE numero_tarjeta = ");
        info_query.append(id_mostrar);
        query.exec(info_query);

        db.close();
    }
    else
    {
        qDebug()<<"Fallo conexion BDD";
    }
}
