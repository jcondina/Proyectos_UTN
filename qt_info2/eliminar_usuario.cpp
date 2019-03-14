#include "eliminar_usuario.h"
#include "ui_eliminar_usuario.h"
#include "confirmar_eliminar.h"
#include "header.h"
#include "error_eliminar.h"
#include "mainwindow.h"

/*! \variable QString borrar
 *  \brief Variable declarada en mainwindow que posee el numero de tarjeta del usuario a eliminar
 */
extern  QString id_borrar;


/*! Constructor */
eliminar_usuario::eliminar_usuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eliminar_usuario)
{
    ui->setupUi(this);
}

/*! Destructor */
eliminar_usuario::~eliminar_usuario()
{
    delete ui;
}

/*! \fn void eliminar_usuario::on_buttonBox_accepted()
 *  \brief Al presionar "Ok" se procede a conectarse a la base de datos y hacer una consulta segun
 *         el numero de tarjeta ingresado. Si se encuentra se abre la ventana de confirmacion y si
 *         no se encuentra se abre una ventana de error
 */
void eliminar_usuario::on_buttonBox_accepted()
{
    //Cargamos la id de tarjeta a borrar
    id_borrar = "'" + ui->lineEdit_ingresar->text() + "'";

    //Conexion BDD
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName($HOSTNAME);
    db.setDatabaseName($DATABASENAME);
    db.setUserName($USERNAME);
    db.setPassword($PASSWORD);
    bool ok = db.open();

    if(ok)
    {
        //Query SQL para busqueda en BDD de id_borrar
        QSqlQuery query;
        QString info_query = "SELECT * FROM persona WHERE numero_tarjeta = ";
        info_query.append(id_borrar);
        query.exec(info_query);

        db.close();

        //Si existe en BDD la ID, se procede a realizar el proceso de borrado
        if (query.size() > 0)
        {
            confirmar_eliminar confirmarEliminar;
            confirmarEliminar.setModal(true);
            confirmarEliminar.exec();
         }
         else
         {
             error_eliminar errorEliminar;
             errorEliminar.setModal(true);
             errorEliminar.exec();
         }
    }
    else
    {
        qDebug()<<"Fallo conexion BDD";
    }
}
