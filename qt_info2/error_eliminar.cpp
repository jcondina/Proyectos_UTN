#include "error_eliminar.h"
#include "ui_error_eliminar.h"

/*! Constructor */
error_eliminar::error_eliminar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::error_eliminar)
{
    ui->setupUi(this);
}

/*! Destructor */
error_eliminar::~error_eliminar()
{
    delete ui;
}
