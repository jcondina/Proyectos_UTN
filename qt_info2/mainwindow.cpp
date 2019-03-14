#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eliminar_usuario.h"
#include "display_datos.h"
#include "ui_display_datos.h"
#include "header.h"

QString rfid_dialog;
QString id_borrar;
QString id_mostrar;
QString bufferTarjetaio;

/*! Constructor */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Llamamos a la funcion de inicial de carga de datos en pantalla
    conectar();

    //Abrimos la ventana de conexion con rfid
    rfid.show();

    //Conexion con la señal de recarga de lista de usuarios en pantalla al cargar usuario nuevo y eliminar usuario
    connect(&nuevoUsuario,SIGNAL(Recargar_lista()),this,SLOT(Recargar_list()));
    connect(this,SIGNAL(Reload()),this,SLOT(Recargar_list()));

    //Conexion de rfid para guardar
    connect(&rfid,SIGNAL(SendData_iotarjeta(QString)),this,SLOT(Tarjeta_io(QString)));

    //Conexion recarga de data
    connect(&rfid,SIGNAL(SendData_io(QString)),this,SLOT(Reload_io(QString)));
}

/*! Destructor */
MainWindow::~MainWindow()
{
    delete ui;
}

/*! \fn void MainWindow::on_pushButton_nuevo_clicked()
 * \brief Al presionar el boton "Nuevo usuario" se abre la ventana correspondiente para hacerlo
 */
void MainWindow::on_pushButton_nuevo_clicked()
{
    //Conexion de Señal RFID a ventana de carga de usuario
    connect(&rfid, SIGNAL(SendData_dialog(QString)), &nuevoUsuario, SLOT(ReceivedData_dialog(QString)));

    //Ejecucion ventana
    nuevoUsuario.setModal(true);
    nuevoUsuario.exec();
}

/*! \fn void MainWindow::on_pushButton_reload_clicked()
 *  \brief Al presionar el boton reload forzamos una actualizacion de las listas en la venta principal
 */
void MainWindow::on_pushButton_reload_clicked()
{
    connect(this,SIGNAL(RELOAD()),this,SLOT(Recargar_list()));

    emit RELOAD();
}

/*! \fn void MainWindow::on_pushButton_eliminar_clicked()
 *  \brief Al presionar el boton "Eliminar usuario" se abre la ventana correspondiente para hacerlo
 */
void MainWindow::on_pushButton_eliminar_clicked()
{
    //Ejecucion ventana
    eliminarUsuario.setModal(true);
    eliminarUsuario.exec();
}

/*! \fn void MainWindow::ReceivedData(QString item, QString zona)
 *  \brief Se reciben los datos enviados al momento de hacer la conexion en el constructor de MainWindow
 *         y se evalua su contenido
 *  \param item Es un string que contiene los datos del usuario sacados de la base de datos
 *  \param zona Es un string que contiene la ubicacion del usuario sacada de la base de datos
 */
void MainWindow::ReceivedData(QString item, QString zona)
{
    //Chequeo recepcion de datos
    qDebug() << "Item: " << item;

    //Se añade el usuaio a la lista en pantalla correspondiente
    if(zona == "adentro")
        ui->listWidget_dentro->addItem(item);
    else
        ui->listWidget_fuera->addItem(item);
}

/*! \fn void MainWindow::on_listWidget_dentro_itemDoubleClicked(QListWidgetItem *item)
 *  \param item Contiene un puntero al item de la lista correspondiente
 *  \brief Al hacer doble click en un item de la lista, se envia el item como parametro y esta funcion
 *         lo recibe para mostrar los datos del usuario correspondiente en una ventana
 */
void MainWindow::on_listWidget_dentro_itemDoubleClicked(QListWidgetItem *item)
{
    if (!item)
        return;

    QString texto = item->text();
    QStringList id = texto.split(" ");
    id_mostrar = "'" + id.last() + "'";

    display_datos displayDatos;
    displayDatos.setModal(true);
    displayDatos.exec();
}

/*! \fn void MainWindow::on_listWidget_fuera_itemDoubleClicked(QListWidgetItem *item)
 *  \param item Contiene un puntero al item de la lista correspondiente
 *  \brief Al hacer doble click en un item de la lista, se envia el item como parametro y esta funcion
 *         lo recibe para mostrar los datos del usuario correspondiente en una ventana
 */
void MainWindow::on_listWidget_fuera_itemDoubleClicked(QListWidgetItem *item)
{
    if (!item)
        return;

    QString texto = item->text();
    QStringList id = texto.split(" ");
    id_mostrar = "'" + id.last() + "'";

    display_datos displayDatos;
    displayDatos.setModal(false);
    displayDatos.exec();
}

/*! \fn void MainWindow::Recargar_list()
 *  \brief Al recibir la señal de recargar se recargan ambas listas
 */
void MainWindow::Recargar_list()
{
    //Borramos ambas listas
    ui->listWidget_dentro->clear();
    ui->listWidget_fuera->clear();

    //Conexion BDD
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName($HOSTNAME);
    db.setDatabaseName($DATABASENAME);
    db.setUserName($USERNAME);
    db.setPassword($PASSWORD);
    bool ok = db.open();

    if(ok)
    {
        //Variables a utilizar
        QString nombre, apellido, dni, numero_tarjeta, zona;

        //Query SQL consulta BDD
        QSqlQuery query;
        query.exec("SELECT * from persona");

        //Recorre la consulta y carga usuario en lista
        while (query.next()) {
                numero_tarjeta = query.value(0).toString();
                nombre = query.value(1).toString();
                apellido = query.value(2).toString();
                dni = query.value(3).toString();
                zona = query.value(4).toString();
                //Señal de carga en lista
                emit SendData(nombre+" "+apellido+" ID: "+numero_tarjeta,zona);
            }
        db.close();
    }
    else
    {
        qDebug()<<"Fallo apertura BDD";
    }
}

/*! \fn void MainWindow::conectar()
 *  \brief La ventana se conecta a la base de datos al construirse para cargar los usuarios dentro
 *         de las listas dentro y fuera
 */
void MainWindow::conectar()
{
    //Conexion de señal para la carga de datos en pantalla
    connect(this, SIGNAL(SendData(QString,QString)), this, SLOT(ReceivedData(QString,QString)));

    //Conexion BDD
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName($HOSTNAME);
    db.setDatabaseName($DATABASENAME);
    db.setUserName($USERNAME);
    db.setPassword($PASSWORD);
    bool ok = db.open();

    if(ok)
    {
        //Variables a utilizar
        QString nombre, apellido, dni, numero_tarjeta, zona;

        //Query SQL de consulta a la BDD, trae todos los usuarios registrados
        QSqlQuery query;
        query.exec("SELECT * from persona");

        //Asignacion y carga de usuarios en pantalla
        while (query.next()) {
                numero_tarjeta = query.value(0).toString();
                nombre = query.value(1).toString();
                apellido = query.value(2).toString();
                dni = query.value(3).toString();
                zona = query.value(4).toString();
                //Señal de carga de usuario en pantalla
                emit SendData(nombre+" "+apellido+" ID: "+numero_tarjeta, zona);
            }
        //Cierre de conexion BDD
        db.close();
    }
    else
    {
        qDebug()<<"Fallo conexion BDD";
    }
}

void MainWindow::Tarjeta_io(QString item)
{
    bufferTarjetaio = item;
    qDebug() << "buffertaje" << bufferTarjetaio;
}

void MainWindow::Reload_io(QString item)
{
    char TJ[14];
    strcpy(TJ,bufferTarjetaio.toUtf8());
    int i;

    for(i=0;i<13;i++)
    {
        TJ[i]=TJ[i+1];
    }
    TJ[12]='\0';

    //Conexion BDD
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName($HOSTNAME);
    db.setDatabaseName($DATABASENAME);
    db.setUserName($USERNAME);
    db.setPassword($PASSWORD);
    bool ok = db.open();

    if(ok)
    {
        if(item.contains("OU"))
        {
            //Query SQL para actualizacion de zona
            QSqlQuery query;
            query.prepare("UPDATE persona SET zona = :ZN WHERE numero_tarjeta = ':T_ID' ");
            query.bindValue(":ZN", "'afuera'");
            query.bindValue(":T_ID", TJ);
            query.exec();
        }
        if(item.contains("IN"))
        {
            //Query SQL para actualizacion de zona
            QSqlQuery query;
            query.prepare("UPDATE persona SET zona = :ZN WHERE numero_tarjeta = ':T_ID' ");
            query.bindValue(":ZN", "'adentro'");
            query.bindValue(":T_ID", TJ);
            query.exec();
        }

        //Cierre de conexion BDD
        db.close();

        emit Reload();
    }
    else
    {
        qDebug()<<"Fallo conexion BDD";
    }

    qDebug() << "In/out= " << item << "NTarjeta= " << bufferTarjetaio ;
}
