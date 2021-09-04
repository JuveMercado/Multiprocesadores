Desarrollar 2 programas que resuelvan las siguientes ecuaciones diferenciales de forma numérica usando el método de Runge-Kutta de orden 4:

y′=te3t−2y

y′=1+(t−y)2

y′=1+y/t

y′=cos(2ty)+sen(3ty)

en el intervalo [0,π] (con 50, mil puntos en el intervalo de evaluación). Para todas las ecuaciones la condición inicial es y(0)=π/4. Se debe de entregar un archivo por cada una de las soluciones determinadas en el programa.

Uno de los programas a desarrollar deberá hacerlo de forma secuencial y el otro en forma paralela usando task level parallelism (TLP). Realizar la documentación en Github y mostrar los tiempos de ejecución de cada uno de los programas.



Se incluyen los archivos con los resultados de cada una de las soluciones del programa, para el paralelo los cuatro archivos parallel.txt y para el secuencial los cuatro archivos secuencial.txt

Dentro de cada programa al ejecutar imprimimos los threads que se encargan de cada tarea y el tiempo total de la ejecución. 