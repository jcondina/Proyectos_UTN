#ifndef ERROR_ELIMINAR_H
#define ERROR_ELIMINAR_H

#include <header.h>

namespace Ui {
class error_eliminar;
}

class error_eliminar : public QDialog
{
    Q_OBJECT

public:
    explicit error_eliminar(QWidget *parent = 0);
    ~error_eliminar();

private:
    Ui::error_eliminar *ui;
};

#endif // ERROR_ELIMINAR_H
