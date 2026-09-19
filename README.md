# Taller 1 – Estructura de Datos

## Integrantes
Andrés Rojas Tejada | 22.065.446-k | andresalitre | ICCI

## Descripción

Sistema básico de gestión de pacientes de un hospital, desarrollado en C++ utilizando estructuras de datos implementadas manualmente (Lista Enlazada, Cola y Pila), punteros, aritmética de punteros, programación orientada a objetos y herencia.

El sistema recibe pacientes desde un archivo de texto, los procesa respetando su orden de llegada (FIFO) mediante una Cola, los deriva al servicio/departamento correspondiente representado como una Lista Enlazada, y registra cada atención en un historial implementado como Pila (LIFO).

## Estructura del proyecto

```
Taller1EstructuraDeDatos/
├── main.cpp
├── pacientes.txt
├── Containers/
│   ├── Node.h
│   ├── List.h
│   ├── Queue.h
│   └── Stack.h
├── Dominio/
│   ├── Persona.h / Persona.cpp
│   ├── Patient.h / Patient.cpp
│   ├── Service.h / Service.cpp
│   └── Attention.h / Attention.cpp
└── Logica/
    ├── PatientFactory.h
    └── PatientFactory.cpp
```

## Instrucciones para compilar y correr el codigo

Para compilarlo y correrlo, se utilizó el siguiente comando:

```bash
git clone https://github.com/andresalitre/Taller1EstructuraDeDatos
cd Taller1EstructuraDeDatos
g++ main.cpp Logica/PatientFactory.cpp Dominio/Patient.cpp Dominio/Persona.cpp Dominio/Service.cpp Dominio/Attention.cpp -o main
./main
```

Si se desea compilar y correr en Windows, se puede utilizar el mismo comando de compilación y luego ejecutar con:

```powershell
git clone https://github.com/andresalitre/Taller1EstructuraDeDatos
cd Taller1EstructuraDeDatos
g++ main.cpp Logica/PatientFactory.cpp Dominio/Patient.cpp Dominio/Persona.cpp Dominio/Service.cpp Dominio/Attention.cpp -o main.exe
.\main.exe
```

El archivo `pacientes.txt` debe estar en la carpeta raíz del repositorio (`Taller1EstructuraDeDatos/`) para que el programa cargue los pacientes correctamente.

## Formato del archivo de entrada

```
001;Juan Perez;25;Cardiologia
002;Maria Soto;67;Urgencias
003;Pedro Rojas;43;Cirugia
```

## Funcionalidades

- Carga de pacientes desde archivo de texto, con validación de archivo inexistente, servicio no válido y pacientes duplicados.
- Cola (Queue) de pacientes en espera, implementada manualmente con nodos y punteros.
- Atención de pacientes en orden FIFO, con derivación automática al servicio correspondiente.
- Lista enlazada principal de servicios, cada uno con su propia lista enlazada de pacientes.
- Historial de atenciones implementado como Pila (Stack), respetando orden LIFO.
- Liberación de memoria dinámica al finalizar la ejecución.

## Estructuras de datos implementadas manualmente

- `Node<T>`
- `List<T>`
- `Queue<T>`
- `Stack<T>`

## Herencia

- `Persona` (clase base): atributos comunes `nombre` y `edad`.
- `Patient` (clase derivada de `Persona`): agrega `id` y `service`.
