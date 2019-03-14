#include "confirmar_eliminar.h"
#include "ui_confirmar_eliminar.h"

/*! \variable QString borrar
 *  \brief Variable declarada en mainwindow que posee el numero de tarjeta del usuario a eliminar
 */
extern  QString id_borrar;

/*! Constructor */
confirmar_eliminar::confirmar_eliminar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confirmar_eliminar)
{

        ui->setupUi(this);

        conectar();
}

/*! Destructor */
confirmar_eliminar::~confirmar_eliminar()
{
    delete ui;
}

/*! \fn void confirmar_eliminar::on_buttonBox_accepted()
 *  \brief Al presionar "Ok" se procede a conectarse a la base de datos y eliminar el usuario segun los datos
 *         ingresados previamente
*/
void confirmar_eliminar::on_buttonBox_accepted()
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
        QString info_query = "DELETE FROM persona WHERE numero_tarjeta = ";
        info_query.append(id_borrar);
        qDebug () << info_query ;

        query.exec(info_query);

        db.close();

        emit Recargar_lista();

        close();
    }
    else
    {
        qDebug()<<"Fallo conexion BDD";
    }
}

/*! \fn void confirmar_eliminar::conectar()
 *  \brief Funcion usada para conectarse con la base de datos y hacer una consulta a la misma segun
 *         el numero de la tarjeta. Luego se completan los campos de la ventana con los datos obtenidos
 */
void confirmar_eliminar::conectar()
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
        info_query.append(id_borrar);
        qDebug () << info_query;

        query.exec(info_query);

        while (query.next()) {
           numero_tarjeta = query.value(0).toString();
           nombre = query.value(1).toString();
           apellido = query.value(2).toString();
           dni = query.value(3).toString();
           zona = query.value(4).toString();
           path = query.value(5).toString();
        }

        this->
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

/*! \fn void confirmar_eliminar::on_buttonBox_rejected()
 *  \brief Al presionar el bonton "Cancel" cerramos la ventana sin efectuar cambios
 */
void confirmar_eliminar::on_buttonBox_rejected()
{
    this->close();
}
