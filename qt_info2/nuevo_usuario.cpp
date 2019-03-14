#include "nuevo_usuario.h"
#include "ui_nuevo_usuario.h"
#include "dialog.h"
#include "ui_dialog.h"
#include "header.h"
#include "hled.h"

/*! Constructor */
nuevo_usuario::nuevo_usuario(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::nuevo_usuario)
{
    ui->setupUi(this);

    // Muestra imagen por defecto al no estar cargado un usuario
    QString nouserimgdir=$NO_IMG;
    QPixmap pix(nouserimgdir);
    ui->label_pix->setPixmap(pix);
    ui->label_dir->setText(nouserimgdir);
}

/*! Destructor */
nuevo_usuario::~nuevo_usuario()
{
    delete ui;
}

/*! \fn void nuevo_usuario::on_buttonBox_accepted()
 *  \brief Al presionar el boton "Ok" se chequea que se hayan completado todos los campos y luego se procede a
 *         agregar un usuario nuevo a la base de datos, luego se envia la señal de recargar las listas
 */
void nuevo_usuario::on_buttonBox_accepted()
{
    // Si los campos se encuentran completados, generamos la conexion con la BDD y carga de datos
    if ((ui->lineEdit_nombre->text() != "") && (ui->lineEdit_apellido->text() != "") && (ui->lineEdit_dni->text() != "") && (ui->lineEdit_id->text() != "") && (ui->lineEdit_id->text() != "ERROR LECTURA") )
    {
        //Conexion BDD
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName($HOSTNAME);
        db.setDatabaseName($DATABASENAME);
        db.setUserName($USERNAME);
        db.setPassword($PASSWORD);
        bool ok = db.open();

        if(ok)
        {
            //Cargamos los campos completados en variables
            QString nombre_add = ui->lineEdit_nombre->text(),
                    apellido_add = ui->lineEdit_apellido->text(),
                    dni_add = ui->lineEdit_dni->text(),
                    id_add = ui->lineEdit_id->text(),
                    path_add = ui->label_dir->text(),
                    zona_add = "afuera";

            //Generamos la query SQL que cargara los datos en la BDD
            QSqlQuery query;
                query.prepare("INSERT INTO persona (numero_tarjeta, nombre, apellido,dni,zona,path) "
                              "VALUES (:id, :nombre, :apellido, :dni, :zona, :path)");
                query.bindValue(":id", id_add);
                query.bindValue(":nombre", nombre_add);
                query.bindValue(":apellido", apellido_add);
                query.bindValue(":dni", dni_add);
                query.bindValue(":zona", zona_add);
                query.bindValue(":path", path_add );
                query.exec();

            //Cerramos la conexion con la BDD
            db.close();

            //Generamos la señal para que se cargue nuevamente la lista de usuarios en la ventana principal
            emit Recargar_lista();

        }
        else
        {
            qDebug()<<"Fallo conexion BDD";
        }
    }

    //Borramos datos cargados
    ui->lineEdit_nombre->clear();
    ui->lineEdit_apellido->clear();
    ui->lineEdit_dni->clear();
    ui->lineEdit_id->clear();

    this->close();
}

/*! \fn void nuevo_usuario::on_buttonBox_rejected()
 *  \brief Al apretar el boton "Cancel" se cierra la ventana
 */
void nuevo_usuario::on_buttonBox_rejected()
{
    this->close();
}

/*! \fn void nuevo_usuario::on_abrirButton_clicked()
 *  \brief Al apretar el boton "Abrir" se crea un dialogo que permite seleccionar un archivo de imagen
 *         para copiar su ruta, guardar la misma y mostrarla en ventana
 */
void nuevo_usuario::on_abrirButton_clicked()
{
    QFileDialog dialog(this);
        dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
        dialog.setViewMode(QFileDialog::Detail);
        QString fileName = QFileDialog::getOpenFileName(this,
           tr("Open Images"), $PATH_IMG, tr("Image Files (*.png *.jpg *.bmp)"));
        if (!fileName.isEmpty())
        {
             QImage image(fileName);
             ui->label_dir->setText(fileName);
             ui->label_pix->setPixmap(QPixmap::fromImage(image));
        }
}

/*! \fn void nuevo_usuario::ReceivedData_dialog(QString item)
 *  \brief Recibe un numero de tarjeta y lo asigna al campo correspondiente
 *  \param item String que contiene el numero de tarjeta
 */
void nuevo_usuario::ReceivedData_dialog(QString item)
{
    //_Si la tarjeta llega bien, realizamos todo el proceso. Caso contrario reingrese tarjeta
    if(item.size()==14)
    {
        int i;
        QString item_send;

        //Cargamos en item_send el valor de la tarjeta, eliminando extremos
        for(i=0;i<12;i++)
        {
            item_send[i]=item[i+1];
        }
        //Mostramos el id en pantalla
        ui->lineEdit_id->setText(item_send);
    }
    else
    {
        //En caso de llegar mal la tarjeta, lo informamos
        ui->lineEdit_id->setText("ERROR LECTURA");
    }
}
