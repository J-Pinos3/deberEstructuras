#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <array>
using namespace std;
/*
EJERCICIOS
EQUIPOS-ANIMALES-BECARIOS-FECHAS
*/
//ESTRUCTURAS
const int MAX = 30;
struct EQUIPOS{

    string nombre_equipo;
    int ganados = 0;
    int empatados = 0;
    int puntos_totales = 0;
};
array <EQUIPOS, MAX> arrEquip;


struct EMPLEADOS{
    string nombre_empleado;
    int edad_empleado;
    string grado_estudios;
    string tipo_contratacion;
};
array <EMPLEADOS, MAX> arrEmpleados;


struct FECHA{
    int anio;
    int mes;
    int dia;
};


struct ANIMAL{

    unsigned int identificador = 0;
    string animal_nombre;
    double peso;
    string animal_tipo;

};

struct LISTA{
    array <ANIMAL, MAX> arrAnimales;
    int contador = 0;
};

//PROTOTIPOS DE LAS FUNCIONES
int Menu();

void IngresarEquipos( array<EQUIPOS, MAX>& arr, int& total);//total debe ser inicializado en 0 antes de usarse
void MostrarEquipos( const array<EQUIPOS, MAX>& arr, const int total );
void OrdenarEquipos( array<EQUIPOS, MAX>& arr, const int total);

void IngresarEmpleados( array <EMPLEADOS, MAX>& arr1, int& total);
void MostrarEmpleados( const array <EMPLEADOS, MAX>& arr1, const int total);

void CompararFechas(const FECHA fecha1, const FECHA fecha2 );

int Menu_Animales();
void CargarAnimales(LISTA& lista, bool& funciona);
void GuardarAnimales(const LISTA& lista);
void LeerAnimal(ANIMAL& animal, const LISTA& lista);
void InsertarAnimal(LISTA& lista, ANIMAL animal, bool& funciona);
void BuscarAnimal(const LISTA& lista);
void MostrarAnimal(const LISTA& lista);

int main()
{
    int opcion = 1;
    int total_Equip = 0;
    int total_Empleados = 0;

    while(opcion != 0){

            opcion = Menu();
            system("cls");

            switch (opcion) {

             //cin.ignore();
            case 1:{
                cout <<"Equipos de f"<<char(163)<<"tbol"<<endl<<endl;
                IngresarEquipos(arrEquip,total_Equip);
                system("cls");
                OrdenarEquipos(arrEquip, total_Equip);
                MostrarEquipos(arrEquip, total_Equip);
            }
            break;


            case 2:{
                cout <<"Zool"<<char(162)<<"gico"<<endl<<endl;
                LISTA lista;
                ANIMAL animal;
                bool funciona;
                int opcion_anim = 1;
                CargarAnimales(lista, funciona);

                if(!funciona){
                    cout <<"No se pudo cargar el archivo"<<endl;
                }else{

                       while(opcion_anim != 4){
                           opcion_anim = Menu_Animales();
                           system("cls");

                           switch(opcion_anim){

                                   case 1:{
                                            LeerAnimal(animal, lista);
                                            InsertarAnimal(lista, animal, funciona);
                                            if(!funciona){
                                                cout <<"El zool"<<char(162)<<"est"<<char(160)<<" lleno"<<endl;
                                            }
                                   }
                                   break;


                                   case 2:{
                                            MostrarAnimal(lista);
                                   }
                                   break;


                                   case 3:{
                                            BuscarAnimal(lista);
                                   }
                                   break;

                                   case 4:{
                                                cout <<"Vuelva Pronto"<<endl;
                                   }
                                   break;

                                   default:{
                                            cout <<"Algo ha salido muy mal"<<endl;
                                   }
                                   break;



                           }//FIN DEL SWITCH PRINCIPAL DE ANIMALES

                           system("pause");
                           system("cls");

                       }//FIN DEL WHILE PRINCIPAL DE ANIMALES

                       GuardarAnimales(lista);
                }

            }
            break;


            case 3:{
                cout <<"Becarios"<<endl<<endl;
                IngresarEmpleados(arrEmpleados,total_Empleados);
                system("cls");
                MostrarEmpleados(arrEmpleados,total_Empleados);
            }
            break;


            case 4:{
                cout <<"Fechas"<<endl<<endl;
                FECHA fecha1, fecha2;

                cout <<"Ingrese los datos de la primera fecha"<<endl;
                cout <<"a"<<char(164)<<"o: ";
                cin >> fecha1.anio;
                while(fecha1.anio < 1){
                    cout <<"Los a"<<char(164)<<"os son valores positivos!"<<endl;
                    cout <<"a"<<char(164)<<"o: ";
                    cin >> fecha1.anio;
                }

                cout <<"mes: ";
                cin >> fecha1.mes;
                while(fecha1.mes < 1 || fecha1.mes > 12){
                    cout <<"El mes ingresado no existe!"<<endl;
                    cout <<"mes: ";
                    cin >> fecha1.mes;
                }

                cout <<"d"<<char(161)<<"a: ";
                cin >> fecha1.dia;
                while(fecha1.dia < 1 || fecha1.dia > 31){
                    cout <<"El d"<<char(161)<<"a ingresado no existe!"<<endl;
                    cout <<"d"<<char(161)<<"a: ";
                    cin >> fecha1.dia;
                }


                cout <<endl<<endl<<endl;
                cout <<"Ingrese los datos de la segunda fecha"<<endl;
                cout <<"a"<<char(164)<<"o: ";
                cin >> fecha2.anio;
                while(fecha2.anio < 1){
                    cout <<"Los a"<<char(164)<<"os son valores positivos!"<<endl;
                    cout <<"a"<<char(164)<<"o: ";
                    cin >> fecha2.anio;
                }

                cout <<"mes: ";
                cin >> fecha2.mes;
                while(fecha2.mes < 1 || fecha2.mes > 12){
                    cout <<"El mes ingresado no existe!"<<endl;
                    cout <<"mes: ";
                    cin >> fecha2.mes;
                }

                cout <<"d"<<char(161)<<"a: ";
                cin >> fecha2.dia;
                while(fecha2.dia < 1 || fecha2.dia > 31){
                    cout <<"El d"<<char(161)<<"a ingresado no existe!"<<endl;
                    cout <<"d"<<char(161)<<"a: ";
                    cin >> fecha2.dia;
                }

                cout <<endl<<endl;

                CompararFechas(fecha1, fecha2);

            }
            break;


            case 0:{
                cout <<"Desarrollado por: Super Compumundo HiperMega Red :)"<<endl;
            }
            break;

            default:{
                    cout <<"ALGO HA SALIDO MUY MAL :("<<endl;
            }
            break;

            }//FIN DEL SWITCH PRINCIPAL

            system("pause");
            system("cls");
    }//FIN DEL WHILE PRINCIPAL

    return 0;
}


//DESARROLLO DE LAS FUNCIONES
int Menu(){

    int opcion = 0;
    cout <<"\t\t\tMEN"<<char(233)<<endl;
    cout <<"\t1) Ejercicio 1"<<endl;
    cout <<"\t2) Ejercicio 2"<<endl;
    cout <<"\t3) Ejercicio 3"<<endl;
    cout <<"\t4) Ejercicio 4"<<endl;
    cout <<"\t0) SALIR"<<endl;

    cout <<"Opci"<<char(162)<<"n: "<<endl;
    cin >> opcion;

    while(opcion < 0 || opcion > 4){
        cout <<"Error, int"<<char(130)<<"ntelo de nuevo"<<endl;
        cout <<"Opci"<<char(162)<<"n: "<<endl;
        cin >> opcion;
        cout <<endl<<endl;
    }

    return opcion;
}//FIN DE LA FUNCIÓN MENU


void IngresarEquipos( array<EQUIPOS, MAX>& arr, int& total){
    int continuar = 1;
    int i = total;
    cout <<"Ingrese los datos de los equipos de f"<<char(163)<<"tbol"<<endl<<endl;
    cin.ignore();
    while(continuar != 2){
        cout <<"Ingrese el nombre del equipo: ";
        getline(cin, arr.at(i).nombre_equipo );

        cout <<"Ingrese los partidos ganados: ";
        cin >> arr.at(i).ganados;

        cout <<"Ingrese los partidos empatados: ";
        cin >> arr.at(i).empatados;

        arr.at(i).puntos_totales = arr.at(i).ganados*3 + arr.at(i).empatados;
        cout <<endl<<endl<<"Desea ingresar otro equipo?"<<endl;
        cout <<"1) Si"<<endl<<"2) No"<<endl;
        cout <<"Opci"<<char(162)<<"n: ";
        cin >>continuar;
        cout <<endl<<endl;
        while(continuar != 1 && continuar != 2){
            cout <<"Valor no v"<<char(160)<<"lido"<<endl;
            cout <<"Desea ingresar otro equipo?"<<endl;
            cout <<"1) Si"<<endl<<"2) No";
            cin >>continuar;
            cout <<endl<<endl;
        }

        total++;
        i++;
        cin.ignore();
    }


}//fin de la función agregar equipos

void MostrarEquipos( const array<EQUIPOS, MAX>& arr, const int total ){

     string linea(50,'-');
     cout <<linea<<endl<<endl;
    for(int i = 0; i < total; i++){
        cout <<"EQUIPO "<<i+1<<endl<<endl;
        cout <<"Nombre: "<<arr.at(i).nombre_equipo<<endl;
        cout <<"Partidos ganados: "<<arr.at(i).ganados<<endl;
        cout <<"Partidos empatados: "<<arr.at(i).empatados<<endl<<endl;
        cout <<linea<<endl<<endl;
    }

}//fin de la función mostrar equipos

void OrdenarEquipos( array<EQUIPOS, MAX>& arr, const int total){

    string aux_nombre;
    int aux_ganados, aux_empatados, aux_totales;

    for(int i = 0; i < total; i++){
        for(int j = i+1; j<total; j++){
            if( arr.at(j).puntos_totales > arr.at(i).puntos_totales ){

                aux_nombre = arr.at(i).nombre_equipo;
                arr.at(i).nombre_equipo = arr.at(j).nombre_equipo;
                arr.at(j).nombre_equipo = aux_nombre;

                aux_ganados = arr.at(i).ganados;
                arr.at(i).ganados = arr.at(j).ganados;
                arr.at(j).ganados = aux_ganados;

                aux_empatados = arr.at(i).empatados;
                arr.at(i).empatados = arr.at(j).empatados;
                arr.at(j).empatados = aux_empatados;

                aux_totales = arr.at(i).puntos_totales;
                arr.at(i).puntos_totales = arr.at(j).puntos_totales;
                arr.at(j).puntos_totales = aux_totales;
            }
        }
    }

}//fin de la función ordenar equipos


void IngresarEmpleados( array <EMPLEADOS, MAX>& arr1, int& total){
    int n;
    cout <<"Ingrese el numero de empleados a registrar: ";
    cin >> n;
    while(n < 0 || n > MAX){
        cout <<"Valor no v"<<char(160)<<"lido, debe estar entre 0 y 30"<<endl;
        cout <<"Ingrese el numero de empleados: ";
        cin >> n;
        cout <<endl<<endl;
    }

    cout <<endl;
    cin.ignore();
    for(int i = 0; i < n; i++){
        cout <<"Ingrese el nombre del empleado: ";
        getline( cin, arr1.at(i).nombre_empleado );

        cout <<"Ingrese la edad del empleado: ";
        cin >> arr1.at(i).edad_empleado;
        while(arr1.at(i).edad_empleado < 0){
            cout <<"Valor no v"<<char(160)<<"lido, la edad es un numero positivo"<<endl;
            cout <<"Ingrese la edad del empleado: ";
            cin >> arr1.at(i).edad_empleado;
            cout <<endl<<endl;
        }

        cin.ignore();
        cout <<"Ingrese el grado de estudios del empleado: ";
        getline( cin, arr1.at(i).grado_estudios );

        cout <<"Ingrese el tipo de contrataci"<<char(162)<<"n del empleado: ";
        getline( cin, arr1.at(i).tipo_contratacion );
        cout <<endl;
            total++;
    }

}//fin de la función ordenar empleados

void MostrarEmpleados( const array <EMPLEADOS, MAX>& arr1, const int total){

    string linea(60, '-');
    cout << linea << endl << endl;

    for(int i = 0; i < total; i++){
        cout <<"Empleado "<<i+1<<endl;
        cout <<"Nombre: "<<arr1.at(i).nombre_empleado<<endl;
        cout <<"Edad: "<<arr1.at(i).edad_empleado<<endl;
        cout <<"Grado de estudios: "<<arr1.at(i).grado_estudios<<endl;
        cout <<"Tipo de contrataci"<<char(162)<<"n: "<<arr1.at(i).tipo_contratacion<<endl<<endl;

        cout << linea << endl << endl;
    }


}//fin de la función mostrar empleados


void CompararFechas(const FECHA fecha1, const FECHA fecha2 ){

        //SE COMPARAN LOS AÑOS
        if( fecha1.anio != fecha2.anio){
            //los años son distintos por tanto pueden ser mayores o menores
            if(fecha1.anio > fecha2.anio){
                cout <<"La mayor fecha es: "<<fecha1.anio<<"/"<<fecha1.mes<<"/"<<fecha1.dia<<endl<<endl;
            }else{
                //el segundo año es el mayot
                cout <<"La mayor fecha es: "<<fecha2.anio<<"/"<<fecha2.mes<<"/"<<fecha2.dia<<endl<<endl;
            }



        }else if(fecha1.anio == fecha2.anio){
               //ESTE ES EL "PEOR CASO" porque los años son iguales
               //YA NO TIENE SENTIDO COMPARAR AÑOS Y SE COMPARAN LOS MESES

                if(fecha1.mes > fecha2.mes){
                    cout <<"La mayor fecha es: "<<fecha1.anio<<"/"<<fecha1.mes<<"/"<<fecha1.dia<<endl<<endl;

                }else if(fecha1.mes < fecha2.mes){
                    cout <<"La mayor fecha es: "<<fecha2.anio<<"/"<<fecha2.mes<<"/"<<fecha2.dia<<endl<<endl;

                }else{
                    //ahora los meses son iguales y ese es el "peor caso"
                    //ahora se comparan los días
                        if(fecha1.dia >= fecha2.dia){

                                if(fecha1.dia > fecha2.dia){
                                    cout <<"La mayor fecha es: "<<fecha1.anio<<"/"<<fecha1.mes<<"/"<<fecha1.dia<<endl<<endl;
                                }else if(fecha1.dia == fecha2.dia){
                                    cout << "Las fechas "<<fecha1.anio<<"/"<<fecha1.mes<<"/"<<fecha1.dia
                                         <<" y "<<fecha2.anio<<"/"<<fecha2.mes<<"/"<<fecha2.dia<<" son iguales"<<endl<<endl;
                                }


                       }else if(fecha1.dia <= fecha2.dia){


                                if(fecha1.dia < fecha2.dia){
                                    cout <<"La mayor fecha es: "<<fecha2.anio<<"/"<<fecha2.mes<<"/"<<fecha2.dia<<endl<<endl;

                                }else if(fecha1.dia == fecha2.dia){
                                    cout << "Las fechas "<<fecha1.anio<<"/"<<fecha1.mes<<"/"<<fecha1.dia
                                         <<" y "<<fecha2.anio<<"/"<<fecha2.mes<<"/"<<fecha2.dia<<" son iguales"<<endl<<endl;
                                }



                        }


                }



        }

}//fin de la función compararfechas


int Menu_Animales(){
    int opcion;
    cout <<"MEN"<<char(233)<<" DEL ZOOL"<<char(224)<<"GICO"<<endl<<endl;
    cout <<"1) Registrar animal"<<endl;
    cout <<"2) Base de datos de animales del zool"<<char(162)<<"gico"<<endl;
    cout <<"3) Buscar animal"<<endl;
    cout <<"4) Salir"<<endl;
    cout <<">";
    cin >> opcion;

    while( opcion < 1 || opcion > 4){
        cout <<"Error, int"<<char(130)<<"ntelo de nuevo"<<endl;
        cout <<">";
        cin >> opcion;

    }

    return opcion;
}//FIN DE LA FUNCIÓN MENU ANIMALES

void CargarAnimales(LISTA& lista, bool& funciona){

    string nombre_Archivo;
    int opcion_Archivo;

    cout <<"1) Crear nuevo archivo"<<endl;
    cout <<"2) Cargar un archivo existente"<<endl<<"Opci"<<char(162)<<"n: ";
    cin >> opcion_Archivo;
    while( opcion_Archivo < 1 || opcion_Archivo > 2 ){
        cout <<"1) Crear nuevo archivo"<<endl;
        cout <<"2) Cargar un archivo existente"<<endl<<"Opci"<<char(162)<<"n: ";
        cin >> opcion_Archivo;
    }

    cin.ignore();
    if(opcion_Archivo == 1){
        cout <<endl<<"Ingrese el nombre del archivo y su extensi"<<char(162)<<"n (nombre_archivo.extension): ";
        getline(cin, nombre_Archivo);

        ofstream archivo_esc(nombre_Archivo.c_str(),ios::out);
            archivo_esc <<"XXX";
        archivo_esc.close();

        opcion_Archivo = 2;//hago opcion = 2 para que el usuario abra ese archivo nuevo y trabaje con el
    }

    if(opcion_Archivo == 2){

        cout <<endl<<"Ingrese el nombre del archivo y su extensi"<<char(162)<<"n para abrirlo (nombre_archivo.extension): ";
        getline(cin, nombre_Archivo);

        ANIMAL animal;
        ifstream archivo_lec;
        char aux = ' ';
        lista.contador = 0;

        archivo_lec.open(nombre_Archivo.c_str(),ios::in);//-----

        if( !archivo_lec.is_open() ){
            funciona = false;

        }else{
            funciona = true;

            getline(archivo_lec, animal.animal_nombre);
            animal.animal_nombre = animal.animal_nombre.substr(0,30);

            while( (animal.animal_nombre != "XXX")&&(lista.contador < MAX) ){

                    getline(archivo_lec, animal.animal_tipo);
                    animal.animal_tipo = animal.animal_tipo.substr(0,30);

                    archivo_lec >> animal.peso;
                    archivo_lec >> animal.identificador;

                    archivo_lec.get(aux);

                    lista.arrAnimales[lista.contador] = animal;
                    lista.contador++;

                    getline(archivo_lec, animal.animal_nombre);
                    animal.animal_nombre = animal.animal_nombre.substr(0,30);
            }

            archivo_lec.close();
        }


    }




}//FIN DE LA FUNCIÓN CARGAR ANIMALES

void GuardarAnimales(const LISTA& lista){

        string nombre_Archivo;
        cin.ignore();
        cout <<endl<<"Ingrese el nombre del archivo y su extensi"<<char(162)<<"n para guardarlo (nombre_archivo.extension) "<<endl;
        cout <<"Nota: el nombre del archivo para guardar deber"<<char(161)<<"a ser el mismo nombre del archivo que carg"<<char(162)<<": ";
        getline(cin, nombre_Archivo);

        ofstream archivo_esc;
        archivo_esc.open(nombre_Archivo.c_str(),ios::out);

            for(int i = 0; i < lista.contador; i++){
                archivo_esc << lista.arrAnimales[i].animal_nombre<<endl;
                archivo_esc << lista.arrAnimales[i].animal_tipo<<endl;
                archivo_esc << lista.arrAnimales[i].peso<<endl;
                archivo_esc << lista.arrAnimales[i].identificador<<endl;
            }

        archivo_esc <<"XXX"<<endl;
        archivo_esc.close();

}//FIN DE LA FUNCIÓN GUARDAR ANIMALES

void LeerAnimal(ANIMAL& animal, const LISTA& lista){
    cin.ignore();
    cout <<"Ingrese el nombre del animal: ";
    getline(cin, animal.animal_nombre);

    cout <<"Ingrese el tipo de animal: ";
    getline(cin, animal.animal_tipo);

    cout <<"Ingrese el peso del animal: ";
    cin >> animal.peso;


    animal.identificador = lista.contador + 1;


    cin.sync();

}//FIN DE LA FUNCIÓN LEER ANIMAL

void InsertarAnimal(LISTA& lista, ANIMAL animal, bool& funciona){
    funciona = true;

    if(lista.contador == MAX ){
        funciona = false;

    }else{
        lista.arrAnimales[lista.contador] = animal;
        lista.contador++;

    }


}//FIN DE LA FUNCIÓN INSERTAR ANIMAL

void BuscarAnimal(const LISTA& lista){

    unsigned int id_animal;
    int index = 0;
    bool encontrado = false;

    cout <<"Ingrese el identificador del animal a buscar: ";
    cin >> id_animal;

    for(int i = 0; i < lista.contador && encontrado == false; i++){
            if(id_animal == lista.arrAnimales[i].identificador){
                index = i;
                encontrado = true;
            }
    }


    if(encontrado){
        cout <<"El animal "<<lista.arrAnimales[index].animal_nombre<<" con id: "<<lista.arrAnimales[index].identificador
            <<endl<<"se encontr"<<char(162)<<" en la posici"<<char(162)<<"n "<<index+1<<endl<<endl;

    }else{
        cout <<"No se pudo encontrar el animal en nuestros registros"<<endl<<endl;
    }

}//FIN DE LA FUNCIÓN BUSCAR ANIMAL

void MostrarAnimal(const LISTA& lista){

    string linea(60,'*');

    cout <<"Lista de animales"<<endl<<endl;
    cout <<linea<<endl<<endl;
    for(int i = 0; i < lista.contador; i++){
        cout <<lista.arrAnimales[i].identificador<<endl;
        cout <<lista.arrAnimales[i].animal_nombre<<endl;
        cout <<lista.arrAnimales[i].animal_tipo<<endl;
        cout <<lista.arrAnimales[i].peso<<endl<<endl;
        cout<<linea<<endl<<endl;
    }



}//FIN DE LA FUNCIÓN MOSTRAR ANIMAL
