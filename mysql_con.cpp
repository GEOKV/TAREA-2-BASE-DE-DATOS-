
/*#include <iostream>
#include "Cliente.h"
using namespace std;

int main()
{
    string nit, nombres, apellidos, direccion, fecha_nacimiento;
    int telefono;
    cout << "Ingrese Nit:";
    getline(cin, nit);
    cout << "Ingrese Nombres:";
    getline(cin, nombres);
    cout << "Ingrese Apellidos:";
    getline(cin, apellidos);
    cout << "Ingrese Direccion:";
    getline(cin, direccion);
    cout << "Ingrese Telefono:";
    cin>> telefono;
    cin.ignore();
    cout << "Ingrese Fecha de Nacimiento:";
    cin >> fecha_nacimiento;
    Cliente c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
    c.crear();
    c.leer();
    system("pause");
    return 0;
}*/
#pragma once
#include <iostream>
#include "Proveedores.h"

using namespace std;
int main() {
   
                int idProveedor=0;
                string proveedor, nit, direccion, telefono;

                        system("cls");
                        cout << "Ingresa el nombre del proveedor: ";
                        getline(cin, proveedor);
                        
                        cout << "Ingresa el nit del proveedor: ";
                        getline(cin, nit);
                        
                        cout << "Ingresa la direccion del proveedor: ";
                        getline(cin, direccion);
                        
                        cout << "Ingresa el telefono del proveedor: ";
                        cin >> telefono;
                        cin.ignore();
                        Proveedores i = Proveedores(telefono, nit, idProveedor, proveedor, direccion);
                        i.crear();
                        i.leer();

                            cout << "Ingresa el id del proveedor a eliminar: ";
                            cin >> idProveedor;
                            Proveedores e = Proveedores();
                            e.set_idProveedor(idProveedor);
                            e.eliminar();
                            e.leer();
                   
                    
                                cout << "Ingresa el Id del Proveedor para poder realizar la modificacion: ";
                                cin >> idProveedor;
                                cin.ignore();
                                cout << "Ingresa el nombre del proveedor: ";
                                getline(cin, proveedor);
                              
                                cout << "Ingresa el nit del proveedor: ";
                                getline(cin, nit);
                                
                                cout << "Ingresa la direccion del proveedor: ";
                                getline(cin, direccion);

                                cout << "Ingresa el telefono del proveedor: ";
                                cin >> telefono;
                                cin.ignore();
                                Proveedores m = Proveedores(telefono, nit,idProveedor, proveedor,direccion);
                                m.modificar();
                                m.leer();

                                return 0;
                            }
                       
                    
                

            




