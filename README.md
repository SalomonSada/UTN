# UTN 

## Funcion jugar

Pensé hacer una funcion jugar, que recibirá 4 parametros:

1.- string name   ---> nombre del jugador 1

2.- string name2  ---> nombre del jugador 2 (Si se juega en el modo 1 jugador, se colocara como un string vacio ---> ""

3.- int jugadores ---> Cantidad de jugadores (Asi saber que modo se va a utilizar dentro de la función)

4.- bool azar     ---> Version del juego, if (true) los dados se estableceran al azar, else if (false) los dados los ingresaremos por teclado

### Ejemplos de como llamar a las funciones:

UN jugador:  jugar(name[0], "", 1, true);
   
DOS jugadores:  jugar(name[0], name[1], 2, true);

SIMULADO: Acorde a si lo queremos hacer de UN jugador o DOS, seran los mismos parametros anteriores, pero cambiamos el true a false

-------------------------------------------------------------------
## Return más de un valor de una función

Investigando ví que existe una librería llamada "tuple", que permite devolver varios valores y de distinos tipos de una función.

Copio referencias:

Indio que lo explica re bien: https://www.youtube.com/watch?v=81-cNkP1CuQ

StackOverflow (Respuesta de Sven) https://stackoverflow.com/questions/6394741/can-a-c-function-return-more-than-one-value#:~:text=A%20C%2B%2B%20function%20can%20return,in%20a%20class%20or%20struct.&text=Or%20you%20could%20use%20std,is%20available%20with%20your%20compiler.

