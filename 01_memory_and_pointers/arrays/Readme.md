🧠 ¿Qué es el Stack?
El stack (pila) es una región de la memoria que se utiliza para almacenar:

- Variables locales
- Parámetros de funciones
- Direcciones de retorno

Las variables en el stack:

- Se asignan automáticamente cuando entras a una función.
- Se liberan automáticamente cuando sales de la función.
- Tienen un tamaño fijo y conocido en tiempo de compilación.

Son rápidas de asignar y liberar.

________________________________________________________________________________________

🧱 ¿Qué es el Heap?
El heap (montón) es otra región de memoria que se usa para almacenar:
Datos que necesitan vivir más tiempo que la ejecución de una función.
Objetos o estructuras creadas dinámicamente (con malloc, calloc, realloc).

Las variables en el heap:
- Se asignan manualmente (con funciones de la librería estándar).
- Se liberan manualmente (con free).
- Son útiles cuando no sabes el tamaño en tiempo de compilación.

Son más lentas de manejar comparadas con el stack.