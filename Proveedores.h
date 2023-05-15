#pragma once
#include "Persona.h"
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>

using namespace std;
class Proveedores : Persona {
	//atributos
private: int idProveedor=0;
	string  proveedor, direccion;

	   //constructor
public:
	Proveedores() {
	}
	Proveedores(string tel, string ni, int idprove, string prove, string dire) : Persona(tel,ni) {
		idProveedor = idprove;
		proveedor = prove;
		nit = ni;
	}

	//set (modificador)
	void set_idProveedor(int idprove) { idProveedor = idprove; }
	void set_proveedor(string prove) { proveedor = prove; }
	void set_direccion(string dire) { direccion = dire; }
	void set_telefono(int tel) { telefono = tel; }
	void set_Nit(string ni) { nit = ni; }
	//get (mostrar)
	int get_idProveedor() { return idProveedor; }
	string get_proveedor() { return proveedor; }
	string get_direccion() { return direccion; }
	string get_telefono() { return telefono; }
	string get_Nit() { return nit; }
	///////////////////////////////////////////////////////////////////////////////////

	
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insertar = "INSERT INTO proveedores (proveedor,nit,direccion,telefono) VALUES('" + proveedor + "','" + nit + "','" + direccion + "'," + telefono + "); ";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "------- Ingreso exitoso --------" << endl;
			}
			else {
				cout << "------- Error al ingresar la informacion -------" << endl;
			}
		}
		else {
			cout << "-------- Error en la conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select *from proveedores;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "---------- Proveedores --------" << endl;

				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " / " << fila[1] << " / " << fila[2] << " / " << fila[3] << " / " << fila[4] << endl;

				}
			}
			else {
				cout << "-------- Error al mostrar la informacion ---------- " << endl;
			}
		}
		else {
			cout << "---------- Error en la conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}
		void modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string modificar = to_string(idProveedor);
			string actualizar = "UPDATE proveedores SET proveedor = '" + proveedor + "', nit ='" + nit + "', direccion = '" + direccion + "', telefono = " + telefono + " WHERE idProveedor = " + modificar + ";";
			const char* a = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), a);
			if (!q_estado) {
				cout << "--------- Modificacion exitosa ---------" << endl;
			}
			else {
				cout << "--------- Error al modificar ---------" << endl;
			}
		}
		else {
			cout << "--------- Error en la conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}
		void eliminar() {
			int q_estado;
			ConexionBD cn = ConexionBD();
			cn.abrir_conexion();
			if (cn.getConectar()) {
				string borrar = to_string(idProveedor);
				string eliminar = "delete from proveedores where idProveedor = " + borrar + ";";
				const char* e = eliminar.c_str();
				q_estado = mysql_query(cn.getConectar(), e);
				if (!q_estado) {
					cout << "-------- Eliminacion exitosa ---------" << endl;
				}
				else {
					cout << "-------- Error al intentar eliminar ---------" << endl;
				}
			}
			else {
				cout << "-------- Error en la conexion ---------" << endl;
			}
			cn.cerrar_conexion();
		}
};
