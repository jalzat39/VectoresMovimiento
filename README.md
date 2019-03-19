# VectoresMovimiento


Explicacion de mpi4py

En mpi tenemos 3 codigos, parallel2, parallel3 y parallel4 para 2,3 y 4 cores respectivamente
cada uno funciona de la siguiente forma, se tiene los rangos (2 si son 2 cores, 3 y 4 respectivamente)
para cada rango se separan los ciclos, ya que el serial es de 0 a 15(por ser 16 pixeles), entonces
en 2 cores se divide en 2 ciclos, cada uno de la mitad del ciclo del serial y se comunican entre ellos para encontrar
el valor minimo. Con 3 y 4 nucleos el funcionamiento es el mismo, solo cambiando al numero de ciclos por core.

Explicacion de openmp

En mpi tenemos un codigo en c(openmp no esta en python todavia), el cual paraleliza lo que va luego del #pragma omp parallel, el codigo que va luego del #pragma omp parallel es ejecutado por todos los threads, pero tambien tenemos un ciclo que paralelizar, este va luego del #pragma omp for, lo que significa es que ese codigo va a estar distribuido entre los threads disponibles