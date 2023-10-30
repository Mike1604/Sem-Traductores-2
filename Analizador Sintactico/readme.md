
# Analizador Sintactico

Esta parte del repositorio corresponde al analizador Sintactico el cual cuenta con una tabla LR1 previamente asignada para una gramatica en especifico, asimismo emplea el analizador lexico previamente realizado, en esta ocasion lee cada uno de los tokens y posteriormente evalua cada una de las reglas y estados y realiza dichas reducciones.

## Compilador
La siguiente imagen corresponde al compilador en el momento del Analizador Sintactico
![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/Compilador.JPG?raw=true)
## Sintactico
La siguiente imagen corresponde al apartado del analizador Sintactico, en el cual podemos ver hay 3 apartados.
Pila el cual corresponde a la pila del analizador Sintactico, donde se va agregando cada token y reduccion.
Entrada el cual corresponde a los tokens siguientes de la entrada.
Salida corresponde a los desplazamientos o regla ejecutada segun el analizador Sintactico
![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/SintacticoApartado.JPG?raw=true)

## 1er Ejemplo
El primer ejemplo que se realizo se introdujo la siguiente cadena:
int main(){ int a; while(a != 2){ a=a+a; } } 
La cual se analiza lexicamente y posteriormente se realiza el analisis Sintactico
![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/PrimerGramatica.JPG?raw=true)
## 1er Ejemplo Analisis sintactico:
![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/PrimerGramatica1.JPG?raw=true)
![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/PrimerGramatica2.JPG?raw=true)
## 2do Ejemplo
El 2d0 ejemplo que se realizo se introdujo una cadena mas compleja la cual es:
int main(){ int a; while(a != 2){ a=a+a; } } 
La cual se analiza lexicamente y posteriormente se realiza el analisis Sintactico
![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/SegundaGramatica.JPG?raw=true)
## 1er Ejemplo Analisis sintactico:
![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/PrimerGramatica1.JPG?raw=true)
![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/PrimerGramatica2.JPG?raw=true)

## 1er Ejemplo Analisis sintactico Arbol:
Otra de las caracteristicas incluidas en dicho analizador sintactico es realizar el arbol sintactico de dicho programa a continuacion podemos ver un ejemplo sencillo del arbol sintactico que funciona con la gramatica empleada anteriormente
![App Screenshot]([https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/PrimerGramatica1.JPG?raw=true](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/SintacticoArbol1.JPG))
![App Screenshot]([https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/PrimerGramatica2.JPG?raw=true](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/SintacticoArbol2.JPG)https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/SintacticoArbol2.JPG)
## 2do Ejemplo Analisis sintactico Arbol:
![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/PrimerGramatica1.JPG?raw=true](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/SintacticoArbol1.JPG](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/SintacticoArbol3.JPG)))
![App Screenshot](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/PrimerGramatica2.JPG?raw=true](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/SintacticoArbol2.JPG)https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/SintacticoArbol2.JPG](https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/SintacticoArbol4.JPG)https://github.com/Mike1604/Sem-Traductores-2/blob/main/Analizador%20Sintactico/Readme%20data/SintacticoArbol4.JPG)


