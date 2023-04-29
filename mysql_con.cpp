#include <mysql.h>
#include <iostream>
using namespace std;

int main()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost","usr_empresa","123456","db_empresa",3306,NULL,0);
    if (conectar) {
        cout << "Conexion Exitosa..." << endl;
    }
    else {
        cout << "Error en la Conexion..." << endl;
    }
    system("pause");
    return 0;
}
