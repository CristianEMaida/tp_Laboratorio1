#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployee;

int main()
{
    char seguir = 's';
    char confirma;
    int proximoLegajo = 20000;
    int rta=0;

    eEmployee lista [TAM];

    if(inicializarPersonas(lista, TAM)==0)
    {
        printf("Personas inicializadas con exito!");
    }else
    {
        printf("Ha ocurrido un problema al inicializar personas");
    }

    proximoLegajo +=5;

    if(altaPersona(lista, TAM, proximoLegajo) == 0)
    {
        proximoLegajo++;
        printf("ALTA EXITOSA!\n");
    }
    else
    {
        printf("Problema para realizar el alta");
    }

    mostrarPersonas(lista, TAM);


    do
    {
        switch(menu())
        {

        case 'a':
            if(altaPersona(lista, TAM, proximoLegajo) == 0)
            {
                proximoLegajo++;
                printf("ALTA EXITOSA!\n");
            }
            else
            {
                printf("Problema para realizar el alta");
            }


            break;
        case 'b':
            rta = bajaPersona(lista, TAM);
            if( rta == 0)
            {
                printf("Baja exitosa\n");
            }
            else if(rta == 2)
            {
                printf("Baja cancelada por usuario\n");
            }
            else
            {
                printf("Se ha producido un error en la baja\n");
            }

            break;
        case 'c':
            rta = modificarPersona(lista, TAM);
            if( rta == 0)
            {
                printf("Modificacion exitosa\n");
            }
            else if(rta == 2)
            {
                printf("La modificacion ha sido cancelada por usuario\n");
            }else
            {
                printf("Se ha producido un error en la modificacion\n");
            }
            break;
        case 'd':
            system("cls");
            rta = mostrarPersonas(lista,TAM);

            break;
        case 'z':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("Opcion invalida!!!\n");

        }

        system("pause");
        break;
    }
    while( seguir == 's');

    return 0;
}


char menu()
{
    char opcion;
    system("cls");

    printf("*** ABM Personas ***\n\n");
    printf("a Alta\n");
    printf("b Baja\n");
    printf("c Modificacion\n");
    printf("d Listar\n");
    printf("z Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}



int mostrarPersonas(ePersona gente[], int tam){

    int error = 1;
    int flag = 0;

    if( gente != NULL && tam > 0)
    {
        //system("cls");
        printf(" Legajo    Nombre    Apellido    Salario    Sector\n");
        printf("----------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty == 0)
            {
                mostrarPersona(gente[i]);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("    No hay empleados en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;

}


void mostrarPersona(ePersona unaPersona){

    printf(" %4d    %10s    %s  %3.2f %c\n", unaPersona.id, unaPersona.name, unaPersona.lastName, unaPersona.salary, unaPersona.sector;

}

int buscarLibre(ePersona gente[], int tam) //////para dar de alta
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(gente[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int altaPersona(ePersona gente[], int tam, int legajo){

    int error = 1;
    int indice;
    ePersona nuevaPersona;

    if(gente!=NULL && tam > 0 && legajo > 0)
    {
        indice = buscarLibre(gente, tam);

        if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }
        else
        {
            //aplicar validaciones a las cargas
            nuevaPersona.id = legajo;
            nuevaPersona.isEmpty = 0;
            printf("\n\nIngrese nombre: ");
            fflush(stdin);
            gets(nuevaPersona.name);
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(nuevaPersona.lastName);
            printf("Ingrese salario: ");
            scanf("%f", &nuevaPersona.altura);
            printf("Ingrese sector: ");
            fflush(stdin);
            scanf("%c", &nuevaPersona.sector);
            gente[indice] = nuevaPersona;
            error = 0;
        }
    }

    return error;
}


int buscarPersona(ePersona gente[], int tam, int legajo)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(gente[i].legajo == legajo && gente[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int bajaPersona(ePersona gente[], int tam)
{
    int error = 1;
    int legajo;
    int indice;
    int confirma;

    if(gente != NULL && tam > 0)
    {
        system("cls");
        printf("    *** BAJA DE PERSONA ***\n");
        mostrarPersonas(gente, tam);
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo);

        indice = buscarPersona(gente, tam, legajo);

        if( indice == -1)
        {
            printf("No existe una persona con ese legajo.\n");
        }
        else
        {
            mostrarPersona(gente[indice]);
            printf("Confirma baja: 1 - SI 2 - NO");
            scanf("%d", &confirma);
            if(confirma == 1)
            {
                gente[indice].isEmpty = 1;
                error = 0;
            }else
            {
                error = 2;
            }
        }

    }

    return error;

}

int modificarPersona(ePersona gente[], int tam)
{
    int error = 1;
    int legajo;
    int indice;
    int confirma;
    eFecha nuevaFecha;

    if(gente != NULL && tam > 0)
    {
        system("cls");
        printf("    *** BAJA DE PERSONA ***\n");
        mostrarPersonas(gente, tam);
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo);

        indice = buscarPersona(gente, tam, legajo);

        if( indice == -1)
        {
            printf("No existe una persona con ese legajo.\n");
        }
        else
        {
            mostrarPersona(gente[indice]);
            printf("\nIngrese nueva fecha de nacimiento");
            scanf("%d/%d/%d" , &nuevaFecha.dia, &nuevaFecha.mes, &nuevaFecha.anio);
            mostrarFecha(nuevaFecha);

            printf("Confirma modificacion?: ");
            fflush(stdin);
            scanf("%d", &confirma);
            if (confirma == 's')
            {
                gente[indice].fNac = nuevaFecha;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }

    }

    return error;

}


int ordenarPersonasApellidoSector(ePersona gente[], int tam, int criterioS, int criterioA)
{

    int error = 1;
    ePersona auxPersona;

    if(gente!=NULL && tam>0 && criterioS>=0 && criterioS<=1 && criterioA >= 0 && criterioA <= 1)
    {


        for(int i=0; i-tam -1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                //a- comparando personas del mismo sexos desempata la altura
                //b- comparando personas de distinto sexo
                ///////////ORDENAMIENTO POR SEXO ASCENDENTE O DESCENDENTE
                if( gente[i].lastName > gente[j].lastName && criterioS == 1)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
                else if(gente[i].lastName < gente[j].lastName && criterioS == 0)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
                else if(gente[i].lastName == gente[j].lastName && gente[i].sector > gente[j].sector && criterioA == 1)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
                else if(gente[i].lastName == gente[j].lastName && gente[i].sector < gente[j].sector && criterioA == 0)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
            }
        }
        error = 0;
    }

    return 0;

}
